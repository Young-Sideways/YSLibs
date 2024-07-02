cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project ("yslibs" LANGUAGES C)

set(SOURCES "main.c")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(core)
add_subdirectory(macro)
#add_subdirectory(util)
add_subdirectory(algorithm)
#add_subdirectory(collection)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS)
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE yslibs::core
    PRIVATE yslibs::macro
    PRIVATE yslibs::algorithm
)

get_property(YSLIBS_C_STANDARD TARGET ${PROJECT_NAME} PROPERTY C_STANDARD)
message(STATUS "Building ${PROJECT_NAME}")
message(STATUS "C_FLAGS    : ${CMAKE_C_FLAGS}")
message(STATUS "C_STANDARD : ${YSLIBS_C_STANDARD}")