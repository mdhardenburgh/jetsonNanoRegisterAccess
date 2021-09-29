/**
 * From Table 1 System Address Map on page 21 - 22 of the TX1 TRM.
 * GPIO-1, GPIO-2, GPIO-3, etc... coresponds to the GPIO bank with the lettered ports as
 * seen in Table 32 from the TX1 TRM.
 * ______________________________________________________________________________________
 * Description | Address Start | Address End | Offset Start | Offset End | Default Length
 * GPIO-1      | 6000:d000     | 6000:d0ff   | 0000:d000    | 0000:d0ff  | 256 B
 * GPIO-2      | 6000:d100     | 6000:d1ff   | 0000:d100    | 0000:d1ff  | 256 B
 * GPIO-3      | 6000:d200     | 6000:d2ff   | 0000:d200    | 0000:d2ff  | 256 B
 * GPIO-4      | 6000:d300     | 6000:d3ff   | 0000:d300    | 0000:d3ff  | 256 B
 * GPIO-5      | 6000:d400     | 6000:d4ff   | 0000:d400    | 0000:d4ff  | 256 B
 * GPIO-6      | 6000:d500     | 6000:d5ff   | 0000:d500    | 0000:d5ff  | 256 B
 * GPIO-7      | 6000:d600     | 6000:d6ff   | 0000:d600    | 0000:d6ff  | 256 B
 * GPIO-8      | 6000:d700     | 6000:d7ff   | 0000:d700    | 0000:d7ff  | 256 B
 *
 * From Table 3.3 on page 17 in the Jetson Nano Dev Kit Carrier Board pdf
 * _______________________________________________________________________________________________________________________________________
 * Header Pin # | Module Pin Name | Module Pin Number | Tegra Pin Name | Default Usage    | Alternate Function         | Tegra GPIO Port #
 * 3            | I2C1_SDA        | 191               | GEN2_I2C_SDA   | I2C #1 Data      | GPIO                       | PJ.03
 * 5            | I2C1_SCL        | 189               | GEN2_I2C_SCL   | I2C #1 Clock     | GPIO                       | PJ.02
 * 7            | GPIO09          | 211               | AUD_MCLK       | GPIO             | Audio Master Clock         | PBB.00
 * 8            | UART1_TXD       | 203               | UART2_TXD      | UART #1 Transmit | GPIO                       | PG.00
 * 10           | UART1_RXD       | 205               | UART2_RXD      | UART #1 Receive  | GPIO                       | PG.01
 * 11           | UART1_RTS*      | 207               | UART2_RTS      | GPIO             | UART #2 Request to Send    | PG.02
 * 12           | I2S0_SCLK       | 199               | DAP4_SCLK      | GPIO             | Audio I2S #0 Clock         | PJ.07
 * 13           | SPI1_SCK        | 106               | SPI2_SCK       | GPIO             | SPI #1 Shift Clock         | PB.06
 * 15           | GPIO12          | 218               | LCD_TE         | GPIO             | –                          | PY.02
 * 16           | SPI1_CSI1*      | 112               | SPI2_CS1       | GPIO             | SPI #1 Chip Select #1      | PDD.00
 * 18           | SPI1_CSI0*      | 110               | SPI2_CS0       | GPIO             | SPI #0 Chip Select #0      | PB.07
 * 19           | SPI0_MOSI       | 89                | SPI1_MOSI      | GPIO             | SPI #0 Master Out/Slave In | PC.00 
 * 21           | SPI0_MISO       | 93                | SPI1_MISO      | GPIO             | SPI #0 Master In/Slave Out | PC.01
 * 22           | SPI1_MISO       | 108               | SPI2_MISO      | GPIO             | SPI #1 Master In/Slave Out | PB.05
 * 23           | SPI0_SCK        | 91                | SPI1_SCK       | GPIO             | SPI #0 Shift Clock         | PC.02
 * 24           | SPI0_CS0*       | 95                | SPI1_CS0       | GPIO             | SPI #0 Chip Select #0      | PC.03
 * 26           | SPI0_CS1*       | 97                | SPI1_CS1       | GPIO             | SPI #0 Chip Select #1      | PC.01
 * 27           | I2C0_SDA        | 187               | GEN1_I2C_SDA   | I2C #0 Data      | GPIO                       | PB.05
 * 28           | I2C0_SCL        | 185               | GEN1_I2C_SCL   | I2C #0 Clock     | GPIO                       | PC.02
 * 29           | GPIO01          | 118               | CAM_AF_EN      | GPIO             | Camera MCLK #2             | PC.03
 * 31           | GPIO11          | 216               | GPIO_PZ0       | GPIO             | Camera MCLK #3             | PZ.00
 * 32           | GPIO07          | 206               | LCD_BL_PWM     | GPIO             | PWM                        | PV.00
 * 33           | GPIO13          | 228               | GPIO_PE6       | GPIO             | PWM                        | PE.06
 * 35           | I2S0_FS         | 197               | DAP4_FS        | GPIO             | Audio I2S #0 Field Select  | PJ.04
 * 36           | UART1_CTS*      | 209               | UART2_CTS      | GPIO             | UART #1 Clear to Send      | PG.03
 * 37           | SPI1_MOSI       | 104               | SPI2_MOSI      | GPIO             | SPI #1 Master Out/Slave In | PB.04
 * 38           | I2S0_DIN        | 195               | DAP4_DIN       | GPIO             | Audio I2S #0 Data in       | PJ.05
 * 40           | I2S0_DOUT       | 193               | DAP4_DOUT      | GPIO             | Audio I2S #0 Data Out      | PJ.06
 *
 * From Table 32: GPIO Register Address Map on page 247 of the TX1 TRM. Each GPIO control bank has 32 GPIOs.
 * 
 * Each port (A, B, C, D, etc...) has 8 GPIO pins associated with it. So port A has the pins PA.00, PA.01, PA.02, PA.03, PA.04,
 * PA.05, PA.06, and PA.07. This is the same for every port. As you can see in the above table the pin PE.06 is at default a 
 * GPIO (with alternate function of PWM). This GPIO coresponds the the physical Tegra pin pad GPIO_PE6, the pysical jetson 
 * module pin 228, and that module pin has the name GPIO13. That module pin is connected to the GPIO header on the carrier
 * board, and it is pin 33. E is found within GPIO Controller 2, so the Controller2 offset address must be used.
 * E is the zeroth element (of ABCD, EFGH, ect). 
 * A command to set the GPIO/SPIO mode of J41-pin33 to GPIO mode:
 * myGpioController2.setRegisterField(GPIO_CNF_0_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_0_RMW::BIT_6_baseBit, GPIO_CNF_0_RMW::BIT_6_bitWidth); 
 * _____________________________________________________________________________________________________
 * Register Name                | Offset (Lower: Read-Modify-Write) | Offset (Upper: Per-Pin Mask Write)
 * GPIO Controller 1 – Port     | A   | B   | C   | D               | A   | B   | C   | D 
 * GPIO_CNF_[A/B/C/D]           | 000 | 004 | 008 | 00C             | 080 | 084 | 088 | 08C
 * GPIO_OE_[A/B/C/D]            | 010 | 014 | 018 | 01C             | 090 | 094 | 098 | 09C
 * GPIO_OUT_[A/B/C/D]           | 020 | 024 | 028 | 02C             | 0A0 | 0A4 | 0A8 | 0AC
 * GPIO_IN_[A/B/C/D]            | 030 | 034 | 038 | 03C             | --- | --- | --- | ---
 * GPIO_INT_STA_[A/B/C/D]       | 040 | 044 | 048 | 04C             | 0C0 | 0C4 | 0C8 | 0CC
 * GPIO_INT_ENB_[A/B/C/D]       | 050 | 054 | 058 | 05C             | 0D0 | 0D4 | 0D8 | 0DC
 * GPIO_INT_LVL_[A/B/C/D]       | 060 | 064 | 068 | 06C             | 0E0 | 0E4 | 0E8 | 0EC
 * GPIO_INT_CLR_[A/B/C/D]       | 070 | 074 | 078 | 07C             | --- | --- | --- | ---
 * GPIO_DB_CTRL_[A/B/C/D]_0     | --- | --- | --- | ---             | 0B0 | 0B4 | 0B8 | 0BC
 * GPIO_DB_CNT _[A/B/C/D]_0     | --- | --- | --- | ---             | 0F0 | 0F4 | 0F8 | 0FC
 * GPIO Controller 2 – Port     | E   | F   | G   | H               | E   | F   | G   | H 
 * GPIO_CNF_[E/F/G/H]           | 100 | 104 | 108 | 10C             | 180 | 184 | 188 | 18C 
 * GPIO_OE_[E/F/G/H]            | 110 | 114 | 118 | 11C             | 190 | 194 | 198 | 19C
 * GPIO_OUT_[E/F/G/H]           | 120 | 124 | 128 | 12C             | 1A0 | 1A4 | 1A8 | 1AC
 * GPIO_IN_[E/F/G/H]            | 130 | 134 | 138 | 13C             | --- | --- | —-- | —-- 
 * GPIO_INT_STA_[E/F/G/H]       | 140 | 144 | 148 | 14C             | 1C0 | 1C4 | 1C8 | 1CC
 * GPIO_INT_ENB_[E/F/G/H]       | 150 | 154 | 158 | 15C             | 1D0 | 1D4 | 1D8 | 1DC
 * GPIO_INT_LVL_[E/F/G/H]       | 160 | 164 | 168 | 16C             | 1E0 | 1E4 | 1E8 | 1EC
 * GPIO_INT_CLR_[E/F/G/H]       | 170 | 174 | 178 | 17C             | -—- | -—- | -—- | -—-
 * GPIO_DB_CTRL_[E/F/G/H]_0     | -—- | -—- | -—- | -—-             | 1B0 | 1B4 | 1B8 | 1BC
 * GPIO_DB_CNT _[E/F/G/H]_0     | -—- | -—- | -—- | -—-             | 1F0 | 1F4 | 1F8 | 1FC
 * GPIO Controller 3 – Port     | I   | J   | K   | L               | I   | J   | K   | L 
 * GPIO_CNF_[I/J/K/L]           | 200 | 204 | 208 | 20C             | 280 | 284 | 288 | 28C
 * GPIO_OE_[I/J/K/L]            | 210 | 214 | 218 | 21C             | 290 | 294 | 298 | 29C
 * GPIO_OUT_[I/J/K/L]           | 220 | 224 | 228 | 22C             | 2A0 | 2A4 | 2A8 | 2AC
 * GPIO_IN_[I/J/K/L]            | 230 | 234 | 238 | 23C             | ——- | ——- | ——- | ——-
 * GPIO_INT_STA_[I/J/K/L]       | 240 | 244 | 248 | 24C             | 2C0 | 2C4 | 2C8 | 2CC
 * GPIO_INT_ENB_[I/J/K/L]       | 250 | 254 | 258 | 25C             | 2D0 | 2D4 | 2D8 | 2DC
 * GPIO_INT_LVL_[I/J/K/L]       | 260 | 264 | 268 | 26C             | 2E0 | 2E4 | 2E8 | 2EC
 * GPIO_INT_CLR_[I/J/K/L]       | 270 | 274 | 278 | 27C             | ——- | ——- | ——- | -——
 * GPIO_DB_CTRL_[I/J/K/L]_0     | ——- | -—— | -—— | -——             | 2B0 | 2B4 | 2B8 | 2BC
 * GPIO_DB_CNT _[I/J/K/L]_0     | -—— | —-— | -—— | -——             | 2F0 | 2F4 | 2F8 | 2FC
 * GPIO Controller 4 – Port     | M   | N   | O   | P               | M   | N   | O   | P
 * GPIO_CNF_[M/N/O/P]           | 300 | 304 | 308 | 30C             | 380 | 384 | 388 | 38C
 * GPIO_OE_[M/N/O/P]            | 310 | 314 | 318 | 31C             | 390 | 394 | 398 | 39C
 * GPIO_OUT_[M/N/O/P]           | 320 | 324 | 328 | 32C             | 3A0 | 3A4 | 3A8 | 3AC
 * GPIO_IN_[M/N/O/P]            | 330 | 334 | 338 | 33C             | —-- | -—- | -—- | -—-
 * GPIO_INT_STA_[M/N/O/P]       | 340 | 344 | 348 | 34C             | 3C0 | 3C4 | 3C8 | 3CC
 * GPIO_INT_ENB_[M/N/O/P]       | 350 | 354 | 358 | 35C             | 3D0 | 3D4 | 3D8 | 3DC
 * GPIO_INT_LVL_[M/N/O/P]       | 360 | 364 | 368 | 36C             | 3E0 | 3E4 | 3E8 | 3EC
 * GPIO_INT_CLR_[M/N/O/P]       | 370 | 374 | 378 | 37C             | -—- | -—- | -—- | -—-
 * GPIO_DB_CTRL_[M/N/O/P]_0     | -—- | -—- | -—- | -—-             | 3B0 | 3B4 | 3B8 | 3BC
 * GPIO_DB_CNT _[M/N/O/P]_0     | -—- | -—— | -—- | -—-             | 3F0 | 3F4 | 3F8 | 3FC
 * GPIO Controller 5 – Port     | Q   | R   | S   | T               | Q   | R   | S   | T
 * GPIO_CNF_[Q/R/S/T]           | 400 | 404 | 408 | 40C             | 480 | 484 | 488 | 48C
 * GPIO_OE_[Q/R/S/T]            | 410 | 414 | 418 | 41C             | 490 | 494 | 498 | 49C
 * GPIO_OUT_[Q/R/S/T]           | 420 | 424 | 428 | 42C             | 4A0 | 4A4 | 4A8 | 4AC
 * GPIO_IN_[Q/R/S/T]            | 430 | 434 | 438 | 43C             | —-- | -—- | -—- | -—-
 * GPIO_INT_STA_[Q/R/S/T]       | 440 | 444 | 448 | 44C             | 4C0 | 4C4 | 4C8 | 4CC
 * GPIO_INT_ENB_[Q/R/S/T]       | 450 | 454 | 458 | 45C             | 4D0 | 4D4 | 4D8 | 4DC
 * GPIO_INT_LVL_[Q/R/S/T]       | 460 | 464 | 468 | 46C             | 4E0 | 4E4 | 4E8 | 4EC
 * GPIO_INT_CLR_[Q/R/S/T]       | 470 | 474 | 478 | 47C             | -—- | -—- | -—- | -—-
 * GPIO_DB_CTRL_[Q/R/S/T]_0     | -—- | -—- | -—- | -—-             | 4B0 | 4B4 | 4B8 | 4BC
 * GPIO_DB_CNT _[Q/R/S/T]_0     | —-- | -—- | -—- | -—-             | 4F0 | 4F4 | 4F8 | 4FC
 * GPIO Controller 6 – Port     | U   | V   | W   | X               | U   | V   | W   | X
 * GPIO_CNF_[U/V/W/X]           | 500 | 504 | 508 | 50C             | 580 | 584 | 588 | 58C
 * GPIO_OE_[U/V/W/X]            | 510 | 514 | 518 | 51C             | 590 | 594 | 598 | 59C
 * GPIO_OUT_[U/V/W/X]           | 520 | 524 | 528 | 52C             | 5A0 | 5A4 | 5A8 | 5AC
 * GPIO_IN_[U/V/W/X]            | 530 | 534 | 538 | 53C             | -—- | -—- | -—- | -—-
 * GPIO_INT_STA_[U/V/W/X]       | 540 | 544 | 548 | 54C             | 5C0 | 5C4 | 5C8 | 5CC
 * GPIO_INT_ENB_[U/V/W/X]       | 550 | 554 | 558 | 55C             | 5D0 | 5D4 | 5D8 | 5DC
 * GPIO_INT_LVL_[U/V/W/X]       | 560 | 564 | 568 | 56C             | 5E0 | 5E4 | 5E8 | 5EC
 * GPIO_INT_CLR_[U/V/W/X]       | 570 | 574 | 578 | 57C             | -—- | -—- | -—- | -—-
 * GPIO_DB_CTRL_[U/V/W/X]_0     | —-- | -—- | -—- | -—-             | 5B0 | 5B4 | 5B8 | 5BC
 * GPIO_DB_CNT _[U/V/W/X]_0     | —-- | -—- | -—- | -—-             | 5F0 | 5F4 | 5F8 | 5FC
 * GPIO Controller 7 – Port     | Y   | Z   | AA  | BB              | Y   | Z   | AA  | BB
 * GPIO_CNF_[Y/Z/AA/BB]         | 600 | 604 | 608 | 60C             | 680 | 684 | 688 | 68C
 * GPIO_OE_[Y/Z/AA/BB]          | 610 | 614 | 618 | 61C             | 690 | 694 | 698 | 69C
 * GPIO_OUT_[Y/Z/AA/BB]         | 620 | 624 | 628 | 62C             | 6A0 | 6A4 | 6A8 | 6AC
 * GPIO_IN_[Y/Z/AA/BB]          | 630 | 634 | 638 | 63C             | -—- | -—- | -—- | -—- 
 * GPIO_INT_STA_[Y/Z/AA/BB]     | 640 | 644 | 648 | 64C             | 6C0 | 6C4 | 6C8 | 6CC
 * GPIO_INT_ENB_[Y/Z/AA/BB]     | 650 | 654 | 658 | 65C             | 6D0 | 6D4 | 6D8 | 6DC
 * GPIO_INT_LVL_[Y/Z/AA/BB]     | 660 | 664 | 668 | 66C             | 6E0 | 6E4 | 6E8 | 6EC
 * GPIO_INT_CLR_[Y/Z/AA/BB]     | 670 | 674 | 678 | 67C             | -—- | -—- | -—- | -—-
 * GPIO_DB_CTRL_[Y/Z/AA/BB]_0   | —-- | -—- | -—- | -—-             | 6B0 | 6B4 | 6B8 | 6BC
 * GPIO_DB_CNT _[Y/Z/AA/BB]_0   | -—- | -—- | -—- | -—-             | 6F0 | 6F4 | 6F8 | 6FC
 * GPIO Controller 8 – Port     | CC  | DD  | EE  | ---             | CC  | DD  | EE  | ---
 * GPIO_CNF_[CC/DD/EE/-]        | 700 | 704 | 708 | -—-             | 780 | 784 | 788 | -—-
 * GPIO_OE_[CC/DD/EE/-]         | 710 | 714 | 718 | —--             | 790 | 794 | 798 | —--
 * GPIO_OUT_[CC/DD/EE/-]        | 720 | 724 | 728 | —--             | 7A0 | 7A4 | 7A8 | —--
 * GPIO_IN_[CC/DD/EE/-]         | 730 | 734 | 738 | —--             | —-- | -—- | -—- | -—-
 * GPIO_INT_STA_[CC/DD/EE/-]    | 740 | 744 | 748 | ---             | 7C0 | 7C4 | 7C8 | ---
 * GPIO_INT_ENB_[CC/DD/EE/-]    | 750 | 754 | 758 | ---             | 7D0 | 7D4 | 7D8 | ---
 * GPIO_INT_LVL_[CC/DD/EE/-]    | 760 | 764 | 768 | ---             | 7E0 | 7E4 | 7E8 | ---
 * GPIO_INT_CLR_[CC/DD/EE/-]    | 770 | 774 | 778 | -—-             | -—- | -—- | -—- | -—- 
 * GPIO_DB_CTRL_[CC/DD/EE/-]_0  | -—- | -—- | -—- | -—-             | 7B0 | 7B4 | 7B8 | -—-
 * GPIO_DB_CNT _[CC/DD/EE/-]_0  | -—- | -—- | -—- | -—-             | 7F0 | 7F4 | 7F8 | -—-
 * 
 */ 
