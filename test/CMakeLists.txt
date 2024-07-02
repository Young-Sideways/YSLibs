cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("test" LANGUAGES C)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

# most aggressive warning settings
target_compile_options(${PROJECT_NAME}
    PUBLIC "-Wall"
    PUBLIC "-Wextra"
    PUBLIC "-Werror"
    PUBLIC "-pedantic"
)

set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR}/test CACHE PATH "Path to tests binary dir")

add_subdirectory(core)

add_test(NAME ${PROJECT_NAME}
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    COMMAND core_test)