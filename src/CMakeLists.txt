include_directories(${programming_principals}/include)

file(GLOB SOURCES "*.cpp")


add_executable(main main.cpp std_lib_facilities.h fib.h)
set_property(TARGET main PROPERTY CXX_STANDARD 17)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch8_drill use.cpp my.cpp my.h)
set_property(TARGET ch8_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch8_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch9_drill ch9.cpp std_lib_facilities.h)
set_property(TARGET ch9_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch9_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch10_drill ch10.cpp std_lib_facilities.h)
set_property(TARGET ch10_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch10_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(Chrono Chrono.cpp Chrono.h std_lib_facilities.h)
set_property(TARGET Chrono PROPERTY CXX_STANDARD 17)
set_property(TARGET Chrono PROPERTY CXX_STANDARD_REQUIRED ON)