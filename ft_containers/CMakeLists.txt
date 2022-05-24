# doc
# https://codevion.github.io/#!cpp/cmake.md

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# name project 
project(exec VERSION 1.0)
# SRC_FILES and add var to add_executable ${SRC_FILES}
file(GLOB_RECURSE SRC_FILES srcs/*.cpp)

add_executable(exec ${SRC_FILES})
target_include_directories(exec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_compile_options(exec PUBLIC -g3 -Wall -Wextra -Werror -Weffc++ -std=c++98 -Wno-deprecated)


# Testing file 
enable_testing()
add_executable(v_erase ./test/vector_erase.cpp)
add_executable(v_iterator ./test/vector_iterator.cpp)
add_executable(v_assign ./test/vector_assign.cpp)
add_executable(v_push_back ./test/vector_push_back.cpp)
add_executable(v_swap ./test/vector_swap.cpp)
add_executable(v_resize ./test/vector_resize.cpp)
add_executable(v_clear ./test/vector_clear.cpp)
add_executable(v_access ./test/vector_access.cpp)


add_test(Test_Vector_Erase v_erase)
add_test(Test_Vector_Iterator v_iterator)
add_test(Test_Vector_Assign v_assign)
add_test(Test_Vector_Push_back v_push_back)
add_test(Test_Vector_Swap v_swap)
add_test(Test_Vector_Resize v_resize)
add_test(Test_Vector_Clear v_clear)
add_test(Test_Vector_Access v_access)
