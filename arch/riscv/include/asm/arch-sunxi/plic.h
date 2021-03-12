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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.         See the
 * GNU General Public License for more details.
 *
 */

#ifndef __SUNXI_INTC_H__
#define __SUNXI_INTC_H__

#include <linux/types.h>
#include <asm/csr.h>
#include <cpu.h>


#if defined(CONFIG_MACH_SUN20IW1)
#define AW_IRQ_USB_OTG                 (45)
#define AW_IRQ_USB_EHCI0               (46)
#define AW_IRQ_USB_OHCI0               (47)
#define AW_IRQ_DMA                     (66)
#define AW_IRQ_TIMER0                  (75)
#define AW_IRQ_TIMER1                  (76)
#define AW_IRQ_NMI                     (152)
#define AW_IRQ_CIR                     (35)
#define PLIC_IRQ_NUM                   (157)

#else
#error "Interrupt definition not available for this architecture"
#endif


/* PLIC registers */
#define PLIC_PRIO_REG(_n)		(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x0000 + (_n) * 4)
#define PLIC_IP_REG(_n)			(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x1000 + (_n) * 4)
#define PLIC_MIE_REG(_n)		(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x2000 + (_n) * 4)
#define PLIC_SIE_REG(_n)		(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x2080 + (_n) * 4)
#define PLIC_CTRL_REG			(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x1FFFFC)
#define PLIC_MTH_REG			(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x200000)
#define PLIC_MCLAIM_REG			(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x200004)
#define PLIC_STH_REG			(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x201000)
#define PLIC_SCLAIM_REG			(IOMEM_ADDR(SUNXI_PLIC_BASE) + 0x201004)


int  irq_enable(int irq_no);
int  irq_disable(int irq_no);
void irq_install_handler (int irq, interrupt_handler_t handle_irq, void *data);
void irq_free_handler(int irq);

#endif
