#Specify version of CMake being used
cmake_minimum_required(VERSION 2.8.7)

# Project name
project(gameoflife)

# flags to the compiler
add_definitions(-Wall -g)

# set TOP DIR
set(TOP_DIR ..)

# subdirectories and headers
include_directories(${TOP_DIR}/headers)

# set SRC_DIR
# all source files in src/ are now associated in SRC variable
set(SRC_DIR ${TOP_DIR}/src)
aux_source_directory(${SRC_DIR} SRC)

# create executable
add_executable(gameoflife ${SRC})

# set directory for executable
set_target_properties(gameoflife PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TOP_DIR}/bin)
