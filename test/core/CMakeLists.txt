cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

file(GLOB_RECURSE SOURCES *.c)

find_library(YSLIBS_CORE NAMES yslibs::core)

foreach(test_file ${SOURCES})
    get_filename_component(test_filename test_file NAME_WLE)
    set(test_name "${test_filename}_ctest")
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} PRIVATE yslibs::core)
    add_test(
        NAME ${test_name}
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        COMMAND ${test_name}
    )
endforeach(test_file)