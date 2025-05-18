cmake_minimum_required(VERSION 3.30)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_library(untitled STATIC
        N-DG.c
        MergeSort.c
        JB.c
        DP.c
        QuickSort.c
        BastCW.c)

add_executable(N-DG N-DG.c)
add_executable(JB JB.c)
add_executable(QuickSort QuickSort.c)
add_executable(HeapSort HeapSort.c)
add_executable(DP DP.c)