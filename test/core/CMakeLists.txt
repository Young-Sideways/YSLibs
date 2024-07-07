cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("core" LANGUAGES C)
set(PROJECT_BINARY_DIR ${CTEST_BINARY_DIRECTORY}/${PROJECT_NAME})

file(GLOB_RECURSE SOURCES *.c)

foreach(test_file ${SOURCES})
    set(test_name ${test_file}_ctest)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} PRIVATE yslibs::core)
    add_test(
        NAME ${test_name}
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
endforeach(test_file)