add_executable(ch21_try_this try_this.cpp)
set_property(TARGET ch21_try_this PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_try_this PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_drill drill.cpp)
set_property(TARGET ch21_drill PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_drill_map drill_map.cpp)
set_property(TARGET ch21_drill_map PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_drill_map PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_drill_vector drill_vector.cpp)
set_property(TARGET ch21_drill_vector PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_drill_vector PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex3 ex3.cpp)
set_property(TARGET ch21_ex3 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex3 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex5 ex5.cpp)
set_property(TARGET ch21_ex5 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex5 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex6 ex6.cpp)
set_property(TARGET ch21_ex6 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex6 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex7 ex7.cpp)
set_property(TARGET ch21_ex7 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex7 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex8 ex8.cpp)
set_property(TARGET ch21_ex8 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex8 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex9 ex9.cpp)
set_property(TARGET ch21_ex9 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch21_ex9 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex10 ex10.cpp)
set_property(TARGET ch21_ex10 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch21_ex10 PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(fltk REQUIRED)
add_executable(ch21_ex11 ex11.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp)
target_link_libraries(ch21_ex11 PUBLIC ${FLTK_LIBRARIES})
target_include_directories(ch21_ex11 PUBLIC ${FLTK_INCLUDE_DIR})
set_property(TARGET ch21_ex11 PROPERTY CXX_STANDARD 14)
set_property(TARGET ch21_ex11 PROPERTY CXX_STANDARD_REQUIRED ON)

add_custom_command(
        TARGET ch21_drill_map POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/classes.txt
                ${CMAKE_CURRENT_BINARY_DIR}/classes.txt)

add_custom_command(
        TARGET ch21_drill_vector POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/floats.txt
                ${CMAKE_CURRENT_BINARY_DIR}/floats.txt)

# Alternative method of adding multiple items to a custom command
#set(sources_ch21_ex9 ${CMAKE_CURRENT_SOURCE_DIR}/orders_1.txt ${CMAKE_CURRENT_SOURCE_DIR}/orders_2.txt)
#list(APPEND args_ex9 ${sources_ch21_ex9})
add_custom_command(
        TARGET ch21_ex9 ch21_ex10 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/orders_1.txt
                ${CMAKE_CURRENT_BINARY_DIR}/orders_1.txt
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/orders_2.txt
                ${CMAKE_CURRENT_BINARY_DIR}/orders_2.txt)