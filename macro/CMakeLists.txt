cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project("private_macro" LANGUAGES C)

add_library(${PROJECT_NAME} INTERFACE)
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/prv)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)


project("macro" LANGUAGES C)

add_library(${PROJECT_NAME} INTERFACE)
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} INTERFACE yslibs::core)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)
