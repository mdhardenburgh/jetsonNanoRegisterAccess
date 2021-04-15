#include <iostream>
#include <string>
#include <cassert>
#include <unistd.h>

#include "../../peripheralController/peripheralController.h"
#include "../../gpioController/gpio.h"
//#include "padGroupController.h"
//#include "pinmuxController.h"

int main(int argc, char *argv[])
{
    
    (void)argc;
    (void)argv;
    PeripheralController gpioController(gpioController7BaseAddress);
    //PeripheralController padController(padControlBase);
    //PeripheralController pinMuxController(pinMuxControlBase);
    
    uint32_t gpioPinState = BIT_N_HIGH;

    // blink GPIO pin 15. GPIO PY.02, Module Pin Number: 218, Module Pin Name GPIO12
    // port Y is the zeroth port gpio controller 4 grouping
    gpioController.setRegisterField(GPIO_CNF_0_RMW::addressOffset, BIT_N_GPIO, GPIO_CNF_0_RMW::BIT_2_baseBit, GPIO_CNF_0_RMW::BIT_2_bitWidth);
    gpioController.setRegisterField(GPIO_CNF_0_RMW::addressOffset, LOCK_BIT_ENABLE, GPIO_CNF_0_RMW::LOCK_2_baseBit, GPIO_CNF_0_RMW::LOCK_2_bitWidth);
    gpioController.setRegisterField(GPIO_OE_0_RMW::addressOffset, BIT_N_DRIVEN, GPIO_OE_0_RMW::BIT_2_baseBit, GPIO_OE_0_RMW::BIT_2_bitWidth);
    gpioController.setRegisterField(GPIO_INT_ENB_0::addressOffset, BIT_N_DISABLE, GPIO_INT_ENB_0::BIT_2_baseBit, GPIO_INT_ENB_0::BIT_2_bitWidth);
    gpioController.setRegisterField(GPIO_OUT_0_RMW::addressOffset, gpioPinState, GPIO_OUT_0_RMW::BIT_2_baseBit, GPIO_OUT_0_RMW::BIT_2_bitWidth);
    
    //uint32_t temp = gpioController.getRegisterField(GPIO_IN_0_RMW::addressOffset, GPIO_IN_0_RMW::BIT_2_baseBit, GPIO_IN_0_RMW::BIT_2_bitWidth); 
    uint32_t readCNF = gpioController.getRegisterField(GPIO_CNF_0_RMW::addressOffset, GPIO_CNF_0_RMW::BIT_2_baseBit, GPIO_CNF_0_RMW::BIT_2_bitWidth); 
    std::cout<<"Port Y bit 2 CNF GPIO: "<<readCNF<<std::endl;

    uint32_t readCNF2 = gpioController.getRegisterField(GPIO_CNF_0_RMW::addressOffset, GPIO_CNF_0_RMW::LOCK_2_baseBit, GPIO_CNF_0_RMW::LOCK_2_bitWidth); 
    std::cout<<"Port Y bit 2 CNF LOCK: "<<readCNF2<<std::endl;

    uint32_t readOE = gpioController.getRegisterField(GPIO_OE_0_RMW::addressOffset, GPIO_OE_0_RMW::BIT_2_baseBit, GPIO_OE_0_RMW::BIT_2_bitWidth); 
    std::cout<<"Port Y bit 2 OE: "<<readOE<<std::endl;

    uint32_t readOUT = gpioController.getRegisterField(GPIO_OUT_0_RMW::addressOffset, GPIO_OUT_0_RMW::BIT_2_baseBit, GPIO_OUT_0_RMW::BIT_2_bitWidth); 
    std::cout<<"Port Y bit 2 OUT: "<<readOUT<<std::endl;


    
    /*  
    while(true)
    {
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
    }
    */
    return 0;
}
