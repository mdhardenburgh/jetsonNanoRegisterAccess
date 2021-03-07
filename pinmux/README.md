# Pinmux and Pad control options

This datasheet is a little hard to understand, like every other paragraph
was written by a different person who only skimmed the last sentence of 
of the previous paragraph. So I tried my best to sythesize it into something I 
could more easily understand and hopefully this helps others too.
  
## Section 9.5 first, Pad Controls.
  
Most MPIO pads have thier own per pad controls (which lives in the pinmux
register) and control group per pad, however some MPIO pads are 
grouped into control groups and dont have thier own per pad controls, and 
some have a combination thereof. All ST (STandard MPIO pad) and DD (Dual 
Driver MPIO pad) pads have thier own indvidiual control group except for the ST_EMMC pads. 
For example, GPIO_PE6 gets its own per pad controls and control group, 9.15.144
lists that pad's per pad register fields at address offset 0x3248 and 21.1.4.61
lists that pad control group register fields at adderss offset 0x9c8.
GPIO_PE6 does not have the DRV_TYPE listed in it's per pad register field,
and instead has DRVDN and DRVUP listed in it's pad control group register
fields. 
 
### Pad Controls
 
Per Pad Options from Table 25. Register Descriptions are in 9.15.                                           
| Control              | Description                                                                          |
| ---------------------|------------------------------------------------------------------------------------- |
| PUPD                 | Internal Pull up, pull down option                                                   |
| TRISTATE_CONTROL     | Enable tristate or High Impedance(Z). Effectivly disables the output diriver         |
| DPD_PARKING_CONTROL  | Keeps the state of the pin through deep sleep                                        |
| E_INPUT              | Enable or disable input reciever                                                     |
| E_LDPR               | Enable or disable base drivers                                                       |
| E_OD                 | Turn your jetson into a brick                                                        |
| E_IO_HV              | Enable or disable "high" voltage IO mode. Send and recieve 3.3V logic.               |
| E_HSM                | Enable or disable high speed mode. For SPI or I2C.                                   |
| SCHMT                | Enable or disable the Schmitt trigger.                                               |
| DRV_TYPE[1:0]        | Enables different combination of impedance code mapping for the pads                 |
|                                                                                                             |
| Per Control Group options from 9.5.2. Register Descriptions are in 9.5.2, 21.1.2 and 21.1.4.4 to 21.1.4.157 |
|                                                                                                             |
| DRVDN/UP             | Drive Down / Up. Driver Output Pull-Up/Pull-Down drive strength code.                |
| SLWR/ SLWF           | Slew Falling / Rising. Driver Output Pull-Up/Pull-Down slew control code.            |

### Register map for the pinmux registers from 9.15. Base address is 0x70000000.
These pinmux registers contain the per pad controls. 

