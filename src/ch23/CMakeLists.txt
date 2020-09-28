add_executable(ch23_try_this try_this.cpp)
set_property(TARGET ch23_try_this PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_try_this PROPERTY CXX_STANDARD_REQUIRED ON)
add_custom_command(
        TARGET ch23_try_this POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/my-mail-file.txt
                ${CMAKE_CURRENT_BINARY_DIR}/my-mail-file.txt)

add_executable(ch23_drill drill.cpp)
set_property(TARGET ch23_drill PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_drill PROPERTY CXX_STANDARD_REQUIRED ON)
add_custom_command(
        TARGET ch23_drill POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/file.txt
                ${CMAKE_CURRENT_BINARY_DIR}/file.txt)

add_executable(ch23_table_validator table_validator.cpp)
set_property(TARGET ch23_table_validator PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_table_validator PROPERTY CXX_STANDARD_REQUIRED ON)
add_custom_command(
        TARGET ch23_table_validator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/table.txt
                ${CMAKE_CURRENT_BINARY_DIR}/table.txt)

add_executable(ch23_ex1 ex1.cpp)
set_property(TARGET ch23_ex1 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex1 PROPERTY CXX_STANDARD_REQUIRED ON)
add_custom_command(
        TARGET ch23_ex1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/mail_file_with_errors.txt
                ${CMAKE_CURRENT_BINARY_DIR}/mail_file_with_errors.txt
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/mail_file_with_errors_2.txt
                ${CMAKE_CURRENT_BINARY_DIR}/mail_file_with_errors_2.txt)


add_executable(ch23_ex2 ex2.cpp)
set_property(TARGET ch23_ex2 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex2 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex3 ex3.cpp)
set_property(TARGET ch23_ex3 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex3 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex5 ex5.cpp)
set_property(TARGET ch23_ex5 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex5 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex6 ex6.cpp)
set_property(TARGET ch23_ex6 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex6 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex7 ex7.cpp)
set_property(TARGET ch23_ex7 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex7 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex8 ex8.cpp)
set_property(TARGET ch23_ex8 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex8 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex9 ex9.cpp)
set_property(TARGET ch23_ex9 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch23_ex9 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex10 ex10.cpp)
set_property(TARGET ch23_ex10 PROPERTY CXX_STANDARD 17)
set_property(TARGET ch23_ex10 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex11 ex11.cpp)
set_property(TARGET ch23_ex11 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex11 PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(ch23_ex12 ex12.cpp)
set_property(TARGET ch23_ex12 PROPERTY CXX_STANDARD 20)
set_property(TARGET ch23_ex12 PROPERTY CXX_STANDARD_REQUIRED ON)