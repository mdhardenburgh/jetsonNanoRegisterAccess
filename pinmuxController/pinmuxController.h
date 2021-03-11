/**
 * @file pinmuxController.h
 * @brief pinmux controller register declaration
 * @author Matthew Hardenburgh
 * @version 0.1
 * @date 3/6/21
 * @copyright Matthew Hardenburgh 2021
 *
 * @section license LICENSE
 * 
 * Jetson nano pinmux controller direct register access drivers
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
 * @class PinmuxController
 * @brief Jetson pinmux controller register group 
 * 
 * @section Description
 *
 * The following class controls and configures the MPIO pads on a per pad basis
 * 
 * During normal operation, these per-pad controls are driven by the pinmux 
 * controller registers. See Section 9.6: Pinmuxing below for more information.
 *
 */

#ifndef PINMUX_CONTROLLER_H
#define PINMUX_CONTROLLER_H

#include <cstdint>

enum class E_PREEMP : uint32_t{DISABLE = (0x0 << 15), ENABLE = (0x1 << 15), bitMask = (0x1 << 15)};

enum class DRV_TYPE : uint32_t{DRIVE_1X = (0x0 << 13), DRIVE_2X = (0x1 << 13), DRIVE_3X = (0x2 << 13), DRIVE_4X = (0x3 << 13), bitMask = (0x3 << 13)};

enum class E_SCHMT : uint32_t{DISABLE = (0x0 << 12), ENABLE = (0x1 << 12), bitMask = (0x1 << 12)};

// enum class E_OD : uint32_t{DISABLE = (0x0 << 11), ENABLE = (0x1 << 11), bitMask = (0x1 << 11)}; //This bit field with PERMENTLY BRICK YOUR JETSON

enum class E_IO_HV : uint32_t{DISABLE = (0x0 << 10), ENABLE = (0x1 << 10), bitMask = (0x1 << 10)};

enum class E_HSM : uint32_t{DISABLE = (0x0 << 9), ENABLE = (0x1 << 9), bitMask = (0x1 << 9)};

enum class E_LPDR : uint32_t{DISABLE = (0x0 << 8), ENABLE = (0x1 << 8), bitMask = (0x1 << 8)};

enum class E_LOCK : uint32_t{DISABLE = (0x0 << 7), ENABLE = (0x1 << 7), bitMask = (0x1 << 7)};

enum class E_INPUT : uint32_t{DISABLE = (0x0 << 6), ENABLE = (0x1 << 6), bitMask = (0x1 << 6)};

enum class PARK : uint32_t{NORMAL = (0x0 << 5), PARKED = (0x1 << 5), bitMask = (0x1 << 5)};

enum class TRISTATE : uint32_t{PASSTHROUGH = (0x0 << 4), TRISTATE = (0x1 << 4), bitMask = (0x1 << 4)};

/**
 *
 */ 
enum class PUPD : uint32_t{NONE = (0x0 << 2), PULL_DOWN = (0x1 << 2), PULL_UP = (0x2 << 2), RSVD = (0x3 << 2), bitMask = (0x3 << 2)};
   
/**
 * refer to bit field [1:0] in section 9.15.1 to 9.15.162
 * to find what the pinmux can be multiplexed to. 
 */
enum class PM : uint32_t{PINMUX_0 = (0x0 << 1), PINMUX_1 = (0x1 << 1), PINMUX_2 = (0x2 << 1), PINMUX_3 = (0x3 << 1), bitMask = (0x3 << 1)};  


class PinmuxController
{
    public:
        PinmuxController();
        ~PinmuxController();
        
        static const uint32_t baseAddress = 0x70000000;

