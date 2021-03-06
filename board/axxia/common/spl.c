/*
 *  board/axxia/common/spl.c
 *
 *  Copyright (C) 2015 Intel (john.jacques@intel.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307	 USA
 */

#include <config.h>
#include <common.h>
#include <version.h>
#include <serial.h>
#include <malloc.h>
#include <spl.h>
#include <spi.h>
#include <spi_flash.h>
#include <watchdog.h>
#include <asm/io.h>

DECLARE_GLOBAL_DATA_PTR;

unsigned int syscon_0x0dc __attribute__ ((section ("data")));
unsigned int syscon_0x100 __attribute__ ((section ("data")));

/*
  ==============================================================================
  ==============================================================================
  Local Stuff
  ==============================================================================
  ==============================================================================
*/

/*#define COPY_MONITOR_TO_RAM*/

/*
  ------------------------------------------------------------------------------
  is_redundant_enabled
*/

#ifndef SYSCACHE_ONLY_MODE

static int
is_redundant_enabled(void)
{
#if !defined(CONFIG_REDUNDANT_UBOOT)
	return 0;
#endif

#if defined(CONFIG_REDUNDANT_UBOOT_AUTO)
	if (0 != (pfuse & (1 << 12)))
		return 1;

	return 0;
#else
	return 1;
#endif
}

#endif	/* SYSCACHE_ONLY_MODE */

/*
  ==============================================================================
  SPL Memory Tests
  ==============================================================================
*/

enum spl_mtest_type {
	spl_mtest_data = 0,
	spl_mtest_addr,
	spl_mtest_mtest,
	spl_mtest_ecc,
	spl_mtest_all
};

/*
  ------------------------------------------------------------------------------
  mtest_data
*/

static int
mtest_data(unsigned long *start, unsigned long *end)
{
	vu_long	*addr;
	ulong	val;
	ulong	readback;
	ulong	errs = 0;
	vu_long *dummy;
	int	j;

	static const ulong bitpattern[] = {
		0x0000000000000001,	/* single bit */
		0x0000000000000003,	/* two adjacent bits */
		0x0000000000000007,	/* three adjacent bits */
		0x000000000000000F,	/* four adjacent bits */
		0x0000000000000005,	/* two non-adjacent bits */
		0x0000000000000015,	/* three non-adjacent bits */
		0x0000000000000055,	/* four non-adjacent bits */
		0xaaaaaaaaaaaaaaaa,	/* alternating 1/0 */
	};

	/*
	 * Data line test: write a pattern to the first
	 * location, write the 1's complement to a 'parking'
	 * address (changes the state of the data bus so a
	 * floating bus doen't give a false OK), and then
	 * read the value back. Note that we read it back
	 * into a variable because the next time we read it,
	 * it might be right (been there, tough to explain to
	 * the quality guys why it prints a failure when the
	 * "is" and "should be" are obviously the same in the
	 * error message).
	 *
	 * Rather than exhaustively testing, we test some
	 * patterns by shifting '1' bits through a field of
	 * '0's and '0' bits through a field of '1's (i.e.
	 * pattern and ~pattern).
	 */
	addr = start;
	dummy = start + 1;

	for (j = 0; j < sizeof(bitpattern)/sizeof(bitpattern[0]); ++j) {
		for (val = bitpattern[j]; val != 0; val <<= 1) {
			*addr  = val;
			/* clear the test data off of the bus */
			*dummy	= ~val;
			readback = *addr;

			if (readback != val) {
				printf("FAILURE (data line): " \
				       "expected %08lx, actual %08lx\n",
				       val, readback);
				errs++;
			}

			*addr  = ~val;
			*dummy	= val;
			readback = *addr;

			if (readback != ~val) {
				printf("FAILURE (data line): " \
				       "Is %08lx, should be %08lx\n",
				       readback, ~val);
				errs++;
			}
		}
	}

	return errs;
}

/*
  ----------------------------------------------------------------------
  mtest_addr
*/

static int
mtest_addr(unsigned long *start, unsigned long *end)
{
	ulong	errs = 0;
	vu_long	len;
	vu_long	offset;
	vu_long	test_offset;
	vu_long	pattern;
	vu_long	temp;
	vu_long	anti_pattern;

	pattern = 0;

	/*
	 * Based on code whose Original Author and Copyright
	 * information follows: Copyright (c) 1998 by Michael
	 * Barr. This software is placed into the public
	 * domain and may be used for any purpose. However,
	 * this notice must not be changed or removed and no
	 * warranty is either expressed or implied by its
	 * publication or distribution.
	 */

	/*
	 * Address line test
	 *
	 * Description: Test the address bus wiring in a
	 *		memory region by performing a walking
	 *		1's test on the relevant bits of the
	 *		address and checking for aliasing.
	 *		This test will find single-bit
	 *		address failures such as stuck -high,
	 *		stuck-low, and shorted pins. The base
	 *		address and size of the region are
	 *		selected by the caller.
	 *
	 * Notes:	For best results, the selected base
	 *		address should have enough LSB 0's to
	 *		guarantee single address bit changes.
	 *		For example, to test a 64-Kbyte
	 *		region, select a base address on a
	 *		64-Kbyte boundary. Also, select the
	 *		region size as a power-of-two if at
	 *		all possible.
	 *
	 * Returns:
	 * 0 if the test succeeds, 1 if the test fails.
	 */
	len = ((ulong)end - (ulong)start)/sizeof(vu_long);
	pattern = (vu_long) 0xaaaaaaaaaaaaaaaa;
	anti_pattern = (vu_long) 0x5555555555555555;

	/*
	 * Write the default pattern at each of the
	 * power-of-two offsets.
	 */
	for (offset = 1; offset < len; offset <<= 1)
		start[offset] = pattern;

	/*
	 * Check for address bits stuck high.
	 */
	test_offset = 0;
	start[test_offset] = anti_pattern;

	for (offset = 1; offset < len; offset <<= 1) {
		temp = start[offset];
		if (temp != pattern) {
			printf("\nFAILURE: Address bit stuck" \
			       " high @ 0x%.8lx:" \
			       " expected 0x%.8lx," \
			       " actual 0x%.8lx\n", \
			       (ulong)&start[offset],
			       pattern, temp);
			errs++;
		}
	}
	start[test_offset] = pattern;
	WATCHDOG_RESET();

	/*
	 * Check for addr bits stuck low or shorted.
	 */
	for (test_offset = 1; test_offset < len;
	     test_offset <<= 1) {
		start[test_offset] = anti_pattern;

		for (offset = 1; offset < len; offset <<= 1) {
			temp = start[offset];
			if ((temp != pattern) &&
			    (offset != test_offset)) {
				printf("\nFAILURE: Address bit"\
				       "stuck low or"
				       " shorted @" \
				       " 0x%.8lx:" \
				       " expected 0x%.8lx, "\
				       "actual 0x%.8lx\n",
				       (ulong)&start[offset],
				       pattern,
				       temp);
				errs++;
			}
		}
		start[test_offset] = pattern;
	}

	return errs;
}

