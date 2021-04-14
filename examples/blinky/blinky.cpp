#include <iostream>
#include <string>
#include <cassert>
#include <unistd.h>

#include "../../peripheralController/peripheralController.h"
#include "../../gpioController/gpio.h"
//#include "padGroupController.h"
//#include "pinmuxController.h"

int main()
{
    PeripheralController gpioController(gpioController7BaseAddress);
    //PeripheralController padController(padControlBase);
    //PeripheralController pinMuxController(pinMuxControlBase);
    
    uint32_t gpioPinState = BIT_N_HIGH;

    // blink GPIO pin 15. GPIO PY.02, Module Pin Number: 218, Module Pin Name GPIO12
    // port Y is the zeroth port gpio controller 4 grouping
    gpioController.setRegisterField(GPIO_CNF_0_RMW::addressOffset, BIT_N_GPIO, GPIO_CNF_0_RMW::BIT_2_baseBit, GPIO_CNF_0_RMW::BIT_2_bitWidth);
    gpioController.setRegisterField(GPIO_OE_0_RMW::addressOffset, BIT_N_DRIVEN, GPIO_OE_0_RMW::BIT_2_baseBit, GPIO_OE_0_RMW::BIT_2_bitWidth);
    gpioController.setRegisterField(GPIO_OUT_0_RMW::addressOffset, gpioPinState, GPIO_OUT_0_RMW::BIT_2_baseBit, GPIO_OUT_0_RMW::BIT_2_bitWidth);
   
    while(true)
    {
        /*
        sleep(1);
        if(gpioPinState == BIT_N_LOW)
        {
            gpioPinState = BIT_N_HIGH;
        }
        else
        {
            gpioPinState = BIT_N_LOW;
        }
        
        gpioController.setRegisterField(GPIO_OUT_0_RMW::addressOffset, gpioPinState, GPIO_OUT_0_RMW::BIT_2_baseBit, GPIO_OUT_0_RMW::BIT_2_bitWidth);
        */
    }

    return 0;
}
