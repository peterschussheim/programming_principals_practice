file(GLOB SOURCES "*.cpp")


add_executable(main main.cpp ../include/Split.h std_lib_facilities.h fib.h)
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

add_executable(ch10_ex1 ch10_ex1.cpp std_lib_facilities.h)
set_property(TARGET ch10_ex1 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch10_ex1 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch11_ex2 ch11_ex2.cpp std_lib_facilities.h)
set_property(TARGET ch11_ex2 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch11_ex2 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch11_drill ch11.cpp std_lib_facilities.h)
set_property(TARGET ch11_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch11_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(Chrono Chrono.cpp Chrono.h std_lib_facilities.h)
set_property(TARGET Chrono PROPERTY CXX_STANDARD 17)
set_property(TARGET Chrono PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(Test_output Test_output.cpp std_lib_facilities.h)
set_property(TARGET Test_output PROPERTY CXX_STANDARD 17)
set_property(TARGET Test_output PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(To_lower To_lower.cpp std_lib_facilities.h)
set_property(TARGET To_lower PROPERTY CXX_STANDARD 17)
set_property(TARGET To_lower PROPERTY CXX_STANDARD_REQUIRED ON)

# FLTK setup
find_package(fltk REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
add_executable(ch12_drill ch12_drill.cpp Graph.cpp Window.cpp std_lib_facilities.h)
target_link_libraries(ch12_drill PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch12_drill PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch12_drill PROPERTY CXX_STANDARD 11)
set_property(TARGET ch12_drill PROPERTY CXX_STANDARD_REQUIRED ON)