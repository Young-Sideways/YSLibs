cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("core" LANGUAGES C)

add_library(${PROJECT_NAME} INTERFACE)
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc/core)
