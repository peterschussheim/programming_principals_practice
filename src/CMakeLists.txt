file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
add_subdirectory(ch14)
add_subdirectory(ch15)

add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 17)
set_property(TARGET main PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch8_drill use.cpp my.cpp my.h)
set_property(TARGET ch8_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch8_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch9_drill ch9.cpp)
set_property(TARGET ch9_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch9_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch10_drill ch10.cpp)
set_property(TARGET ch10_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch10_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch10_ex1 ch10_ex1.cpp)
set_property(TARGET ch10_ex1 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch10_ex1 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch11_ex2 ch11_ex2.cpp)
set_property(TARGET ch11_ex2 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch11_ex2 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch11_drill ch11.cpp)
set_property(TARGET ch11_drill PROPERTY CXX_STANDARD 17)
set_property(TARGET ch11_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(Chrono Chrono.cpp)
set_property(TARGET Chrono PROPERTY CXX_STANDARD 17)
set_property(TARGET Chrono PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(Test_output Test_output.cpp)
set_property(TARGET Test_output PROPERTY CXX_STANDARD 17)
set_property(TARGET Test_output PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(To_lower To_lower.cpp)
set_property(TARGET To_lower PROPERTY CXX_STANDARD 17)
set_property(TARGET To_lower PROPERTY CXX_STANDARD_REQUIRED ON)

# FLTK setup
find_package(fltk REQUIRED)
add_executable(ch12_drill ch12_drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp)
target_link_libraries(ch12_drill PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch12_drill PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch12_drill PROPERTY CXX_STANDARD 11)
set_property(TARGET ch12_drill PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch12_exercises ch12_exercises.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp)
target_link_libraries(ch12_exercises PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch12_exercises PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch12_exercises PROPERTY CXX_STANDARD 11)
set_property(TARGET ch12_exercises PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch13_drill ch13_drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp)
target_link_libraries(ch13_drill PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch13_drill PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch13_drill PROPERTY CXX_STANDARD 11)
set_property(TARGET ch13_drill PROPERTY CXX_STANDARD_REQUIRED ON)


find_package(fltk REQUIRED)
add_executable(ch13_ex ch13_ex.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp)
target_link_libraries(ch13_ex PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch13_ex PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch13_ex PROPERTY CXX_STANDARD 11)
set_property(TARGET ch13_ex PROPERTY CXX_STANDARD_REQUIRED ON)