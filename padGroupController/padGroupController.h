/**
 * @file padGroupController.h
 * @brief padGroupController register declaration
 * @author Matthew Hardenburgh
 * @version 0.1
 * @date 3/6/21
 * @copyright Matthew Hardenburgh 2021
 *
 * @section license LICENSE
 * 
 * Jetson Nano pad group controller direct register access drivers
 * Copyright (C) 2021  Matthew Hardenburgh
 * mdhardenburgh@protonmail.com
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see https://www.gnu.org/licenses/.
 */ 

/**
 * @class PadGroupController
 * @brief Jetson pad group controller controller register group 
 * 
 * @section Description
 *
 * The per pad group options controller. A good number of pads have have thier 
 * own pad control grop. Typically, control group options is the slew rate or 
 * drive strenth. For EMMC2_PAD_E, EMMC2_PAD_PUPD, EMMC4_PAD_E, EMMC4_PAD_PUPD 
 * registers there are other different options.
 *
 */

#ifndef PAD_GROUP_CONTROLLER_H
#define PAD_GROUP_CONTROLLER_H

#include <cstdint>

struct padGroupController
{

    static const uint32_t SLWF_BITFIELD_HIGHEST = 0x0;
    static const uint32_t SLWF_BITFIELD_HIGH = 0x1;
    static const uint32_t SLWF_BITFIELD_LOW = 0x2;
    static const uint32_t SLWF_BITFIELD_LOWEST = 0x3;
    
    static const uint32_t SLWR_BITFIELD_HIGHEST = 0x0;
    static const uint32_t SLWR_BITFIELD_HIGH = 0x1;
    static const uint32_t SLWR_BITFIELD_LOW = 0x2;
    static const uint32_t SLWR_BITFIELD_LOWEST = 0x3;
    
    static const uint32_t PAD_PUPD_PULLD_BIT_DIS = 0;
    static const uint32_t PAD_PUPD_PULLD_BIT_EN = 1;
    
    static const uint32_t PAD_PUPD_PULLU_BIT_DIS = 0;
    static const uint32_t PAD_PUPD_PULLU_BIT_EN = 1;
    
    static const uint32_t PARK_BIT_NORMAL = 0;
    static const uint32_t PARK_BIT_PARKED = 1;
    
    static const uint32_t E_PREEMP_BIT_DISABLE = 0x0;
    static const uint32_t E_PREEMP_BIT_ENABLE = 0x1;
    
    static const uint32_t E_SCHMT_BIT_DISABLE = 0x0;
    static const uint32_t E_SCHMT_BIT_ENABLE = 0x1;
    
    static const uint32_t PAD_DRV_TYPE_BIT_66_100 = 0x0;
    static const uint32_t PAD_DRV_TYPE_BIT_33_50 = 0x1;
    
    static const uint32_t baseAddress = 0x70000000;

};

// 21.1.4.4
struct ALS_PROX_INT_CFG
{
    static const uint32_t addressOffset = 0x8E4;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;

};

//21.1.4.5
struct AP_READY_CFG 
{
    static const uint32_t addressOffset = 0x8E8;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;

};

// 21.1.4.6
struct AP_WAKE_BT_CFG
{
    static const uint32_t addressOffset = 0x8EC;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;

};

//21.1.4.7
struct AP_WAKE_NFC_CFG
{
    static const uint32_t addressOffset = 0x8F0;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;

};

//21.1.4.8
struct AUD_MCLK_CFG
{
    static const uint32_t addressOffset = 0x8F4;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;

};

