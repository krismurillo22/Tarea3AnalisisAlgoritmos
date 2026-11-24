cmake_minimum_required(VERSION 3.16)

project(SortingAlgorithmsBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sorting_benchmark
    src/main.cpp
    src/merge_sort.cpp
    src/selection_sort.cpp
    src/bubble_sort.cpp
    src/quick_sort.cpp
    src/heap_sort.cpp
    src/insertion_sort.cpp
)

target_include_directories(sorting_benchmark PRIVATE include)