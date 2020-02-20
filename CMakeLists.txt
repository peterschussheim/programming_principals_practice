# CMakeList.txt : CMake project for programming_principals_practice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (programming_principals CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
include_directories(include)
add_subdirectory(src)

