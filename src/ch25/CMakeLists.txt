add_executable(ch25_try_this try_this.cpp)
set_property(TARGET ch25_try_this PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_try_this PROPERTY CXX_STANDARD_REQUIRED ON)
add_custom_command(
        TARGET ch25_try_this POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/encrypted.txt
                ${CMAKE_CURRENT_BINARY_DIR}/encrypted.txt
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/constitution.txt
                ${CMAKE_CURRENT_BINARY_DIR}/constitution.txt)

add_executable(ch25_drill drill.cpp)
set_property(TARGET ch25_drill PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_drill PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex2 ex2.cpp)
set_property(TARGET ch25_ex2 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex2 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex3 ex3.cpp)
set_property(TARGET ch25_ex3 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex3 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex4 ex4.cpp)
set_property(TARGET ch25_ex4 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex4 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex5 ex5.cpp)
set_property(TARGET ch25_ex5 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex5 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex6 ex6.cpp)
set_property(TARGET ch25_ex6 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex6 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex7 ex7.cpp)
set_property(TARGET ch25_ex7 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex7 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex8 ex8.cpp)
set_property(TARGET ch25_ex8 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex8 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex9 ex9.cpp)
set_property(TARGET ch25_ex9 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch25_ex9 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex10 ex10.cpp)
set_property(TARGET ch25_ex10 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch25_ex10 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex11 ex11.cpp)
set_property(TARGET ch25_ex11 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex11 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch25_ex12 ex12.cpp)
set_property(TARGET ch25_ex12 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch25_ex12 PROPERTY CXX_STANDARD_REQUIRED ON)