/*
 * Copyright (C) 2017 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm/imx-common/sys_proto.h>
#include <linux/types.h>

enum boot_dev_type {
	FLASH_TYPE_SD = 1,
	FLASH_TYPE_MMC = 2,
	FLASH_TYPE_NAND = 3,
	FLASH_TYPE_FLEXSPINOR = 4,
	FLASH_TYPE_WEIM = 5,
	FLASH_TYPE_EEPROM = 6,
	BT_DEV_TYPE_SATA_DISK = 7,

	BT_DEV_TYPE_CAN = 0xC,
	BT_DEV_TYPE_UART = 0xD,
	BT_DEV_TYPE_USB = 0xE,
	BT_DEV_TYPE_MEM_DEV = 0xF
};

struct boot_dev_info_t {
	uint8_t bt_type;
	uint8_t instance;
	uint8_t dev_type;
	uint8_t rsvd2;
};

struct rom_sw_info_t {
	struct boot_dev_info_t boot_dev_info;
	uint32_t core_freq;
	uint32_t axi_freq;
	uint32_t ddr_freq;
	uint32_t rom_tick_freq;
	uint32_t rsvd[3];
};

struct pass_over_info_t {
	uint16_t barker;
	uint16_t len;
	uint32_t g_bt_cfg_shadow;
	uint32_t card_address_mode;
	uint32_t bad_block_count_met;
	uint32_t g_ap_mu;
};

int print_bootinfo(void);
int init_otg_power(void);
void power_off_pd_devices(const char* permanent_on_devices[], int size);
