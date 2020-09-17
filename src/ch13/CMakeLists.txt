find_package(fltk REQUIRED)
add_executable(ch13_drill ch13_drill.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch13_drill PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch13_drill PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch13_drill PROPERTY CXX_STANDARD 11)
set_property(TARGET ch13_drill PROPERTY CXX_STANDARD_REQUIRED ON)


find_package(fltk REQUIRED)
add_executable(ch13_ex ch13_ex.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch13_ex PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch13_ex PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch13_ex PROPERTY CXX_STANDARD 11)
set_property(TARGET ch13_ex PROPERTY CXX_STANDARD_REQUIRED ON)