cmake_minimum_required(VERSION 3.0)

project(factorial)

add_executable(factorial 
    factorial.c 
    ${PROJECT_SOURCE_DIR}/src/big_int.c)
target_include_directories(factorial PUBLIC ${PROJECT_SOURCE_DIR}/include)