//21.1.4.9
struct BATT_BCL_CFG
{
    static const uint32_t addressOffset = 0x8F8;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.10
struct BT_RST_CFG
{
    static const uint32_t addressOffset = 0x8FC;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.11
struct BT_WAKE_AP_CFG
{
    static const uint32_t addressOffset = 0x900;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.12
struct BUTTON_HOME_CFG
{
    static const uint32_t addressOffset = 0x904;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.13
struct BUTTON_POWER_ON_CFG
{
    static const uint32_t addressOffset = 0x908;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.14
struct BUTTON_SLIDE_SW_CFG
{
    static const uint32_t addressOffset = 0x90C;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.15
struct BUTTON_VOL_DOWN_CFG
{
    static const uint32_t addressOffset = 0x910;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.16
struct BUTTON_VOL_UP_CFG
{
    static const uint32_t addressOffset = 0x914;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.17
struct CAM1_MCLK_CFG
{
    static const uint32_t addressOffset = 0x918;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.18
struct CAM1_PWDN_CFG
{
    static const uint32_t addressOffset = 0x91C;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.19
struct CAM1_STROBE_CFG
{
    static const uint32_t addressOffset = 0x920;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.20
struct CAM2_MCLK_CFG
{
    static const uint32_t addressOffset = 0x924;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.21
struct CAM2_PWDN_CFG
{
    static const uint32_t addressOffset = 0x928;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.22
struct CAM_AF_EN_CFG
{
    static const uint32_t addressOffset = 0x92C;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.23
struct CAM_FLASH_EN_CFG
{
    static const uint32_t addressOffset = 0x930;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.24
struct CAM_I2C_SCL_CFG
{
    static const uint32_t addressOffset = 0x934;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.25
struct CAM_I2C_SDA_CFG
{
    static const uint32_t addressOffset = 0x938;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
}; 

// 21.1.4.26
struct CAM_RST_CFG
{
    static const uint32_t addressOffset = 0x93C;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.27
struct CLK_32K_IN_CFG
{
    static const uint32_t addressOffset = 0x940;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.28
struct CLK_32K_OUT_CFG
{
    static const uint32_t addressOffset = 0x944;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.29
struct CLK_REQ_CFG
{
    static const uint32_t address = 0x7000 + 0x948;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.30

struct CORE_PWR_REQ_CFG
{
    static const uint32_t addressOffset =  0x94c;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.31
struct CPU_PWR_REQ_CFG
{
    uint32_t addressOffset = 0x950;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.32
struct DAP1_DIN_CFG
{
    static const uint32_t addressOffset = 0x954;
    
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.33
struct DAP1_DOUT_CFG
{
    static const uint32_t addressOffset = 0x958;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};


// 21.1.4.34
struct DAP1_FS_CFG
{
    static const uint32_t addressOffset = 0x95C;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.35
struct DAP1_SCLK_CFG
{
    static const uint32_t addressOffset = 0x960;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.36
struct DAP2_DIN_CFG
{
    static const uint32_t addressOffset = 0x964;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.37
struct DAP2_DOUT_CFG
{
    static const uint32_t addressOffset = 0x968;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.38
struct DAP2_FS_CFG
{
    static const uint32_t addressOffset = 0x96C;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.39
struct DAP2_SCLK_CFG
{
    static const uint32_t addressOffset = 0x970;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.40
struct DAP4_DIN_CFG
{
    static const uint32_t addressOffset = 0x974;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.41
struct DAP4_DOUT_CFG
{
    static const uint32_t addressOffset = 0x978;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.42
struct DAP4_FS_CFG
{
    static const uint32_t addressOffset = 0x97C;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.43
struct DAP4_SCLK_CFG
{
    static const uint32_t addressOffset = 0x980;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.44
struct DMIC1_CLK_CFG
{
    static const uint32_t addressOffset = 0x984;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.45
struct DMIC1_DAT_CFG
{
    static const uint32_t addressOffset = 0x988;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.46
struct DMIC2_CLK_CFG
{
    static const uint32_t addressOffset = 0x98C;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.47
struct DMIC2_DAT_CFG
{
    static const uint32_t addressOffset = 0x990;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.48
struct DMIC3_CLK_CFG
{
    static const uint32_t addressOffset = 0x994;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.49
struct DMIC3_DAT_CFG
{
    static const uint32_t addressOffset = 0x998;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.50
struct DP_HPD_CFG
{
    static const uint32_t addressOffset = 0x99C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.51
struct DVFS_CLK_CFG
{
    static const uint32_t addressOffset = 0x9A0;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.52
struct DVFS_PWM_CFG
{
    static const uint32_t addressOffset = 0x9A4;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.53
struct GEN1_I2C_SCL_CFG
{
    static const uint32_t addressOffset = 0x9A8;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.54
struct GEN1_I2C_SDA_CFG
{
    static const uint32_t addressOffset = 0x9AC;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.55
struct GEN2_I2C_SCL_CFG
{
    static const uint32_t addressOffset = 0x9B0;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.56
struct GEN2_I2C_SDA_CFG
{
    static const uint32_t addressOffset = 0x9B4;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.57
struct GEN3_I2C_SCL_CFG
{
    static const uint32_t addressOffset = 0x9B8;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.58
struct GEN3_I2C_SDA_CFG
{
    static const uint32_t addressOffset = 0x9BC;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};
   
// 21.1.4.59
struct GPIO_PA6_CFG
{
    static const uint32_t addressOffset = 0x9C0;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.60
struct GPIO_PCC7_CFG
{
    static const uint32_t addressOffset = 0x9C4;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.61
struct GPIO_PE6_CFG
{
    static const uint32_t addressOffset = 0x9C8;

    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.62
struct GPIO_PE7_CFG
{
    static const uint32_t addressOffset = 0x9CC;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.63
struct GPIO_PH6_CFG
{
    static const uint32_t addressOffset = 0x9D0;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.64
struct GPIO_PK0_CFG
{
    static const uint32_t addressOffset = 0x9D4;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.65
struct GPIO_PK1_CFG
{
    static const uint32_t addressOffset = 0x9D8;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.66
struct GPIO_PK2_CFG
{
    static const uint32_t addressOffset = 0x9DC;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.67
struct GPIO_PK3_CFG
{
    static const uint32_t addressOffset = 0x9E0;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.68
struct GPIO_PK4_CFG
{
    static const uint32_t addressOffset = 0x9E4;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.69
struct GPIO_PK5_CFG 
{
    static const uint32_t addressOffset = 0x9E8;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.70
struct GPIO_PK6_CFG
{
    static const uint32_t addressOffset = 0x9EC;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.71
struct GPIO_PK7_CFG
{
    static const uint32_t addressOffset = 0x9F0;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.72
struct GPIO_PL0_CFG
{
    static const uint32_t addressOffset = 0x9F4;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.73
struct GPIO_PL1_CFG
{
    static const uint32_t addressOffset = 0x9F8;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.74
struct GPIO_PZ0_CFG
{
    static const uint32_t addressOffset = 0x9FC;

    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};


// 21.1.4.75
struct GPIO_PZ1_CFG
{
    static const uint32_t addressOffset = 0xA00;

    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.76
struct GPIO_PZ2_CFG
{
    static const uint32_t addressOffset = 0xA04;

    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.77
struct GPIO_PZ3_CFG
{
    static const uint32_t addressOffset = 0xA08;

    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.78
struct GPIO_PZ4_CFG
{
    static const uint32_t addressOffset = 0xA0C;

    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.79
struct GPIO_PZ5_CFG
{
    static const uint32_t addressOffset = 0xA10;

    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.80
struct GPIO_X1_AUD_CFG
{
    static const uint32_t addressOffset = 0xA14;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.81
struct GPIO_X3_AUD_CFG
{
    static const uint32_t addressOffset = 0xA18;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.82
struct GPS_EN_CFG
{
    static const uint32_t addressOffset = 0xA1C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.83
struct GPS_RST_CFG
{
    static const uint32_t addressOffset = 0xA20;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.84
struct GPS_RST_CFG
{
    static const uint32_t addressOffset = 0xA244;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.85
struct HDMI_INT_DP_HPD_CFG
{
    static const uint32_t addressOffset = 0xA28;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.86
struct JTAG_RTCK_CFGJTAG_RTCK_CFG
{
    static const uint32_t addressOffset = 0xA2C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.87
struct LCD_BL_EN_CFG
{
    static const uint32_t addressOffset = 0xA30;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.88
struct LCD_BL_PWM_CFG
{
    static const uint32_t addressOffset = 0xA34;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.89
struct LCD_GPIO1_CFG
{
    static const uint32_t addressOffset = 0xA38;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.90
struct LCD_GPIO2_CFG
{
    static const uint32_t addressOffset = 0xA3C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.91
struct LCD_RST_CFG
{
    static const uint32_t addressOffset = 0xA40;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.92
struct LCD_TE_CFG
{
    static const uint32_t addressOffset = 0xA44;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.93
struct MODEM_WAKE_AP_CFG
{
    static const uint32_t addressOffset = 0xA48;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.94
struct MOTION_INT_CFG
{
    static const uint32_t addressOffset = 0xA4C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.95
struct NFC_EN_CFG
{
    static const uint32_t addressOffset = 0xA50;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.96
struct NFC_INT_CFG
{
    static const uint32_t addressOffset = 0xA54;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.97
struct PEX_L0_CLKREQ_N_CFG
{
    static const uint32_t addressOffset = 0xA58;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.98
struct PEX_L0_RST_N_CFG
{
    static const uint32_t addressOffset = 0xA5C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.99
struct PEX_L1_CLKREQ_N_CFG
{
    static const uint32_t addressOffset = 0xA60;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.100
struct PEX_L1_RST_N_CFG
{
    static const uint32_t addressOffset = 0xA64;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.101
struct PEX_WAKE_N_CFG
{
    static const uint32_t addressOffset = 0xA68;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.102
struct PWR_I2C_SCL_CFG
{
    static const uint32_t addressOffset = 0xA6C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.103
struct PWR_I2C_SDA_CFG
{
    static const uint32_t addressOffset = 0xA70;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.104
struct PWR_I2C_SDA_CFG
{
    static const uint32_t addressOffset = 0xA74;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.105
struct QSPI_COMP_CFG
{
    static const uint32_t addressOffset = 0xA78;
 
    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.106
struct QSPI_SCK_CFG
{
    static const uint32_t addressOffset = 0xA90;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.107
struct SATA_LED_ACTIVE_CFG
{
    static const uint32_t addressOffset = 0xA94;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.108
struct SDMMC1_PAD_CFG
{
    static const uint32_t addressOffset = 0xA98;
 
    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
 
    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.109
struct EMMC2_PAD_E_CFG
{
    static const uint32_t addressOffset = 0xA9C;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;

