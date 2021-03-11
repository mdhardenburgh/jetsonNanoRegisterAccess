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
 *
 */

#ifndef PAD_GROUP_CONTROLLER_H
#define PAD_GROUP_CONTROLLER_H

#include <cstdint>


enum class padGroupBitFields : uint32_t{SLWF = 30, PREEMP = 15, DRV_TYPE = 13, SCHMT = 12, /* OD = 11, */ IO_HV = 10,  HSM = 9, LPDR = 8,  LOCK = 7, INPUT = 6, PARK = 5, TRISTATE = 4, PUPD = 2, PM = 0};

enum class SLEW : uint32_t{HIGHEST, HIGH, LOW, LOWEST};

enum class E_PREEMP : uint32_t{DISABLE, ENABLE};

enum class DRV_TYPE : uint32_t{DRIVE_1X, DRIVE_2X, DRIVE_3X, DRIVE_4X};

enum class E_SCHMT : uint32_t{DISABLE, ENABLE};

// enum class E_OD : uint32_t{DISABLE, ENABLE}; //This bit field with PERMENTLY BRICK YOUR JETSON

enum class E_IO_HV : uint32_t{DISABLE, ENABLE};

enum class E_HSM : uint32_t{DISABLE, ENABLE};

enum class E_LPDR : uint32_t{DISABLE, ENABLE};

enum class E_LOCK : uint32_t{DISABLE, ENABLE};

enum class E_INPUT : uint32_t{DISABLE, ENABLE};

enum class PARK : uint32_t{NORMAL, PARKED};

enum class TRISTATE : uint32_t{PASSTHROUGH, TRISTATE};

/**
 *
 */ 
enum class PUPD : uint32_t{NONE, PULL_DONW, PULL_UP, RSVD};
   
/**
 * refer to bit field [1:0] in section 9.15.1 to 9.15.162
 * to find what the pinmux can be multiplexed to. 
 */
enum class PM : uint32_t{PINMUX_0, PINMUX_1, PINMUX_2, PINMUX_3};  

class PadGroupController
{
    public:
        
        PadGroupController();
        ~PadGroupController();
        
        static const uint32_t baseAddress = 0x70000000;
         
