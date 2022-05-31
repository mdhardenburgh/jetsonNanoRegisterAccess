# CMakeLists files in this project can
# refer to the root source directory of the project as ${JetsonNanoRegisterAccess_SOURCE_DIR} and
# to the root binary directory of the project as ${JetsonNanoRegisterAccess_BINARY_DIR}.
cmake_minimum_required(VERSION 3.23.1)
project(JetsonNanoRegisterAccess_IS_TOP_LEVEL VERSION 1.0)

# Recurse into the subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory(examples/blinky)
add_subdirectory(gpioController)
add_subdirectory(padGroupController)
add_subdirectory(peripheralController)
add_subdirectory(pinmuxController)
