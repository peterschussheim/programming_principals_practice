add_executable(ch_14_drill drill.cpp)
set_property(TARGET ch_14_drill PROPERTY CXX_STANDARD 11)
set_property(TARGET ch_14_drill PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch_14_ex1 ex1.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch_14_ex1 PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch_14_ex1 PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch_14_ex1 PROPERTY CXX_STANDARD 11)
set_property(TARGET ch_14_ex1 PROPERTY CXX_STANDARD_REQUIRED ON)


find_package(fltk REQUIRED)
add_executable(ch_14_binary_tree binary_tree.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch_14_binary_tree PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch_14_binary_tree PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch_14_binary_tree PROPERTY CXX_STANDARD 11)
set_property(TARGET ch_14_binary_tree PROPERTY CXX_STANDARD_REQUIRED ON)