cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("task2" LANGUAGES C)

file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/inc/task1/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

target_link_libraries(${PROJECT_NAME}
        INTERFACE yslibs::core
        INTERFACE yslibs::macro
        PRIVATE   yslibs::util
        PRIVATE   yslibs::algorithm
        PRIVATE   yslibs::collection
)