    static const uint32_t DAT7_PARK_bit = 26;
    static const uint32_t DAT7_PARK_bitWidth = 1;

    static const uint32_t DAT6_PARK_bit = 25;
    static const uint32_t DAT6_PARK_bitWidth = 1;

    static const uint32_t DAT5_PARK_bit = 24;
    static const uint32_t DAT5_PARK_bitWidth = 1;

    static const uint32_t DAT4_PARK_bit = 23;
    static const uint32_t DAT4_PARK_bitWidth = 1;

    static const uint32_t DAT3_PARK_bit = 22;
    static const uint32_t DAT3_PARK_bitWidth = 1;

    static const uint32_t DAT2_PARK_bit = 21;
    static const uint32_t DAT2_PARK_bitWidth = 1;

    static const uint32_t DAT1_PARK_bit = 20;
    static const uint32_t DAT1_PARK_bitWidth = 1;

    static const uint32_t DAT0_PARK_bit = 19;
    static const uint32_t DAT0_PARK_bitWidth = 1;

    static const uint32_t CMD_PARK_bit = 18;
    static const uint32_t CMD_PARK_bitWidth = 1;

    static const uint32_t DQSB_PARK_bit = 17;
    static const uint32_t DQSB_PARK_bitWidth = 1;

    static const uint32_t DQS_PARK_bit = 16;
    static const uint32_t DQS_PARK_bitWidth = 1;

