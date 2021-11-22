cmake_minimum_required(VERSION 3.14)
project(my_project C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

#start GoogleTests
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()
#end GoogleTests

add_executable(
        my_project my_project/codewars/counting_duplicates.h
        my_project my_project/codewars/counting_duplicates.c
        my_project my_project/main.c
        my_project my_project/web_examples/binary_search.c
        my_project my_project/web_examples/binary_search.h
        my_project my_project/codewars/palindrome.c
        my_project my_project/codewars/palindrome.h
        my_project my_project/course_ex/exercise_1_20.c
        my_project my_project/course_ex/exercise_1_20.h
        my_project my_project/course_ex/external_variables_and_scope.c
        my_project my_project/course_ex/external_variables_and_scope.h
        my_project my_project/codewars/prime.c
        my_project my_project/course_ex/linked_list/list.c
        my_project my_project/course_ex/linked_list/list.h
)

target_link_libraries(my_project gtest_main)
add_executable(list my_project/course_ex/linked_list/list.c my_project/course_ex/linked_list/list.h my_project/course_ex/linked_list/main.c)