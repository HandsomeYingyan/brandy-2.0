/*
 * Copyright (C) 2019 Allwinner.
 * weidonghui <weidonghui@allwinnertech.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
*/
#include <common.h>
#include <sunxi_power/axp.h>

__attribute__((section(".data"))) static struct sunxi_bmu_dev_t *sunxi_bmu_dev =
	NULL;

/* traverse the u-boot segment to find the bmu offset*/
static struct sunxi_bmu_dev_t *bmu_get_axp_dev_t(void)
{
	struct sunxi_bmu_dev_t *sunxi_bmu_dev_temp;
	struct sunxi_bmu_dev_t *sunxi_bmu_dev_start =
		ll_entry_start(struct sunxi_bmu_dev_t, bmu);
	int max = ll_entry_count(struct sunxi_bmu_dev_t, bmu);
	for (sunxi_bmu_dev_temp = sunxi_bmu_dev_start;
	     sunxi_bmu_dev_temp != sunxi_bmu_dev_start + max;
	     sunxi_bmu_dev_temp++) {
		if (!strncmp("bmu", sunxi_bmu_dev_temp->bmu_name, 3)) {
			if (!sunxi_bmu_dev_temp->probe()) {
				printf("BMU: %s found\n",
				       sunxi_bmu_dev_temp->bmu_name);
				return sunxi_bmu_dev_temp;
			}
		}
	}
	printf("BMU: no found\n");
	return NULL;
}

/* matches chipid*/
int bmu_probe(void)
{
	sunxi_bmu_dev = bmu_get_axp_dev_t();
	if (sunxi_bmu_dev == NULL)
		return -1;
	return 0;
}

/*Set shutdown*/
int bmu_set_power_off(void)
{
	return sunxi_bmu_dev->set_power_off();
}

/* Get the reason for triggering the boot, (button to power on, power on)*/
int bmu_get_poweron_source(void)
{
	return sunxi_bmu_dev->get_poweron_source();
}

/*Get the current axp bus: DCIN&VBUS&BATTERY&NO exist */
int bmu_get_axp_bus_exist(void)
{
	return sunxi_bmu_dev->get_axp_bus_exist();
}

/*Set coulomb counter switch*/
int bmu_set_coulombmeter_onoff(int onoff)
{
	return sunxi_bmu_dev->set_coulombmeter_onoff(onoff);
}

/*Get the average battery voltage*/
int bmu_get_battery_vol(void)
{
	return sunxi_bmu_dev->get_battery_vol();
}

/*Get battery capacity*/
int bmu_get_battery_capacity(void)
{
	return sunxi_bmu_dev->get_battery_capacity();
}

/*Get the battery presence flag*/
int bmu_get_battery_probe(void)
{
	return sunxi_bmu_dev->get_battery_probe();
}

/*limit total current*/
int bmu_set_vbus_current_limit(int current)
{
	return sunxi_bmu_dev->set_vbus_current_limit(current);
}

/*Get current limit current*/
int bmu_get_vbus_current_limit(void)
{
	return sunxi_bmu_dev->get_vbus_current_limit();
}

/*Set the current charge size*/
int bmu_set_charge_current_limit(int current)
{
	return sunxi_bmu_dev->set_charge_current_limit(current);
}

/*get register value*/
unsigned char bmu_get_reg_value(unsigned char reg_addr)
{
	return sunxi_bmu_dev->get_reg_value(reg_addr);
}

/*set register value*/
unsigned char bmu_set_reg_value(unsigned char reg_addr, unsigned char reg_value)
{
	return sunxi_bmu_dev->set_reg_value(reg_addr, reg_value);
}

