cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project("collection" LANGUAGES C)

file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/inc/collection/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_options(${PROJECT_NAME}
    PUBLIC  "-fms-extensions"
    PUBLIC  "-Wno-microsoft-anon-tag"
    PRIVATE "-Wno-incompatible-pointer-types"
    PUBLIC "-Wno-pointer-type-mismatch"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

add_subdirectory(private)

target_link_libraries(${PROJECT_NAME}
    #PUBLIC  yslibs::core
    #PUBLIC  yslibs::macro
    #PRIVATE yslibs::algorithm
    PUBLIC  yslibs::private_collection
)