| Section  | Name                            | Offset | Read/Write | Reset      |
| ---------|---------------------------------|--------|------------|----------- | 
| 9.15.1   | PINMUX_AUX_SDMMC1_CLK_0         | 0x3000 | R/W        | 0x00002074 |
| 9.15.2   | PINMUX_AUX_SDMMC1_CMD_0         | 0x3004 | R/W        | 0x00002078 |
| 9.15.3   | PINMUX_AUX_SDMMC1_DAT3_0        | 0x3008 | R/W        | 0x00002078 |
| 9.15.4   | PINMUX_AUX_SDMMC1_DAT2_0        | 0x300c | R/W        | 0x00002078 | 
| 9.15.5   | PINMUX_AUX_SDMMC1_DAT1_0        | 0x3010 | R/W        | 0x00002078 | 
| 9.15.6   | PINMUX_AUX_SDMMC1_DAT0_0        | 0x3014 | R/W        | 0x00002078 | 
| 9.15.7   | PINMUX_AUX_SDMMC3_CLK_0         | 0x301c | R/W        | 0x00002074 |
| 9.15.8   | PINMUX_AUX_SDMMC3_CMD_0         | 0x3020 | R/W        | 0x00002078 |
| 9.15.9   | PINMUX_AUX_SDMMC3_DAT0_0        | 0x3024 | R/W        | 0x00002078 |
| 9.15.10  | PINMUX_AUX_SDMMC3_DAT1_0        | 0x3028 | R/W        | 0x00002078 |
| 9.15.11  | PINMUX_AUX_SDMMC3_DAT2_0        | 0x302c | R/W        | 0x00002078 |
| 9.15.12  | PINMUX_AUX_SDMMC3_DAT3_0        | 0x3030 | R/W        | 0x00002078 |
| 9.15.13  | PINMUX_AUX_PEX_L0_RST_N_0       | 0x3038 | R/W        | 0x00000460 |
| 9.15.14  | PINMUX_AUX_PEX_L0_CLKREQ_N_0    | 0x303c | R/W        | 0x00000470 |
| 9.15.15  | PINMUX_AUX_PEX_WAKE_N_0         | 0x3040 | R/W        | 0x00000470 |
| 9.15.16  | PINMUX_AUX_PEX_L1_RST_N_0       | 0x3044 | R/W        | 0x00000460 |
| 9.15.17  | PINMUX_AUX_PEX_L1_CLKREQ_N_0    | 0x3048 | R/W        | 0x00000470 |
| 9.15.18  | PINMUX_AUX_SATA_LED_ACTIVE_0    | 0x304c | R/W        | 0x00000060 |
| 9.15.19  | PINMUX_AUX_SPI1_MOSI_0          | 0x3050 | R/W        | 0x0000e074 | 
| 9.15.20  | PINMUX_AUX_SPI1_MISO_0          | 0x3054 | R/W        | 0x0000e074 |
| 9.15.21  | PINMUX_AUX_SPI1_SCK_0           | 0x3058 | R/W        | 0x0000e074 | 
| 9.15.22  | PINMUX_AUX_SPI1_CS0_0           | 0x305c | R/W        | 0x0000e078 | 
| 9.15.23  | PINMUX_AUX_SPI1_CS1_0           | 0x3060 | R/W        | 0x0000e078 |
| 9.15.24  | PINMUX_AUX_SPI2_MOSI_0          | 0x3064 | R/W        | 0x00006074 |
| 9.15.25  | PINMUX_AUX_SPI2_MISO_0          | 0x3068 | R/W        | 0x00006074 | 
| 9.15.26  | PINMUX_AUX_SPI2_SCK_0           | 0x306c | R/W        | 0x00006074 |
| 9.15.27  | PINMUX_AUX_SPI2_CS0_0           | 0x3070 | R/W        | 0x00006078 |
| 9.15.28  | PINMUX_AUX_SPI2_CS1_0           | 0x3074 | R/W        | 0x00006078 |
| 9.15.29  | PINMUX_AUX_SPI4_MOSI_0          | 0x3078 | R/W        | 0x0000e074 |
| 9.15.30  | PINMUX_AUX_SPI4_MISO_0          | 0x307c | R/W        | 0x0000e074 |
| 9.15.31  | PINMUX_AUX_SPI4_SCK_0           | 0x3080 | R/W        | 0x0000e074 |
| 9.15.32  | PINMUX_AUX_SPI4_CS0_0           | 0x3084 | R/W        | 0x0000e078 |
| 9.15.33  | PINMUX_AUX_QSPI_SCK_0           | 0x3088 | R/W        | 0x00003078 |
| 9.15.34  | PINMUX_AUX_QSPI_CS_N_0          | 0x308c | R/W        | 0x00003078 |
| 9.15.35  | PINMUX_AUX_QSPI_IO0_0           | 0x3090 | R/W        | 0x00003078 |
| 9.15.36  | PINMUX_AUX_QSPI_IO1_0           | 0x3094 | R/W        | 0x00003078 |
| 9.15.37  | PINMUX_AUX_QSPI_IO2_0           | 0x3098 | R/W        | 0x00003078 |
| 9.15.38  | PINMUX_AUX_QSPI_IO3_0           | 0x309c | R/W        | 0x00003078 |
| 9.15.39  | PINMUX_AUX_DMIC1_CLK_0          | 0x30a4 | R/W        | 0x00000074 |
| 9.15.40  | PINMUX_AUX_DMIC1_DAT_0          | 0x30a8 | R/W        | 0x00000074 |
| 9.15.41  | PINMUX_AUX_DMIC2_CLK_0          | 0x30ac | R/W        | 0x00000074 |
| 9.15.42  | PINMUX_AUX_DMIC2_DAT_0          | 0x30b0 | R/W        | 0x00000074 |
| 9.15.43  | PINMUX_AUX_DMIC3_CLK_0          | 0x30b4 | R/W        | 0x00000074 |
| 9.15.44  | PINMUX_AUX_DMIC3_DAT_0          | 0x30b8 | R/W        | 0x00000074 |
| 9.15.45  | PINMUX_AUX_GEN1_I2C_SCL_0       | 0x30bc | R/W        | 0x00000570 |
| 9.15.46  | PINMUX_AUX_GEN1_I2C_SDA_0       | 0x30c0 | R/W        | 0x00000570 |
| 9.15.47  | PINMUX_AUX_GEN2_I2C_SCL_0       | 0x30c4 | R/W        | 0x00000572 | 
| 9.15.48  | PINMUX_AUX_GEN2_I2C_SDA_0       | 0x30c8 | R/W        | 0x00000572 |
| 9.15.49  | PINMUX_AUX_GEN3_I2C_SCL_0       | 0x30cc | R/W        | 0x00000570 |
| 9.15.50  | PINMUX_AUX_GEN3_I2C_SDA_0       | 0x30d0 | R/W        | 0x00000570 |
| 9.15.51  | PINMUX_AUX_CAM_I2C_SCL_0        | 0x30d4 | R/W        | 0x00000570 |
| 9.15.52  | PINMUX_AUX_CAM_I2C_SDA_0        | 0x30d8 | R/W        | 0x00000570 |
| 9.15.53  | PINMUX_AUX_PWR_I2C_SCL_0        | 0x30dc | R/W        | 0x00000170 | 
| 9.15.54  | PINMUX_AUX_PWR_I2C_SDA_0        | 0x30e0 | R/W        | 0x00000170 |
| 9.15.54  | PINMUX_AUX_UART1_TX_0           | 0x30e4 | R/W        | 0x00000074 |
| 9.15.56  | PINMUX_AUX_UART1_RX_0           | 0x30e8 | R/W        | 0x00000074 | 
| 9.15.57  | PINMUX_AUX_UART1_RTS_0          | 0x30ec | R/W        | 0x00000074 |
| 9.15.58  | PINMUX_AUX_UART1_CTS_0          | 0x30f0 | R/W        | 0x00000074 |
| 9.15.59  | PINMUX_AUX_UART2_TX_0           | 0x30f4 | R/W        | 0x00000074 |
| 9.15.60  | PINMUX_AUX_UART2_RX_0           | 0x30f8 | R/W        | 0x00000078 |
| 9.15.61  | PINMUX_AUX_UART2_RTS_0          | 0x30fc | R/W        | 0x00000074 |
| 9.15.62  | PINMUX_AUX_UART2_CTS_0          | 0x3100 | R/W        | 0x00000074 |
| 9.15.63  | PINMUX_AUX_UART3_TX_0           | 0x3104 | R/W        | 0x00000074 |
| 9.15.64  | PINMUX_AUX_UART3_RX_0           | 0x3108 | R/W        | 0x00000074 |
| 9.15.65  | PINMUX_AUX_UART3_RTS_0          | 0x310c | R/W        | 0x00000074 |
| 9.15.66  | PINMUX_AUX_UART3_CTS_0          | 0x3110 | R/W        | 0x00000078 |
| 9.15.67  | PINMUX_AUX_UART4_TX_0           | 0x3114 | R/W        | 0x00000074 |
| 9.15.68  | PINMUX_AUX_UART4_RX_0           | 0x3118 | R/W        | 0x00000074 |
| 9.15.69  | PINMUX_AUX_UART4_RTS_0          | 0x311c | R/W        | 0x00000074 |
| 9.15.70  | PINMUX_AUX_UART4_CTS_0          | 0x3120 | R/W        | 0x00000074 |
| 9.15.71  | PINMUX_AUX_DAP1_FS_0            | 0x3124 | R/W        | 0x00006074 |
| 9.15.72  | PINMUX_AUX_DAP1_DIN_0           | 0x3128 | R/W        | 0x00006074 |
| 9.15.73  | PINMUX_AUX_DAP1_DOUT_0          | 0x312c | R/W        | 0x00006074 | 
| 9.15.74  | PINMUX_AUX_DAP1_SCLK_0          | 0x3130 | R/W        | 0x00006074 | 
| 9.15.75  | PINMUX_AUX_DAP2_FS_0            | 0x3134 | R/W        | 0x00006074 |
| 9.15.76  | PINMUX_AUX_DAP2_DIN_0           | 0x3138 | R/W        | 0x00006074 |
| 9.15.77  | PINMUX_AUX_DAP2_DOUT_0          | 0x313c | R/W        | 0x00006074 |
| 9.15.78  | PINMUX_AUX_DAP2_SCLK_0          | 0x3140 | R/W        | 0x00006074 |
| 9.15.79  | PINMUX_AUX_DAP4_FS_0            | 0x3144 | R/W        | 0x00000074 |
| 9.15.80  | PINMUX_AUX_DAP4_DIN_0           | 0x3148 | R/W        | 0x00000074 |
| 9.15.81  | PINMUX_AUX_DAP4_DOUT_0          | 0x314c | R/W        | 0x00000074 |
| 9.15.82  | PINMUX_AUX_DAP4_SCLK_0          | 0x3150 | R/W        | 0x00000074 |
| 9.15.83  | PINMUX_AUX_CAM1_MCLK_0          | 0x3154 | R/W        | 0x00000074 |
| 9.15.84  | PINMUX_AUX_CAM2_MCLK_0          | 0x3158 | R/W        | 0x00000074 |
| 9.15.85  | PINMUX_AUX_JTAG_RTCK_0          | 0x315c | R/W        | 0x00000068 |
| 9.15.86  | PINMUX_AUX_CLK_32K_IN_0         | 0x3160 | R/W        | 0x00000000 |
| 9.15.87  | PINMUX_AUX_CLK_32K_OUT_0        | 0x3164 | R/W        | 0x00000074 | 
| 9.15.88  | PINMUX_AUX_BATT_BCL_0           | 0x3168 | R/W        | 0x00000570 | 
| 9.15.89  | PINMUX_AUX_CLK_REQ_0            | 0x316c | R/W        | 0x00000040 |
| 9.15.90  | PINMUX_AUX_CPU_PWR_REQ_0        | 0x3170 | R/W        | 0x00000040 |
| 9.15.91  | PINMUX_AUX_PWR_INT_N_0          | 0x3174 | R/W        | 0x00000040 | 
| 9.15.92  | PINMUX_AUX_SHUTDOWN_0           | 0x3178 | R/W        | 0x00000040 |
| 9.15.93  | PINMUX_AUX_CORE_PWR_REQ_0       | 0x317c | R/W        | 0x00000040 |
| 9.15.94  | PINMUX_AUX_AUD_MCLK_0           | 0x3180 | R/W        | 0x00000074 |
| 9.15.95  | PINMUX_AUX_DVFS_PWM_0           | 0x3184 | R/W        | 0x00000074 |
| 9.15.96  | PINMUX_AUX_DVFS_CLK_0           | 0x3188 | R/W        | 0x00000078 |
| 9.15.97  | PINMUX_AUX_GPIO_X1_AUD_0        | 0x318c | R/W        | 0x00000074 |
| 9.15.98  | PINMUX_AUX_GPIO_X3_AUD_0        | 0x3190 | R/W        | 0x00000078 |
| 9.15.99  | PINMUX_AUX_GPIO_PCC7_0          | 0x3194 | R/W        | 0x00000570 |
| 9.15.100 | PINMUX_AUX_HDMI_CEC_0           | 0x3198 | R/W        | 0x00000570 |
| 9.15.101 | PINMUX_AUX_HDMI_INT_DP_HPD_0    | 0x319c | R/W        | 0x00000574 |
| 9.15.102 | PINMUX_AUX_SPDIF_OUT_0          | 0x31a0 | R/W        | 0x00000078 |
| 9.15.103 | PINMUX_AUX_SPDIF_IN_0           | 0x31a4 | R/W        | 0x00000074 |
| 9.15.104 | PINMUX_AUX_USB_VBUS_EN0_0       | 0x31a8 | R/W        | 0x00000560 |
| 9.15.105 | PINMUX_AUX_USB_VBUS_EN1_0       | 0x31ac | R/W        | 0x00000560 |
| 9.15.106 | PINMUX_AUX_DP_HPD0_0            | 0x31b0 | R/W        | 0x00000074 |
| 9.15.107 | PINMUX_AUX_WIFI_EN_0            | 0x31b4 | R/W        | 0x00000074 |
| 9.15.108 | PINMUX_AUX_WIFI_RST_0           | 0x31b8 | R/W        | 0x00000074 |
| 9.15.109 | PINMUX_AUX_WIFI_WAKE_AP_0       | 0x31bc | R/W        | 0x00000074 |
| 9.15.110 | PINMUX_AUX_AP_WAKE_BT_0         | 0x31c0 | R/W        | 0x00000074 |
| 9.15.111 | PINMUX_AUX_BT_RST_0             | 0x31c4 | R/W        | 0x00000074 |
| 9.15.112 | PINMUX_AUX_BT_WAKE_AP_0         | 0x31c8 | R/W        | 0x00000074 |
| 9.15.113 | PINMUX_AUX_AP_WAKE_NFC_0        | 0x31cc | R/W        | 0x00000074 | 
| 9.15.114 | PINMUX_AUX_NFC_EN_0             | 0x31d0 | R/W        | 0x00000074 |
| 9.15.115 | PINMUX_AUX_NFC_INT_0            | 0x31d4 | R/W        | 0x00000074 |
| 9.15.116 | PINMUX_AUX_GPS_EN_0             | 0x31d8 | R/W        | 0x00000074 |
| 9.15.117 | PINMUX_AUX_GPS_RST_0            | 0x31dc | R/W        | 0x00000074 |
| 9.15.118 | PINMUX_AUX_CAM_RST_0            | 0x31e0 | R/W        | 0x00000074 |
| 9.15.119 | PINMUX_AUX_CAM_AF_EN_0          | 0x31e4 | R/W        | 0x00000074 |
| 9.15.120 | PINMUX_AUX_CAM_FLASH_EN_0       | 0x31e8 | R/W        | 0x00000074 | 
| 9.15.121 | PINMUX_AUX_CAM1_PWDN_0          | 0x31ec | R/W        | 0x00000074 |
| 9.15.122 | PINMUX_AUX_CAM2_PWDN_0          | 0x31f0 | R/W        | 0x00000074 |
| 9.15.123 | PINMUX_AUX_CAM1_STROBE_0        | 0x31f4 | R/W        | 0x00000074 |
| 9.15.124 | PINMUX_AUX_LCD_TE_0             | 0x31f8 | R/W        | 0x00000074 |
| 9.15.125 | PINMUX_AUX_LCD_BL_PWM_0         | 0x31fc | R/W        | 0x00000074 |
| 9.15.126 | PINMUX_AUX_LCD_BL_EN_0          | 0x3200 | R/W        | 0x00000074 |
| 9.15.127 | PINMUX_AUX_LCD_RST_0            | 0x3204 | R/W        | 0x00000074 |
| 9.15.128 | PINMUX_AUX_LCD_GPIO1_0          | 0x3208 | R/W        | 0x00000074 | 
| 9.15.129 | PINMUX_AUX_LCD_GPIO2_0          | 0x320c | R/W        | 0x00000074 |
| 9.15.130 | PINMUX_AUX_AP_READY_0           | 0x3210 | R/W        | 0x00000074 |
| 9.15.131 | PINMUX_AUX_TOUCH_RST_0          | 0x3214 | R/W        | 0x00000074 |
| 9.15.132 | PINMUX_AUX_TOUCH_CLK_0          | 0x3218 | R/W        | 0x00000074 | 
| 9.15.133 | PINMUX_AUX_MODEM_WAKE_AP_0      | 0x321c | R/W        | 0x00000074 |
| 9.15.134 | PINMUX_AUX_TOUCH_INT_0          | 0x3220 | R/W        | 0x00000074 |
| 9.15.135 | PINMUX_AUX_MOTION_INT_0         | 0x3224 | R/W        | 0x00000074 |
| 9.15.136 | PINMUX_AUX_ALS_PROX_INT_0       | 0x3228 | R/W        | 0x00000074 |
| 9.15.137 | PINMUX_AUX_TEMP_ALERT_0         | 0x322c | R/W        | 0x00000074 |
| 9.15.138 | PINMUX_AUX_BUTTON_POWER_ON_0    | 0x3230 | R/W        | 0x00000078 |
| 9.15.139 | PINMUX_AUX_BUTTON_VOL_UP_0      | 0x3234 | R/W        | 0x00000078 |
| 9.15.140 | PINMUX_AUX_BUTTON_VOL_DOWN_0    | 0x3238 | R/W        | 0x00000078 |
| 9.15.141 | PINMUX_AUX_BUTTON_SLIDE_SW_0    | 0x323c | R/W        | 0x00000078 |
| 9.15.142 | PINMUX_AUX_BUTTON_HOME_0        | 0x3240 | R/W        | 0x00000078 |
| 9.15.143 | PINMUX_AUX_GPIO_PA6_0           | 0x3244 | R/W        | 0x00000030 |
| 9.15.144 | PINMUX_AUX_GPIO_PE6_0           | 0x3248 | R/W        | 0x00000074 |
| 9.15.145 | PINMUX_AUX_GPIO_PE7_0           | 0x324c | R/W        | 0x00000074 |
| 9.15.146 | PINMUX_AUX_GPIO_PH6_0           | 0x3250 | R/W        | 0x00000074 |
| 9.15.147 | PINMUX_AUX_GPIO_PK0_0           | 0x3254 | R/W        | 0x00006074 |
| 9.15.148 | PINMUX_AUX_GPIO_PK1_0           | 0x3258 | R/W        | 0x00006074 |
| 9.15.149 | PINMUX_AUX_GPIO_PK2_0           | 0x325c | R/W        | 0x00006074 |
| 9.15.150 | PINMUX_AUX_GPIO_PK3_0           | 0x3260 | R/W        | 0x00006074 |
| 9.15.151 | PINMUX_AUX_GPIO_PK4_0           | 0x3264 | R/W        | 0x00006074 |
| 9.15.152 | PINMUX_AUX_GPIO_PK5_0           | 0x3268 | R/W        | 0x00006074 |
| 9.15.153 | PINMUX_AUX_GPIO_PK6_0           | 0x326c | R/W        | 0x00006074 |
| 9.15.154 | PINMUX_AUX_GPIO_PK7_0           | 0x3270 | R/W        | 0x00006074 |
| 9.15.155 | PINMUX_AUX_GPIO_PL0_0           | 0x3274 | R/W        | 0x00006074 |
| 9.15.156 | PINMUX_AUX_GPIO_PL1_0           | 0x3278 | R/W        | 0x00006074 |
| 9.15.157 | PINMUX_AUX_GPIO_PZ0_0           | 0x327c | R/W        | 0x00000074 |
| 9.15.158 | PINMUX_AUX_GPIO_PZ1_0           | 0x3280 | R/W        | 0x00000074 |
| 9.15.159 | PINMUX_AUX_GPIO_PZ2_0           | 0x3284 | R/W        | 0x00000074 |
| 9.15.160 | PINMUX_AUX_GPIO_PZ3_0           | 0x3288 | R/W        | 0x00000074 | 
| 9.15.161 | PINMUX_AUX_GPIO_PZ4_0           | 0x328c | R/W        | 0x00000074 |
| 9.15.162 | PINMUX_AUX_GPIO_PZ5_0           | 0x3290 | R/W        | 0x00000074 |

### Register map for the pinmux registers from 21.1.4.4 to 21.1.4.144. Base address is 0x70000000.
These registers contain the per pad group controls. 

| Section    | Name                            | Offset | Read/Write | Reset      |
|------------|---------------------------------|--------|------------|------------| 
| 21.1.4.4   | ALS_PROX_INT_CFG                | 0x8e4  | R/W        | 0x00000000 |
