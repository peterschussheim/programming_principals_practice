include_directories(${programming_principals}/include)

file(GLOB SOURCES "*.cpp")

add_library(Exercises ${SOURCES})
set_property(TARGET Exercises PROPERTY CXX_STANDARD 11)
set_property(TARGET Exercises PROPERTY CXX_STANDARD_REQUIRED ON)
add_executable (main "main.cpp")