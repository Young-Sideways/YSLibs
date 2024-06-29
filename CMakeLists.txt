cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("yslibs" LANGUAGES C)

set(HEADERS "main.h")
set(SOURCES "main.c")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

add_subdirectory(core)
add_subdirectory(macro)
add_subdirectory(util)
add_subdirectory(algorithm)
add_subdirectory(collection)

add_subdirectory(task1)
add_subdirectory(task2)
add_subdirectory(task3)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS)
    target_compile_options(${PROJECT_NAME}
        PUBLIC "-Wno-deprecated-declarations"
        PUBLIC "-w")
endif()

target_link_libraries(${PROJECT_NAME}
    INTERFACE ${PROJECT_NAME}::core
    INTERFACE ${PROJECT_NAME}::macro
    PRIVATE   ${PROJECT_NAME}::util
    PRIVATE   ${PROJECT_NAME}::algorithm
    PRIVATE   ${PROJECT_NAME}::collection

    PRIVATE   ${PROJECT_NAME}::task1
    PRIVATE   ${PROJECT_NAME}::task2
    PRIVATE   ${PROJECT_NAME}::task3
)