    static const uint32_t CLKB_PARK_bit = 15;
    static const uint32_t CLKB_PARK_bitWidth = 1;

    static const uint32_t CLK_PARK_bit = 14;
    static const uint32_t CLK_PARK_bitWidth = 1;

    static const uint32_t DRVUP_bit = 8;
    static const uint32_t DRVUP_bit_bitWidth = 6;

    static const uint32_t DRVDN_bit = 2;
    static const uint32_t DRVDN_bitWidth 6;

    static const uint32_t E_PREEMP_bit = 1;
    static const uint32_t E_PREEMP_bitWidth = 1;

    static const uint32_t E_SCHMT_bit = 0;
    static const uint32_t E_SCHMT_bitWidth = 1;
};

/**
 * DRV_TYPE[0]: 0 - 66/100 ohm driver; 1 - 33/50 ohm driver
 * DRV_TYPE[1]: should be zero always - not used
 */

// 21.1.4.110
struct EMMC2_PAD_DRV_TYPE_CFG
{
    static const uint32_t addressOffset = 0xAA0;

    static const uint32_t PAD_D7_DRV_TYPE_bit = 20;
    static const uint32_t PAD_D7_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D6_DRV_TYPE_bit = 18;
    static const uint32_t PAD_D6_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D5_DRV_TYPE_bit = 16;
    static const uint32_t PAD_D5_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D4_DRV_TYPE_bit = 14;
    static const uint32_t PAD_D4_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D3_DRV_TYPE_bit = 12;
    static const uint32_t PAD_D3_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D2_DRV_TYPE_bit = 10;
    static const uint32_t PAD_D2_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D1_DRV_TYPE_bit = 8;
    static const uint32_t PAD_D1_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D0_DRV_TYPE_bit = 6;
    static const uint32_t PAD_D0_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_CLKB_DRV_TYPE_bit = 4;
    static const uint32_t PAD_CLKB_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_CLK_DRV_TYPE_bit = 2;
    static const uint32_t PAD_CLK_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_CMD_DRV_TYPE_bit = 0;
    static const uint32_t PAD_CMD_DRV_TYPE_bitWidth = 1;
};

// 21.1.4.111
struct EMMC2_PAD_PUPD_CFG
{
    static const uint32_t addressOffset = 0xAA4;

