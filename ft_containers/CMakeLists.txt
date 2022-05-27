# doc
# https://codevion.github.io/#!cpp/cmake.md

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -Wall -Wextra -Werror -Weffc++ -std=c++98 -Wno-deprecated")
# name project 
project(containers VERSION 1.0)
# SRC_FILES and add var to add_executable ${SRC_FILES}
file(GLOB_RECURSE SRC_FILES srcs/*.cpp)

add_executable(containers ${SRC_FILES})
target_include_directories(containers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_compile_options(containers PUBLIC -g3 -Wall -Wextra -Werror -Weffc++ -std=c++98 -Wno-deprecated)


# Testing file 
# Vector 
enable_testing()
add_executable(v_erase ./test/vector_erase.cpp)
add_executable(v_iterator ./test/vector_iterator.cpp)
add_executable(v_assign ./test/vector_assign.cpp)
add_executable(v_push_back ./test/vector_push_back.cpp)
add_executable(v_swap ./test/vector_swap.cpp)
add_executable(v_resize ./test/vector_resize.cpp)
add_executable(v_clear ./test/vector_clear.cpp)
add_executable(v_access ./test/vector_access.cpp)
add_executable(v_equal ./test/vector_equal.cpp)
add_executable(v_lex ./test/vector_lexicographical.cpp)
add_executable(v_enable ./test/vector_enable_if.cpp)
add_executable(v_is_integral ./test/vector_is_integral.cpp)
add_executable(v_pair ./test/vector_pair.cpp)
add_executable(v_iterator_traits ./test/vector_iterator_traits.cpp)
add_executable(v_rev_iterator ./test/rev_iterator.cpp)
add_executable(v_pop_back ./test/vector_pop_back.cpp)
add_executable(v_back ./test/vector_back.cpp)
add_executable(v_empty ./test/vector_empty.cpp)
add_executable(v_capacity ./test/vector_capacity.cpp)
add_executable(v_insert ./test/vector_insert.cpp)

add_test(Test_Vector_Erase v_erase)
add_test(Test_Vector_Iterator v_iterator)
add_test(Test_Vector_Assign v_assign)
add_test(Test_Vector_Push_back v_push_back)
add_test(Test_Vector_Swap v_swap)
add_test(Test_Vector_Resize v_resize)
add_test(Test_Vector_Clear v_clear)
add_test(Test_Vector_Access v_access)
add_test(Test_Vector_Equal v_equal)
add_test(Test_Vector_Lex v_lex)
add_test(Test_Vector_enalble_if v_enable)
add_test(Test_Vector_integral v_is_integral)
add_test(Test_Pair v_pair)
add_test(Test_Vector_Iterator_Trais v_iterator_traits)
add_test(Test_Rev_iterator v_rev_iterator)
add_test(Test_Pop_Back v_pop_back)
add_test(Test_Back v_back)
add_test(Test_Empty v_empty)
add_test(Test_Capacity v_capacity)
add_test(Test_Insert v_insert)

# stack
add_executable(v_stack_empty ./test/stack_empty.cpp)
add_executable(v_stack_size ./test/stack_size.cpp)
add_executable(v_stack_top ./test/stack_top.cpp)
add_executable(v_stack_push ./test/stack_push.cpp)
add_executable(v_stack_pop ./test/stack_pop.cpp)
add_executable(v_stack_swap ./test/stack_swap.cpp)


add_test(Test_Stack_empty v_stack_empty)
add_test(Test_Stack_size v_stack_size)
add_test(Test_Stack_push v_stack_push)
add_test(Test_Stack_swap v_stack_swap)


# main 42 test
add_executable(v_42 ./test/main42.cpp)

add_test(Test_42 v_42 "42")