struct gpioController{
    static const uint32_t gpioController1BaseAddress = 0x6000d000;
    static const uint32_t gpioController2BaseAddress = 0x6000d100;
    static const uint32_t gpioController3BaseAddress = 0x6000d200;
    static const uint32_t gpioController4BaseAddress = 0x6000d300;
    static const uint32_t gpioController5BaseAddress = 0x6000d400;
    static const uint32_t gpioController6BaseAddress = 0x6000d500;
    static const uint32_t gpioController7BaseAddress = 0x6000d600;
    static const uint32_t gpioController8BaseAddress = 0x6000d700;
     
    static const uint32_t LOCK_BIT_DISABLE = 0;
    static const uint32_t LOCK_BIT_ENABLE = 1;
     
    static const uint32_t BIT_N_SPIO = 0;
    static const uint32_t BIT_N_GPIO = 1;
     
    static const uint32_t BIT_N_TRI_STATE = 0;
    static const uint32_t BIT_N_DRIVEN = 1;
     
    static const uint32_t BIT_N_LOW = 0;
    static const uint32_t BIT_N_HIGH = 1;
     
    static const uint32_t BIT_N_INACTIVE = 0;
    static const uint32_t BIT_N_ACTIVE = 1;
     
    static const uint32_t BIT_N_DISABLE = 0;
    static const uint32_t BIT_N_ENABLE = 1;
     
