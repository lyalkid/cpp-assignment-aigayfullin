cmake_minimum_required(VERSION 3.14)
project(cpp_assignment CXX)

# C++ standard specification
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(binary_read_write binary_read_write.cpp)
