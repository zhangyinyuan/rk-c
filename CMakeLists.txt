#cmake_minimum_required(VERSION 3.29)
#project(rk_c C)
#
#set(CMAKE_C_STANDARD 11)
#
#add_library(rk_c STATIC library.c
#        MergeSort.c)


cmake_minimum_required(VERSION 3.26)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file}
            MergeSort.c
            N.c
    )
endforeach()