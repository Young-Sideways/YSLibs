cmake_minimum_required (VERSION 3.25 FATAL_ERROR)

project ("yslibs" LANGUAGES C)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS)
endif()

set(SOURCES "main.c")
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(core)
target_link_libraries(${PROJECT_NAME}
    PRIVATE yslibs::core
)

if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(test)
endif(BUILD_TESTING)