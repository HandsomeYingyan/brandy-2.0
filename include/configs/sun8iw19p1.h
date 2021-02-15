/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration settings for the Allwinner sun8iw19 CPU
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*#define FPGA_PLATFORM*/
/*
 * sun8iw19 specific configuration
 */

#ifdef CONFIG_USB_EHCI_HCD
#define CONFIG_USB_EHCI_SUNXI
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif

/* sram layout*/
#define SUNXI_SRAM_A1_BASE		(0x00020000L)
#define SUNXI_SRAM_A1_SIZE		(0x18000)

#define SUNXI_SRAM_C_BASE		(0x00038000L)
#define SUNXI_SRAM_C_SIZE		(0x21000)

#define SUNXI_SYS_SRAM_BASE		SUNXI_SRAM_A1_BASE
#define SUNXI_SYS_SRAM_SIZE		(SUNXI_SRAM_A1_SIZE + SUNXI_SRAM_C_SIZE)

#define CONFIG_SUNXI_USB_PHYS	1

#define GICD_BASE		0x3021000
#define GICC_BASE		0x3022000
#define CONFIG_SYS_BOOTM_LEN 0x2000000

/*#define CONFIG_MMC_LOGICAL_OFFSET   (20 * 1024 * 1024/512)*/
/*
 * Include common sunxi configuration where most the settings are
 */
#include <configs/sunxi-common.h>

#endif /* __CONFIG_H */