        static const uint32_t ALS_PROX_INT_CFG = 0x8e4; // R/W     0x00000000
        static const uint32_t AP_READY_CFG    = 0x8e8; // R/W     0x00000000
        static const uint32_t AP_WAKE_BT_CFG  = 0x8ec; // R/W     0x00000000
        static const uint32_t AP_WAKE_NFC_CFG = 0x8f0; // R/W     0x00000000
        static const uint32_t AUD_MCLK_CFG    = 0x8f4; // R/W     0x00000000
        static const uint32_t BATT_BCL_CFG    = 0x8f8; // R/W     0x00000000
        static const uint32_t BT_RST_CFG      = 0x8fc; // R/W     0x00000000
        static const uint32_t BT_WAKE_AP_CFG  = 0x900; // R/W     0x00000000
        static const uint32_t BUTTON_HOME_CFG = 0x904; // R/W     0x00000000
        static const uint32_t BUTTON_POWER_ON_CFG = 0x908; // R/W     0x00000000
        static const uint32_t BUTTON_SLIDE_SW_CFG = 0x90c; // R/W     0x00000000
        static const uint32_t BUTTON_VOL_DOWN_CFG = 0x910; // R/W     0x00000000
        static const uint32_t BUTTON_VOL_UP_CFG = 0x914; // R/W     0x00000000
        static const uint32_t CAM1_MCLK_CFG   = 0x918; // R/W     0x00000000
        static const uint32_t CAM1_PWDN_CFG   = 0x91c; // R/W     0x00000000
        static const uint32_t CAM1_STROBE_CFG = 0x920; // R/W     0x00000000
        static const uint32_t CAM2_MCLK_CFG   = 0x924; // R/W     0x00000000
        static const uint32_t CAM2_PWDN_CFG   = 0x928; // R/W     0x00000000
        static const uint32_t CAM_AF_EN_CFG   = 0x92c; // R/W     0x00000000
        static const uint32_t CAM_FLASH_EN_CFG = 0x930; // R/W     0x00000000
        static const uint32_t CAM_I2C_SCL_CFG = 0x934; // R/W     0x00000000
        static const uint32_t CAM_I2C_SDA_CFG = 0x938; // R/W     0x00000000
        static const uint32_t CAM_RST_CFG     = 0x93c; // R/W     0x00000000
        static const uint32_t CLK_32K_IN_CFG  = 0x940; // R/W     0x00000000
        static const uint32_t CLK_32K_OUT_CFG = 0x944; // R/W     0x00000000
        static const uint32_t CLK_REQ_CFG     = 0x948; // R/W     0x00000000
        static const uint32_t CORE_PWR_REQ_CFG = 0x94c; // R/W     0x00000000
        static const uint32_t CPU_PWR_REQ_CFG =  0x950; // R/W     0x00000000
        static const uint32_t DAP1_DIN_CFG    =  0x954; // R/W     0x00000000
        static const uint32_t DAP1_DOUT_CFG   =  0x958; // R/W     0x00000000
        static const uint32_t DAP1_FS_CFG     =  0x95c; // R/W     0x00000000
        static const uint32_t DAP1_SCLK_CFG   =  0x960; // R/W     0x00000000
        static const uint32_t DAP2_DIN_CFG    =  0x964; // R/W     0x00000000
        static const uint32_t DAP2_DOUT_CFG   =  0x968; // R/W     0x00000000
        static const uint32_t DAP2_FS_CFG     =  0x96c; // R/W     0x00000000
        static const uint32_t DAP2_SCLK_CFG   =  0x970; // R/W     0x00000000
        static const uint32_t DAP4_DIN_CFG    =  0x974; // R/W     0x00000000
        static const uint32_t DAP4_DOUT_CFG   =  0x978; // R/W     0x00000000
        static const uint32_t DAP4_FS_CFG     =  0x97c; // R/W     0x00000000
        static const uint32_t DAP4_SCLK_CFG   =  0x980; // R/W     0x00000000
        static const uint32_t DMIC1_CLK_CFG   =  0x984; // R/W     0x00000000
        static const uint32_t DMIC1_DAT_CFG   =  0x988; // R/W     0x00000000
        static const uint32_t DMIC2_CLK_CFG   =  0x98c; // R/W     0x00000000
        static const uint32_t DMIC2_DAT_CFG   =  0x990; // R/W     0x00000000
        static const uint32_t DMIC3_CLK_CFG   =  0x994; // R/W     0x00000000
        static const uint32_t DMIC3_DAT_CFG   =  0x998; // R/W     0x00000000
        static const uint32_t DP_HPD_CFG      =  0x99c; // R/W     0x00000000
        static const uint32_t DVFS_CLK_CFG    =  0x9a0; // R/W     0x00000000
        static const uint32_t DVFS_PWM_CFG    =  0x9a4; // R/W     0x00000000
        static const uint32_t GEN1_I2C_SCL_CFG  = 0x9a8; // R/W     0x00000000
        static const uint32_t GEN1_I2C_SDA_CFG  = 0x9ac; // R/W     0x00000000
        static const uint32_t GEN2_I2C_SCL_CFG  = 0x9b0; // R/W     0x00000000
        static const uint32_t GEN2_I2C_SDA_CFG  = 0x9b4; // R/W     0x00000000
        static const uint32_t GEN3_I2C_SCL_CFG  = 0x9b8; // R/W     0x00000000
        static const uint32_t GEN3_I2C_SDA_CFG  = 0x9bc; // R/W     0x00000000
        static const uint32_t GPIO_PA6_CFG    = 0x9c0; // R/W     0x00000000
        static const uint32_t GPIO_PCC7_CFG   = 0x9c4; // R/W     0x00000000
        static const uint32_t GPIO_PE6_CFG    = 0x9c8; // R/W     0x00000000
        static const uint32_t GPIO_PE7_CFG    = 0x9cc; // R/W     0x00000000
        static const uint32_t GPIO_PH6_CFG    = 0x9d0; // R/W     0x00000000
        static const uint32_t GPIO_PK0_CFG    = 0x9d4; // R/W     0x00000000
        static const uint32_t GPIO_PK1_CFG    = 0x9d8; // R/W     0x00000000
        static const uint32_t GPIO_PK2_CFG    = 0x9dc; // R/W     0x00000000
        static const uint32_t GPIO_PK3_CFG    = 0x9e0; // R/W     0x00000000
        static const uint32_t GPIO_PK4_CFG    = 0x9e4; // R/W     0x00000000
        static const uint32_t GPIO_PK5_CFG    = 0x9e8; // R/W     0x00000000
        static const uint32_t GPIO_PK6_CFG    = 0x9ec; // R/W     0x00000000
        static const uint32_t GPIO_PK7_CFG    = 0x9f0; // R/W     0x00000000
        static const uint32_t GPIO_PL0_CFG    = 0x9f4; // R/W     0x00000000
        static const uint32_t GPIO_PL1_CFG    = 0x9f8; // R/W     0x00000000
        static const uint32_t GPIO_PZ0_CFG    = 0x9fc; // R/W     0x00000000
        static const uint32_t GPIO_PZ1_CFG    = 0xa00; // R/W     0x00000000
        static const uint32_t GPIO_PZ2_CFG    = 0xa04; // R/W     0x00000000
        static const uint32_t GPIO_PZ3_CFG    = 0xa08; // R/W     0x00000000
        static const uint32_t GPIO_PZ4_CFG    = 0xa0c; // R/W     0x00000000
        static const uint32_t GPIO_PZ5_CFG    = 0xa10; // R/W     0x00000000
        static const uint32_t GPIO_X1_AUD_CFG = 0xa14; // R/W     0x00000000
        static const uint32_t GPIO_X3_AUD_CFG = 0xa18; // R/W     0x00000000
        static const uint32_t GPS_EN_CFG      = 0xa1c; // R/W     0x00000000
        static const uint32_t GPS_RST_CFG     = 0xa20; // R/W     0x00000000
        static const uint32_t HDMI_CEC_CFG    = 0xa24; // R/W     0x00000000
        static const uint32_t HDMI_INT_DP_HPD_CFG = 0xa28; // R/W     0x00000000
        static const uint32_t JTAG_RTCK_CFG   = 0xa2c; // R/W     0x00000000
        static const uint32_t LCD_BL_EN_CFG   = 0xa30; // R/W     0x00000000
        static const uint32_t LCD_BL_PWM_CFG  = 0xa34; // R/W     0x00000000
        static const uint32_t LCD_GPIO1_CFG   = 0xa38; // R/W     0x00000000
        static const uint32_t LCD_GPIO2_CFG   = 0xa3c; // R/W     0x00000000
        static const uint32_t LCD_RST_CFG     = 0xa40; // R/W     0x00000000
        static const uint32_t LCD_TE_CFG      = 0xa44; // R/W     0x00000000
        static const uint32_t MODEM_WAKE_AP_CFG = 0xa48; // R/W     0x00000000
        static const uint32_t MOTION_INT_CFG  = 0xa4c // R/W     0x00000000
        static const uint32_t NFC_EN_CFG      = 0xa50 // R/W     0x00000000
        static const uint32_t NFC_INT_CFG     = 0xa54 // R/W     0x00000000
        static const uint32_t PEX_L0_CLKREQ_N_CFG = 0xa58 // R/W     0x00000000
        static const uint32_t PEX_L0_RST_N_CFG    = 0xa5c // R/W     0x00000000
        static const uint32_t PEX_L1_CLKREQ_N_CFG = 0xa60 // R/W     0x00000000
        static const uint32_t PEX_L1_RST_N_CFG    = 0xa64 // R/W     0x00000000
        static const uint32_t PEX_WAKE_N_CFG  = 0xa68; // R/W     0x00000000
        static const uint32_t PWR_I2C_SCL_CFG = 0xa6c; // R/W     0x00000000
        static const uint32_t PWR_I2C_SDA_CFG = 0xa70; // R/W     0x00000000
        static const uint32_t PWR_INT_N_CFG   = 0xa74; // R/W     0x00000000
        static const uint32_t QSPI_COMP_CFG   = 0xa78; // R/W     0x00808000
        static const uint32_t QSPI_SCK_CFG    = 0xa90; // R/W     0x50000000
        static const uint32_t SATA_LED_ACTIVE_CFG =  0xa94 // R/W     0x00000000
        static const uint32_t SDMMC1_PAD_CFG  = 0xa98; // R/W     0x00808000
        static const uint32_t EMMC2_PAD_E_CFG = 0xa9c; // R/W     0x07ffc310
        static const uint32_t EMMC2_PAD_DRV_TYPE_CFG  = 0xaa0; // R/W     0x00155555
        static const uint32_t EMMC2_PAD_PUPD_CFG      = 0xaa4; // R/W     0x026aaaa6
        static const uint32_t SDMMC3_PAD_CFG  = 0xab0; // R/W     0x00808000
        static const uint32_t EMMC4_PAD_E_CFG = 0xab4; // R/W     0x07ffc310
        static const uint32_t EMMC4_PAD_DRV_TYPE_CFG = 0xab8; // R/W     0x00155555
        static const uint32_t EMMC4_PAD_PUPD_CFG     = 0xabc; // R/W     0x026aaaa6
        static const uint32_t SHUTDOWN_CFG   = 0xac8; // R/W     0x00000000
        static const uint32_t SPDIF_IN_CFG   = 0xacc; // R/W     0x00000000
        static const uint32_t SPDIF_OUT_CFG  = 0xad0; // R/W     0x00000000
        static const uint32_t SPI1_CS0_CFG   = 0xad4; // R/W     0x00000000
        static const uint32_t SPI1_CS1_CFG   = 0xad8; // R/W     0x00000000
        static const uint32_t SPI1_MISO_CFG  = 0xadc; // R/W     0x00000000
        static const uint32_t SPI1_MOSI_CFG  = 0xae0; // R/W     0x00000000
        static const uint32_t SPI1_SCK_CFG   = 0xae4; // R/W     0x00000000
        static const uint32_t SPI2_CS0_CFG   = 0xae8; // R/W     0x00000000
        static const uint32_t SPI2_CS1_CFG   = 0xaec; // R/W     0x00000000
        static const uint32_t SPI2_MISO_CFG  = 0xaf0; // R/W     0x00000000
        static const uint32_t SPI2_MOSI_CFG  = 0xaf4; // R/W     0x00000000
        static const uint32_t SPI2_SCK_CFG   = 0xaf8; // R/W     0x00000000
        static const uint32_t SPI4_CS0_CFG   = 0xafc; // R/W     0x00000000
        static const uint32_t SPI4_MISO_CFG  = 0xb00; // R/W     0x00000000
        static const uint32_t SPI4_MOSI_CFG  = 0xb04; // R/W     0x00000000
        static const uint32_t SPI4_SCK_CFG   = 0xb08; // R/W     0x00000000
        static const uint32_t TEMP_ALERT_CFG = 0xb0c; // R/W     0x00000000
        static const uint32_t TOUCH_CLK_CFG  = 0xb10; // R/W     0x00000000
        static const uint32_t TOUCH_INT_CFG  = 0xb14; // R/W     0x00000000
        static const uint32_t TOUCH_RST_CFG  = 0xb18; // R/W     0x00000000
        static const uint32_t UART1_CTS_CFG  = 0xb1c; // R/W     0x00000000
        static const uint32_t UART1_RTS_CFG  = 0xb20; // R/W     0x00000000
        static const uint32_t UART1_RX_CFG   = 0xb24; // R/W     0x00000000
        static const uint32_t UART1_TX_CFG   = 0xb28; // R/W     0x00000000
        static const uint32_t UART2_CTS_CFG  = 0xb2c; // R/W     0x00000000
        static const uint32_t UART2_RTS_CFG  = 0xb30; // R/W     0x00000000
        static const uint32_t UART2_RX_CFG   = 0xb34; // R/W     0x00000000
        static const uint32_t UART2_TX_CFG   = 0xb38; // R/W     0x00000000
    
    private:

};

#endif //PINMUX_CONTROLLER_H