    static const uint32_t PAD_DQSB_PUPD_PULLU_bit = 25;
    static const uint32_t PAD_DQSB_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_DQSB_PUPD_PULLD_bit = 24;
    static const uint32_t PAD_DQSB_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_DQS_PUPD_PULLU_bit = 23;
    static const uint32_t PAD_DQS_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_DQS_PUPD_PULLD_bit = 22;
    static const uint32_t PAD_DQS_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D7_PUPD_PULLU_bit = 21;
    static const uint32_t PAD_D7_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D7_PUPD_PULLD_bit = 20;
    static const uint32_t PAD_D7_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D6_PUPD_PULLU_bit = 19;
    static const uint32_t PAD_D6_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D6_PUPD_PULLD_bit = 18;
    static const uint32_t PAD_D6_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D5_PUPD_PULLU_bit = 17;
    static const uint32_t PAD_D5_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D5_PUPD_PULLD_bit = 16;
    static const uint32_t PAD_D5_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D4_PUPD_PULLU_bit = 15;
    static const uint32_t PAD_D4_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D4_PUPD_PULLD_bit = 14;
    static const uint32_t PAD_D4_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D3_PUPD_PULLU_bit = 13;
    static const uint32_t PAD_D3_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D3_PUPD_PULLD_bit = 12;
    static const uint32_t PAD_D3_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D2_PUPD_PULLU_bit = 11;
    static const uint32_t PAD_D2_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D2_PUPD_PULLD_bit = 10;
    static const uint32_t PAD_D2_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D1_PUPD_PULLU_bit = 9;
    static const uint32_t PAD_D1_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D1_PUPD_PULLD_bit = 8;
    static const uint32_t PAD_D1_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D0_PUPD_PULLU_bit = 7;
    static const uint32_t PAD_D0_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D0_PUPD_PULLD_bit = 6;
    static const uint32_t PAD_D0_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_CLKB_PUPD_PULLU_bit = 5;
    static const uint32_t PAD_CLKB_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_CLKB_PUPD_PULLD_bit = 4;
    static const uint32_t PAD_CLKB_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_CLK_PUPD_PULLU_bit = 3;
    static const uint32_t PAD_CLK_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_CLK_PUPD_PULLD_bit = 2;
    static const uint32_t PAD_CLK_PUPD_PULLD_bitWidth = 1;

