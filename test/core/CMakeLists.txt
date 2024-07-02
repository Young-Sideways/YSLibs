cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("core_test" LANGUAGES C)

set(SOURCES "main.c")

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    INTERFACE yslibs::core
)