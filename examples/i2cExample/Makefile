# To cross compile on x86 use the following flags
#include ../../peripheralController/peripheralController.mk
#ARM_GCC_PATH = ../../../gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/
#CXX = $(ARM_GCC_PATH)aarch64-none-linux-gnu-g++
#ARCH_FLAGS = -march=armv8-a
#STARTUP_DEFS =
#CXX_FLAGS = $(ARCH_FLAGS) $(STARTUP_DEFS) -c -g -std=c++11 -Wall -W -Werror -pedantic

# To Compile on the Jetson use the following flags
#include ../../peripheralController/peripheralController.mk
ARM_GCC_PATH = ../../../gcc-arm-10.2-2020.11-x86_64-aarch64-none-linux-gnu/bin/
CXX = g++
ARCH_FLAGS = -march=armv8-a
STARTUP_DEFS = 
CXX_FLAGS = $(STARTUP_DEFS) -c -g -std=c++11 -Wall -W -Werror -pedantic

blinky: blinky.o peripheralController.o
	$(CXX) $^  -o $@

blinky.o: blinky.cpp  
	$(CXX) $^ $(CXX_FLAGS) -o $@

peripheralController.o: ../../peripheralController/peripheralController.cpp
	$(CXX) $^ $(CXX_FLAGS) -o $@

clean:
	rm -f blinky
	rm -r blinky.o
	rm -f ../../peripheralController/peripheralController.o
