/*
 * (C) Copyright 2018 allwinnertech  <wangwei@allwinnertech.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _SUNXI_CPU_NCAT_V2_H
#define _SUNXI_CPU_NCAT_V2_H

#define SUNXI_SS_BASE			0x03040000

#define SUNXI_PIO_BASE			0x02000000
#define SUNXI_CCM_BASE			0x02001000
#define SUNXI_DMA_BASE			0x03002000

/* SID address space starts at 0x03006000, but e-fuse is at offset 0x200 */
#define SUNXI_SID_BASE			0x03006000
#define SUNXI_SID_SRAM_BASE		0x03006200
#define SUNXI_TIMER_BASE		0x02050000

#define SUNXI_PLIC_BASE			0x10000000
#define SUNXI_IOMMU_BASE		0x02010000

#define SUNXI_DRAM_COM_BASE		0x04002000
#define SUNXI_DRAM_CTL0_BASE		0x04003000
#define SUNXI_DRAM_PHY0_BASE		0x04005000
#define SUNXI_MMC0_BASE			0x04020000
#define SUNXI_MMC1_BASE			0x04021000
#define SUNXI_MMC2_BASE			0x04022000

#define SUNXI_UART0_BASE		0x02500000
#define SUNXI_UART1_BASE		0x02500400
#define SUNXI_UART2_BASE		0x02500800
#define SUNXI_UART3_BASE		0x02500C00

#define SUNXI_TWI0_BASE			0x02502000
#define SUNXI_TWI1_BASE			0x02502400
#define SUNXI_RSB_BASE			0x02032000

#define SUNXI_SPI0_BASE			0x04025000
#define SUNXI_SPI1_BASE			0x04026000
#define SUNXI_GMAC_BASE			0x04500000
#define SUNXI_USB0_BASE			0x04100000
#define SUNXI_USB1_BASE			0x04200000

/*USB DRD AS ehci0*/
#define SUNXI_EHCI0_BASE		0x05101000
#define SUNXI_EHCI1_BASE		0x05200000

#define SUNXI_HDMI_BASE			0x05500000
#define SUNXI_TCON_TOP_BASE		0x05600000
#define SUNXI_TCON_LCD0_BASE	0x05461000
#define SUNXI_TCON_TV0_BASE		0x05470000

#define SUNXI_RTC_BASE			0x07090000
#define SUNXI_R_CPUCFG_BASE		0x07000400
#define SUNXI_PRCM_BASE			0x07010000
#define SUNXI_R_IR_RX_BASE		0x07040000
#define SUNXI_R_PIO_BASE		0x07022000
#define SUNXI_R_UART_BASE		0x07080000
#define SUNXI_R_TWI_BASE		0x07020800
#define SUNXI_RTWI_BRG_REG		(SUNXI_PRCM_BASE+0x019c)

#define SUNXI_CPUXCFG_BASE		0x08100000

#define SUNXI_USBOTG_BASE		SUNXI_USB0_BASE
#define SUNXI_RTC_DATA_BASE     (SUNXI_RTC_BASE+0x100)

/*physical key*/
#define SUNXI_GPADC_BASE                  (0x02009000L)
#define SUNXI_LRADC_BASE                  (0x02009800L)
#define SUNXI_KEYADC_BASE                 SUNXI_LRADC_BASE

#ifndef __ASSEMBLY__
void sunxi_board_init(void);
void sunxi_reset(void);
int sunxi_get_sid(unsigned int *sid);
#endif

#endif /* _SUNXI_CPU_SCAT_V2H */
