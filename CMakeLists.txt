cmake_minimum_required(VERSION 3.0)
project(cmake_test LANGUAGES CXX)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(test main.cpp)
target_include_directories(test INTERFACE lib/)
target_compile_features(test INTERFACE cxx_std_20)

