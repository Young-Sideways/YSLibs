cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project("macro" LANGUAGES C)

add_library(${PROJECT_NAME} INTERFACE)
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

#target_compile_options(${PROJECT_NAME} INTERFACE "-Wno-invalid-token-paste")
target_compile_options(${PROJECT_NAME} INTERFACE "-Wno-gnu-zero-variadic-macro-arguments")

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(${PROJECT_NAME} INTERFACE yslibs::core)
