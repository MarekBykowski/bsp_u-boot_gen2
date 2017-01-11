#include <config.h>
#include <common.h>
#include <asm/io.h>

static int number_of_clusters;
static int bit_by_cluster[12];	/* Last 4 are DSP on XLF */

extern int is_xlf_a0(void);

static int
initialize_cluster_info(void)
{
	number_of_clusters = 12;

	if (is_xlf_a0()) {
			bit_by_cluster[0]  = 11;
			bit_by_cluster[1]  = 12;
			bit_by_cluster[2]  = 17;
			bit_by_cluster[3]  = 18;
			bit_by_cluster[4]  = 29;
			bit_by_cluster[5]  = 30;
			bit_by_cluster[6]  = 35;
			bit_by_cluster[7]  =  0;
			bit_by_cluster[8]  = 14;
			bit_by_cluster[9]  = 15;
			bit_by_cluster[10] = 32;
			bit_by_cluster[11] = 33;
	} else {
			bit_by_cluster[0]  = 32;
			bit_by_cluster[1]  = 29;
			bit_by_cluster[2]  = 18;
			bit_by_cluster[3]  = 14;
			bit_by_cluster[4]  = 12;
			bit_by_cluster[5]  = 11;
			bit_by_cluster[6]  =  0;
			bit_by_cluster[7]  = 35;
			bit_by_cluster[8]  = 33;
			bit_by_cluster[9]  = 30;
			bit_by_cluster[10] = 17;
			bit_by_cluster[11] = 15;
	}

	return 0;
}

static unsigned long
get_bit_by_cluster(unsigned long cluster)
{
	return bit_by_cluster[cluster];
}


int
set_cluster_coherency(unsigned cluster, unsigned state)
{
	unsigned int sdcr_offsets[] = {
		0x00,		/* This is the DVM */
		0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27
	};
	int i;
	int retries;
	unsigned int mask;
	int upper_half = 0;
	unsigned int value;
	unsigned long shelley_base;

	printf("%s cluster %u %s the coherency domain.\n",
		state == 1 ? "Adding" : "Removing",
		cluster,
		state == 1 ? "to" : "from");

	shelley_base = DICKENS;

	initialize_cluster_info();

	if (cluster >= number_of_clusters)
		return -1;

	if (31 < get_bit_by_cluster(cluster)) {
		mask = (1 << (get_bit_by_cluster(cluster) - 32));
		upper_half = 1;
	} else {
		mask = (1 << get_bit_by_cluster(cluster));
	}

	for (i = 0; i < (sizeof(sdcr_offsets) / sizeof(unsigned int)); ++i) {
		unsigned long offset;

		offset = (shelley_base | (sdcr_offsets[i] << 16));

		if (0 != upper_half)
			offset += 4;

		if (0 == state)
			writel((unsigned int)mask, offset + 0x220);
		else
			writel((unsigned int)mask, offset + 0x210);

		retries = 1000;

		do {
			--retries;
			value = readl(offset + 0x200);

			if (0 == state) {
				if (0 == (mask & value))
					break;
			} else {
				if (mask == (mask & value))
					break;
			}
		} while (0 < retries);

		if (0 == retries)
			return -1;
	}

	return 0;
}
