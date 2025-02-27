/*
 *  Copyright (c) 2005-2007 Pierre Ossman, All Rights Reserved.
 *  Copyright (c) 2018-2023 CTCaer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 */

#ifndef SD_DEF_H
#define SD_DEF_H

/* SD commands                           type  argument     response */
/* class 0 */
/* This is basically the same command as for MMC with some quirks. */
#define SD_SEND_RELATIVE_ADDR     3 /* bcr                     R6  */
#define SD_SEND_IF_COND           8 /* bcr  [11:0] See below   R7  */
#define SD_SWITCH_VOLTAGE        11 /* ac                      R1  */
/* class 10 */
#define SD_SWITCH                 6 /* adtc [31:0] See below   R1  */
/* class 5 */
#define SD_ERASE_WR_BLK_START    32 /* ac   [31:0] data addr   R1  */
#define SD_ERASE_WR_BLK_END      33 /* ac   [31:0] data addr   R1  */

/* Application commands */
#define SD_APP_SET_BUS_WIDTH             6 /* ac   [1:0] bus width    R1  */
#define SD_APP_SD_STATUS                13 /* adtc                    R1  */
#define SD_APP_SEND_NUM_WR_BLKS         22 /* adtc                    R1  */
#define SD_APP_OP_COND                  41 /* bcr  [31:0] OCR         R3  */
#define SD_APP_SET_CLR_CARD_DETECT      42 /* adtc                    R1  */
#define SD_APP_SEND_SCR                 51 /* adtc                    R1  */

/* Application secure commands */
#define SD_APP_SECURE_READ_MULTI_BLOCK  18 /* adtc                      R1  */
#define SD_APP_SECURE_WRITE_MULTI_BLOCK 25 /* adtc                      R1  */
#define SD_APP_SECURE_WRITE_MKB         26 /* adtc                      R1  */
#define SD_APP_SECURE_ERASE             38 /* adtc                      R1b */
#define SD_APP_GET_MKB                  43 /* adtc   [31:0] See below   R1  */
#define SD_APP_GET_MID                  44 /* adtc                      R1  */
#define SD_APP_SET_CER_RN1              45 /* adtc                      R1  */
#define SD_APP_GET_CER_RN2              46 /* adtc                      R1  */
#define SD_APP_SET_CER_RES2             47 /* adtc                      R1  */
#define SD_APP_GET_CER_RES1             48 /* adtc                      R1  */
#define SD_APP_CHANGE_SECURE_AREA       49 /* adtc                      R1b */

/* OCR bit definitions */
#define SD_OCR_VDD_18       (1 << 7)	 /* VDD voltage 1.8 */
#define SD_VHD_27_36        (1 << 8)     /* VDD voltage 2.7 ~ 3.6 */
#define SD_OCR_VDD_27_34    (0x7F << 15) /* VDD voltage 2.7 ~ 3.4 */
#define SD_OCR_VDD_32_33    (1 << 20)	 /* VDD voltage 3.2 ~ 3.3 */
#define SD_OCR_S18R         (1 << 24)    /* 1.8V switching request */
#define SD_ROCR_S18A        SD_OCR_S18R  /* 1.8V switching accepted by card */
#define SD_OCR_XPC          (1 << 28)    /* SDXC power control */
#define SD_OCR_CCS          (1 << 30)    /* Card Capacity Status */
#define SD_OCR_BUSY         (1 << 31)    /* Card Power up Status */

/*
 * SD_SWITCH argument format:
 *
 *      [31] Check (0) or switch (1)
 *      [30:24] Reserved (0)
 *      [23:20] Function group 6
 *      [19:16] Function group 5
 *      [15:12] Function group 4
 *      [11:8] Function group 3
 *      [7:4] Function group 2
 *      [3:0] Function group 1
 */

/*
 * SD_SEND_IF_COND argument format:
 *
 *	[31:12] Reserved (0)
 *	[11:8] Host Voltage Supply Flags
 *	[7:0] Check Pattern (0xAA)
 */

/*
 * SD_APP_GET_MKB argument format:
 *
 *	[31:24] Number of blocks to read (512 block size)
 *	[23:16] MKB ID
 *	[15:0] Block offset
 */

/*
 * SCR field definitions
 */
#define SCR_SPEC_VER_0		0	/* Implements system specification 1.0 - 1.01 */
#define SCR_SPEC_VER_1		1	/* Implements system specification 1.10 */
#define SCR_SPEC_VER_2		2	/* Implements system specification 2.00-3.0X */
#define SD_SCR_BUS_WIDTH_1	(1<<0)
#define SD_SCR_BUS_WIDTH_4	(1<<2)

/*
 * SD bus widths
 */
#define SD_BUS_WIDTH_1		0
#define SD_BUS_WIDTH_4		2

/*
 * SD bus speeds
 */
#define UHS_SDR12_BUS_SPEED		0
#define HIGH_SPEED_BUS_SPEED	1
#define UHS_SDR25_BUS_SPEED		1
#define UHS_SDR50_BUS_SPEED		2
#define UHS_SDR104_BUS_SPEED	3
#define UHS_DDR50_BUS_SPEED		4
#define HS400_BUS_SPEED 		5

#define SD_MODE_HIGH_SPEED	(1 << HIGH_SPEED_BUS_SPEED)
#define SD_MODE_UHS_SDR12	(1 << UHS_SDR12_BUS_SPEED)
#define SD_MODE_UHS_SDR25	(1 << UHS_SDR25_BUS_SPEED)
#define SD_MODE_UHS_SDR50	(1 << UHS_SDR50_BUS_SPEED)
#define SD_MODE_UHS_SDR104	(1 << UHS_SDR104_BUS_SPEED)
#define SD_MODE_UHS_DDR50	(1 << UHS_DDR50_BUS_SPEED)

#define SD_DRIVER_TYPE_B	0x01
#define SD_DRIVER_TYPE_A	0x02

#define SD_SET_POWER_LIMIT_0_72	0
#define SD_SET_POWER_LIMIT_1_44	1
#define SD_SET_POWER_LIMIT_2_16	2
#define SD_SET_POWER_LIMIT_2_88	3

#define SD_MAX_POWER_0_72 (1 << SD_SET_POWER_LIMIT_0_72)
#define SD_MAX_POWER_1_44 (1 << SD_SET_POWER_LIMIT_1_44)
#define SD_MAX_POWER_2_16 (1 << SD_SET_POWER_LIMIT_2_16)
#define SD_MAX_POWER_2_88 (1 << SD_SET_POWER_LIMIT_2_88)

/*
 * SD_SWITCH mode
 */
#define SD_SWITCH_CHECK		0
#define SD_SWITCH_SET		1

/*
 * SD_SWITCH function groups
 */
#define SD_SWITCH_GRP_ACCESS	0
#define SD_SWITCH_GRP_CMDSYS    1
#define SD_SWITCH_GRP_DRVSTR    2
#define SD_SWITCH_GRP_PWRLIM    3

/*
 * SD_SWITCH access modes
 */
#define SD_SWITCH_ACCESS_DEF	0
#define SD_SWITCH_ACCESS_HS		1

#endif /* SD_DEF_H */
