cmake_minimum_required(VERSION 3.10)
project(software_engineering)

aux_source_directory(src/support/handy/handy handy_lib)
set(handy ${handy_lib})

add_executable(test_main test/random_test.cpp)