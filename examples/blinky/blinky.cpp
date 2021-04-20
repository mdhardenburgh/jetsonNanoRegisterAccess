#include <iostream>
#include <string>
#include <cassert>
#include <unistd.h>

#include "../../peripheralController/peripheralController.h"
#include "../../gpioController/gpio.h"
//#include "padGroupController.h"
#include "../../pinmuxController/pinmuxController.h"

int main(int argc, char *argv[])
{   
    (void)argc;
    (void)argv;
    PeripheralController myGpioController(gpioController::gpioController3BaseAddress);
    //PeripheralController padController(padControlBase);
    PeripheralController myPinMuxController(pinmuxController::baseAddress);
    
    //uint32_t gpioPinState = gpioController::BIT_N_HIGH;

    
    // blink GPIO header pin 15. GPIO PY.02, Module Pin Number: 218, Module Pin Name GPIO12, Tegra Pin Name LCD_TE
    // GPIO header pin 12, module pin I2S0_SCLK, module pin pin #199, tegra pin name DAP4_SCLK, default usage GPIO, Alternate function Audio I2S #0 Clock, tegra gort # PJ.07 
    //myPinMuxController.setRegisterField(PINMUX_AUX_LCD_TE_0::addressOffset, 0, PINMUX_AUX_LCD_TE_0::PM_bit, PINMUX_AUX_LCD_TE_0::PM_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, 0, PINMUX_AUX_DAP4_SCLK_0::PUPD_bit, PINMUX_AUX_DAP4_SCLK_0::PUPD_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, 0, PINMUX_AUX_DAP4_SCLK_0::TRISTATE_bit, PINMUX_AUX_DAP4_SCLK_0::TRISTATE_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_LCD_TE_0::addressOffset, 0, PINMUX_AUX_LCD_TE_0::PARK_bit, PINMUX_AUX_LCD_TE_0::PARK_bitWidth);
    //myPinMuxController.setRegisterField(PINMUX_AUX_LCD_TE_0::addressOffset, 0, PINMUX_AUX_LCD_TE_0::E_INPUT_bit, PINMUX_AUX_LCD_TE_0::E_INPUT_bitWidth);
    
    uint32_t readPM = myPinMuxController.getRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, PINMUX_AUX_DAP4_SCLK_0::PM_bit, PINMUX_AUX_DAP4_SCLK_0::PM_bitWidth);
    uint32_t readPUPD = myPinMuxController.getRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, PINMUX_AUX_DAP4_SCLK_0::PUPD_bit, PINMUX_AUX_DAP4_SCLK_0::PUPD_bitWidth);
    uint32_t readTRI = myPinMuxController.getRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, PINMUX_AUX_DAP4_SCLK_0::TRISTATE_bit, PINMUX_AUX_DAP4_SCLK_0::TRISTATE_bitWidth);
    uint32_t readPARK = myPinMuxController.getRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, PINMUX_AUX_DAP4_SCLK_0::PARK_bit, PINMUX_AUX_DAP4_SCLK_0::PARK_bitWidth);
    uint32_t readINPUT = myPinMuxController.getRegisterField(PINMUX_AUX_DAP4_SCLK_0::addressOffset, PINMUX_AUX_DAP4_SCLK_0::E_INPUT_bit, PINMUX_AUX_DAP4_SCLK_0::E_INPUT_bitWidth);
    
    std::cout<<"pinmux PM bit: "<<readPM<<std::endl;
    std::cout<<"pinmux PUPD bit: "<<readPUPD<<std::endl;
    std::cout<<"pinmux TRISTATE bit: "<<readTRI<<std::endl;
    std::cout<<"pinmux PARK bit: "<<readPARK<<std::endl;
    std::cout<<"pinmux INPUT bit: "<<readINPUT<<std::endl;

    // port Y is the zeroth port gpio controller 4 grouping
    //myGpioController.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::LOCK_BIT_DISABLE, GPIO_CNF_1_RMW::LOCK_7_baseBit, GPIO_CNF_1_RMW::LOCK_7_bitWidth);
    //myGpioController.setRegisterField(GPIO_CNF_1_RMW::addressOffset, gpioController::BIT_N_GPIO, GPIO_CNF_1_RMW::BIT_7_baseBit, GPIO_CNF_1_RMW::BIT_7_bitWidth);
    //myGpioController.setRegisterField(GPIO_OE_1_RMW::addressOffset, gpioController::BIT_N_DRIVEN, GPIO_OE_1_RMW::BIT_7_baseBit, GPIO_OE_1_RMW::BIT_7_bitWidth);
    //myGpioController.setRegisterField(GPIO_INT_ENB_1::addressOffset, gpioController::BIT_N_DISABLE, GPIO_INT_ENB_1::BIT_7_baseBit, GPIO_INT_ENB_1::BIT_7_bitWidth);
    //myGpioController.setRegisterField(GPIO_OUT_1_RMW::addressOffset, gpioPinState, GPIO_OUT_1_RMW::BIT_7_baseBit, GPIO_OUT_1_RMW::BIT_7_bitWidth);
    /*
    uint32_t readCNF = myGpioController.getRegisterField(GPIO_CNF_1_RMW::addressOffset, GPIO_CNF_1_RMW::BIT_7_baseBit, GPIO_CNF_1_RMW::BIT_7_bitWidth); 
    std::cout<<"Port Y bit 2 CNF GPIO: "<<readCNF<<std::endl;

    uint32_t readCNF2 = myGpioController.getRegisterField(GPIO_CNF_1_RMW::addressOffset, GPIO_CNF_1_RMW::LOCK_7_baseBit, GPIO_CNF_1_RMW::LOCK_7_bitWidth); 
    std::cout<<"Port Y bit 2 CNF LOCK: "<<readCNF2<<std::endl;

    uint32_t readOE = myGpioController.getRegisterField(GPIO_OE_1_RMW::addressOffset, GPIO_OE_1_RMW::BIT_7_baseBit, GPIO_OE_1_RMW::BIT_7_bitWidth); 
    std::cout<<"Port Y bit 2 OE: "<<readOE<<std::endl;
    */
    uint32_t readOUT = myGpioController.getRegisterField(GPIO_OUT_1_RMW::addressOffset, GPIO_OUT_1_RMW::BIT_7_baseBit, GPIO_OUT_1_RMW::BIT_7_bitWidth); 
    std::cout<<"Port Y bit 2 OUT: "<<readOUT<<std::endl;

    while(true)
    {
       // sleep(10);
	break;
    }
     
    //myGpioController.setRegisterField(GPIO_OUT_0_RMW::addressOffset, ~gpioPinState, GPIO_OUT_0_RMW::BIT_2_baseBit, GPIO_OUT_0_RMW::BIT_2_bitWidth);
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