/*
  ----------------------------------------------------------------------
  mtest_mtest
*/

#define WATCHDOG_MOD 1000000

static int
mtest_mtest(unsigned long *start, unsigned long *end)
{
	ulong	errs = 0;
	vu_long	offset;
	vu_long	pattern;
	vu_long	temp;
	vu_long	anti_pattern;
	vu_long	num_words;
	vu_long progress_mod;

	pattern = 0;

	/*
	 * Description: Test the integrity of a physical
	 *	memory device by performing an
	 *	increment/decrement test over the
	 *	entire region. In the process every
	 *	storage bit in the device is tested
	 *	as a zero and a one. The base address
	 *	and the size of the region are
	 *	selected by the caller.
	 *
	 * Returns:
	 *     0 if the test succeeds, 1 if the test fails.
	 */
	num_words =
		((ulong)end - (ulong)start)/sizeof(vu_long) + 1;

	/*
	 * Fill memory with a known pattern.
	 */

	puts("Filling");
	progress_mod = (num_words / (79 - strlen("Filling")));
	WATCHDOG_RESET();

	for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
		start[offset] = pattern;

		if ((offset % WATCHDOG_MOD) == 0)
			WATCHDOG_RESET();

		if ((offset % progress_mod) == 0)
			puts(".");
	}

	puts("\n");

	/*
	 * Check each location and invert it
	 * for the second pass.
	 */

	puts("Comparing and Inverting");
	progress_mod = (num_words / (79 - strlen("Comparing and Inverting")));
	WATCHDOG_RESET();

	for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
		if ((offset % WATCHDOG_MOD) == 0)
			WATCHDOG_RESET();

		if ((offset % progress_mod) == 0)
			puts(".");

		temp = start[offset];

		if (temp != pattern) {
			printf("\nFAILURE (read/write) @ 0x%.8lx: " \
			       "expected 0x%.8lx, actual 0x%.8lx)\n",
			       (ulong)&start[offset], pattern, temp);
			errs++;
		}

		anti_pattern = ~pattern;
		start[offset] = anti_pattern;
	}

	puts("\n");

	/*
	 * Check each location for the inverted pattern
	 * and zero it.
	 */

	puts("Comparing");
	progress_mod = (num_words / (79 - strlen("Comparing")));
	WATCHDOG_RESET();

	for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
		if ((offset % WATCHDOG_MOD) == 0)
			WATCHDOG_RESET();

		if ((offset % progress_mod) == 0)
			puts(".");

		anti_pattern = ~pattern;
		temp = start[offset];

		if (temp != anti_pattern) {
			printf("\nFAILURE (read/write): @ 0x%.8lx: "
			       "expected 0x%.8lx, actual 0x%.8lx)\n",
			       (ulong)&start[offset], anti_pattern, temp);
			errs++;
		}

		start[offset] = 0;
	}

	puts("\n");

	return errs;
}

/*
  ----------------------------------------------------------------------
  mtest_ecc

  The object of this test is to make sure all the physical lines
  connecting memory work.  The patterns are based on the patterns
  used during coarse write leveling.

  Note that the name, ecc, simply means that the ECC lines should be
  excersized as well as the data/address lines.
*/

static int
mtest_ecc(unsigned long *start, unsigned long *end)
{
	int i;
	unsigned long *memory;
	unsigned long patterns[] = {
		0xed76c3c392790f56,
		0x14cffe90f414bafc,
		0x0213a40229acc6ba,
		0x923b663440ff84f2,
		0xf4b90a1c203eff5a,
		0x32409395517a4434,
		0x6780cade6aed1ab0,
		0xe6f38088f1c96f7d,
		0x9bf98feb7efffc08,
		0xaa49f06d12c46b44,
		0xac35d1a4bd1d02d1,
		0x298b4e091d0c0beb,
		0x1045f89d74ea7d2f,
		0x55b65995591809be,
		0x69f558ba0c894c83,
		0xd27e9e7ee3dc14c9,
		0xf1f76fd4b9df2547,
		0x4d1a99d7bbec92ec,
		0xd48b5ae66287cd9e,
		0xa5536cf1987f4bce,
		0xdfec8e2f3802c6b5,
		0xd3d28b18afdee879,
		0x8c3de09aafe75289,
		0x3c2521c5c0032135,
		0xddcb086a85b4e341,
		0xc343b3418e23d95e,
		0x6757d6dec7c883d4,
		0x746938ff42f92872,
		0xbee0d90d6256228b,
		0xaa23014136d7a3d5,
		0x111f392e9ec0603c,
		0x2ce3abbaa9967c59
	};

	/* Make sure enough space is available starting at start. */
	if ((end - start) < (sizeof(patterns) / sizeof(unsigned long))) {
		printf("Not enough memory for ECC test (%lu minimum).\n",
		       (sizeof(patterns) / sizeof(unsigned long)));
		return -1;
	}

	/* Write all patterns. */
	memory = start;

	for (i = 0; i < (sizeof(patterns) / sizeof(unsigned long)); ++i)
		*memory++ = patterns[i];

	/* Read and compare. */
	memory = start;

	for (i = 0; i < (sizeof(patterns) / sizeof(unsigned long));
	     ++i, ++memory) {
		if (patterns[i] != *memory) {
			printf("ECC Compare Failed at 0x%p: 0x%lx != 0x%lx\n",
			       (start + i), *memory, patterns[i]);

			return -1;
		}
	}

	return 0;
}

/*
  ----------------------------------------------------------------------
  spl_mtest

  Drivers for all the available tests.
*/

int
spl_mtest(unsigned long *start, unsigned long *end, int total_iterations,
	  enum spl_mtest_type type)
{
	ulong	errs = 0;
	int iterations = 0;
	char *spl_mtest_str[] = {
		"Data",
		"Address",
		"standard",
		"ECC",
		"All"
	};

	printf("Running %s Test: 0x%p ... 0x%p:\n",
	       spl_mtest_str[type], start, end);

