cmake_minimum_required(VERSION 3.6)
project(localAssignmentC__)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Location.cpp Location.h Mammal.cpp Mammal.h extraFuncs.h extraFuncs.cpp Pod.cpp Pod.h)
add_executable(localAssignmentC__ ${SOURCE_FILES})