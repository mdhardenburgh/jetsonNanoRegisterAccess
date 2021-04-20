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
    fileDescriptor = open("/dev/mem", O_RDWR|O_SYNC);
    assert(fileDescriptor > 0); // can't open /dev/mem, must use in super user mode
    
    void *tempPtr = NULL;

    //offset or base address must be a multiple of the page size
    tempPtr = (mmap(NULL, BLOCK_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fileDescriptor, baseAddress & (~(BLOCK_SIZE - 1))));
    memMap = (volatile uint32_t*)tempPtr + (baseAddress & ((BLOCK_SIZE-1)));
    assert(memMap != NULL);
    
    //close(tempFd);
}

PeripheralController::~PeripheralController()
{
    assert(memMap != NULL);

    int32_t error = munmap((void*)memMap, BLOCK_SIZE);
    (void)error;
    //close(fileDescriptor);
    //assert(error <= 0);
}

void PeripheralController::setRegisterField(uint32_t addrOffset, uint32_t value, uint32_t baseBit, uint32_t bitWidth)
{
    assert(memMap != NULL);
    uint32_t bitMask = (((1 << bitWidth) - 1) << baseBit);   

    *((memMap + (addrOffset))) &= (~bitMask);
    *((memMap + (addrOffset))) |= (value << baseBit);   
}

uint32_t PeripheralController::getRegisterField(uint32_t addrOffset, uint32_t baseBit, uint32_t bitWidth)
{
    assert(memMap != NULL);
    uint32_t bitMask = (((1 << bitWidth) - 1) << baseBit);   
    return((*((memMap + addrOffset)))&bitMask);
}