	for (;;) {
		if (iterations >= total_iterations) {
			printf("Tested %d iteration(s) with %lu errors.\n",
			       iterations, errs);

			return errs != 0;
		}

		iterations++;
		printf("Iteration: %d\n", iterations);
		debug("\n");

		if ((type == spl_mtest_data) || (type == spl_mtest_all))
			errs += mtest_data(start, end);

		if ((type == spl_mtest_addr) || (type == spl_mtest_all))
			errs += mtest_addr(start, end);

		if ((type == spl_mtest_mtest) || (type == spl_mtest_all))
			errs += mtest_mtest(start, end);

		if ((type == spl_mtest_ecc) || (type == spl_mtest_all))
			errs += mtest_ecc(start, end);
	}

	return 0;
}

/*
  ==============================================================================
  ==============================================================================
  Global Stuff
  ==============================================================================
  ==============================================================================
*/

/*
  ------------------------------------------------------------------------------
  check_memory_ranges
*/

static void
check_memory_ranges(void)
{
	int i;
	unsigned int *ranges;

	ranges = &global->memory_ranges[0];

	for (i = 0; i < 8; ++i) {
		unsigned long offset;
		unsigned long end;

		offset = (unsigned long)(*ranges++);
		offset *= 0x100000;
		end = (unsigned long)(*ranges++);

		if (0 == end)
			continue;

		end *= 0x100000;
		end = offset + end;

		if (global->flags & PARAMETERS_GLOBAL_ENABLE_SW_MEM_DATA_TEST)
			spl_mtest((unsigned long *)offset,
				  (unsigned long *)end,
				  1, spl_mtest_data);

		if (global->flags & PARAMETERS_GLOBAL_ENABLE_SW_MEM_ADDR_TEST)
			spl_mtest((unsigned long *)offset,
				  (unsigned long *)end,
				  1, spl_mtest_addr);

		if (global->flags & PARAMETERS_GLOBAL_ENABLE_SW_MEM_MTEST)
			spl_mtest((unsigned long *)offset,
				  (unsigned long *)end,
				  1, spl_mtest_mtest);

		if (global->flags & PARAMETERS_GLOBAL_ENABLE_SW_MEM_ECC_TEST)
			spl_mtest((unsigned long *)offset,
				  (unsigned long *)end,
				  1, spl_mtest_ecc);
	}

	axxia_sysmem_check_ecc();

	return;
}

u32 spl_boot_device(void)
{
	return (u32) BOOT_DEVICE_SPI;
}


/*
  ------------------------------------------------------------------------------
  verify_image
*/

#ifndef SYSCACHE_ONLY_MODE

static int
verify_image(struct spi_flash *flash,
	     unsigned long flash_offset,
	     int secure_boot)
{
	struct image_header header;
	char *sbb_magic;
	unsigned char sbb_encrypted;
	unsigned int sbb_size;
	void *membase = (void *)0x1000;

	/*
	  The U-Boot SPI flash interface uses NULL in the in or out
	  address to indicate direction.  That being the case, it
	  isn't possible to copy from SPI flash to address 0 (base of
	  system memory).  Since the header has to be skipped at the
	  end anyway, with a memmove(), just start a bit above 0.
	*/

	/*
	  Must begin with a U-Boot mkimage header of some sort.
	*/

	WATCHDOG_RESET();
	spi_flash_read(flash, flash_offset,
		       sizeof(struct image_header), &header);
	spl_parse_image_header(&header);
	spi_flash_read(flash, flash_offset,
		       spl_image.size + sizeof(struct image_header),
		       membase);
	spl_image.load_addr += (unsigned long)membase;
	WATCHDOG_RESET();

	if (!image_check_magic(&header)) {
		puts("\tBad Magic!\n");

		return -1;
	}

	if (!image_check_target_arch(&header)) {
		puts("\tWrong Architecture!\n");

		return -1;
	}

	if (ntohl(header.ih_dcrc) !=
	    crc32(0, (unsigned char *)
		  (membase + sizeof(struct image_header)),
		  (spl_image.size - sizeof(struct image_header)))) {
		puts("\tBad Checksum!\n");

		return -1;
	}

	/*
	  Now that the image has been verified from the U-Boot
	  perspective, remove the mkimage header.
	*/

	membase += sizeof(struct image_header);

	/*
	  If secure boot is enabled, verify.
	*/

	WATCHDOG_RESET();

	if (0 != secure_boot) {
#ifndef CONFIG_TARGET_SIMULATION
		if (0 != sbb_verify_image((void *)membase, (void *)membase,
					  0, 1, 0)) {
			puts("\tInsecure!\n");

			return -1;
		}
#endif

		memmove((void *)0, (void *)membase,
			spl_image.size - sizeof(struct image_header));

		return 0;
	}

	/*
	  If secure boot is not enabled, but the image is signed,
	  remove the secure boot header (12 bytes in the unencrypted
	  case).
	*/

	WATCHDOG_RESET();
	sbb_magic = membase;
	sbb_encrypted = *((unsigned char *)(membase + 9));
	sbb_encrypted &= 1;

	if (0 == strncmp(sbb_magic, "SBB!", 4)) {
		if (0 != sbb_encrypted)
			return -1;

		sbb_size = ntohl(*((unsigned int *)(membase + 4)));
		memmove((void *)0, ((void *)membase + 12), sbb_size);

		return 0;
	}

	/*
	  Remove membase.
	*/

	WATCHDOG_RESET();
	memmove((void *)0, (void *)membase,
		(spl_image.size - sizeof(struct image_header)));

	return 0;
}

#endif	/* SYSCACHE_ONLY_MODE */

/*
  ------------------------------------------------------------------------------
  jump_to_monitor

  This function is intentional not made static to enable using a jtag
  debugger to boot a system with no external host and uninitialized
  serial flash.
*/

typedef enum {
	AXXIA_5600 = 0,
	AXXIA_6700 = 1,
	AXXIA_6700_B0 = 2
} axxia_target_t;

typedef enum {
	AXXIA_SIM = 0,
	AXXIA_EMU = 1,
	AXXIA_HW = 2
} axxia_platform_t;

typedef enum {
	AXXIA_NONE = 0,
	AXXIA_SYSCACHE_ONLY = 1
} axxia_option_t;

typedef enum {
	CACHE_PROTECTION_DISABLED = 0,
	CACHE_PROTECTION_ENABLED = 1
} axxia_cache_protection_t;

