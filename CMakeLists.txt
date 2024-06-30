cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("yslibs" LANGUAGES C)

set(HEADERS "main.h")
set(SOURCES "main.c")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

add_subdirectory(core)
add_subdirectory(macro)
add_subdirectory(util)
add_subdirectory(algorithm)
add_subdirectory(collection)


if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS)
endif()

# most aggressive warning settings
target_compile_options(${PROJECT_NAME}
    PUBLIC "-Wall"
    PUBLIC "-Wextra"
    PUBLIC "-Werror"
    PUBLIC "-pedantic"
)

target_link_libraries(${PROJECT_NAME}
    INTERFACE ${PROJECT_NAME}::core
    INTERFACE ${PROJECT_NAME}::macro
    PRIVATE   ${PROJECT_NAME}::util
    PRIVATE   ${PROJECT_NAME}::algorithm
    PRIVATE   ${PROJECT_NAME}::collection
)
