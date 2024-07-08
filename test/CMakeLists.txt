cmake_minimum_required (VERSION 3.25 FATAL_ERROR)

message("ctest bin dir: ${CTEST_BINARY_DIRECTORY}")
project ("test" LANGUAGES C)

message("include dir: ${PROJECT_SOURCE_DIR}/inc")
include_directories(${PROJECT_SOURCE_DIR}/inc)

add_subdirectory(core)