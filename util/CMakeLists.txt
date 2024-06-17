cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project("util" LANGUAGES C)

file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/inc/${PROJECT_NAME}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_library(yslibs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS)
    target_compile_options(${PROJECT_NAME} PUBLIC "-Wno-deprecated-declarations")
endif()

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/inc)
if (LINUX)
    find_library(MATH_LIBRARY m)
    if(MATH_LIBRARY)
        target_link_libraries(${PROJECT_NAME} PRIVATE ${MATH_LIBRARY})
    endif()
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE yslibs::core
    PRIVATE yslibs::macro
)