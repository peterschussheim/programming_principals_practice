include_directories(${programming_principals}/include)

file(GLOB SOURCES "*.cpp")

#add_library(Exercises ${SOURCES})

add_executable(main main.cpp std_lib_facilities.h)
set_property(TARGET main PROPERTY CXX_STANDARD 11)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)