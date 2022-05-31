cmake_minimum_required(VERSION 3.23.1)

# set the project name and version
project(blinky VERSION 1.0)
add_executable(${PROJECT_NAME} blinky.cpp)
configure_file(blinkyConfig.h.in blinkyConfig.h)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(${PROJECT_NAME} gpioController padGroupController peripheralController pinmuxController)
target_compile_options(${PROJECT_NAME} PRIVATE -march=armv8-a -c -g -std=c++11 -Wall -W -Werror -pedantic)

# specify the C++ standard
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)


