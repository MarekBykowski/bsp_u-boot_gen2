#include <common.h>
#include <command.h>

enum axxia_test_type {
	axxia_test_data = 0,
	axxia_test_addr,
	axxia_test_mtest,
	axxia_test_ecc,
	axxia_test_all
};

extern int axxia_sysmem_bist(unsigned long long address, unsigned long long length, enum bist_type type);

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

	for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
		start[offset] = pattern;

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

	for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
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

	for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {

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
int
axxia_test(unsigned long *start, unsigned long *end, int total_iterations,
	  enum axxia_test_type type)
{
	ulong	errs = 0;
	int iterations = 0;
	char *axxia_test_str[] = {
		"Data",
		"Address",
		"standard",
		"ECC",
		"All"
	};

	printf("Running %s Test: 0x%p ... 0x%p:\n",
	       axxia_test_str[type], start, end);

	for (;;) {
		if (iterations >= total_iterations) {
			printf("Tested %d iteration(s) with %lu errors.\n",
			       iterations, errs);

			return errs != 0;
		}

		iterations++;
		printf("Iteration: %d\n", iterations);
		debug("\n");

		if ((type == axxia_test_data) || (type == axxia_test_all))
			errs += mtest_data(start, end);

		if ((type == axxia_test_addr) || (type == axxia_test_all))
			errs += mtest_addr(start, end);

		if ((type == axxia_test_mtest) || (type == axxia_test_all))
			errs += mtest_mtest(start, end);

		if ((type == axxia_test_ecc) || (type == axxia_test_all))
			errs += mtest_ecc(start, end);
	}

	return 0;
}
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
			axxia_test((unsigned long *)offset,
				  (unsigned long *)end,
				  1, axxia_test_data);

		if (global->flags & PARAMETERS_GLOBAL_ENABLE_SW_MEM_ADDR_TEST)
			axxia_test((unsigned long *)offset,
				  (unsigned long *)end,
				  1, axxia_test_addr);

		if (global->flags & PARAMETERS_GLOBAL_ENABLE_SW_MEM_MTEST)
			axxia_test((unsigned long *)offset,
				  (unsigned long *)end,
				  1, axxia_test_mtest);

		if (global->flags & PARAMETERS_GLOBAL_ENABLE_SW_MEM_ECC_TEST)
			axxia_test((unsigned long *)offset,
				  (unsigned long *)end,
				  1, axxia_test_ecc);
	}

	return;
}

static int do_bist(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	printf("Running bists\n");
	/*axxia_sysmem_bist(0ULL, sysmem_size(), data);*/
	check_memory_ranges();
	return 0;
}

U_BOOT_CMD(
	bist,	1,	1,	do_bist,
	"mbist",
	""
);
