//All uncommented reads in the loop should work with the default SD card image
//The commented reads in the loop might work with additional pinmux/boot configuration changes

#include <iostream>
#include <string>
#include <cassert>
#include <unistd.h>
#include <cstring>
#include <linux/uinput.h>

#include "../../peripheralController/peripheralController.h"
#include "../../gpioController/gpio.h"
#include "../../pinmuxController/pinmuxController.h"
int main()
{
	PeripheralController myGpioController1(gpioController::gpioController1BaseAddress);
	PeripheralController myGpioController2(gpioController::gpioController2BaseAddress);
	PeripheralController myGpioController3(gpioController::gpioController3BaseAddress);
	PeripheralController myGpioController4(gpioController::gpioController4BaseAddress);
	PeripheralController myGpioController5(gpioController::gpioController5BaseAddress);
	PeripheralController myGpioController6(gpioController::gpioController6BaseAddress);
	PeripheralController myGpioController7(gpioController::gpioController7BaseAddress);
	PeripheralController myGpioController8(gpioController::gpioController8BaseAddress);
    PeripheralController myPinMuxController(pinmuxController::baseAddress);
	
	//Force J41-pin40 to input mode
	myGpioController3.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_6_baseBit, GPIO_CNF_1_RMW::BIT_6_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_DOUT_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_DAP4_DOUT_0::PUPD_bit, PINMUX_AUX_DAP4_DOUT_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_DOUT_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_DAP4_DOUT_0::E_INPUT_bit, PINMUX_AUX_DAP4_DOUT_0::E_INPUT_bitWidth);
	
	
	//Force J41-pin38 to input mode
	myGpioController3.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_5_baseBit, GPIO_CNF_1_RMW::BIT_5_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_DIN_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_DAP4_DIN_0::PUPD_bit, PINMUX_AUX_DAP4_DIN_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_DIN_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_DAP4_DIN_0::E_INPUT_bit, PINMUX_AUX_DAP4_DIN_0::E_INPUT_bitWidth);
	
	//Force J41-pin37 to input mode
	myGpioController1.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_4_baseBit, GPIO_CNF_1_RMW::BIT_4_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_MOSI_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI2_MOSI_0::PUPD_bit, PINMUX_AUX_SPI2_MOSI_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_MOSI_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI2_MOSI_0::E_INPUT_bit, PINMUX_AUX_SPI2_MOSI_0::E_INPUT_bitWidth);
	
	//Force J41-pin36 to input mode
	//Doesn't work without further pinmux configuration and/or disabling of UART2
	//myGpioController2.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_3_baseBit, GPIO_CNF_2_RMW::BIT_3_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_UART2_CTS_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_UART2_CTS_0::PUPD_bit, PINMUX_AUX_UART2_CTS_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_UART2_CTS_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_UART2_CTS_0::E_INPUT_bit, PINMUX_AUX_UART2_CTS_0::E_INPUT_bitWidth);
	
	//Force J41-pin35 to input mode
	myGpioController3.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_4_baseBit, GPIO_CNF_1_RMW::BIT_4_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_FS_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_DAP4_FS_0::PUPD_bit, PINMUX_AUX_DAP4_FS_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_FS_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_DAP4_FS_0::E_INPUT_bit, PINMUX_AUX_DAP4_FS_0::E_INPUT_bitWidth);
	
	//Force J41-pin33 to input mode
	//pin 33 just doesnt work?
	//myGpioController2.setRegisterField(GPIO_CNF_0_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_0_RMW::BIT_6_baseBit, GPIO_CNF_0_RMW::BIT_6_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_GPIO_PE6_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_GPIO_PE6_0::PUPD_bit, PINMUX_AUX_GPIO_PE6_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_GPIO_PE6_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_GPIO_PE6_0::E_INPUT_bit, PINMUX_AUX_GPIO_PE6_0::E_INPUT_bitWidth);
	
	//Force J41-pin32 to input mode
	myGpioController6.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_0_baseBit, GPIO_CNF_1_RMW::BIT_0_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_LCD_BL_PWM_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_LCD_BL_PWM_0::PUPD_bit, PINMUX_AUX_LCD_BL_PWM_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_LCD_BL_PWM_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_LCD_BL_PWM_0::E_INPUT_bit, PINMUX_AUX_LCD_BL_PWM_0::E_INPUT_bitWidth);
	
	//Force J41-pin31 to input mode
	myGpioController7.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_0_baseBit, GPIO_CNF_1_RMW::BIT_0_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_GPIO_PZ0_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_GPIO_PZ0_0::PUPD_bit, PINMUX_AUX_GPIO_PZ0_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_GPIO_PZ0_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_GPIO_PZ0_0::E_INPUT_bit, PINMUX_AUX_GPIO_PZ0_0::E_INPUT_bitWidth);
	
	//Force J41-pin29 to input mode
	//pin 29 just doesnt work?
	//myGpioController1.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_3_baseBit, GPIO_CNF_2_RMW::BIT_3_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_CAM_AF_EN_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_CAM_AF_EN_0::PUPD_bit, PINMUX_AUX_CAM_AF_EN_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_CAM_AF_EN_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_CAM_AF_EN_0::E_INPUT_bit, PINMUX_AUX_CAM_AF_EN_0::E_INPUT_bitWidth);
	
	//Force J41-pin28 to input mode
	//pin 28 just doesnt work?
	//myGpioController1.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_2_baseBit, GPIO_CNF_2_RMW::BIT_2_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_GEN1_I2C_SCL_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_GEN1_I2C_SCL_0::PUPD_bit, PINMUX_AUX_GEN1_I2C_SCL_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_GEN1_I2C_SCL_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_GEN1_I2C_SCL_0::E_INPUT_bit, PINMUX_AUX_GEN1_I2C_SCL_0::E_INPUT_bitWidth);
	
	//Force J41-pin27 to input mode
	//pin 27 just doesnt work?
	//myGpioController1.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_5_baseBit, GPIO_CNF_1_RMW::BIT_5_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_GEN1_I2C_SDA_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_GEN1_I2C_SDA_0::PUPD_bit, PINMUX_AUX_GEN1_I2C_SDA_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_GEN1_I2C_SDA_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_GEN1_I2C_SDA_0::E_INPUT_bit, PINMUX_AUX_GEN1_I2C_SDA_0::E_INPUT_bitWidth);
	
	//Force J41-pin26 to input mode
	//pin 26 doesnt seem to work?
	//myGpioController1.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_1_baseBit, GPIO_CNF_2_RMW::BIT_1_bitWidth);
    //attempting to set the pullup bit to 2 (pull up) pisses off the compiler
	//myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_CS1_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI1_CS1_0::PUPD_bit, PINMUX_AUX_SPI1_CS1_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_CS1_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI1_CS1_0::E_INPUT_bit, PINMUX_AUX_SPI1_CS1_0::E_INPUT_bitWidth);
	
	//Force J41-pin24 to input mode
	// pin 24 refuses to go into gpio mode
	//myGpioController1.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_3_baseBit, GPIO_CNF_2_RMW::BIT_3_bitWidth);
	//myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_CS0_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI1_CS0_0::PUPD_bit, PINMUX_AUX_SPI1_CS0_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_CS0_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI1_CS0_0::E_INPUT_bit, PINMUX_AUX_SPI1_CS0_0::E_INPUT_bitWidth);
	
	//Force J41-pin23 to input mode
	myGpioController1.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_2_baseBit, GPIO_CNF_2_RMW::BIT_2_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_SCK_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI1_SCK_0::PUPD_bit, PINMUX_AUX_SPI1_SCK_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_SCK_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI1_SCK_0::E_INPUT_bit, PINMUX_AUX_SPI1_SCK_0::E_INPUT_bitWidth);
	
	//Force J41-pin22 to input mode
	myGpioController1.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_5_baseBit, GPIO_CNF_1_RMW::BIT_5_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_MISO_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI2_MISO_0::PUPD_bit, PINMUX_AUX_SPI2_MISO_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_MISO_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI2_MISO_0::E_INPUT_bit, PINMUX_AUX_SPI2_MISO_0::E_INPUT_bitWidth);
	
	//Force J41-pin21 to input mode
	myGpioController1.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_1_baseBit, GPIO_CNF_2_RMW::BIT_1_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_MISO_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI1_MISO_0::PUPD_bit, PINMUX_AUX_SPI1_MISO_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_MISO_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI1_MISO_0::E_INPUT_bit, PINMUX_AUX_SPI1_MISO_0::E_INPUT_bitWidth);
	
	//Force J41-pin19 to input mode
	myGpioController1.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_0_baseBit, GPIO_CNF_2_RMW::BIT_0_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_MOSI_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI1_MOSI_0::PUPD_bit, PINMUX_AUX_SPI1_MOSI_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI1_MOSI_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI1_MOSI_0::E_INPUT_bit, PINMUX_AUX_SPI1_MOSI_0::E_INPUT_bitWidth);
	
	//Force J41-pin18 to input mode
	myGpioController1.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_7_baseBit, GPIO_CNF_1_RMW::BIT_7_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_CS0_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI2_CS0_0::PUPD_bit, PINMUX_AUX_SPI2_CS0_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_CS0_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI2_CS0_0::E_INPUT_bit, PINMUX_AUX_SPI2_CS0_0::E_INPUT_bitWidth);
	
	//Force J41-pin16 to input mode
	myGpioController8.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_0_baseBit, GPIO_CNF_1_RMW::BIT_0_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_CS1_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI2_CS1_0::PUPD_bit, PINMUX_AUX_SPI2_CS1_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_CS1_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI2_CS1_0::E_INPUT_bit, PINMUX_AUX_SPI2_CS1_0::E_INPUT_bitWidth);
	
	//Force J41-pin15 to input mode
	myGpioController7.setRegisterField(GPIO_CNF_0_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_0_RMW::BIT_2_baseBit, GPIO_CNF_0_RMW::BIT_2_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_LCD_TE_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_LCD_TE_0::PUPD_bit, PINMUX_AUX_LCD_TE_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_LCD_TE_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_LCD_TE_0::E_INPUT_bit, PINMUX_AUX_LCD_TE_0::E_INPUT_bitWidth);
	
	//Force J41-pin13 to input mode
	myGpioController1.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_6_baseBit, GPIO_CNF_1_RMW::BIT_6_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_SCK_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_SPI2_SCK_0::PUPD_bit, PINMUX_AUX_SPI2_SCK_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_SCK_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_SPI2_SCK_0::E_INPUT_bit, PINMUX_AUX_SPI2_SCK_0::E_INPUT_bitWidth);
	
	//Force J41-pin12 to input mode
	myGpioController3.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_7_baseBit, GPIO_CNF_1_RMW::BIT_7_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_DAP4_SCLK_0::PUPD_bit, PINMUX_AUX_DAP4_SCLK_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_DAP4_SCLK_0::E_INPUT_bit, PINMUX_AUX_DAP4_SCLK_0::E_INPUT_bitWidth);
	
	//Force J41-pin11 to input mode
	myGpioController2.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_2_baseBit, GPIO_CNF_2_RMW::BIT_2_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_UART2_RTS_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_UART2_RTS_0::PUPD_bit, PINMUX_AUX_UART2_RTS_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_UART2_RTS_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_UART2_RTS_0::E_INPUT_bit, PINMUX_AUX_UART2_RTS_0::E_INPUT_bitWidth);
	
	//Force J41-pin10 to input mode
	myGpioController2.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_1_baseBit, GPIO_CNF_2_RMW::BIT_1_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_UART2_RX_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_UART2_RX_0::PUPD_bit, PINMUX_AUX_UART2_RX_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_UART2_RX_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_UART2_RX_0::E_INPUT_bit, PINMUX_AUX_UART2_RX_0::E_INPUT_bitWidth);
	
	//Force J41-pin8 to input mode
	myGpioController2.setRegisterField(GPIO_CNF_2_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_2_RMW::BIT_0_baseBit, GPIO_CNF_2_RMW::BIT_0_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_UART2_TX_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_UART2_TX_0::PUPD_bit, PINMUX_AUX_UART2_TX_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_UART2_TX_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_UART2_TX_0::E_INPUT_bit, PINMUX_AUX_UART2_TX_0::E_INPUT_bitWidth);
	
	//Force J41-pin7 to input mode
	myGpioController7.setRegisterField(GPIO_CNF_3_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_3_RMW::BIT_0_baseBit, GPIO_CNF_3_RMW::BIT_0_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_AUD_MCLK_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_AUD_MCLK_0::PUPD_bit, PINMUX_AUX_AUD_MCLK_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_AUD_MCLK_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_AUD_MCLK_0::E_INPUT_bit, PINMUX_AUX_AUD_MCLK_0::E_INPUT_bitWidth);
	
	//Force J41-pin5 to input mode
	myGpioController3.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_2_baseBit, GPIO_CNF_1_RMW::BIT_2_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_GEN2_I2C_SCL_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_GEN2_I2C_SCL_0::PUPD_bit, PINMUX_AUX_GEN2_I2C_SCL_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_GEN2_I2C_SCL_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_GEN2_I2C_SCL_0::E_INPUT_bit, PINMUX_AUX_GEN2_I2C_SCL_0::E_INPUT_bitWidth);
	
	//Force J41-pin3 to input mode
	myGpioController3.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_3_baseBit, GPIO_CNF_1_RMW::BIT_3_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_GEN2_I2C_SDA_0::addressOffset, pinmuxController::PUPD_BIT_PULL_UP, PINMUX_AUX_GEN2_I2C_SDA_0::PUPD_bit, PINMUX_AUX_GEN2_I2C_SDA_0::PUPD_bitWidth);
    myPinMuxController.setRegisterField(PINMUX_AUX_GEN2_I2C_SDA_0::addressOffset, pinmuxController::E_INPUT_BIT_ENABLE, PINMUX_AUX_GEN2_I2C_SDA_0::E_INPUT_bit, PINMUX_AUX_GEN2_I2C_SDA_0::E_INPUT_bitWidth);
	
	uint32_t readGPIOINPUT = 0;
	
	//readGPIOINPUT = myPinMuxController.getRegisterField(PINMUX_AUX_SPI1_CS0_0::addressOffset, PINMUX_AUX_SPI1_CS0_0::PM_bit, PINMUX_AUX_SPI1_CS0_0::PM_bitWidth);
	//std::cout<<"pin 24 Pinmux PM bit: "<<readGPIOINPUT<<std::endl;

	//readGPIOINPUT = myPinMuxController.getRegisterField(PINMUX_AUX_SPI1_CS0_0::addressOffset, PINMUX_AUX_SPI1_CS0_0::PUPD_bit, PINMUX_AUX_SPI1_CS0_0::PUPD_bitWidth);
	//std::cout<<"pin 24 Pinmux PullUp/PullDown bit: "<<readGPIOINPUT<<std::endl;

	//readGPIOINPUT = myPinMuxController.getRegisterField(PINMUX_AUX_SPI1_CS0_0::addressOffset, PINMUX_AUX_SPI1_CS0_0::TRISTATE_bit, PINMUX_AUX_SPI1_CS0_0::TRISTATE_bitWidth);
	//std::cout<<"pin 24 Pinmux Tristate bit: "<<readGPIOINPUT<<std::endl;
	
	//readGPIOINPUT = myPinMuxController.getRegisterField(PINMUX_AUX_SPI1_CS0_0::addressOffset, PINMUX_AUX_SPI1_CS0_0::PARK_bit, PINMUX_AUX_SPI1_CS0_0::PARK_bitWidth);
	//std::cout<<"pin 24 Pinmux PARK bit: "<<readGPIOINPUT<<std::endl;

	//readGPIOINPUT = myPinMuxController.getRegisterField(PINMUX_AUX_SPI1_CS0_0::addressOffset, PINMUX_AUX_SPI1_CS0_0::E_INPUT_bit, PINMUX_AUX_SPI1_CS0_0::E_INPUT_bitWidth);
	//std::cout<<"pin 24 Pinmux INPUT bit: "<<readGPIOINPUT<<std::endl;
	
	//readGPIOINPUT = myGpioController1.getRegisterField(GPIO_CNF_2_RMW::addressOffset, GPIO_CNF_2_RMW::LOCK_3_baseBit, GPIO_CNF_2_RMW::LOCK_3_bitWidth);
    //std::cout<<"pin 24 LOCK bit: "<<readGPIOINPUT<<std::endl;
	
	//readGPIOINPUT = myGpioController1.getRegisterField(GPIO_CNF_2_RMW::addressOffset, GPIO_CNF_2_RMW::BIT_3_baseBit, GPIO_CNF_2_RMW::BIT_3_bitWidth);
    //std::cout<<"pin 24 GPIO/SPIO bit: "<<readGPIOINPUT<<std::endl;
	
	//readGPIOINPUT = myGpioController1.getRegisterField(GPIO_OE_2_RMW::addressOffset, GPIO_OE_2_RMW::BIT_3_baseBit, GPIO_OE_2_RMW::BIT_3_bitWidth);  
    //std::cout<<"pin 24 OE bit: "<<readGPIOINPUT<<std::endl;
	
	//readGPIOINPUT = myGpioController1.getRegisterField(GPIO_OUT_2_RMW::addressOffset, GPIO_OUT_2_RMW::BIT_3_baseBit, GPIO_OUT_2_RMW::BIT_3_bitWidth);
    //std::cout<<"pin 24 OUT bit: "<<readGPIOINPUT<<std::endl;
	
	while(true)
    {
        sleep(1);
		
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_6_baseBit, GPIO_IN_1_RMW::BIT_6_bitWidth);
		std::cout<<"pin 40 INPUT bit: "<<readGPIOINPUT<<std::endl;		
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_5_baseBit, GPIO_IN_1_RMW::BIT_5_bitWidth);
		std::cout<<"pin 38 INPUT bit: "<<readGPIOINPUT<<std::endl;
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_4_baseBit, GPIO_IN_1_RMW::BIT_4_bitWidth);
		std::cout<<"pin 37 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		/*
		pin 36 is in use by UART2
		readGPIOINPUT = myGpioController2.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_3_baseBit, GPIO_IN_2_RMW::BIT_3_bitWidth);
		std::cout<<"pin 36 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_4_baseBit, GPIO_IN_1_RMW::BIT_4_bitWidth);
		std::cout<<"pin 35 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		/*
		pin 33 just doesnt work for input?
		readGPIOINPUT = myGpioController2.getRegisterField(GPIO_IN_0_RMW::addressOffset, GPIO_IN_0_RMW::BIT_6_baseBit, GPIO_IN_0_RMW::BIT_6_bitWidth);
		std::cout<<"pin 33 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		readGPIOINPUT = myGpioController6.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_0_baseBit, GPIO_IN_1_RMW::BIT_0_bitWidth);
		std::cout<<"pin 32 INPUT bit: "<<readGPIOINPUT<<std::endl;
		readGPIOINPUT = myGpioController7.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_0_baseBit, GPIO_IN_1_RMW::BIT_0_bitWidth);
		std::cout<<"pin 31 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		/*
		pin 29 just doesnt work for input?
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_3_baseBit, GPIO_IN_2_RMW::BIT_3_bitWidth);
		std::cout<<"pin 29 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 28 just doesnt work for input?
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_2_baseBit, GPIO_IN_2_RMW::BIT_2_bitWidth);
		std::cout<<"pin 28 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 27 just doesnt work for input?
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_5_baseBit, GPIO_IN_1_RMW::BIT_5_bitWidth);
		std::cout<<"pin 27 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 26 just doesnt work for input?
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_1_baseBit, GPIO_IN_2_RMW::BIT_1_bitWidth);
		std::cout<<"pin 26 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/

		/*
		pin 26 refuses to go into gpio mode (but its lock bit is not set)
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_3_baseBit, GPIO_IN_2_RMW::BIT_3_bitWidth);
		std::cout<<"pin 24 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 23 just doesnt work for input?
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_2_baseBit, GPIO_IN_2_RMW::BIT_2_bitWidth);
		std::cout<<"pin 23 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_5_baseBit, GPIO_IN_1_RMW::BIT_5_bitWidth);
		std::cout<<"pin 22 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		/*
		pin 21 just doesnt work for input?
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_1_baseBit, GPIO_IN_2_RMW::BIT_1_bitWidth);
		std::cout<<"pin 21 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 19 just doesnt work for input?
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_0_baseBit, GPIO_IN_2_RMW::BIT_0_bitWidth);
		std::cout<<"pin 19 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_7_baseBit, GPIO_IN_1_RMW::BIT_7_bitWidth);
		std::cout<<"pin 18 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		
		readGPIOINPUT = myGpioController8.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_0_baseBit, GPIO_IN_1_RMW::BIT_0_bitWidth);
		std::cout<<"pin 16 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		/*
		pin 15 just doesnt work for input?
		readGPIOINPUT = myGpioController7.getRegisterField(GPIO_IN_0_RMW::addressOffset, GPIO_IN_0_RMW::BIT_2_baseBit, GPIO_IN_0_RMW::BIT_2_bitWidth);
		std::cout<<"pin 15 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		//pin 13 kind of works? it will pull up to 1, but will go back to 0 quickly after
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_6_baseBit, GPIO_IN_1_RMW::BIT_6_bitWidth);
		std::cout<<"pin 13 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		/*
		pin 12 just doesnt work for input?
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_7_baseBit, GPIO_IN_1_RMW::BIT_7_bitWidth);
		std::cout<<"pin 12 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 11 just doesnt work for input?
		readGPIOINPUT = myGpioController2.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_2_baseBit, GPIO_IN_2_RMW::BIT_2_bitWidth);
		std::cout<<"pin 11 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 10 just doesnt work for input?
		readGPIOINPUT = myGpioController2.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_1_baseBit, GPIO_IN_2_RMW::BIT_1_bitWidth);
		std::cout<<"pin 10 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 8 just doesnt work for input?
		readGPIOINPUT = myGpioController2.getRegisterField(GPIO_IN_2_RMW::addressOffset, GPIO_IN_2_RMW::BIT_0_baseBit, GPIO_IN_2_RMW::BIT_0_bitWidth);
		std::cout<<"pin 8 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		readGPIOINPUT = myGpioController7.getRegisterField(GPIO_IN_3_RMW::addressOffset, GPIO_IN_3_RMW::BIT_0_baseBit, GPIO_IN_3_RMW::BIT_0_bitWidth);
		std::cout<<"pin 7 INPUT bit: "<<readGPIOINPUT<<std::endl;
		
		/*
		pin 5 just doesnt work for input?
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_2_baseBit, GPIO_IN_1_RMW::BIT_2_bitWidth);
		std::cout<<"pin 5 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
		
		/*
		pin 3 just doesnt work for input?
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_3_baseBit, GPIO_IN_1_RMW::BIT_3_bitWidth);
		std::cout<<"pin 3 INPUT bit: "<<readGPIOINPUT<<std::endl;
		*/
	}
    
     return 0;
}