typedef struct axxia_configuration {
	axxia_target_t target;
	axxia_platform_t platform;
	axxia_option_t option;
	unsigned int per_clock_hz;
	unsigned int baud_rate;
	axxia_cache_protection_t cache_protection;
} axxia_configuration_t;

extern void *__monitor_parameters;

void
jump_to_monitor(void *address)
{
	void (*entry)(void *, void *);
	axxia_configuration_t *axxia_configuration;

	axxia_configuration = (axxia_configuration_t *)&__monitor_parameters;
#if defined(CONFIG_AXXIA_56XX_SIM)
	axxia_configuration->target = AXXIA_5600;
	axxia_configuration->platform = AXXIA_SIM;
#elif defined(CONFIG_AXXIA_56XX_EMU)
	axxia_configuration->target = AXXIA_5600;
	axxia_configuration->platform = AXXIA_EMU;
#elif defined(CONFIG_AXXIA_56XX)
	axxia_configuration->target = AXXIA_5600;
	axxia_configuration->platform = AXXIA_HW;
#elif defined(CONFIG_AXXIA_XLF_SIM)
	axxia_configuration->target = AXXIA_6700;
	axxia_configuration->platform = AXXIA_SIM;
#elif defined(CONFIG_AXXIA_XLF_EMU)
	axxia_configuration->target = AXXIA_6700;
	axxia_configuration->platform = AXXIA_EMU;
#elif defined(CONFIG_AXXIA_XLF)
	if (0 != is_xlf_a0())
		axxia_configuration->target = AXXIA_6700;
	else
		axxia_configuration->target = AXXIA_6700_B0;

	axxia_configuration->platform = AXXIA_HW;
#endif
#ifdef SYSCACHE_ONLY_MODE
	axxia_configuration->option = AXXIA_SYSCACHE_ONLY;
#endif
#ifdef CONFIG_CACHE_PROTECTION
	axxia_configuration->cache_protection = CACHE_PROTECTION_ENABLED;
#endif

	if (0 != acp_clock_get(clock_peripheral,
			       &axxia_configuration->per_clock_hz))
		acp_failure(__FILE__, __func__, __LINE__);

	axxia_configuration->per_clock_hz *= 1000;
	axxia_configuration->baud_rate = gd->baudrate;
	entry = (void (*)(void *, void *))address;
	cleanup_before_linux();
	entry(NULL, axxia_configuration);
	acp_failure(__FILE__, __func__, __LINE__);

	return;
}

/*
  ------------------------------------------------------------------------------
  jtag_jump_to_monitor
*/

void __attribute__((used))
jtag_jump_to_monitor(void)
{
	jump_to_monitor((void *)0x8031001000);

	return;
}

/*
  ------------------------------------------------------------------------------
  load_image
*/

#ifdef SYSCACHE_ONLY_MODE

static void
load_image(void)
{
	struct spi_flash *flash;
	struct image_header header;
	unsigned int bytes_written = 0;
	/* 
 	  GPDMA requires 16 byte alignment for a source address.
 	*/
	unsigned int buffer[64] __attribute__ ((aligned(16)));
	unsigned int offset = CONFIG_UBOOT_OFFSET;
	unsigned int size;
	unsigned long output = 0;
	int ret = 0;

	/*
	  Initialize L3 cache by writing to all locations.  Write the
	  U-Boot image at offset 0 and then fill the rest.
	*/

	flash = spi_flash_probe(CONFIG_SPL_SPI_BUS, CONFIG_SPL_SPI_CS,
				CONFIG_SF_DEFAULT_SPEED,
				CONFIG_SF_DEFAULT_MODE);

	if (!flash) {
		puts("SPI probe failed.\n");
		hang();
	}

	spi_flash_read(flash, offset, sizeof(struct image_header), &header);
	spl_parse_image_header(&header);

	if (!image_check_magic(&header)) {
		puts("\tBad Magic!\n");
		hang();
	}

	if (!image_check_target_arch(&header)) {
		puts("\tWrong Architecture!\n");
		hang();
	}

	offset += sizeof(struct image_header);
	size = spl_image.size - sizeof(struct image_header);

	while (SYSCACHE_SIZE > bytes_written) {
		memset(buffer, 0, sizeof(buffer));

		if (0 < size) {
			spi_flash_read(flash, offset,
				       size > 256 ? 256 : size, buffer);
			size -= size > 256 ? 256 : size;
		}

		ret = gpdma_xfer((void *)output, (void *)buffer, 256, 1);
		if (ret != 0) {
			printf("xfer failed %d, %u\n", ret, bytes_written);
			break;
		}
		bytes_written += 256;
		output += 256;
		offset += 256;
	}

	return;
}

#else  /* SYSCACHE_ONLY_MODE */

