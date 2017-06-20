cmake_minimum_required(VERSION 2.8)
project(asminter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

file(GLOB HEADERS "./*.h")
file(GLOB SOURCES "./*.cpp")
add_executable(asminter ${SOURCES} ${HEADERS} type.h)
set_target_properties(asminter PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")

