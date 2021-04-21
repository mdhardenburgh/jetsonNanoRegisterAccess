/**
 * @file peripheralController.h
 * @brief peripheral controller class declaration
 * @author Matthew Hardenburgh
 * @version 0.1
 * @date 3/6/21
 * @copyright Matthew Hardenburgh 2021
 *
 * @section license LICENSE
 * 
 * Jetson Nano peripheral controller class
 * Copyright (C) 2021  Matthew Hardenburgh
 * mdhardenburgh@protonmail.com
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see https://www.gnu.org/licenses/.
 */ 

/**
 * @class PeripheralController
 * @brief Jetson Nano peripheral controller
 * 
 * @section Description
 *
 * The following class provides a simple way to access the control registers
 * of peripherals. 
 * 
 */

#ifndef PERIPHERAL_CONTROLLER_H
#define PERIPHERAL_CONTROLLER_H

#include <cstdint>
#include <cstddef>

class PeripheralController
{
    public:
        PeripheralController();
        PeripheralController(uint32_t baseAddress);
        ~PeripheralController();
        
        /*
         * The following functions use a bitmask technique to 
         * set or get the values for the registers therefore
         * multiple bit fields can be set or get at once.
         */
        void setRegisterField(uint32_t addrOffset, uint32_t value, uint32_t baseBit, uint32_t bitWidth);
        uint32_t getRegisterField(uint32_t addrOffset, uint32_t baseBit, uint32_t bitWidth);

       
    private:
        const uint32_t BLOCK_SIZE = 0x1000; //4096
        void* memMap = NULL;
	uint32_t baseAddress = 0;

};

#endif //PERIPHERAL_CONTROLLER_H
