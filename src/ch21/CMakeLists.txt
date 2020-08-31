
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

add_executable(ch21_ex2 ex2.cpp)
set_property(TARGET ch21_ex2 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex2 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex3 ex3.cpp)
set_property(TARGET ch21_ex3 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex3 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex5 ex5.cpp)
set_property(TARGET ch21_ex5 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex5 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex6 ex6.cpp)
set_property(TARGET ch21_ex6 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex6 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex11 ex11.cpp)
set_property(TARGET ch21_ex11 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex11 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch21_ex12 ex12.cpp)
set_property(TARGET ch21_ex12 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch21_ex12 PROPERTY CXX_STANDARD_REQUIRED ON)

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