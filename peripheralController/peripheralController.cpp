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
    (*this).baseAddress = baseAddress;

    int fileDescriptor = open("/dev/mem", O_RDWR|O_SYNC);
    assert(fileDescriptor > 0); // can't open /dev/mem, must use in super user mode
    
    //offset or base address must be a multiple of the page size
    memMap = mmap(NULL, BLOCK_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fileDescriptor, baseAddress & (~(BLOCK_SIZE - 1)));
    assert(memMap != NULL);
    
    close(fileDescriptor);
}

PeripheralController::~PeripheralController()
{
    assert(memMap != NULL);

    int32_t error = munmap(memMap, BLOCK_SIZE);
    (void)error;
    //assert(error <= 0);
}

void PeripheralController::setRegisterField(uint32_t addrOffset, uint32_t value, uint32_t baseBit, uint32_t bitWidth)
{
    assert(memMap != NULL);
    uint32_t bitMask = ((1 << bitWidth) - 1) << baseBit;   

    *((volatile uint8_t*)memMap + (baseAddress&(BLOCK_SIZE - 1)) + addrOffset) &= ~bitMask;   
    *((volatile uint8_t*)memMap + (baseAddress&(BLOCK_SIZE - 1)) + addrOffset) |= (value << baseBit);
}

uint32_t PeripheralController::getRegisterField(uint32_t addrOffset, uint32_t baseBit, uint32_t bitWidth)
{
    assert(memMap != NULL);
    
    uint32_t registerValue = *((volatile uint8_t*)memMap + (baseAddress&(BLOCK_SIZE - 1)) + addrOffset);
    return (registerValue >> baseBit)&((1<<bitWidth)-1); 
}

