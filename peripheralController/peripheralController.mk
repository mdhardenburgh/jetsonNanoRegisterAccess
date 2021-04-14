CXX = aarch64-none-linux-gnu-g++
ARCH_FLAGS = -march=armv8-a
STARTUP_DEFS = 
CXX_FLAGS = $(ARCH_FLAGS) $(STARTUP_DEFS) -c -g -std=c++11 -Wall -W -Werror -pedantic

peripheralController.o: peripheralController.cpp
	$(CXX) $^ $(CXX_FLAGS) -o $@
