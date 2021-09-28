cmake_minimum_required(VERSION 3.20)
project(Lance_C)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lance_C Lance.cpp)
add_executable(BinaryTree src/datastructure/chapter5_tree/BinaryTree.c)
add_executable(LinkedString src/datastructure/chapter4_string/LinkedString.cpp)
add_executable(Index src/datastructure/chapter4_string/Index.cpp)
add_executable(LinkedStack src/datastructure/chapter3_stack&sequence/LinkedStack.cpp)
add_executable(QuickSort src/datastructure/chapter8_sort/QuickSort.c)
add_executable(ReturnString src/runoob/ReturnString.c)
add_executable(Question1 src/GDUT/exam/1.cpp)