    static const uint32_t DELTA_BIT_N_DISABLE = 0;
    static const uint32_t DELTA_BIT_N_ENABLE = 1; // 1 means Trigger Interrupt on ANY change of input if EDGE is TRUE
     
    static const uint32_t EDGE_BIT_N_DISABLE = 0;
    static const uint32_t EDGE_BIT_N_ENABLE = 1; // 1 means Configure as Edge-Triggered Interrupt
     
    static const uint32_t BIT_N_SET = 0;
    static const uint32_t BIT_N_CLEAR = 1;
     
    static const uint32_t MSK_BIT_N_DISABLE = 0;
    static const uint32_t MSK_BIT_N_ENABLE = 1;
     
    //ABC being the associtated port A through EE
    static const uint32_t MSK_PORT_ABC_DBC_EN_BIT_N_DISABLE = 0;
    static const uint32_t MSK_PORT_ABC_DBC_EN_BIT_N_ENABLE = 1;
    
    static const uint32_t PORT_ABC_DBC_EN_BIT_N_LOW = 0;
    static const uint32_t PORT_ABC_DBC_EN_BIT_N_HIGH = 1;
};

// GPIO Controller 1 – Start Addr 6000:d000

/**
 * 9.13.1 GPIO_CNF_0 
 *
 * Designates whether each pin operates as a GPIO or as an SFIO. By default all 
 * pins come up in SFIO mode. These can be programmed to GPIO mode at any stage.
 *
 * Lock bits are used to control the access to the CNF and OE registers. When 
 * set, no one can write to the CNF and OE bits. They can be programmed ONLY 
 * during Boot and get reset by chip reset only.
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_CNF_0_RMW
{
    static const uint32_t addressOffset = 0x000;

    static const uint32_t LOCK_7_baseBit  = 15;
    static const uint32_t LOCK_7_bitWidth = 1;
   
    static const uint32_t LOCK_6_baseBit  = 14;
    static const uint32_t LOCK_6_bitWidth = 1;
     
    static const uint32_t LOCK_5_baseBit  = 13;
    static const uint32_t LOCK_5_bitWidth = 1;

    static const uint32_t LOCK_4_baseBit  = 12;
    static const uint32_t LOCK_4_bitWidth = 1;
     
    static const uint32_t LOCK_3_baseBit  = 11;
    static const uint32_t LOCK_3_bitWidth = 1;
     
    static const uint32_t LOCK_2_baseBit  = 10;
    static const uint32_t LOCK_2_bitWidth = 1;

    static const uint32_t LOCK_1_baseBit  = 9;
    static const uint32_t LOCK_1_bitWidth = 1;
     
    static const uint32_t LOCK_0_baseBit  = 8;
    static const uint32_t LOCK_0_bitWidth = 1;
 
    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_CNF_1_RMW
{
    static const uint32_t addressOffset = 0x004;

    static const uint32_t LOCK_7_baseBit = 15;
    static const uint32_t LOCK_7_bitWidth = 1;

    static const uint32_t LOCK_6_baseBit = 14;
    static const uint32_t LOCK_6_bitWidth = 1;

    static const uint32_t LOCK_5_baseBit = 13;
    static const uint32_t LOCK_5_bitWidth = 1;

    static const uint32_t LOCK_4_baseBit = 12;
    static const uint32_t LOCK_4_bitWidth = 1;

    static const uint32_t LOCK_3_baseBit = 11;
    static const uint32_t LOCK_3_bitWidth = 1;

    static const uint32_t LOCK_2_baseBit = 10;
    static const uint32_t LOCK_2_bitWidth = 1;

    static const uint32_t LOCK_1_baseBit = 9;
    static const uint32_t LOCK_1_bitWidth = 1;

    static const uint32_t LOCK_0_baseBit = 8;
    static const uint32_t LOCK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_CNF_2_RMW
{
    static const uint32_t addressOffset = 0x008;

    static const uint32_t LOCK_7_baseBit = 15;
    static const uint32_t LOCK_7_bitWidth = 1;

    static const uint32_t LOCK_6_baseBit = 14;
    static const uint32_t LOCK_6_bitWidth = 1;

    static const uint32_t LOCK_5_baseBit = 13;
    static const uint32_t LOCK_5_bitWidth = 1;

    static const uint32_t LOCK_4_baseBit = 12;
    static const uint32_t LOCK_4_bitWidth = 1;

    static const uint32_t LOCK_3_baseBit = 11;
    static const uint32_t LOCK_3_bitWidth = 1;

    static const uint32_t LOCK_2_baseBit = 10;
    static const uint32_t LOCK_2_bitWidth = 1;

    static const uint32_t LOCK_1_baseBit = 9;
    static const uint32_t LOCK_1_bitWidth = 1;

    static const uint32_t LOCK_0_baseBit = 8;
    static const uint32_t LOCK_0_bitWidth = 1;
     
    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_CNF_3_RMW
{
    static const uint32_t addressOffset = 0x00C;

    static const uint32_t LOCK_7_baseBit = 15;
    static const uint32_t LOCK_7_bitWidth = 1;

    static const uint32_t LOCK_6_baseBit = 14;
    static const uint32_t LOCK_6_bitWidth = 1;

    static const uint32_t LOCK_5_baseBit = 13;
    static const uint32_t LOCK_5_bitWidth = 1;

    static const uint32_t LOCK_4_baseBit = 12;
    static const uint32_t LOCK_4_bitWidth = 1;

    static const uint32_t LOCK_3_baseBit = 11;
    static const uint32_t LOCK_3_bitWidth = 1;

    static const uint32_t LOCK_2_baseBit = 10;
    static const uint32_t LOCK_2_bitWidth = 1;

    static const uint32_t LOCK_1_baseBit = 9;
    static const uint32_t LOCK_1_bitWidth = 1;

    static const uint32_t LOCK_0_baseBit = 8;
    static const uint32_t LOCK_0_bitWidth = 1;
 
    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;
    
};

/**
 * 9.13.2 GPIO_OE_0
 *
 * GPIO mode (GPIO_CNF.x=1) must be true for this condition to be valid.
 * 
 * The set of registers below are used to either drive the signal out or as an 
 * Input. This needs to be programmed depending upon whether the pin needs to 
 * be in either Input or Output.
 * 
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_OE_0_RMW
{
    static const uint32_t addressOffset = 0x010;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_OE_1_RMW
{
    static const uint32_t addressOffset = 0x014;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_OE_2_RMW
{
    static const uint32_t addressOffset = 0x018;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_OE_3_RMW
{
    static const uint32_t addressOffset = 0x01C;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.3 GPIO_OUT_0
 *
 * GPIO_CNF.x=1 (in GPIO mode) AND GPIO_OE.x=1 (GPIO output enabled) must be 
 * true for this to be valid. This register will take affect only in GPIO 
 * mode. This register is used to drive the value out on a given pin.
 * 
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_OUT_0_RMW
{
    static const uint32_t addressOffset = 0x020;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_OUT_1_RMW
{
    static const uint32_t addressOffset = 0x024;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_OUT_2_RMW
{
    static const uint32_t addressOffset = 0x028;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_OUT_3_RMW
{
    static const uint32_t addressOffset = 0x02C;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.4 GPIO_IN_0
 *
 * GPIO mode (GPIO_CNF.x=1) must be true for this condition to be valid. This 
 * is a read-only register used to read the value from the pin. This is an 
 * array of 4 identical register entries; the register fields below apply to each entry.
 */