        static const uint32_t PINMUX_AUX_SDMMC1_CLK_0 = 0x3000;
        static const uint32_t PINMUX_AUX_SDMMC1_CMD_0 = 0x3004;
        static const uint32_t PINMUX_AUX_SDMMC1_DAT3_0 = 0x3008;
        static const uint32_t PINMUX_AUX_SDMMC1_DAT2_0 = 0x300c;
        static const uint32_t PINMUX_AUX_SDMMC1_DAT1_0 = 0x3010;
        static const uint32_t PINMUX_AUX_SDMMC1_DAT0_0 = 0x3014;
        static const uint32_t PINMUX_AUX_SDMMC3_CLK_0 = 0x301c;
        static const uint32_t PINMUX_AUX_SDMMC3_CMD_0 = 0x3020;
        static const uint32_t PINMUX_AUX_SDMMC3_DAT0_0 = 0x3024;
        static const uint32_t PINMUX_AUX_SDMMC3_DAT1_0 = 0x3028;
        static const uint32_t PINMUX_AUX_SDMMC3_DAT2_0 = 0x302c'
        static const uint32_t PINMUX_AUX_SDMMC3_DAT3_0 = 0x3030; //  R/W     0x00002078
        static const uint32_t PINMUX_AUX_PEX_L0_RST_N_0 = 0x3038; // R/W     0x00000460
        static const uint32_t PINMUX_AUX_PEX_L0_CLKREQ_N_0 = 0x303c; // R/W     0x00000470
        static const uint32_t PINMUX_AUX_PEX_WAKE_N_0 = 0x3040; // R/W     0x00000470
        static const uint32_t PINMUX_AUX_PEX_L1_RST_N_0 = 0x3044; // R/W     0x00000460
        static const uint32_t PINMUX_AUX_PEX_L1_CLKREQ_N_0 = 0x3048; // R/W     0x00000470
        static const uint32_t PINMUX_AUX_SATA_LED_ACTIVE_0 = 0x304c; // R/W     0x00000060
        static const uint32_t PINMUX_AUX_SPI1_MOSI_0 =  0x3050; // R/W     0x0000e074
        static const uint32_t PINMUX_AUX_SPI1_MISO_0 = 0x3054; // R/W     0x0000e074
        static const uint32_t PINMUX_AUX_SPI1_SCK_0 = 0x3058; // R/W     0x0000e074
        static const uint32_t PINMUX_AUX_SPI1_CS0_0 = 0x305c; // R/W     0x0000e078
        static const uint32_t PINMUX_AUX_SPI1_CS1_0   = 0x3060; // R/W     0x0000e078
        static const uint32_t PINMUX_AUX_SPI2_MOSI_0  = 0x3064; //  R/W     0x00006074
        static const uint32_t PINMUX_AUX_SPI2_MISO_0  = 0x3068; //  R/W     0x00006074
        static const uint32_t PINMUX_AUX_SPI2_SCK_0   = 0x306c; //  R/W     0x00006074
        static const uint32_t PINMUX_AUX_SPI2_CS0_0   = 0x3070; //  R/W     0x00006078
        static const uint32_t PINMUX_AUX_SPI2_CS1_0   = 0x3074; //  R/W     0x00006078
        static const uint32_t PINMUX_AUX_SPI4_MOSI_0  = 0x3078; //  R/W     0x0000e074
        static const uint32_t PINMUX_AUX_SPI4_MISO_0  = 0x307c; //  R/W     0x0000e074
        static const uint32_t PINMUX_AUX_SPI4_SCK_0   = 0x3080; //  R/W     0x0000e074
        static const uint32_t PINMUX_AUX_SPI4_CS0_0   = 0x3084; //  R/W     0x0000e078
        static const uint32_t PINMUX_AUX_QSPI_SCK_0   = 0x3088; //  R/W     0x00003078
        static const uint32_t PINMUX_AUX_QSPI_CS_N_0  = 0x308c; //  R/W     0x00003078
        static const uint32_t PINMUX_AUX_QSPI_IO0_0   = 0x3090; //  R/W     0x00003078
        static const uint32_t PINMUX_AUX_QSPI_IO1_0   = 0x3094; //  R/W     0x00003078
        static const uint32_t PINMUX_AUX_QSPI_IO2_0   = 0x3098; //  R/W     0x00003078
        static const uint32_t PINMUX_AUX_QSPI_IO3_0   = 0x309c; //  R/W     0x00003078
        static const uint32_t PINMUX_AUX_DMIC1_CLK_0  = 0x30a4; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_DMIC1_DAT_0  = 0x30a8; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_DMIC2_CLK_0  = 0x30ac; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_DMIC2_DAT_0  = 0x30b0; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_DMIC3_CLK_0  = 0x30b4; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_DMIC3_DAT_0  = 0x30b8; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_GEN1_I2C_SCL_0 = 0x30bc; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_GEN1_I2C_SDA_0 = 0x30c0; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_GEN2_I2C_SCL_0 = 0x30c4; // R/W     0x00000572
        static const uint32_t PINMUX_AUX_GEN2_I2C_SDA_0 = 0x30c8; // R/W     0x00000572
        static const uint32_t PINMUX_AUX_GEN3_I2C_SCL_0 = 0x30cc; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_GEN3_I2C_SDA_0 = 0x30d0; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_CAM_I2C_SCL_0  = 0x30d4; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_CAM_I2C_SDA_0  = 0x30d8; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_PWR_I2C_SCL_0  = 0x30dc; // R/W     0x00000170
        static const uint32_t PINMUX_AUX_PWR_I2C_SDA_0  = 0x30e0; // R/W     0x00000170
        static const uint32_t PINMUX_AUX_UART1_TX_0  = 0x30e4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART1_RX_0  = 0x30e8; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART1_RTS_0 = 0x30ec; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART1_CTS_0 = 0x30f0; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART2_TX_0  = 0x30f4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART2_RX_0  = 0x30f8; // R/W     0x00000078
        static const uint32_t PINMUX_AUX_UART2_RTS_0 = 0x30fc; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART2_CTS_0 = 0x3100; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART3_TX_0  = 0x3104; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART3_RX_0  = 0x3108; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART3_RTS_0 = 0x310c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART3_CTS_0 = 0x3110; // R/W     0x00000078
        static const uint32_t PINMUX_AUX_UART4_TX_0  = 0x3114; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART4_RX_0  = 0x3118; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART4_RTS_0 = 0x311c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_UART4_CTS_0 = 0x3120; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_DAP1_FS_0   = 0x3124; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP1_DIN_0  = 0x3128; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP1_DOUT_0 = 0x312c; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP1_SCLK_0 = 0x3130; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP2_FS_0   = 0x3134; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP2_DIN_0  = 0x3138; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP2_DOUT_0 = 0x313c; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP2_SCLK_0 = 0x3140; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_DAP4_FS_0   = 0x3144; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_DAP4_DIN_0  = 0x3148; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_DAP4_DOUT_0 = 0x314c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_DAP4_SCLK_0 = 0x3150; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM1_MCLK_0 = 0x3154; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM2_MCLK_0 = 0x3158; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_JTAG_RTCK_0 = 0x315c; // R/W     0x00000068
        static const uint32_t PINMUX_AUX_CLK_32K_IN_0 = 0x3160; // R/W     0x00000000
        static const uint32_t PINMUX_AUX_CLK_32K_OUT_0 = 0x3164; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_BATT_BCL_0 = 0x3168; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_CLK_REQ_0 = 0x316c; // R/W     0x00000040
        static const uint32_t PINMUX_AUX_CPU_PWR_REQ_0 = 0x3170; // R/W     0x00000040
        static const uint32_t PINMUX_AUX_PWR_INT_N_0 = 0x3174; // R/W     0x00000040
        static const uint32_t PINMUX_AUX_SHUTDOWN_0 = 0x3178; // R/W     0x00000040
        static const uint32_t PINMUX_AUX_CORE_PWR_REQ_0 = 0x317c; // R/W     0x00000040
        static const uint32_t PINMUX_AUX_AUD_MCLK_0 = 0x3180; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_DVFS_PWM_0 = 0x3184; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_DVFS_CLK_0 = 0x3188; // R/W     0x00000078
        static const uint32_t PINMUX_AUX_GPIO_X1_AUD_0 = 0x318c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_X3_AUD_0 = 0x3190; // R/W     0x00000078
        static const uint32_t PINMUX_AUX_GPIO_PCC7_0 = 0x3194; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_HDMI_CEC_0 = 0x3198; // R/W     0x00000570
        static const uint32_t PINMUX_AUX_HDMI_INT_DP_HPD_0 = 0x319c; // R/W     0x00000574
        static const uint32_t PINMUX_AUX_SPDIF_OUT_0 = 0x31a0; // R/W     0x00000078
        static const uint32_t PINMUX_AUX_SPDIF_IN_0 = 0x31a4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_USB_VBUS_EN0_0 = 0x31a8; // R/W     0x00000560
        static const uint32_t PINMUX_AUX_USB_VBUS_EN1_0 = 0x31ac; // R/W     0x00000560
        static const uint32_t PINMUX_AUX_DP_HPD0_0 = 0x31b0; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_WIFI_EN_0 = 0x31b4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_WIFI_RST_0 = 0x31b8; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_WIFI_WAKE_AP_0 = 0x31bc; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_AP_WAKE_BT_0 = 0x31c0; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_BT_RST_0 = 0x31c4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_BT_WAKE_AP_0 = 0x31c8; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_AP_WAKE_NFC_0 = 0x31cc; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_NFC_EN_0 = 0x31d0; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_NFC_INT_0 = 0x31d4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPS_EN_0 = 0x31d8; //  R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPS_RST_0 = 0x31dc; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM_RST_0 = 0x31e0; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM_AF_EN_0 = 0x31e4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM_FLASH_EN_0 = 0x31e8; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM1_PWDN_0 = 0x31ec; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM2_PWDN_0 = 0x31f0; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_CAM1_STROBE_0 = 0x31f4; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_LCD_TE_0     = 0x31f8; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_LCD_BL_PWM_0 = 0x31fc; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_LCD_BL_EN_0  = 0x3200; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_LCD_RST_0    = 0x3204; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_LCD_GPIO1_0  = 0x3208; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_LCD_GPIO2_0  = 0x320c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_AP_READY_0   = 0x3210; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_TOUCH_RST_0  = 0x3214; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_TOUCH_CLK_0  = 0x3218; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_MODEM_WAKE_AP_0 = 0x321c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_TOUCH_INT_0 = 0x3220; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_MOTION_INT_0 = 0x3224; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_ALS_PROX_INT_0 = 0x3228; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_TEMP_ALERT_0 = 0x322c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_BUTTON_POWER_ON_0 = 0x3230; // R/W     0x00000078
        static const uint32_t PINMUX_AUX_BUTTON_VOL_UP_0   = 0x3234; //  R/W     0x00000078
        static const uint32_t PINMUX_AUX_BUTTON_VOL_DOWN_0 = 0x3238; //  R/W     0x00000078
        static const uint32_t PINMUX_AUX_BUTTON_SLIDE_SW_0 = 0x323c; //  R/W     0x00000078
        static const uint32_t PINMUX_AUX_BUTTON_HOME_0     = 0x3240; //  R/W     0x00000078
        static const uint32_t PINMUX_AUX_GPIO_PA6_0 = 0x3244; // R/W     0x00000030
        static const uint32_t PINMUX_AUX_GPIO_PE6_0 = 0x3248; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PE7_0 = 0x324c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PH6_0 = 0x3250; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PK0_0 = 0x3254; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PK1_0 = 0x3258; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PK2_0 = 0x325c; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PK3_0 = 0x3260; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PK4_0 = 0x3264; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PK5_0 = 0x3268; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PK6_0 = 0x326c; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PK7_0 = 0x3270; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PL0_0 = 0x3274; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PL1_0 = 0x3278; // R/W     0x00006074
        static const uint32_t PINMUX_AUX_GPIO_PZ0_0 = 0x327c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PZ1_0 = 0x3280; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PZ2_0 = 0x3284; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PZ3_0 = 0x3288; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PZ4_0 = 0x328c; // R/W     0x00000074
        static const uint32_t PINMUX_AUX_GPIO_PZ5_0 = 0x3290; // R/W     0x00000074
    
    
    private:
};

#endif //PINMUX_CONTROLLER_H
