//This example uses pin 40, 38, and 37.
//GND -> Switch
//3.3v -> Resistor -> other side of switch + Pin 40/38/37
//It is assumed pins are held high when the switch is open
//When a pin goes low from a switch closing, it will be passed as keyboard input.
//pin40==keyboard_1
//pin39==keyboard_2
//pin37==keyboard_3

#include <iostream>
#include <string>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <cstring>
#include <linux/uinput.h>

#include "../../peripheralController/peripheralController.h"
#include "../../gpioController/gpio.h"
#include "../../pinmuxController/pinmuxController.h"

//for emitting keyboard events to the OS
//https://www.kernel.org/doc/html/v4.12/input/uinput.html
void emit(int fk, int type, int code, int val)
{
	struct input_event ie;

	ie.type = type;
	ie.code = code;
	ie.value = val;
	/* timestamp values below are ignored */
	ie.time.tv_sec = 0;
	ie.time.tv_usec = 0;

	write(fk, &ie, sizeof(ie));
}

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
	
	//  set up our emulated keyboard
	struct uinput_setup usetup;
	int fk = open("/dev/uinput", O_WRONLY | O_NONBLOCK);

	ioctl(fk, UI_SET_EVBIT, EV_KEY);

	//  You must define each key that should exist in our emulated keyboard.
	//	A list of common input event codes can be found at:
	//  https://code.woboq.org/qt5/include/linux/input-event-codes.h.html
	ioctl(fk, UI_SET_KEYBIT, KEY_SPACE);
	ioctl(fk, UI_SET_KEYBIT, KEY_ENTER);
	ioctl(fk, UI_SET_KEYBIT, KEY_ESC);
	ioctl(fk, UI_SET_KEYBIT, KEY_BACKSPACE);
	ioctl(fk, UI_SET_KEYBIT, KEY_TAB);
	ioctl(fk, UI_SET_KEYBIT, KEY_LEFT);
	ioctl(fk, UI_SET_KEYBIT, KEY_RIGHT);
	ioctl(fk, UI_SET_KEYBIT, KEY_UP);
	ioctl(fk, UI_SET_KEYBIT, KEY_DOWN);
	ioctl(fk, UI_SET_KEYBIT, KEY_1);
	ioctl(fk, UI_SET_KEYBIT, KEY_2);
	ioctl(fk, UI_SET_KEYBIT, KEY_3);
	ioctl(fk, UI_SET_KEYBIT, KEY_4);
	ioctl(fk, UI_SET_KEYBIT, KEY_5);
	ioctl(fk, UI_SET_KEYBIT, KEY_6);
	ioctl(fk, UI_SET_KEYBIT, KEY_7);
	ioctl(fk, UI_SET_KEYBIT, KEY_8);
	ioctl(fk, UI_SET_KEYBIT, KEY_9);
	ioctl(fk, UI_SET_KEYBIT, KEY_0);
	ioctl(fk, UI_SET_KEYBIT, KEY_A);
	ioctl(fk, UI_SET_KEYBIT, KEY_B);
	ioctl(fk, UI_SET_KEYBIT, KEY_C);
	ioctl(fk, UI_SET_KEYBIT, KEY_D);
	ioctl(fk, UI_SET_KEYBIT, KEY_E);
	ioctl(fk, UI_SET_KEYBIT, KEY_F);
	ioctl(fk, UI_SET_KEYBIT, KEY_G);
	ioctl(fk, UI_SET_KEYBIT, KEY_H);
	ioctl(fk, UI_SET_KEYBIT, KEY_I);
	ioctl(fk, UI_SET_KEYBIT, KEY_J);
	ioctl(fk, UI_SET_KEYBIT, KEY_K);
	ioctl(fk, UI_SET_KEYBIT, KEY_L);
	ioctl(fk, UI_SET_KEYBIT, KEY_M);
	ioctl(fk, UI_SET_KEYBIT, KEY_N);
	ioctl(fk, UI_SET_KEYBIT, KEY_O);
	ioctl(fk, UI_SET_KEYBIT, KEY_P);
	ioctl(fk, UI_SET_KEYBIT, KEY_Q);
	ioctl(fk, UI_SET_KEYBIT, KEY_R);
	ioctl(fk, UI_SET_KEYBIT, KEY_S);
	ioctl(fk, UI_SET_KEYBIT, KEY_T);
	ioctl(fk, UI_SET_KEYBIT, KEY_U);
	ioctl(fk, UI_SET_KEYBIT, KEY_V);
	ioctl(fk, UI_SET_KEYBIT, KEY_W);
	ioctl(fk, UI_SET_KEYBIT, KEY_X);
	ioctl(fk, UI_SET_KEYBIT, KEY_Y);
	ioctl(fk, UI_SET_KEYBIT, KEY_Z);


	memset(&usetup, 0, sizeof(usetup));
	usetup.id.bustype = BUS_USB;
	usetup.id.vendor = 0x1234; /* sample vendor */
	usetup.id.product = 0x5678; /* sample product */
	strcpy(usetup.name, "Jetson GPIO");

	//actually initalizes/"plugs in" the keyboard
	ioctl(fk, UI_DEV_SETUP, &usetup);
	ioctl(fk, UI_DEV_CREATE);
	
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
	
	uint32_t readGPIOINPUT = gpioController::BIT_N_HIGH;
	bool pin40val = 0;
	bool pin39val = 0;
	bool pin37val = 0;

    while(true)
    {
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_6_baseBit, GPIO_IN_1_RMW::BIT_6_bitWidth);
		//std::cout<<"pin 40 INPUT bit: "<<readGPIOINPUT<<std::endl;		
		if(readGPIOINPUT == 0) {
			if(!pin40val) {
				emit(fk, EV_KEY, KEY_1, 1);
				emit(fk, EV_SYN, SYN_REPORT, 0);
				pin40val = 1;
			}
		} else {
			if(pin40val) {
				emit(fk, EV_KEY, KEY_1, 0);
				emit(fk, EV_SYN, SYN_REPORT, 0);
				pin40val = 0;
			}
		}
		
		readGPIOINPUT = myGpioController3.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_5_baseBit, GPIO_IN_1_RMW::BIT_5_bitWidth);
		//std::cout<<"pin 38 INPUT bit: "<<readGPIOINPUT<<std::endl;
		if(readGPIOINPUT == 0) {
			if(!pin39val) {
				emit(fk, EV_KEY, KEY_2, 1);
				emit(fk, EV_SYN, SYN_REPORT, 0);
				pin39val = 1;
			}
		} else {
			if(pin39val) {
				emit(fk, EV_KEY, KEY_2, 0);
				emit(fk, EV_SYN, SYN_REPORT, 0);
				pin39val = 0;
			}
		}
		
		readGPIOINPUT = myGpioController1.getRegisterField(GPIO_IN_1_RMW::addressOffset, GPIO_IN_1_RMW::BIT_4_baseBit, GPIO_IN_1_RMW::BIT_4_bitWidth);
		//std::cout<<"pin 37 INPUT bit: "<<readGPIOINPUT<<std::endl;
		if(readGPIOINPUT == 0) {
			if(!pin37val) {
				emit(fk, EV_KEY, KEY_3, 1);
				emit(fk, EV_SYN, SYN_REPORT, 0);
				pin37val = 1;
			}
		} else {
			if(pin37val) {
				emit(fk, EV_KEY, KEY_3, 0);
				emit(fk, EV_SYN, SYN_REPORT, 0);
				pin37val = 0;
			}
		}
    }
    return 0;
}
