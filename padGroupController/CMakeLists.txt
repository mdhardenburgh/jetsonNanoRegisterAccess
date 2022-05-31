cmake_minimum_required(VERSION 3.23.1)
project(padGroupController VERSION 1.0)

add_library(${PROJECT_NAME} INTERFACE)
#add_library(sub::lib2 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})
