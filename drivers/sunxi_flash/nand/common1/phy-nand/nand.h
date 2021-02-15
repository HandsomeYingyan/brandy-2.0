/*
 * rawnand.h
 *
 * Copyright (C) 2019 Allwinner.
 *
 * cuizhikui <cuizhikui@allwinnertech.com>
 *
 * SPDX-License-Identifier: GPL-2.0
 */
#ifndef __NAND_H__
#define __NAND_H__

#define NAND_VERSION_0 0x03
#define NAND_VERSION_1 0x01

#define SUPPORT_SUPER_STANDBY


struct nand_chip_info;
struct _nand_info;

struct nand_chips_ops {
	int (*nand_chips_init)(struct nand_chip_info *chip);
	void (*nand_chips_cleanup)(struct nand_chip_info *chip);
	int (*nand_chips_standby)(struct nand_chip_info *chip);
	int (*nand_chips_resume)(struct nand_chip_info *chip);
};

#endif /*NAND_H*/
