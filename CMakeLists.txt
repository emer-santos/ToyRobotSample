cmake_minimum_required(VERSION 3.12)
project(toy_robot_sample LANGUAGES CXX)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBSRC_NAME "src")
set(APP_NAME "run_app")
set(TESTAPP_NAME "run_test")
set(SRC_FILES 
    ${CMAKE_SOURCE_DIR}/src/ToyRobot.cpp
    ${CMAKE_SOURCE_DIR}/src/Command.cpp
    ${CMAKE_SOURCE_DIR}/src/Direction.cpp
)

add_library(${LIBSRC_NAME} ${SRC_FILES})
target_include_directories(${LIBSRC_NAME} INTERFACE ${CMAKE_SOURCE_DIR}/src/ )

add_executable(${TESTAPP_NAME} test_main.cpp)
target_link_libraries(${TESTAPP_NAME} PRIVATE ${LIBSRC_NAME})
target_include_directories(${LIBSRC_NAME} INTERFACE ${CMAKE_SOURCE_DIR} )

add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} PRIVATE ${LIBSRC_NAME})
