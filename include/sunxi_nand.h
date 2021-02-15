/*
 * (C) Copyright 2007-2013
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Jerry Wang <wangflord@allwinnertech.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#ifndef  _SUNXI_NAND_H
#define  _SUNXI_NAND_H

#include <stdbool.h>

enum size_type {
	BYTE,
	SECTOR,
	PAGE,
	BLOCK
};

/* the interface for nand with nftl */
extern int nand_get_mbr(char* buffer, unsigned int len);
extern int nand_uboot_init(int boot_mode);
extern int nand_uboot_exit(int force);
extern int nand_uboot_probe(void);
extern unsigned int nand_uboot_read(unsigned int start, unsigned int sectors,
		void *buffer);
extern unsigned int nand_uboot_write(unsigned int start, unsigned int sectors,
		void *buffer);
extern int ubi_nand_get_flash_info(void *info, unsigned int len);
extern int nand_download_boot0(unsigned int length, void *buffer);
extern int nand_download_uboot(unsigned int length, void *buffer);
extern int nand_force_download_uboot(unsigned int length ,void *buffer);
extern int nand_write_boot0(void *buffer,unsigned int length);
extern int nand_read_boot0(void *buffer,unsigned int length);
extern int nand_uboot_erase(int user_erase);
extern unsigned int nand_uboot_get_flash_info(void *buffer, unsigned int length);
extern unsigned int nand_uboot_set_flash_info(void *buffer, unsigned int length);
extern unsigned int nand_uboot_get_flash_size(void);
extern int nand_uboot_flush(void);
extern int NAND_Uboot_Force_Erase(void);
extern int nand_secure_storage_read(int item, unsigned char *buf,
		unsigned int len);
extern int nand_secure_storage_write(int item, unsigned char *buf,
		unsigned int len);


/* the interface for nand with ubi */
extern bool nand_use_ubi(void);
extern int ubi_nand_flush(void);
extern int ubi_nand_probe_uboot(void);
extern int ubi_nand_attach_mtd(void);
extern int ubi_nand_exit_uboot(int force);
extern int ubi_nand_init_uboot(int boot_mode);
extern unsigned int ubi_nand_size(void);
extern int ubi_nand_erase(int force);
extern int ubi_nand_force_erase(void);
extern int ubi_nand_read(unsigned int start, unsigned int sectors, void *buffer);
extern int ubi_nand_write(unsigned int start, unsigned int sectors, void *buf);
extern int ubi_nand_download_uboot(unsigned int len, void *buf);
extern int ubi_nand_download_boot0(unsigned int len, void *buf);
extern int ubi_nand_write_end(void);
extern int ubi_nand_update_ubi_env(void);
extern int ubi_nand_secure_storage_read(int item, void *buf, unsigned int len);
extern int ubi_nand_secure_storage_write(int item, void *buf, unsigned int len);

#endif

