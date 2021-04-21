#include <iostream>
#include <string>
#include <cassert>
#include <unistd.h>

#include "../../peripheralController/peripheralController.h"
#include "../../gpioController/gpio.h"
#include "../../pinmuxController/pinmuxController.h"

int main()
{   
    PeripheralController myGpioController(gpioController::gpioController1BaseAddress);
    PeripheralController myPinMuxController(pinmuxController::baseAddress);
    
    uint32_t gpioPinState = gpioController::BIT_N_HIGH;

    // Header pin #13, SoM pin name: SPI1_SCK, SoM pin #106, Tegra chip pin name: SPI2_SCK, Default usage: GPIO, Alternate usage: SPI #1 Shift Clock, GPIO Port PB.06 
    myPinMuxController.setRegisterField(PINMUX_AUX_SPI2_SCK_0::addressOffset, 0, PINMUX_AUX_SPI2_SCK_0::TRISTATE_bit, PINMUX_AUX_SPI2_SCK_0::TRISTATE_bitWidth);
    
    // port B is the first port gpio controller 1 grouping
    myGpioController.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::LOCK_BIT_DISABLE, GPIO_CNF_1_RMW::LOCK_6_baseBit, GPIO_CNF_1_RMW::LOCK_6_bitWidth);
    myGpioController.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_6_baseBit, GPIO_CNF_1_RMW::BIT_6_bitWidth);
    myGpioController.setRegisterField(GPIO_OE_1_RMW::addressOffset, gpioController::BIT_N_DRIVEN, GPIO_OE_1_RMW::BIT_6_baseBit, GPIO_OE_1_RMW::BIT_6_bitWidth);  
    myGpioController.setRegisterField(GPIO_OUT_1_RMW::addressOffset, gpioController::BIT_N_HIGH, GPIO_OUT_1_RMW::BIT_6_baseBit, GPIO_OUT_1_RMW::BIT_6_bitWidth);
    
    for(int i = 0; i < 10; i++)
    {
        sleep(1);
        if(gpioPinState == gpioController::BIT_N_LOW)
        {
            gpioPinState = gpioController::BIT_N_HIGH;
        }
        else
        {
            gpioPinState = gpioController::BIT_N_LOW;
        }
        
        myGpioController.setRegisterField(GPIO_OUT_1_RMW::addressOffset, gpioPinState, GPIO_OUT_1_RMW::BIT_6_baseBit, GPIO_OUT_1_RMW::BIT_6_bitWidth);
    }
    
    myGpioController.setRegisterField(GPIO_OUT_1_RMW::addressOffset, gpioController::BIT_N_LOW, GPIO_OUT_1_RMW::BIT_6_baseBit, GPIO_OUT_1_RMW::BIT_6_bitWidth);
    return 0;
}
