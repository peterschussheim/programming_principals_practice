find_package(fltk REQUIRED)
add_executable(ch_15_drill drill.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch_15_drill PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch_15_drill PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch_15_drill PROPERTY CXX_STANDARD 11)
set_property(TARGET ch_15_drill PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch_15_ex1 ex1.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch_15_ex1 PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch_15_ex1 PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch_15_ex1 PROPERTY CXX_STANDARD 11)
set_property(TARGET ch_15_ex1 PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch_15_ex2 ex2.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch_15_ex2 PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch_15_ex2 PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch_15_ex2 PROPERTY CXX_STANDARD 11)
set_property(TARGET ch_15_ex2 PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch_15_ex4 ex4.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch_15_ex4 PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch_15_ex4 PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch_15_ex4 PROPERTY CXX_STANDARD 11)
set_property(TARGET ch_15_ex4 PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch_15_ex5 ex5.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch_15_ex5 PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch_15_ex5 PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch_15_ex5 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch_15_ex5 PROPERTY CXX_STANDARD_REQUIRED ON)
