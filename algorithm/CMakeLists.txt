cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project("algorithm" LANGUAGES C)

file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/inc/${PROJECT_NAME}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME}::core)