    // PULLD: enables weak pull down; PULLDU:enables weak pull up.
    static const uint32_t PAD_CMD_PUPD_PULLU_bit = 1;
    static const uint32_t PAD_CMD_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_CMD_PUPD_PULLD_bit = 0;
    static const uint32_t PAD_CMD_PUPD_PULLD_bitWidth = 1;
};

/*
 * Controls for BDSDMEM pads of SDMMC3.
 *
 * The following calibration codes need to be used for the pad under default conditions. In general, the calibration pad provides the
 * code for the pad.
 *
 * To bypass calibration and provide default code for the required impedance, these values (in decimal) should be used.
 *
 * On power ON, Vio is 3.3 V only. Software runs calibration, when Vio is switched to 1.8 V. So, we should use 3.3 V DRV codes
 * as default values.
 *
 */

// 21.1.4.112
struct SDMMC3_PAD_CFG
{
    static const uint32_t addressOffset = 0xAB0;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
 
    static const uint32_t DRVUP_CZ_bit = 20;
    static const uint32_t DRVUP_CZ_bitWidth 7;

    static const uint32_t DRVDN_CZ_bit = 12;
    static const uint32_t DRVDN_CZ_bitWidth 7;
};

// 21.1.4.113
struct EMMC4_PAD_E_CFG
{
    static const uint32_t addressOffset = 0xAB4;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;

    static const uint32_t DAT7_PARK_bit = 26;
    static const uint32_t DAT7_PARK_bitWidth = 1;

    static const uint32_t DAT6_PARK_bit = 25;
    static const uint32_t DAT6_PARK_bitWidth = 1;

    static const uint32_t DAT5_PARK_bit = 24;
    static const uint32_t DAT5_PARK_bitWidth = 1;

    static const uint32_t DAT4_PARK_bit = 23;
    static const uint32_t DAT4_PARK_bitWidth = 1;

    static const uint32_t DAT3_PARK_bit = 22;
    static const uint32_t DAT3_PARK_bitWidth = 1;

    static const uint32_t DAT2_PARK_bit = 21;
    static const uint32_t DAT2_PARK_bitWidth = 1;

    static const uint32_t DAT1_PARK_bit = 20;
    static const uint32_t DAT1_PARK_bitWidth = 1;

    static const uint32_t DAT0_PARK_bit = 19;
    static const uint32_t DAT0_PARK_bitWidth = 1;

    static const uint32_t CMD_PARK_bit = 18;
    static const uint32_t CMD_PARK_bitWidth = 1;

    static const uint32_t DQSB_PARK_bit = 17;
    static const uint32_t DQSB_PARK_bitWidth = 1;

    static const uint32_t DQS_PARK_bit = 16;
    static const uint32_t DQS_PARK_bitWidth = 1;

    static const uint32_t CLKB_PARK_bit = 15;
    static const uint32_t CLKB_PARK_bitWidth = 1;

    static const uint32_t CLK_PARK_bit = 14;
    static const uint32_t CLK_PARK_bitWidth = 1;

    static const uint32_t DRVUP_bit = 8;
    static const uint32_t DRVUP_bit_bitWidth = 6;

    static const uint32_t DRVDN_bit = 2;
    static const uint32_t DRVDN_bitWidth 6;

    static const uint32_t E_PREEMP_bit = 1;
    static const uint32_t E_PREEMP_bitWidth = 1;

    static const uint32_t E_SCHMT_bit = 0;
    static const uint32_t E_SCHMT_bitWidth = 1;
};

/**
 * DRV_TYPE[0]: 0 - 66/100 ohm driver; 1 - 33/50 ohm driver
 * DRV_TYPE[1]: should be zero always - not used
 */

// 21.1.4.114
struct EMMC4_PAD_DRV_TYPE_CFG
{
    static const uint32_t addressOffset = 0xAB8;

    static const uint32_t PAD_D7_DRV_TYPE_bit = 20;
    static const uint32_t PAD_D7_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D6_DRV_TYPE_bit = 18;
    static const uint32_t PAD_D6_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D5_DRV_TYPE_bit = 16;
    static const uint32_t PAD_D5_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D4_DRV_TYPE_bit = 14;
    static const uint32_t PAD_D4_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D3_DRV_TYPE_bit = 12;
    static const uint32_t PAD_D3_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D2_DRV_TYPE_bit = 10;
    static const uint32_t PAD_D2_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D1_DRV_TYPE_bit = 8;
    static const uint32_t PAD_D1_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_D0_DRV_TYPE_bit = 6;
    static const uint32_t PAD_D0_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_CLKB_DRV_TYPE_bit = 4;
    static const uint32_t PAD_CLKB_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_CLK_DRV_TYPE_bit = 2;
    static const uint32_t PAD_CLK_DRV_TYPE_bitWidth = 1;

