/*
 * Copyright (C) 2019 Allwinner.
 * weidonghui <weidonghui@allwinnertech.com>
 *
 * SUNXI AXP  Driver
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#include <common.h>
#include <sunxi_power/axp.h>
#include <asm/arch/pmic_bus.h>

__attribute__((section(".data"))) static struct sunxi_pmu_dev_t *sunxi_pmu_dev =
	NULL;

/* traverse the u-boot segment to find the pmu offset*/
static struct sunxi_pmu_dev_t *pmu_get_axp_dev_t(void)
{
	struct sunxi_pmu_dev_t *sunxi_pmu_dev_temp;
	struct sunxi_pmu_dev_t *sunxi_pmu_dev_start =
		ll_entry_start(struct sunxi_pmu_dev_t, pmu);
	int max = ll_entry_count(struct sunxi_pmu_dev_t, pmu);
	for (sunxi_pmu_dev_temp = sunxi_pmu_dev_start;
	     sunxi_pmu_dev_temp != sunxi_pmu_dev_start + max;
	     sunxi_pmu_dev_temp++) {
		if (!strncmp("pmu", sunxi_pmu_dev_temp->pmu_name, 3)) {
			if (!sunxi_pmu_dev_temp->probe()) {
				printf("PMU: %s found\n",
				       sunxi_pmu_dev_temp->pmu_name);
				return sunxi_pmu_dev_temp;
			}
		}
	}
	printf("PMU: no found\n");
	return NULL;
}

/* matches chipid*/
int pmu_probe(void)
{
	sunxi_pmu_dev = pmu_get_axp_dev_t();
	if (sunxi_pmu_dev == NULL)
		return -1;
	return 0;
}

/*Set a certain power, voltage value. */
int pmu_set_voltage(char *name, uint vol_value, uint onoff)
{
	return sunxi_pmu_dev->set_voltage(name, vol_value, onoff);
}

/*Read a certain power, voltage value */
int pmu_get_voltage(char *name)
{
	return sunxi_pmu_dev->get_voltage(name);
}

/*Set shutdown*/
int pmu_set_power_off(void)
{
	return sunxi_pmu_dev->set_power_off();
}

/*Sets the state of the next mode */
int pmu_set_sys_mode(int status)
{
	return sunxi_pmu_dev->set_sys_mode(status);
}

/*Get the current mode*/
int pmu_get_sys_mode(void)
{
	return sunxi_pmu_dev->get_sys_mode();
}

/*Get the button length interrupt*/
int pmu_get_key_irq(void)
{
	return sunxi_pmu_dev->get_key_irq();
}

/*Set limit total voltage*/
int pmu_set_bus_vol_limit(int vol_value)
{
	return sunxi_pmu_dev->set_bus_vol_limit(vol_value);
}

/*get register value*/
unsigned char pmu_get_reg_value(unsigned char reg_addr)
{
	return sunxi_pmu_dev->get_reg_value(reg_addr);
}

/*set register value*/
unsigned char pmu_set_reg_value(unsigned char reg_addr, unsigned char reg_value)
{
	return sunxi_pmu_dev->set_reg_value(reg_addr, reg_value);
}

