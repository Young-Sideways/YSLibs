cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project("algorithm" LANGUAGES C)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC STATIC ${PROJECT_SOURCE_DIR}/inc)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_PROJECT_NAME}::core)