#include <iostream>
#include <string>
#include <cassert>

#include "peripheralController.h"
#include "gpio.h"
#include "padGroupController.h"
#include "pinmuxController.h"

int main()
{
    PeripheralController gpioController(gpioController7BaseAddress);
    PeripheralController padController(padControlBase);
    PeripheralController pinMuxController(pinMuxControlBase);

    // blink GPIO pin 15. GPIO PY.02, Module Pin Number: 218, Module Pin Name GPIO12

    while(true)
    {

    }

    return 0;
}