struct GPIO_IN_0_RMW
{
    static const uint32_t addressOffset = 0x030;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_IN_1_RMW
{
    static const uint32_t addressOffset = 0x034;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_IN_2_RMW
{
    static const uint32_t addressOffset = 0x038;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_IN_3_RMW
{
    static const uint32_t addressOffset = 0x03C;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * All GPIO inputs can be independently programmed to generate an interrupt 
 * request.
 * 
 * In addition, the individual trigger level for interrupt on each input pin 
 * can be programmed as either active-on-high or active-on-low. For example, to 
 * program an active-on-high interrupt on baseBit 3 of GPIO-PORT_C, write '1' into 
 * baseBit 3 of GPIO_INT.LVL.C register (this sets the interrupt to be 
 * active-on-high), and then write '1' into baseBit 3 of GPIO_INT.ENB.C (this 
 * enables interrupt on the named bit).
 *
 * The interrupt flag status can be read in the appropriate baseBit of the 
 * GPIO_INT.STA.C register. Once the programmed interrupt occurs, status should 
 * be cleared by writing into the appropriate baseBit of the GPIO_INT.CLR.C 
 * register. Note that the interrupt thus generated is routed to the processor 
 * only if the corresponding baseBit for GPIO interrupts in the Secondary interrupt
 *  controller is enabled.
 */

/**
 * 9.13.5 GPIO_INT_STA_0
 *
 * GPIO mode (GPIO_CNF.x=1) and GPIO_INT.ENB.x=1 must be true for this condition 
 * to be valid. Every GPIO pin generates an Interrupt when switching from 
 * Low-High to High-Low. Interrupt status for each port is saved in an 
 * Interrupt status register.
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_INT_STATUS_0_RMW
{
    static const uint32_t addressOffset = 0x040;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_STATUS_1_RMW
{
    static const uint32_t addressOffset = 0x044;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_STATUS_2_RMW
{
    static const uint32_t addressOffset = 0x048;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_STATUS_3_RMW
{
    static const uint32_t addressOffset = 0x04C;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.6 GPIO_INT_ENB_0
 *
 * Every baseBit of the GPIO pin has an enable which, when enabled, routes the 
 * Interrupt to the Interrupt controller. This is an array of 4 identical 
 * register entries; the register fields below apply to each entry.
 */

struct GPIO_INT_ENB_0
{
    static const uint32_t addressOffset = 0x050;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_ENB_1
{
    static const uint32_t addressOffset = 0x054;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_ENB_2
{
    static const uint32_t addressOffset = 0x058;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_ENB_3
{
    static const uint32_t addressOffset = 0x05C;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.7 GPIO_INT_LVL_0
 *
 * The GPIO can detect an interrupt for any edge- or level-sensitive signal.
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry
 */

struct GPIO_INT_LEVEL_0_RMW
{
    static const uint32_t addressOffset = 0x060;

    static const uint32_t DELTA_7_baseBit = 23;
    static const uint32_t DELTA_7_bitWidth = 1;

    static const uint32_t DELTA_6_baseBit = 22;
    static const uint32_t DELTA_6_bitWidth = 1;
 
    static const uint32_t DELTA_5_baseBit = 21;
    static const uint32_t DELTA_5_bitWidth = 1;
  
    static const uint32_t DELTA_4_baseBit = 20;
    static const uint32_t DELTA_4_bitWidth = 1;
   
    static const uint32_t DELTA_3_baseBit = 19;
    static const uint32_t DELTA_3_bitWidth = 1;
     
    static const uint32_t DELTA_2_baseBit = 18;
    static const uint32_t DELTA_2_bitWidth = 1;
      
    static const uint32_t DELTA_1_baseBit = 17;
    static const uint32_t DELTA_1_bitWidth = 1;
       
    static const uint32_t DELTA_0_baseBit = 16;
    static const uint32_t DELTA_0_bitWidth = 1;

    static const uint32_t EDGE_7_baseBit = 15;
    static const uint32_t EDGE_7_bitWidth = 1;
         
    static const uint32_t EDGE_6_baseBit = 14;
    static const uint32_t EDGE_6_bitWidth = 1;
          
    static const uint32_t EDGE_5_baseBit = 13;
    static const uint32_t EDGE_5_bitWidth = 1;
           
    static const uint32_t EDGE_4_baseBit = 12;
    static const uint32_t EDGE_4_bitWidth = 1;
            
    static const uint32_t EDGE_3_baseBit = 11;
    static const uint32_t EDGE_3_bitWidth = 1;
             
    static const uint32_t EDGE_2_baseBit = 10;
    static const uint32_t EDGE_2_bitWidth = 1;
              
    static const uint32_t EDGE_1_baseBit = 9;
    static const uint32_t EDGE_1_bitWidth = 1;
               
    static const uint32_t EDGE_0_baseBit = 8;
    static const uint32_t EDGE_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_LEVEL_1_RMW
{
    static const uint32_t addressOffset = 0x064;

    static const uint32_t DELTA_7_baseBit = 23;
    static const uint32_t DELTA_7_bitWidth = 1;

    static const uint32_t DELTA_6_baseBit = 22;
    static const uint32_t DELTA_6_bitWidth = 1;
 
    static const uint32_t DELTA_5_baseBit = 21;
    static const uint32_t DELTA_5_bitWidth = 1;
  
    static const uint32_t DELTA_4_baseBit = 20;
    static const uint32_t DELTA_4_bitWidth = 1;
   
    static const uint32_t DELTA_3_baseBit = 19;
    static const uint32_t DELTA_3_bitWidth = 1;
    
    static const uint32_t DELTA_2_baseBit = 18;
    static const uint32_t DELTA_2_bitWidth = 1;
      
    static const uint32_t DELTA_1_baseBit = 17;
    static const uint32_t DELTA_1_bitWidth = 1;
       
    static const uint32_t DELTA_0_baseBit = 16;
    static const uint32_t DELTA_0_bitWidth = 1;
        
    static const uint32_t EDGE_7_baseBit = 15;
    static const uint32_t EDGE_7_bitWidth = 1;
         
    static const uint32_t EDGE_6_baseBit = 14;
    static const uint32_t EDGE_6_bitWidth = 1;
          
    static const uint32_t EDGE_5_baseBit = 13;
    static const uint32_t EDGE_5_bitWidth = 1;
           
    static const uint32_t EDGE_4_baseBit = 12;
    static const uint32_t EDGE_4_bitWidth = 1;
            
    static const uint32_t EDGE_3_baseBit = 11;
    static const uint32_t EDGE_3_bitWidth = 1;
             
    static const uint32_t EDGE_2_baseBit = 10;
    static const uint32_t EDGE_2_bitWidth = 1;
              
    static const uint32_t EDGE_1_baseBit = 9;
    static const uint32_t EDGE_1_bitWidth = 1;
               
    static const uint32_t EDGE_0_baseBit = 8;
    static const uint32_t EDGE_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_LEVEL_2_RMW
{
    static const uint32_t addressOffset = 0x068;

    static const uint32_t DELTA_7_baseBit = 23;
    static const uint32_t DELTA_7_bitWidth = 1;

    static const uint32_t DELTA_6_baseBit = 22;
    static const uint32_t DELTA_6_bitWidth = 1;
 
    static const uint32_t DELTA_5_baseBit = 21;
    static const uint32_t DELTA_5_bitWidth = 1;
  
    static const uint32_t DELTA_4_baseBit = 20;
    static const uint32_t DELTA_4_bitWidth = 1;
   
    static const uint32_t DELTA_3_baseBit = 19;
    static const uint32_t DELTA_3_bitWidth = 1;
     
    static const uint32_t DELTA_2_baseBit = 18;
    static const uint32_t DELTA_2_bitWidth = 1;
      
    static const uint32_t DELTA_1_baseBit = 17;
    static const uint32_t DELTA_1_bitWidth = 1;
       
    static const uint32_t DELTA_0_baseBit = 16;
    static const uint32_t DELTA_0_bitWidth = 1;
        
    static const uint32_t EDGE_7_baseBit = 15;
    static const uint32_t EDGE_7_bitWidth = 1;
         
    static const uint32_t EDGE_6_baseBit = 14;
    static const uint32_t EDGE_6_bitWidth = 1;
          
    static const uint32_t EDGE_5_baseBit = 13;
    static const uint32_t EDGE_5_bitWidth = 1;
           
    static const uint32_t EDGE_4_baseBit = 12;
    static const uint32_t EDGE_4_bitWidth = 1;
            
    static const uint32_t EDGE_3_baseBit = 11;
    static const uint32_t EDGE_3_bitWidth = 1;
             
    static const uint32_t EDGE_2_baseBit = 10;
    static const uint32_t EDGE_2_bitWidth = 1;
              
    static const uint32_t EDGE_1_baseBit = 9;
    static const uint32_t EDGE_1_bitWidth = 1;
              
    static const uint32_t EDGE_0_baseBit = 8;
    static const uint32_t EDGE_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_LEVEL_3_RMW
{
    static const uint32_t addressOffset = 0x06C;

    static const uint32_t DELTA_7_baseBit = 23;
    static const uint32_t DELTA_7_bitWidth = 1;

    static const uint32_t DELTA_6_baseBit = 22;
    static const uint32_t DELTA_6_bitWidth = 1;
 
    static const uint32_t DELTA_5_baseBit = 21;
    static const uint32_t DELTA_5_bitWidth = 1;
  
    static const uint32_t DELTA_4_baseBit = 20;
    static const uint32_t DELTA_4_bitWidth = 1;
   
    static const uint32_t DELTA_3_baseBit = 19;
    static const uint32_t DELTA_3_bitWidth = 1;
     
    static const uint32_t DELTA_2_baseBit = 18;
    static const uint32_t DELTA_2_bitWidth = 1;
    
    static const uint32_t DELTA_1_baseBit = 17;
    static const uint32_t DELTA_1_bitWidth = 1;
       
    static const uint32_t DELTA_0_baseBit = 16;
    static const uint32_t DELTA_0_bitWidth = 1;
        
    static const uint32_t EDGE_7_baseBit = 15;
    static const uint32_t EDGE_7_bitWidth = 1;
         
    static const uint32_t EDGE_6_baseBit = 14;
    static const uint32_t EDGE_6_bitWidth = 1;
          
    static const uint32_t EDGE_5_baseBit = 13;
    static const uint32_t EDGE_5_bitWidth = 1;
    
    static const uint32_t EDGE_4_baseBit = 12;
    static const uint32_t EDGE_4_bitWidth = 1;
         
    static const uint32_t EDGE_3_baseBit = 11;
    static const uint32_t EDGE_3_bitWidth = 1;
    
    static const uint32_t EDGE_2_baseBit = 10;
    static const uint32_t EDGE_2_bitWidth = 1;
    
    static const uint32_t EDGE_1_baseBit = 9;
    static const uint32_t EDGE_1_bitWidth = 1;
    
    static const uint32_t EDGE_0_baseBit = 8;
    static const uint32_t EDGE_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.8 GPIO_INT_CLR_0
 * 
 * This write-only register clears the Interrupts that are set. This is valid 
 * only in GPIO mode when GPIO_INT.ENB is set.
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_INT_CLEAR_0_RMW
{
    static const uint32_t addressOffset = 0x070;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_CLEAR_1_RMW
{
    static const uint32_t addressOffset = 0x074;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_CLEAR_2_RMW
{
    static const uint32_t addressOffset = 0x078;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_INT_CLEAR_3_RMW
{
    static const uint32_t addressOffset = 0x07C;

    const uint32_t BIT_7_baseBit = 7;
    const uint32_t BIT_7_bitWidth = 1;

    const uint32_t BIT_6_baseBit = 6;
    const uint32_t BIT_6_bitWidth = 1;

    const uint32_t BIT_5_baseBit = 5;
    const uint32_t BIT_5_bitWidth = 1;

    const uint32_t BIT_4_baseBit = 4;
    const uint32_t BIT_4_bitWidth = 1;

    const uint32_t BIT_3_baseBit = 3;
    const uint32_t BIT_3_bitWidth = 1;

    const uint32_t BIT_2_baseBit = 2;
    const uint32_t BIT_2_bitWidth = 1;

    const uint32_t BIT_1_baseBit = 1;
    const uint32_t BIT_1_bitWidth = 1;

    const uint32_t BIT_0_baseBit = 0;
    const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.9 GPIO_MSK_CNF_0
 *
 * Each register is provided with an individual 16-baseBit version for enabling 
 * Masked Writes to avoid a Read-Modify-Write operation by the firmware. The 
 * exception is for the interrupt clear register, whose functionality is 
 * combined in the interrupt status register. Individual pins only can be 
 * programmed by suitably enabling the write masks in the upper byte of these 
 * 16-baseBit registers.
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_MSK_CNF_0
{
    static const uint32_t addressOffset = 0x080;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
     
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
   
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
    
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
   
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
   
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
    
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
    
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_CNF_1
{
    static const uint32_t addressOffset = 0x084;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
    
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
          
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
      
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
         
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
         
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
           
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
          
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_CNF_2
{
    static const uint32_t addressOffset = 0x088;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
         
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
          
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
         
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
        
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
            
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
         
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
          
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_CNF_3
{
    static const uint32_t addressOffset = 0x08C;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
     
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
       
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
     
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
    
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
         
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
           
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
              
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.10 GPIO_MSK_OE_0
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_MSK_OE_0
{
    static const uint32_t addressOffset = 0x090;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
         
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
          
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
           
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
            
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
             
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
             
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
            
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_OE_1
{
    static const uint32_t addressOffset = 0x094;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
         
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
          
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
         
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
         
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
           
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
            
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
            
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_OE_2
{
    static const uint32_t addressOffset = 0x098;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
       
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
   
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
  
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
 
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
   
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
   
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
  
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_OE_3
{
    static const uint32_t addressOffset = 0x09C;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
   
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
  
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
  
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
  
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
   
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
  
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
  
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.11 GPIO_MSK_OUT_0
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_MSK_OUT_0
{
    static const uint32_t addressOffset = 0x0A0;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
 
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
  
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
    
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
    
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
    
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
    
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
   
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_OUT_1
{
    static const uint32_t addressOffset = 0x0A4;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
     
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
  
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
   
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
  
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
  
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
   
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
   
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_OUT_2
{
    static const uint32_t addressOffset = 0x0A8;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
     
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
   
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
 
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
 
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
 
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
    
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_OUT_3
{
    static const uint32_t addressOffset = 0x0AC;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
 
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
 
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
   
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
  
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
   
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
 
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
 
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.12 GPIO_DB_CTRL_P0_0
 */
struct GPIO_DB_CTRL_P0
{
    static const uint32_t addressOffset = 0x0B0;

    static const uint32_t MSK_PA_DBC_EN_7_baseBit = 15;
    static const uint32_t MSK_PA_DBC_EN_7_bitWidth = 1;
        
    static const uint32_t MSK_PA_DBC_EN_6_baseBit = 14;
    static const uint32_t MSK_PA_DBC_EN_6_bitWidth = 1;
          
    static const uint32_t MSK_PA_DBC_EN_5_baseBit = 13;
    static const uint32_t MSK_PA_DBC_EN_5_bitWidth = 1;
        
    static const uint32_t MSK_PA_DBC_EN_4_baseBit = 12;
    static const uint32_t MSK_PA_DBC_EN_4_bitWidth = 1;
         
    static const uint32_t MSK_PA_DBC_EN_3_baseBit = 11;
    static const uint32_t MSK_PA_DBC_EN_3_bitWidth = 1;
          
    static const uint32_t MSK_PA_DBC_EN_2_baseBit = 10;
    static const uint32_t MSK_PA_DBC_EN_2_bitWidth = 1;
           
    static const uint32_t MSK_PA_DBC_EN_1_baseBit = 9;
    static const uint32_t MSK_PA_DBC_EN_1_bitWidth = 1;
            
    static const uint32_t MSK_PA_DBC_EN_0_baseBit = 8;
    static const uint32_t MSK_PA_DBC_EN_0_bitWidth = 1;

    static const uint32_t PA_DBC_EN_7_baseBit = 7;
    static const uint32_t PA_DBC_EN_7_bitWidth = 1;

    static const uint32_t PA_DBC_EN_6_baseBit = 6;
    static const uint32_t PA_DBC_EN_6_bitWidth = 1;

    static const uint32_t PA_DBC_EN_5_baseBit = 5;
    static const uint32_t PA_DBC_EN_5_bitWidth = 1;

    static const uint32_t PA_DBC_EN_4_baseBit = 4;
    static const uint32_t PA_DBC_EN_4_bitWidth = 1;

    static const uint32_t PA_DBC_EN_3_baseBit = 3;
    static const uint32_t PA_DBC_EN_3_bitWidth = 1;

    static const uint32_t PA_DBC_EN_2_baseBit = 2;
    static const uint32_t PA_DBC_EN_2_bitWidth = 1;

    static const uint32_t PA_DBC_EN_1_baseBit = 1;
    static const uint32_t PA_DBC_EN_1_bitWidth = 1;

    static const uint32_t PA_DBC_EN_0_baseBit = 0;
    static const uint32_t PA_DBC_EN_0_bitWidth = 1;

};

// 9.13.13 GPIO_DB_CTRL_P1_0
struct GPIO_DB_CTRL_P1
{
    static const uint32_t addressOffset = 0x0B4;

    static const uint32_t MSK_PB_DBC_EN_7_baseBit = 15;
    static const uint32_t MSK_PB_DBC_EN_7_bitWidth = 1;
     
    static const uint32_t MSK_PB_DBC_EN_6_baseBit = 14;
    static const uint32_t MSK_PB_DBC_EN_6_bitWidth = 1;
      
    static const uint32_t MSK_PB_DBC_EN_5_baseBit = 13;
    static const uint32_t MSK_PB_DBC_EN_5_bitWidth = 1;
       
    static const uint32_t MSK_PB_DBC_EN_4_baseBit = 12;
    static const uint32_t MSK_PB_DBC_EN_4_bitWidth = 1;
        
    static const uint32_t MSK_PB_DBC_EN_3_baseBit = 11;
    static const uint32_t MSK_PB_DBC_EN_3_bitWidth = 1;
         
    static const uint32_t MSK_PB_DBC_EN_2_baseBit = 10;
    static const uint32_t MSK_PB_DBC_EN_2_bitWidth = 1;
          
    static const uint32_t MSK_PB_DBC_EN_1_baseBit = 9;
    static const uint32_t MSK_PB_DBC_EN_1_bitWidth = 1;
           
    static const uint32_t MSK_PB_DBC_EN_0_baseBit = 8;
    static const uint32_t MSK_PB_DBC_EN_0_bitWidth = 1;

    static const uint32_t PB_DBC_EN_7_baseBit = 7;
    static const uint32_t PB_DBC_EN_7_bitWidth = 1;

    static const uint32_t PB_DBC_EN_6_baseBit = 6;
    static const uint32_t PB_DBC_EN_6_bitWidth = 1;

    static const uint32_t PB_DBC_EN_5_baseBit = 5;
    static const uint32_t PB_DBC_EN_5_bitWidth = 1;

    static const uint32_t PB_DBC_EN_4_baseBit = 4;
    static const uint32_t PB_DBC_EN_4_bitWidth = 1;

    static const uint32_t PB_DBC_EN_3_baseBit = 3;
    static const uint32_t PB_DBC_EN_3_bitWidth = 1;

    static const uint32_t PB_DBC_EN_2_baseBit = 2;
    static const uint32_t PB_DBC_EN_2_bitWidth = 1;

    static const uint32_t PB_DBC_EN_1_baseBit = 1;
    static const uint32_t PB_DBC_EN_1_bitWidth = 1;

    static const uint32_t PB_DBC_EN_0_baseBit = 0;
    static const uint32_t PB_DBC_EN_0_bitWidth = 1;

};

// 9.13.14 GPIO_DB_CTRL_P2_0
struct GPIO_DB_CTRL_P2
{
    static const uint32_t addressOffset = 0x0B8;

    static const uint32_t MSK_PC_DBC_EN_7_baseBit = 15;
    static const uint32_t MSK_PC_DBC_EN_7_bitWidth = 1;
   
    static const uint32_t MSK_PC_DBC_EN_6_baseBit = 14;
    static const uint32_t MSK_PC_DBC_EN_6_bitWidth = 1;
     
    static const uint32_t MSK_PC_DBC_EN_5_baseBit = 13;
    static const uint32_t MSK_PC_DBC_EN_5_bitWidth = 1;
      
    static const uint32_t MSK_PC_DBC_EN_4_baseBit = 12;
    static const uint32_t MSK_PC_DBC_EN_4_bitWidth = 1;
      
    static const uint32_t MSK_PC_DBC_EN_3_baseBit = 11;
    static const uint32_t MSK_PC_DBC_EN_3_bitWidth = 1;
       
    static const uint32_t MSK_PC_DBC_EN_2_baseBit = 10;
    static const uint32_t MSK_PC_DBC_EN_2_bitWidth = 1;
        
    static const uint32_t MSK_PC_DBC_EN_1_baseBit = 9;
    static const uint32_t MSK_PC_DBC_EN_1_bitWidth = 1;
          
    static const uint32_t MSK_PC_DBC_EN_0_baseBit = 8;
    static const uint32_t MSK_PC_DBC_EN_0_bitWidth = 1;

    static const uint32_t PC_DBC_EN_7_baseBit = 7;
    static const uint32_t PC_DBC_EN_7_bitWidth = 1;

    static const uint32_t PC_DBC_EN_6_baseBit = 6;
    static const uint32_t PC_DBC_EN_6_bitWidth = 1;

    static const uint32_t PC_DBC_EN_5_baseBit = 5;
    static const uint32_t PC_DBC_EN_5_bitWidth = 1;

    static const uint32_t PC_DBC_EN_4_baseBit = 4;
    static const uint32_t PC_DBC_EN_4_bitWidth = 1;

    static const uint32_t PC_DBC_EN_3_baseBit = 3;
    static const uint32_t PC_DBC_EN_3_bitWidth = 1;

    static const uint32_t PC_DBC_EN_2_baseBit = 2;
    static const uint32_t PC_DBC_EN_2_bitWidth = 1;

    static const uint32_t PC_DBC_EN_1_baseBit = 1;
    static const uint32_t PC_DBC_EN_1_bitWidth = 1;

    static const uint32_t PC_DBC_EN_0_baseBit = 0;
    static const uint32_t PC_DBC_EN_0_bitWidth = 1;

};

// 9.13.15 GPIO_DB_CTRL_P3_0
struct GPIO_DB_CTRL_P3
{
    static const uint32_t addressOffset = 0x0BC;

    static const uint32_t MSK_PD_DBC_EN_7_baseBit = 15;
    static const uint32_t MSK_PD_DBC_EN_7_bitWidth = 1;
     
    static const uint32_t MSK_PD_DBC_EN_6_baseBit = 14;
    static const uint32_t MSK_PD_DBC_EN_6_bitWidth = 1;
     
    static const uint32_t MSK_PD_DBC_EN_5_baseBit = 13;
    static const uint32_t MSK_PD_DBC_EN_5_bitWidth = 1;
      
    static const uint32_t MSK_PD_DBC_EN_4_baseBit = 12;
    static const uint32_t MSK_PD_DBC_EN_4_bitWidth = 1;
     
    static const uint32_t MSK_PD_DBC_EN_3_baseBit = 11;
    static const uint32_t MSK_PD_DBC_EN_3_bitWidth = 1;
       
    static const uint32_t MSK_PD_DBC_EN_2_baseBit = 10;
    static const uint32_t MSK_PD_DBC_EN_2_bitWidth = 1;
        
    static const uint32_t MSK_PD_DBC_EN_1_baseBit = 9;
    static const uint32_t MSK_PD_DBC_EN_1_bitWidth = 1;
         
    static const uint32_t MSK_PD_DBC_EN_0_baseBit = 8;
    static const uint32_t MSK_PD_DBC_EN_0_bitWidth = 1;

    static const uint32_t PD_DBC_EN_7_baseBit = 7;
    static const uint32_t PD_DBC_EN_7_bitWidth = 1;

    static const uint32_t PD_DBC_EN_6_baseBit = 6;
    static const uint32_t PD_DBC_EN_6_bitWidth = 1;

    static const uint32_t PD_DBC_EN_5_baseBit = 5;
    static const uint32_t PD_DBC_EN_5_bitWidth = 1;

    static const uint32_t PD_DBC_EN_4_baseBit = 4;
    static const uint32_t PD_DBC_EN_4_bitWidth = 1;

    static const uint32_t PD_DBC_EN_3_baseBit = 3;
    static const uint32_t PD_DBC_EN_3_bitWidth = 1;

    static const uint32_t PD_DBC_EN_2_baseBit = 2;
    static const uint32_t PD_DBC_EN_2_bitWidth = 1;

    static const uint32_t PD_DBC_EN_1_baseBit = 1;
    static const uint32_t PD_DBC_EN_1_bitWidth = 1;

    static const uint32_t PD_DBC_EN_0_baseBit = 0;
    static const uint32_t PD_DBC_EN_0_bitWidth = 1;

};

/**
 * 9.13.16 GPIO_MSK_INT_STA_0
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_MSK_INT_STATUS_0
{
    static const uint32_t addressOffset = 0x0C0;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
 
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
   
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
    
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
   
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
   
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
 
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
      
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_STATUS_1
{
    static const uint32_t addressOffset = 0x0C4;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
    
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
     
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
      
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
     
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
       
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
        
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
         
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_STATUS_2
{
    static const uint32_t addressOffset = 0x0C8;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
      
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
      
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
       
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
        
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
         
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
           
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
          
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_STATUS_3
{
    static const uint32_t addressOffset = 0x0CC;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
  
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
     
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
     
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
      
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
       
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
        
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
         
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.17 GPIO_MSK_INT_ENB_0
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_MSK_INT_ENB_0
{
    static const uint32_t addressOffset = 0x0D0;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
  
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
 
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
  
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
   
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
    
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
   
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
    
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_ENB_1
{
    static const uint32_t addressOffset = 0x0D4;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
 
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
  
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
  
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
    
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
    
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
     
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
     
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_ENB_2
{
    static const uint32_t addressOffset = 0x0D8;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
 
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
   
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
  
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
  
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
  
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
   
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
  
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_ENB_3
{
    static const uint32_t addressOffset = 0x0DC;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;

    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
    
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
     
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
      
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
      
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
       
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
        
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

/**
 * 9.13.18 GPIO_MSK_INT_LVL_0
 *
 * This is an array of 4 identical register entries; the register fields below 
 * apply to each entry.
 */

struct GPIO_MSK_INT_LVL_0
{
    static const uint32_t addressOffset = 0x0E0;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
  
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
    
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
     
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
      
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
       
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
      
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
         
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_LVL_1
{
    static const uint32_t addressOffset = 0x0E4;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
   
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
    
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
    
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
      
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
       
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
        
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
         
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_LVL_2
{
    static const uint32_t addressOffset = 0x0E8;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;
   
    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;
    
    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
     
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
      
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
       
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
       
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
        
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

struct GPIO_MSK_INT_LVL_3
{
    static const uint32_t addressOffset = 0x0EC;

    static const uint32_t MSK_7_baseBit = 15;
    static const uint32_t MSK_7_bitWidth = 1;

    static const uint32_t MSK_6_baseBit = 14;
    static const uint32_t MSK_6_bitWidth = 1;

    static const uint32_t MSK_5_baseBit = 13;
    static const uint32_t MSK_5_bitWidth = 1;
    
    static const uint32_t MSK_4_baseBit = 12;
    static const uint32_t MSK_4_bitWidth = 1;
   
    static const uint32_t MSK_3_baseBit = 11;
    static const uint32_t MSK_3_bitWidth = 1;
     
    static const uint32_t MSK_2_baseBit = 10;
    static const uint32_t MSK_2_bitWidth = 1;
      
    static const uint32_t MSK_1_baseBit = 9;
    static const uint32_t MSK_1_bitWidth = 1;
      
    static const uint32_t MSK_0_baseBit = 8;
    static const uint32_t MSK_0_bitWidth = 1;

    static const uint32_t BIT_7_baseBit = 7;
    static const uint32_t BIT_7_bitWidth = 1;

    static const uint32_t BIT_6_baseBit = 6;
    static const uint32_t BIT_6_bitWidth = 1;

    static const uint32_t BIT_5_baseBit = 5;
    static const uint32_t BIT_5_bitWidth = 1;

    static const uint32_t BIT_4_baseBit = 4;
    static const uint32_t BIT_4_bitWidth = 1;

    static const uint32_t BIT_3_baseBit = 3;
    static const uint32_t BIT_3_bitWidth = 1;

    static const uint32_t BIT_2_baseBit = 2;
    static const uint32_t BIT_2_bitWidth = 1;

    static const uint32_t BIT_1_baseBit = 1;
    static const uint32_t BIT_1_bitWidth = 1;

    static const uint32_t BIT_0_baseBit = 0;
    static const uint32_t BIT_0_bitWidth = 1;

};

// 9.13.19 GPIO_DB_CNT_P0_0
struct GPIO_DB_CNT_P0
{
    static const uint32_t addressOffset = 0x0F0;

    static const uint32_t PA_DBC_CNT_baseBit = 0;
    static const uint32_t PA_DBC_CNT_bitWidth = 8;

};

// 9.13.20 GPIO_DB_CNT_P1_0
struct GPIO_DB_CNT_P1
{
    static const uint32_t addressOffset = 0x0F4;

    static const uint32_t PB_DBC_CNT_baseBit = 0;
    static const uint32_t PB_DBC_CNT_bitWidth = 8;

};

// 9.13.21 GPIO_DB_CNT_P2_0
struct GPIO_DB_CNT_P2
{
    static const uint32_t addressOffset = 0x0F8;

    static const uint32_t PC_DBC_CNT_baseBit = 0;
    static const uint32_t PC_DBC_CNT_bitWidth = 8;

};

// 9.13.22 GPIO_DB_CNT_P3_0
struct GPIO_DB_CNT_P3
{
    static const uint32_t addressOffset = 0x0FC;

    static const uint32_t PD_DBC_CNT_baseBit = 0;
    static const uint32_t PD_DBC_CNT_bitWidth = 8;
        
};

