# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(IrisDS)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
# Add the include directory for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/iris.cpp
    src/utils.cpp
    main.cpp
)

# Add the executable
add_executable(IrisDS ${SOURCES})

set_target_properties(IrisDS PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