    static const uint32_t PAD_CMD_DRV_TYPE_bit = 0;
    static const uint32_t PAD_CMD_DRV_TYPE_bitWidth = 1;
};

// 21.1.4.115
struct EMMC4_PAD_PUPD_CFG
{
    static const uint32_t addressOffset = 0xABC;

    static const uint32_t PAD_DQSB_PUPD_PULLU_bit = 25;
    static const uint32_t PAD_DQSB_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_DQSB_PUPD_PULLD_bit = 24;
    static const uint32_t PAD_DQSB_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_DQS_PUPD_PULLU_bit = 23;
    static const uint32_t PAD_DQS_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_DQS_PUPD_PULLD_bit = 22;
    static const uint32_t PAD_DQS_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D7_PUPD_PULLU_bit = 21;
    static const uint32_t PAD_D7_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D7_PUPD_PULLD_bit = 20;
    static const uint32_t PAD_D7_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D6_PUPD_PULLU_bit = 19;
    static const uint32_t PAD_D6_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D6_PUPD_PULLD_bit = 18;
    static const uint32_t PAD_D6_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D5_PUPD_PULLU_bit = 17;
    static const uint32_t PAD_D5_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D5_PUPD_PULLD_bit = 16;
    static const uint32_t PAD_D5_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D4_PUPD_PULLU_bit = 15;
    static const uint32_t PAD_D4_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D4_PUPD_PULLD_bit = 14;
    static const uint32_t PAD_D4_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D3_PUPD_PULLU_bit = 13;
    static const uint32_t PAD_D3_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D3_PUPD_PULLD_bit = 12;
    static const uint32_t PAD_D3_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D2_PUPD_PULLU_bit = 11;
    static const uint32_t PAD_D2_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D2_PUPD_PULLD_bit = 10;
    static const uint32_t PAD_D2_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D1_PUPD_PULLU_bit = 9;
    static const uint32_t PAD_D1_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D1_PUPD_PULLD_bit = 8;
    static const uint32_t PAD_D1_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_D0_PUPD_PULLU_bit = 7;
    static const uint32_t PAD_D0_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_D0_PUPD_PULLD_bit = 6;
    static const uint32_t PAD_D0_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_CLKB_PUPD_PULLU_bit = 5;
    static const uint32_t PAD_CLKB_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_CLKB_PUPD_PULLD_bit = 4;
    static const uint32_t PAD_CLKB_PUPD_PULLD_bitWidth = 1;

    static const uint32_t PAD_CLK_PUPD_PULLU_bit = 3;
    static const uint32_t PAD_CLK_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_CLK_PUPD_PULLD_bit = 2;
    static const uint32_t PAD_CLK_PUPD_PULLD_bitWidth = 1;

    // PULLD: enables weak pull down; PULLDU:enables weak pull up.
    static const uint32_t PAD_CMD_PUPD_PULLU_bit = 1;
    static const uint32_t PAD_CMD_PUPD_PULLU_bitWidth = 1;

