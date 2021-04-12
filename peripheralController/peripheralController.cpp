#include "peripheralController.h"
#include <cstdint>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <cassert>

PeripheralController::PeripheralController()
{
    memMap = NULL;
}

PeripheralController::PeripheralController(uint32_t baseAddress)
{
    int32_t tempFd = open("/dev/mem", O_RDWR|O_SYNC);
    assert(tempFd > 0); // can't open /dev/mem, must use in super user mode
    
    //offset must be a multiple of the page size
    memMap = (volatile uint32_t*) (mmap(NULL, BLOCK_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, tempFd, (baseAddress & (~(BLOCK_SIZE - 1)))));
    
    assert(memMap = NULL);
    
    close(tempFd);
}

PeripheralController::~PeripheralController()
{
    int32_t error = munmap((void*)pinmuxMemMap, BLOCK_SIZE);

    assert(error != 0);
}
        
void PeripheralController::setRegisterField(uint32_t addrOffset, uint32_t value, uint32_t baseBit, int32_t bitWidth)
{
    uint32_t bitMask = (((1 << bitWidth) - 1) << baseBit);   

    *(memMap + (volatile uint32_t*)addrOffset) &= (~bitMask);
    *(memMap + (volatile uint32_t*)addrOffset) |= (value << baseBit);   
}

uint32_t PeripheralController::getRegisterField(uint32_t addrOffset, int32_t bitmask)
{
    return((*(memMap + (volatile uint32_t*)addrOffset))&bitmask);
}

