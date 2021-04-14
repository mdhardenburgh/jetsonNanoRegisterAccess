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
    memMap = (volatile uint32_t*)(mmap(NULL, BLOCK_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, tempFd, baseAddress));
    
    assert(memMap != NULL);
    
    close(tempFd);
}

PeripheralController::~PeripheralController()
{
    assert(memMap != NULL);

    int32_t error = munmap((void*)memMap, BLOCK_SIZE);

    assert(error != 0);
}

void PeripheralController::setRegisterField(uint32_t addrOffset, uint32_t value, uint32_t baseBit, uint32_t bitWidth)
{
    assert(memMap != NULL);
    uint32_t bitMask = (((1 << bitWidth) - 1) << baseBit);   

    *(memMap + addrOffset) &= (~bitMask);
    *(memMap + addrOffset) |= (value << baseBit);   
}

uint32_t PeripheralController::getRegisterField(uint32_t addrOffset, uint32_t baseBit, uint32_t bitWidth)
{
    assert(memMap != NULL);
    uint32_t bitMask = (((1 << bitWidth) - 1) << baseBit);   
    return((*(memMap + addrOffset))&bitMask);
}