    static const uint32_t PAD_CMD_PUPD_PULLD_bit = 0;
    static const uint32_t PAD_CMD_PUPD_PULLD_bitWidth = 1;
};

// 21.1.4.116
struct SHUTDOWN_CFG
{
    static const uint32_t addressOffset = 0xAC8;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.117
struct SPDIF_IN_CFG
{
    static const uint32_t addressOffset = 0xACC;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.118
struct SPDIF_OUT_CFG
{
    static const uint32_t addressOffset = 0xAD0;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.119
struct SPI1_CS0_CFG
{
    static const uint32_t addressOffset = 0xAD4;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.120
struct SPI1_CS1_CFG
{
    static const uint32_t addressOffset = 0xAD8;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.121
struct SPI1_MISO_CFG
{
    static const uint32_t addressOffset = 0xADC;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.122
struct SPI1_MOSI_CFG
{
    static const uint32_t addressOffset = 0xAE0;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.123
struct SPI1_SCK_CFG
{
    static const uint32_t addressOffset = 0xAE4;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.124
struct SPI2_CS0_CFG 
{
    static const uint32_t addressOffset = 0xAE8;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.125
struct SPI2_CS1_CFG
{
    static const uint32_t addressOffset = 0xAEC;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.126
struct SPI2_MISO_CFG
{
    static const uint32_t addressOffset = 0xAF0;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.127
struct SPI2_MOSI_CFG
{
    static const uint32_t addressOffset = 0xAF4;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.128
struct SPI2_SCK_CFG
{
    static const uint32_t addressOffset = 0xAF8;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.129
struct SPI4_CS0_CFG
{
    static const uint32_t addressOffset = 0xAFC;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.130
struct SPI4_MISO_CFG
{
    static const uint32_t addressOffset = 0xB00;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.131
struct SPI4_MOSI_CFG
{
    static const uint32_t addressOffset = 0xB04;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.132
struct SPI4_SCK_CFG
{
    static const uint32_t addressOffset = 0xB08;

    static const uint32_t SLWF_bit = 30;
    static const uint32_t SLWF_bitWidth = 2;

    static const uint32_t SLWR_bit = 28;
    static const uint32_t SLWR_bitWidth = 2;
};

// 21.1.4.133
struct TEMP_ALERT_CFG
{
    static const uint32_t addressOffset = 0xB0C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.134
struct TOUCH_CLK_CFG
{
    static const uint32_t addressOffset = 0xB10;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.135
struct TOUCH_INT_CFG
{
    static const uint32_t addressOffset = 0xB14;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.136
struct TOUCH_RST_CFG
{
    static const uint32_t addressOffset = 0xB18;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.137
struct UART1_CTS_CFG
{
    static const uint32_t addressOffset = 0xB1C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.138
struct UART1_RTS_CFG
{
    static const uint32_t addressOffset = 0xB20;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.139
struct UART1_RX_CFG
{
    static const uint32_t addressOffset = 0xB24;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.140
struct UART1_TX_CFG
{
    static const uint32_t addressOffset = 0xB28;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.141
struct UART2_CTS_CFG
{
    static const uint32_t addressOffset = 0xB2C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.142
struct UART2_RTS_CFG
{
    static const uint32_t addressOffset = 0xB30;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.143
struct UART2_RX_CFG
{
    static const uint32_t addressOffset = 0xB34;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.144
struct UART2_TX_CFG
{
    static const uint32_t addressOffset = 0xB38;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.145
struct UART3_CTS_CFG
{
    static const uint32_t addressOffset = 0xB3C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.146
struct UART3_RTS_CFG
{
    static const uint32_t addressOffset = 0xB40;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.147
struct UART3_RX_CFG
{
    static const uint32_t addressOffset = 0xB44;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.148
struct UART3_TX_CFG
{
    static const uint32_t addressOffset = 0xB48;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.149
struct UART4_CTS_CFG
{
    static const uint32_t addressOffset = 0xB4C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.150
struct UART4_RTS_CFG
{
    static const uint32_t addressOffset = 0xB50;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.151
struct UART4_RX_CFG
{
    static const uint32_t addressOffset = 0xB54;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.152
struct UART4_TX_CFG
{
    static const uint32_t addressOffset = 0xB58;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.153
struct USB_VBUS_EN0_CFG
{
    static const uint32_t addressOffset = 0xB5C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.154
struct USB_VBUS_EN1_CFG
{
    static const uint32_t addressOffset = 0xB60;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.155
struct WIFI_EN_CFG
{
    static const uint32_t addressOffset = 0xB64;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.156
struct WIFI_RST_CFG
{
    static const uint32_t addressOffset = 0xB68;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

// 21.1.4.157
struct WIFI_WAKE_AP_CFG
{
    static const uint32_t addressOffset = 0xB6C;
    
    static const uint32_t DRVUP_bit = 20;
    static const uint32_t DRVUP_bitWidth 5;

    static const uint32_t DRVDN_bit = 12;
    static const uint32_t DRVDN_bitWidth = 5;
};

#endif //PINMUX_CONTROLLER_H
