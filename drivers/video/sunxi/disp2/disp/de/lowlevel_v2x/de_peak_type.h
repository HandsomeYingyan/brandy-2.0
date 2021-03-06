/*
 * drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_peak_type.h
 *
 * Copyright (c) 2007-2019 Allwinnertech Co., Ltd.
 * Author: zhengxiaobin <zhengxiaobin@allwinnertech.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __DE_PEAK_TYPE_H__
#define __DE_PEAK_TYPE_H__

#include "de_rtmx.h"

#define PEAK_PARA_NUM 3
#define PEAK_MODE_NUM 3

union LP_CTRL_REG {
	unsigned int dwval;
	struct {
		unsigned int en:1;
		unsigned int res0:7;
		unsigned int win_en:1;
		unsigned int res1:23;
	} bits;
};

union LP_SIZE_REG {
	unsigned int dwval;
	struct {
		unsigned int width:12;
		unsigned int res0:4;
		unsigned int height:12;
		unsigned int res1:4;
	} bits;
};

union LP_WIN0_REG {
	unsigned int dwval;
	struct {
		unsigned int win_left:12;
		unsigned int res0:4;
		unsigned int win_top:12;
		unsigned int res1:4;
	} bits;
};

union LP_WIN1_REG {
	unsigned int dwval;
	struct {
		unsigned int win_right:12;
		unsigned int res0:4;
		unsigned int win_bot:12;
		unsigned int res1:4;
	} bits;
};

union LP_FILTER_REG {
	unsigned int dwval;
	struct {
		unsigned int bp1_ratio:6;
		unsigned int res0:2;
		unsigned int bp0_ratio:6;
		unsigned int res1:2;
		unsigned int hp_ratio:6;
		unsigned int res2:9;
		unsigned int filter_sel:1;
	} bits;
};

union LP_CSTM_FILTER0_REG {
	unsigned int dwval;
	struct {
		unsigned int c0:9;
		unsigned int res0:7;
		unsigned int c1:9;
		unsigned int res1:7;
	} bits;
};

union LP_CSTM_FILTER1_REG {
	unsigned int dwval;
	struct {
		unsigned int c2:9;
		unsigned int res0:7;
		unsigned int c3:9;
		unsigned int res1:7;
	} bits;
};

union LP_CSTM_FILTER2_REG {
	unsigned int dwval;
	struct {
		unsigned int c4:9;
		unsigned int res0:23;
	} bits;
};

union LP_GAIN_REG {
	unsigned int dwval;
	struct {
		unsigned int gain:8;
		unsigned int res0:24;
	} bits;
};

union LP_GAINCTRL_REG {
	unsigned int dwval;
	struct {
		unsigned int beta:5;
		unsigned int res0:11;
		unsigned int dif_up:8;
		unsigned int res1:8;
	} bits;
};

union LP_SHOOTCTRL_REG {
	unsigned int dwval;
	struct {
		unsigned int neg_gain:6;
		unsigned int res0:26;
	} bits;
};

union LP_CORING_REG {
	unsigned int dwval;
	struct {
		unsigned int corthr:8;
		unsigned int res0:24;
	} bits;
};

struct __peak_reg_t {
	union LP_CTRL_REG ctrl;	                  /* 0x0000 */
	union LP_SIZE_REG size;	                  /* 0x0004 */
	union LP_WIN0_REG win0;	                  /* 0x0008 */
	union LP_WIN1_REG win1;	                  /* 0x000c */
	union LP_FILTER_REG filter;	              /* 0x0010 */
	union LP_CSTM_FILTER0_REG cfilter0;	      /* 0x0014 */
	union LP_CSTM_FILTER1_REG cfilter1;	      /* 0x0018 */
	union LP_CSTM_FILTER2_REG cfilter2;	      /* 0x001c */
	union LP_GAIN_REG gain;	                  /* 0x0020 */
	union LP_GAINCTRL_REG gainctrl;	          /* 0x0024 */
	union LP_SHOOTCTRL_REG shootctrl;	        /* 0x0028 */
	union LP_CORING_REG coring;	              /* 0x002c */
};

struct __peak_config_data {
	/* peak */
	unsigned int peak_en;
	unsigned int gain;
	unsigned int hp_ratio;
	unsigned int bp0_ratio;

	/* window */
	unsigned int win_en;
	struct de_rect win;

};

#endif
