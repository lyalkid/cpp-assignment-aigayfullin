cmake_minimum_required(VERSION 3.16)
project(cw04)

# Add executable target

add_executable(stack stack.cpp)
target_compile_options(stack PRIVATE -O0 -fno-stack-protector)
# target_compile_features(stack PRIVATE cxx_std_17)

add_executable(stack_canary stack_canary.cpp)
target_compile_options(stack_canary PRIVATE -O0 -fstack-protector-all)
# target_compile_features(stack_canary PRIVATE cxx_std_17)

add_executable(heap heap.cpp)
target_compile_options(heap PRIVATE -O0 -fno-stack-protector)
# target_compile_features(heap PRIVATE cxx_std_17)

add_executable(dyn_mem dyn_mem.cpp)

# add_executable(cw04 cw04.cpp)
# target_compile_options(cw04 PRIVATE -O0 -fno-stack-protector)