static void
load_image(void)
{
	struct spi_flash *flash;
	int watchdog_timeout;
	int a_valid;
	int b_valid;
	unsigned long a_sequence = 0;
	unsigned long b_sequence = 0;
	int copy_to_use = 0;
	int sbb_enabled = 0;
	struct image_header header;

	/*
	 * Load U-Boot image from SPI flash into RAM
	 */

	flash = spi_flash_probe(CONFIG_SPL_SPI_BUS, CONFIG_SPL_SPI_CS,
				CONFIG_SF_DEFAULT_SPEED,
				CONFIG_SF_DEFAULT_MODE);

	if (!flash) {
		puts("SPI probe failed.\n");
		hang();
	}

	if (is_redundant_enabled()) {
		/*
		  Was the last reset caused by a watchdog timeout?
		*/

		watchdog_timeout = (0 != (syscon_0x0dc & 0x4));

		/*
		  Is this a secure boot?
		*/

		sbb_enabled = (1 == is_sbb_enabled(0));

		/*
		  Is image A valid?
		*/

		WATCHDOG_RESET();
		puts("Checking U-Boot Image A\n");

		if (0 == verify_image(flash, CONFIG_UBOOT_OFFSET, sbb_enabled))
			a_valid = 1;
		else
			a_valid = 0;

		if (1 == a_valid) {
			char *temp;

			temp = getenv("uboot_a_sequence");

			if (NULL != temp)
				a_sequence = simple_strtoul(temp, NULL, 0);
			else
				a_sequence = 0;
		}

		/*
		  Is image B valid?
		*/

		WATCHDOG_RESET();
		puts("Checking U-Boot Image B\n");

		if (0 == verify_image(flash, CONFIG_UBOOT_OFFSET_REDUND,
				      sbb_enabled))
			b_valid = 1;
		else
			b_valid = 0;

		if (1 == b_valid) {
			char *temp;

			temp = getenv("uboot_b_sequence");

			if (NULL != temp)
				b_sequence = simple_strtoul(temp, NULL, 0);
			else
				b_sequence = 0;
		}

		if (0 == a_valid && 0 == b_valid) {
			acp_failure(__FILE__, __func__, __LINE__);
		} else if (0 == a_valid && 0 != b_valid) {
			copy_to_use = 1;
		} else if (0 != a_valid && 0 == b_valid) {
			copy_to_use = 0;
		} else {
			if (0xffffffff == a_sequence && b_sequence == 0)
				copy_to_use = 1;
			else if (b_sequence > a_sequence)
				copy_to_use = 1;

			if (0 != watchdog_timeout)
				copy_to_use = (0 == copy_to_use) ? 1 : 0;
		}

		printf("U-Boot: Watchdog %d A/B Valid %d/%d A/B Sequence %lu/%lu => %s\n",
		       watchdog_timeout, a_valid, b_valid,
		       a_sequence, b_sequence,
		       (0 == copy_to_use) ? "A" : "B");

		/*
		  If B was selected, do nothing, as it has already been
		  loaded, if A, reload.
		*/

		if (0 == copy_to_use &&
		    0 != verify_image(flash, CONFIG_UBOOT_OFFSET, sbb_enabled))
			acp_failure(__FILE__, __func__, __LINE__);
	} else {
		/* Load u-boot, mkimage header is 64 bytes. */
		spi_flash_read(flash, CONFIG_UBOOT_OFFSET, 0x40, &header);
		spl_parse_image_header(&header);
		spl_image.load_addr = 0;

		if (IH_MAGIC == image_get_magic(&header)) {
			/* Load a U-Boot Image, Verifying Checksum */
			spi_flash_read(flash, CONFIG_SYS_SPI_U_BOOT_OFFS +
				       sizeof(struct image_header),
				       spl_image.size,
				       (void *)0x1000);
			memmove((void *)0, (void *)0x1000, spl_image.size);

			if (ntohl(header.ih_dcrc) !=
			    crc32(0, (unsigned char *)0,
				  (spl_image.size -
				   sizeof(struct image_header)))) {
				puts("Bad U-Boot Image Checksums!\n");
				acp_failure(__FILE__, __func__, __LINE__);
			}
		} else {
			/* Load a U-Boot Binary */
			spi_flash_read(flash, CONFIG_SYS_SPI_U_BOOT_OFFS,
				       spl_image.size,
				       (void *)0x1000);
			memmove((void *)0, (void *)0x1000, spl_image.size);
		}

#ifdef CONFIG_AXXIA_SIM
		{
			void *header;
			char *sbb_magic;
			unsigned char sbb_encrypted;
			unsigned int sbb_size;

			header = malloc(12);
			memcpy(header, (void *)0, 12);
			sbb_magic = (void *)header;
			sbb_encrypted = *((unsigned char *)(header + 9));
			sbb_encrypted &= 1;

			if (0 == strncmp(sbb_magic, "SBB!", 4) &&
			    (0 == sbb_encrypted)) {
				sbb_size = ntohl(*((unsigned int *)4));
				memmove((void *)0, (void *)12, sbb_size);
				free(header);
			}
		}
#else
		if (0 != sbb_verify_image(0x00000000, 0x00000000, 0, 1, 0))
			acp_failure(__FILE__, __func__, __LINE__);
#endif
	}

#ifdef COUNTER_FREQUENCY_MULTIPLIER
	/*
	  During performance testing, it is sometimes useful to see
	  how much affect OS overhead is having.  This is especially
	  true when using the emulation platform, as the clocks are
	  quite a bit slower.  The following multiplies the cntfrq_el0
	  value on all cores by a factor set in the environment,
	  'cntfrq_multiplier'.  Since sleeps/delays will increase by
	  this factor, system ticks will be delayed by that factor as
	  well.  This should allow performance code to get more cycles
	  per tick.
	*/

	{
		char *temp;
		unsigned long frequency;

		temp = getenv("cntfrq_multiplier");

		if (NULL != temp) {
			frequency = simple_strtoul(temp, NULL, 0);
			printf("CNTRFQ_EL0 will be multipled by %lu.\n",
			       frequency);
			frequency = COUNTER_FREQUENCY * frequency;
			asm volatile ("msr cntfrq_el0, %0" : : "r" (frequency));
		}
	}
#endif

#ifdef COPY_MONITOR_TO_RAM
	memcpy((void *)0x7ffc1000, (void *)0x8031001000, 0x10000);
	jump_to_monitor((void *)0x7ffc1000);
	/*asm volatile ("ldr x10, =0x7ffc1000\nret x10");*/
#else
	jump_to_monitor((void *)0x8031001000);
	/*asm volatile ("ldr x10, =0x8031001000\nret x10");*/
#endif
}

#endif	/* SYSCACHE_ONLY_MODE */

/*
  ------------------------------------------------------------------------------
  display_l3_lock
*/

#ifdef CONFIG_AXXIA_ANY_XLF
static void
display_l3_lock(void)
{
	unsigned long long base[4][8];
	unsigned int num_ways[8];
	int i;
	int j;

	/* Get the bases... */
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 8; ++j)
			base[i][j] = readq(DICKENS +
					   (i * 8) + ((j + 0x20) * 0x10000) +
					   0x48);

	/* Get the ways... */
	for (i = 0 ; i < 8; ++i)
		num_ways[i] = readl(DICKENS + ((i + 0x20) * 0x10000) + 0x40);

#ifdef CONFIG_AXXIA_ANY_EMU
	printf("L3 Cache Line Locking -- Total Size is %d MB\n",
	       num_ways[0]);
#else  /* CONFIG_AXXIA_ANY_EMU */
	printf("L3 Cache Line Locking -- Total Size is %d MB\n",
	       num_ways[0] * 2);
#endif	/* CONFIG_AXXIA_ANY_EMU */

	for (i = 0; i < 4; ++i) {
		printf("\tBase %d : 0x%llx ", i, (base[i][0] & 0xfffffffffff));

		if (0ULL != ((1ULL << 63) & base[i][0]))
			puts("(valid)\n");
		else
			puts("(invalid)\n");
	}

	return;
}
#endif	/* CONFIG_AXXIA_ANY_XLF */

/*
  ------------------------------------------------------------------------------
  board_init_f

  Replaces the weakly defined board_init_f in arch/arm/lib/spl.c.
*/

