# Set the project name
cmake_minimum_required(VERSION 3.23.1)
project (peripheralController VERSION 1.0)

# Add a library with the above sources
add_library(${PROJECT_NAME} peripheralController.cpp)
#add_library(sub::lib1 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_compile_options(${PROJECT_NAME} PRIVATE -march=armv8-a -c -g -std=c++11 -Wall -W -Werror -pedantic)
