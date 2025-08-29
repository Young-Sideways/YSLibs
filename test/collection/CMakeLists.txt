cmake_minimum_required (VERSION 3.25 FATAL_ERROR)

file(GLOB_RECURSE SOURCES *.c)

foreach(test_file ${SOURCES})
    get_filename_component(test_filename ${test_file} NAME_WLE)
    set(test_name "${test_filename}_ctest")

    add_executable(${test_name} ${test_file})

    target_link_libraries(${test_name} PUBLIC yslibs::collection)
    add_test(
        NAME ${test_name}
        COMMAND ${test_name}
    )
endforeach()