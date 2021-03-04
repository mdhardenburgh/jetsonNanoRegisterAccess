/**
 * This datasheet is a little hard to understand, like every other paragraph
 * was written by a different person who only skimmed the last sentence of 
 * of the previous paragraph. So I tried my best to sythesize it into something I 
 * could more easily understand and hopefully this helps others too.
 *
 * Hold on tight, this is going to be a bumpy ride.
 *
 * So for some reason, Nvidia decided to group the pinmux registers into the
 * Misc. APB section of the register map, so all of these start at the address of
 * 0x70000000. Also for some reason all of the information regarding pad 
 * controls and pinmuxing is spread well over FIVE SECTIONS!! Most of the 
 * information is contained in the sections 9.5, 9.6, 9.15, 21.1.2, and 21.4.
 * I want to emphasize here that pad controls, pinmuxing controls and GPIO
 * controls (as contained in gpio.h) are all seperate concepts. Go re-read that
 * last sentence its important. Maybe I'm just stupid, but for a while it 
 * seemed to me pinmuxing and pad controls are tightly coupled. They are not, 
 * EVEN THOUGH, "during normal operation per pad controls is driven by the 
 * pinmux control registers". Several embedded systems that I have used such 
 * as the TM4C123GH6PM 32 bit ARM4F microcontroller combine it into the GPIO 
 * section, but I digress...
 * 
 * Lets start with Section 9.5 first, Pad Controls.
 * 
 * Most MPIO pads have thier own per pad controls (which lives in the pinmux
 * register) and control group per pad, however some MPIO pads are 
 * grouped into control groups and dont have per pad controls, and some have a 
 * combination thereof. All ST (STandard MPIO pad) and DD (Dual Driver MPIO pad)
 * pads have thier own indvidiual control group except for the ST_EMMC pads. 
 * For example, GPIO_PE6 gets its own per pad controls and control group, 9.15.144
 * lists that pad's per pad register fields at address offset 0x3248 and 21.1.4.61
 * lists that pad control group register fields at adderss offset 0x9c8.
 * GPIO_PE6 does not have the DRV_TYPE listed in it's per pad register field,
 * and instead has DRVDN and DRVUP listed in it's pad control group register
 * fields. 
 *
 * But first, a caviat. I want to emphasize here that during normal operation,
 * per pad controls is driven by the pinmux control registers as described in
 * section 9.6 and listed in section 9.15. Re-read that last sentence, its 
 * important. To add even more to this perpetually perplexing pudding cake, pad 
 * control registers are mentioned in section 21.2, Pad Control Registers AND 
 * the register definitions are listed in sections 21.1.4.4 to 21.1.4.157. I 
 * assume to only provide continuity with the idea of "oh yeah, these things 
 * mentioned earlier and made to look like they belong in one part of the memory
 * map are actually in a differrent part of the memory map."
 *
 * Still with me? All right, enough of my ranting, brass tacks here.
 *
 * Each MPIO pad has 2 sets of settings or controls. One collection of 
 * controls are on a per pad basis, and the other is on a "control group" 
 * basis. The per pad controls reside in the Pinmux Control Registers. There 
 * are 162 of these Pinmux Control Registers (list in section 9.15) and 152 Pad 
 * Control Group Registers (listed in section 21.1.4.4 to 21.1.4.157). A pad 
 * control group is a group of MPIO pads that share common settings and are 
 * controlled together. Control groups are sometimes refered to as I/O bricks.
 * 
 *
 * All possible per pad controls are listed on Table 25 on page 229. The per 
 * pad controls may include (not all of them have these controls such as PE6) PUPD, 
 * TRISTATE_CONTROL, DPD_PARKING, E_INPUT, E_LPDR, E_OD (Output Disable. 
 * PERMENTLY dispables the pad), E_IO_HV, E_HSM, SCHMT, DRV_TYPE[1:0]. Not all
 * pads have all of these controls. The per pad options will be discussed in 
 * more detail when I get to section 9.6 and Table 29: Pinmux Register Format,
 * but its rather straight forward.
 *
 * Pad Controls
 * _____________________________________________________________________________________________
 *                                   Per Pad Options
 * _________________________________________________________________________________________________
 * Control              | Description
 * PUPD                 | Internal Pull up, pull down option
 * TRISTATE_CONTROL     |
 *
 * The pad control group register map is shown in table 26 on page 231. The pad
 * controls group controls may include. SCH (Schmitt trigger for the control group),
 * PREEMP (pre-emphasis circuit), PU, PD, PRK, DRV_TYPE, DRVDN, DRVUP, SLWR, 
 * SLWF. The information for the register format for the per pad controls are 
 * not straight forward, but instead is in THREE DIFFERNT PLACES. LOOKING AT YOU NVIDIA!!!
 *
 * The first place is in section 9.5.2. All ST (STandard MPIO pad) and DD (Dual
 * Driver MPIO pad) pads have thier each indvidiual control group except for 
 * the ST_EMMC pads. Additionally, Nvidia mentions to reference section 21.1.2
 * 
