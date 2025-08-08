cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project("test" LANGUAGES C)

include_directories(${PROJECT_SOURCE_DIR}/inc)

message("--- BUILDING TESTS ---")

add_subdirectory(core)
add_subdirectory(macro)