cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("test" LANGUAGES C)
set(PROJECT_BINARY_DIR ${CTEST_BINARY_DIRECTORY} CACHE PATH "Path to tests binary dir")

include(${PROJECT_SOURCE_DIR}/inc/test.h)

add_subdirectory(core)