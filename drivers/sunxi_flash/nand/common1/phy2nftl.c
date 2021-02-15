/*SPDX-Licensen-Identifier: GPL-2.0*/

#include "phy2nftl.h"
/*#include <linux/mtd/aw-spinand-nftl.h>*/
/*#include "phy-nand/rawnand/rawnand_ids.h"*/

extern __u32 get_storage_type(void);

void nftl_get_spinand_phyinfo(nand_phyinfo_for_nftl_t *info)
{
	/*
	 *info->die_cnt_per_chip = spinand_nftl_get_die_cnt();
	 *info->blk_cnt_per_die = spinand_nftl_get_die_size(BLOCK);
	 *info->page_cnt_per_blk = (__u16)spinand_nftl_get_single_block_size(PAGE);
	 *info->sector_cnt_per_page = (__u8)spinand_nftl_get_single_page_size(SECTOR);
	 *spinand_nftl_get_chip_id(info->nand_chip_id);
	 */

	return;
}

void nftl_get_rawnand_phyinfo(nand_phyinfo_for_nftl_t *info)
{
	/*
	 *info->die_cnt_per_chip = spinand_nftl_get_die_cnt();
	 *info->blk_cnt_per_die = spinand_nftl_get_die_size(BLOCK);
	 *info->page_cnt_per_blk = (__u16)spinand_nftl_get_single_block_size(PAGE);
	 *info->sector_cnt_per_page = (__u8)spinand_nftl_get_single_page_size(SECTOR);
	 *spinand_nftl_get_chip_id(info->nand_chip_id);
	 */
}
void nftl_get_nand_phyinfo(nand_phyinfo_for_nftl_t *info)
{
	if (get_storage_type() == 1)
		;
	else if (get_storage_type() == 2)
		nftl_get_spinand_phyinfo(info);
}