void
board_init_f(ulong dummy)
{
	int rc;
	unsigned int value;
	unsigned int pvalue;
#if defined(CONFIG_AXXIA_ANY_56XX)
	unsigned int lor;
#endif
	int i;

	/*
	  Work-Around for Hardware Debug

	  Reverse the polarity of coresight_ap_deviceen (bit 19)..

	  Without this update, JTAG debugging won't work.
	*/

#ifdef CONFIG_AXXIA_ANY_XLF

	if (1 == is_xlf_a0()) {
		writel(0xab, (SYSCON + 0x2000));
		writel(0x4700000, (SYSCON + 0x2008));
		writel(0, (SYSCON + 0x2000));
	}

#endif	/* CONFIG_AXXIA_ANY_XLF */

	/* Set the CNTFRQ register. */
	asm volatile("msr cntfrq_el0, %0"
		     : : "r" (COUNTER_FREQUENCY) : "memory");

 	/* Clear bss. */
	memset(__bss_start, 0, __bss_end - __bss_start);

	/* Set global data pointer. */
	gd = &gdata;

#ifdef CONFIG_SYS_SPL_MALLOC_START
        mem_malloc_init((void *)CONFIG_SYS_SPL_MALLOC_START,
                        CONFIG_SYS_SPL_MALLOC_SIZE);
#endif

	/* read and clear reset status (write one to clear) */
	value = readl(SYSCON + 0x100);
	syscon_0x100 = value;
	writel(value, (SYSCON + 0x100));

	/*
	 * if this is a power-up/pin reset then initialize
	 * persistent registers 
	 */

	if ((value & 0x00000001))
		for (i = 0; i < 9; i++)
			writel(0, (SYSCON + (0xdc + (4 * i))));

        /*
	 * For robustness, reboot chip in quiet post power-up
         * electrical environment.
         */

#if defined(CONFIG_AXXIA_ANY_56XX)
        lor = readl(SYSCON + 0x2004);

        if ((value & 0x00000001) && (0 == (lor & 0x80))) {
		unsigned int temp;

		/*
		  Clear out the SSP fifo so the bootrom doesn't read
		  junk after the reset in simulation.  On the
		  hardware, the SSP gets reset during a chip reset,
		  but not in simulation.
		*/

		temp = readl(SSP + 0x4);
		temp |= (1 << 1);
		writel(temp, (SSP + 0x4));

		while (readl(SSP + 0xc) != 0x3)
			(void)readl(SSP + 0x8);

		/* Write the key. */
		writel(0xab, (SYSCON + 0x2000));
		/* Clear the pin reset bit. */
		writel(0x1, (SYSCON + 0x100));
		/* Cause a chip reset.  Hardware delays this for 1024 cycles */
		writel(0x2, (SYSCON + 0x2008));
		/* Enable all cores. */
		writel(0x0, (SYSCON + 0x2010));
		/* Clear the key. */
		writel(0, (SYSCON + 0x2000));
		/* Let the reset happen. */
		wfi();
        }
#endif

	/*
	  Set bit 2 of 0xdc if the last reset was caused by a watchdog
	  timeout; otherwise, clear it.  Also clear bit 0 if it was
	  set (used to indicate a planned ddr retention reset).
	 */

	pvalue = readl(SYSCON + 0xdc);
	syscon_0x0dc = pvalue;

	if (0 != (value & 0x66))
		pvalue |= 0x4;
	else
		pvalue &= ~0x4;

#ifdef CONFIG_MEMORY_RETENTION
	pvalue &= ~(1 << 0);
#endif

	writel(pvalue, (SYSCON + 0xdc));
	gd->baudrate = CONFIG_BAUDRATE;
	serial_initialize();
	serial_init();
	gd->have_console = 1;

	puts("\n"
	     "_______              _____            _____________________  \n"
	     "___    |___  _____  ____(_)_____ _    __  ___/__  __ \\__  / \n"
	     "__  /| |_  |/_/_  |/_/_  /_  __ `/    _____ \\__  /_/ /_  /  \n"
	     "_  ___ |_>  < __>  < _  / / /_/ /     ____/ /_  ____/_  /___ \n"
	     "/_/  |_/_/|_| /_/|_| /_/  \\__,_/      /____/ /_/     /_____/\n"
	     "\n");

#ifdef AXXIA_VERSION
	printf("Axxia Version: %s\n", AXXIA_VERSION);
#else
	printf("Axxia Version: UNKNOWN\n");
#endif

#ifdef AXXIA_ATF_VERSION
	printf("Axxia ATF Version: %s\n", AXXIA_ATF_VERSION);
#else
	printf("Axxia ATF Version: UNKNOWN\n");
#endif

#ifdef CONFIG_AXXIA_ANY_XLF

	printf("XLF CHIP VERSION: (pfuse=0x%x) ", pfuse);

	if (0 == pfuse) {
		unsigned int value;

		puts("(via NCA revision) ");

		/* Handle Un-Fused Parts */
		ncr_read32(NCP_REGION_ID(0x16, 0xff), 0, &value);

		if (1 == ((value >> 8) & 0x7))
			puts("B0\n");
		else
			puts("A0\n");
	} else if (0 != ((pfuse & 0x700) >> 8)) {
		puts("B0\n");
	} else {
		puts("A0\n");
	}

#endif	/* CONFIG_AXXIA_ANY_XLF */

#ifdef SYSCACHE_ONLY_MODE
	printf("Running in System Cache\n");
#endif

#ifdef LEAVE_DICKENS_NONSECURE
	printf("Making Dickens Registers Accessible from Non-Secure Masters\n");
	value = readl(DICKENS + 0);
	value |= 1;
	writel(value, (DICKENS + 0));
#endif

#ifdef CONFIG_HW_WATCHDOG
	rc = start_watchdog(WATCHDOG_TIMEOUT_SECS);

	if (0 == rc)
		puts("Started Watchdog Timer\n");
	else
		puts("Failed to start watchdog timer!\n");
#endif	/* CONFIG_HW_WATCHDOG */

#if defined(CONFIG_AXXIA_XLF) || defined(CONFIG_AXXIA_XLF_EMU)
	/* Set the default TTYPE for NCAP (v3 only, XLF). */
#if defined(CONFIG_AXXIA_EMU)
	writel(0x22002ba1, 0x800404024c);
	writel(0x120a122f, 0x800404028c);
#else
	{
		int cluster ;
		u64 a53_ncap_base = 0x8004040000ULL; /* 0x168.1.0 */

		for (cluster = 0;
			cluster < 8;
			cluster++, a53_ncap_base += 0x00040000) {

				writel(0x22002ba1, a53_ncap_base + 0x24c);
				writel(0x120a122f, a53_ncap_base + 0x28c);
		}
	}

#endif
#endif

	/*
	  The USB phys read the values stored in the following
	  registers when enabled.  Some of the default values need to
	  be changed.

	  After wrting the new values, use SYSCON to reset the USB phys.
	*/

#ifdef CONFIG_AXXIA_USB0

	/* Modify some Default Values */
	writel(COMPDISTUNE0_VALUE, AXXIA_USB0_BASE + COMPDISTUNE0);
	writel(OTGTUNE0_VALUE, AXXIA_USB0_BASE + OTGTUNE0);
	writel(SQRXTUNE0_VALUE, AXXIA_USB0_BASE + SQRXTUNE0);
	writel(TXFSLSTUNE0_VALUE, AXXIA_USB0_BASE + TXFSLSTUNE0);
	writel(TXHSXVTUNE0_VALUE, AXXIA_USB0_BASE + TXHSXVTUNE0);
	writel(TXPREEMPAMPTUNE0_VALUE, AXXIA_USB0_BASE + TXPREEMPAMPTUNE0);
	writel(TXPREEMPPULSETUNE0_VALUE, AXXIA_USB0_BASE + TXPREEMPPULSETUNE0);
	writel(TXRESTUNE0_VALUE, AXXIA_USB0_BASE + TXRESTUNE0);
	writel(TXRISETUNE0_VALUE, AXXIA_USB0_BASE + TXRISETUNE0);
	writel(TXVREFTUNE0_VALUE, AXXIA_USB0_BASE + TXVREFTUNE0);
	writel(PCSRXLOSMASK_VALUE, AXXIA_USB0_BASE + PCSRXLOSMASK);
	writel(PCSTXDEEMPH3P4DB_VALUE, AXXIA_USB0_BASE + PCSTXDEEMPH3P4DB);
	writel(PCSTXDEEMPH6DB_VALUE, AXXIA_USB0_BASE + PCSTXDEEMPH6DB);
	writel(PCSTXSWINGFULL_VALUE, AXXIA_USB0_BASE + PCSTXSWINGFULL);
	writel(TXVBOOSTLVL_VALUE, AXXIA_USB0_BASE + TXVBOOSTLVL);

	/* Switch the USB interrupt from edge to level. */
	value = readl(0x9000200004);
	value &= ~2;
	writel(value, 0x9000200004);

	/* Assert Controller Reset */
	value = readl(AXXIA_USB0_CONFIG + 0xc110);
	value |= (1 << 11);
	writel(value, (AXXIA_USB0_CONFIG + 0xc110));

	/* Reset the USB PHY. */
	writel(0xab, (SYSCON + 0x2000));
#if defined(CONFIG_AXXIA_ANY_56XX)
	value = readl(SYSCON + 0x2044);
	value |= (1 << 17);
	writel(value, (SYSCON + 0x2044));
	udelay(1);
	value &= ~(1 << 17);
	writel(value, (SYSCON + 0x2044));
#elif defined(CONFIG_AXXIA_ANY_XLF)
	value = readl(SYSCON + 0x20a0);
	value |= (1 << 29);
	writel(value, (SYSCON + 0x20a0));
	udelay(1);
	value &= ~(1 << 29);
	writel(value, (SYSCON + 0x20a0));
#endif
	writel(0, (SYSCON + 0x2000));

	/* Wait for RTUNE Ack */
	do {
		udelay(10);
		value = readl(AXXIA_USB0_BASE + 0x6c);
	} while (0 != (value & (1 << 2)));

	if (0 == USB_WA_LEVEL()) {
		/* USB_WA_PHY_STAR_9001023074 */
		writel(0x8, AXXIA_USB0_BASE + 0xc);
		value = readl(AXXIA_USB0_BASE + 0x10) & 0x3ff;

		if (60 < value)
			writel(42, AXXIA_USB0_BASE + 0x10);

		writel(0x54c, AXXIA_USB0_BASE + 0xc);
	}

	/* USB_WA_PHY_STAR_9000944754 */
	writel(SSP_LANE0_ANA_RX_SCOPE_VDCC_VALUE,
	       AXXIA_USB0_BASE + SSP_LANE0_ANA_RX_SCOPE_VDCC);

	value = readl(AXXIA_USB0_CONFIG + 0xc2c0);
	value &= ~(1 << 18);

	if (0 == USB_WA_LEVEL()) {
		/* USB_WA_PHY_STAR_9000952264_ALT */
		writel(0x6, AXXIA_USB0_BASE + 0x40bc);
		writel(0x80, AXXIA_USB0_BASE + 0xd4);
		value &= ~(1 << 28);
	} else {
		/* USB_WA_PHY_STAR_9000952264 */
		value |= (1 << 28);
	}

	writel(value, (AXXIA_USB0_CONFIG + 0xc2c0));

	/* De-assert the Controller Reset */
	value = readl(AXXIA_USB0_CONFIG + 0xc110);
	value &= ~(1 << 11);
	writel(value, (AXXIA_USB0_CONFIG + 0xc110));

#endif	/* CONFIG_AXXIA_USB0 */

#ifdef CONFIG_AXXIA_USB1

	/* Modify some Default Values */
	writel(COMPDISTUNE0_VALUE, AXXIA_USB1_BASE + COMPDISTUNE0);
	writel(OTGTUNE0_VALUE, AXXIA_USB1_BASE + OTGTUNE0);
	writel(SQRXTUNE0_VALUE, AXXIA_USB1_BASE + SQRXTUNE0);
	writel(TXFSLSTUNE0_VALUE, AXXIA_USB1_BASE + TXFSLSTUNE0);
	writel(TXHSXVTUNE0_VALUE, AXXIA_USB1_BASE + TXHSXVTUNE0);
	writel(TXPREEMPAMPTUNE0_VALUE, AXXIA_USB1_BASE + TXPREEMPAMPTUNE0);
	writel(TXPREEMPPULSETUNE0_VALUE, AXXIA_USB1_BASE + TXPREEMPPULSETUNE0);
	writel(TXRESTUNE0_VALUE, AXXIA_USB1_BASE + TXRESTUNE0);
	writel(TXRISETUNE0_VALUE, AXXIA_USB1_BASE + TXRISETUNE0);
	writel(TXVREFTUNE0_VALUE, AXXIA_USB1_BASE + TXVREFTUNE0);
	writel(PCSRXLOSMASK_VALUE, AXXIA_USB1_BASE + PCSRXLOSMASK);
	writel(PCSTXDEEMPH3P4DB_VALUE, AXXIA_USB1_BASE + PCSTXDEEMPH3P4DB);
	writel(PCSTXDEEMPH6DB_VALUE, AXXIA_USB1_BASE + PCSTXDEEMPH6DB);
	writel(PCSTXSWINGFULL_VALUE, AXXIA_USB1_BASE + PCSTXSWINGFULL);
	writel(TXVBOOSTLVL_VALUE, AXXIA_USB1_BASE + TXVBOOSTLVL);

	/* Switch the USB interrupt from edge to level. */
	value = readl(0x9800200004);
	value &= ~2;
	writel(value, 0x9800200004);

	/* Assert Controller Reset */
	value = readl(AXXIA_USB1_CONFIG + 0xc110);
	value |= (1 << 11);
	writel(value, (AXXIA_USB1_CONFIG + 0xc110));

	/* Reset the USB PHY. */
	writel(0xab, (SYSCON + 0x2000));
	value = readl(SYSCON + 0x20a0);
	value |= (1 << 31);
	writel(value, (SYSCON + 0x20a0));
	udelay(1);
	value &= ~(1 << 31);
	writel(value, (SYSCON + 0x20a0));
	writel(0, (SYSCON + 0x2000));

	/* Wait for RTUNE Ack */
	do {
		udelay(10);
		value = readl(AXXIA_USB1_BASE + 0x6c);
	} while (0 != (value & (1 << 2)));

	/* This is USB_WA_PHY_STAR_9000944754 */
	writel(SSP_LANE0_ANA_RX_SCOPE_VDCC_VALUE,
	       AXXIA_USB1_BASE + SSP_LANE0_ANA_RX_SCOPE_VDCC);

	value = readl(AXXIA_USB1_CONFIG + 0xc2c0);
	value &= ~(1 << 18);
	/* USB_WA_PHY_STAR_9000952264 */
	value |= (1 << 28);
	writel(value, (AXXIA_USB1_CONFIG + 0xc2c0));

	/* De-assert the Controller Reset */
	value = readl(AXXIA_USB1_CONFIG + 0xc110);
	value &= ~(1 << 11);
	writel(value, (AXXIA_USB1_CONFIG + 0xc110));

#endif	/* CONFIG_AXXIA_USB1 */

	rc = axxia_initialize();
	if (0 != rc)
		acp_failure(__FILE__, __func__, __LINE__);

#ifdef CONFIG_AXXIA_ANY_XLF
	display_l3_lock();
#endif	/* CONFIG_AXXIA_ANY_XLF */

#ifdef CONFIG_HW_WATCHDOG
	/*
	  Now that the PLLs/Clocks may be different, re-calculate the
	  number of cycles for a watchdog timeout.
	*/

	set_watchdog_timeout(WATCHDOG_TIMEOUT_SECS);
#endif	/* CONFIG_HW_WATCHDOG */

#if defined(CONFIG_AXXIA_SPL_DIAGNOSTICS)
	printf("Press Any Key to Enter SPL Diagnostic Mode...\n");
	{
		int delay = 30;

		while (0 < delay--) {
			if (tstc()) {
				getc(); /* discard character */
				spl_diagnostics();
				break;
			}

			mdelay(100);
		}
	}
#endif	/* CONFIG_AXXIA_SPL_DIAGNOSTICS */

#if !defined(CONFIG_AXXIA_EMU)
	puts("");
	axxia_display_clocks();
#endif

	/*
	  The NEMAC DMA engine does not, in all cases, keep unaligned
	  packets in order.  To keep this from happening, set the
	  rd_iss bit to 1 in the nemdma_asib_fn_mode register.
	  Setting this bits forces reads to be done sequentially.
	 */
	value = readl(PERIPH_SCB + 0x44108);
	value |= 1;
	writel(value, (PERIPH_SCB + 0x44108));

#ifdef SYSCACHE_ONLY_MODE
	if (0 != setup_security())
		acp_failure(__FILE__, __func__, __LINE__);
	load_image();
	printf("U-Boot Loaded in System Cache, Jumping to Monitor\n");
	jump_to_monitor((void *)0x8031001000);
#endif	/* SYSCACHE_ONLY_MODE */

	if (0 != (global->flags & PARAMETERS_GLOBAL_RUN_SMEM_BIST)) {
		printf("Testing Memory From 0, 0x%llx bytes\n",
		       sysmem_size());
		axxia_sysmem_bist(0ULL, sysmem_size(), data);
	} else if (0 != (global->flags & PARAMETERS_GLOBAL_RUN_SMEM_RANGES)) {
		check_memory_ranges();
	}

	if (0 != (global->flags & PARAMETERS_GLOBAL_RUN_CMEM_BIST)) {
		printf("Testing Classifier Memory From 0, 0x%llx bytes\n",
		       cmem_size());
		axxia_cmem_bist(0ULL, cmem_size(), data);
	}

	printf("System Initialized\n\n");

	/* Move the stack to ram. */
	asm volatile ("mov sp, %0" : : "r" (CONFIG_SYS_INIT_SP_ADDR));

	if (0 != setup_security())
		acp_failure(__FILE__, __func__, __LINE__);

#ifdef CONFIG_SPL_ENV_SUPPORT
	mem_malloc_init((void *)CONFIG_SYS_MALLOC_BASE, CONFIG_SYS_MALLOC_SIZE);
	env_init();
	env_relocate();
#endif	/* CONFIG_SPL_ENV_SUPPORT */

	/*
	 * The counter frequency in simulation can vary, and may need
	 * to be adjusted for performance.  The following will set
	 * CNTFRQ_EL0 to the value specified by the environment
	 * variable "cntfrq_override".
	 */

	{
		char *cntfrq_ovr_str;
		unsigned int cntfrq_ovr;

		cntfrq_ovr_str = getenv("cntfrq_override");

		if (NULL != cntfrq_ovr_str) {
			cntfrq_ovr = simple_strtoul(cntfrq_ovr_str, NULL, 0);
			printf("Resetting the CNTFRQ Register to %u.\n",
				cntfrq_ovr);
			asm volatile("msr cntfrq_el0, %0"
				     : : "r" (cntfrq_ovr) : "memory");
		}
	}

	/*
	  Load U-Boot in memory and jump to the monitor.
	*/

	load_image();

	jtag_jump_to_monitor();

	return;
}

/*
  ------------------------------------------------------------------------------
  spl_board_init
*/

void
spl_board_init(void)
{
	return;
}
