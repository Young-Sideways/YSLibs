cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project("core" LANGUAGES C)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${CMAKE_PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)
