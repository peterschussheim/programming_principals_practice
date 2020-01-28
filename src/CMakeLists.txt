include_directories(${programming_principals}/include)

file(GLOB SOURCES "*.cpp")


add_executable(main main.cpp std_lib_facilities.h)
set_property(TARGET main PROPERTY CXX_STANDARD 11)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch8_drill use.cpp my.cpp my.h)
set_property(TARGET ch8_drill PROPERTY CXX_STANDARD 11)
set_property(TARGET ch8_drill PROPERTY CXX_STANDARD_REQUIRED ON)