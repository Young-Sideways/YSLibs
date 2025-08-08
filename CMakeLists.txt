cmake_minimum_required (VERSION 3.25 FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project ("yslibs" LANGUAGES C)


set(SOURCES "main.c")
add_executable(${PROJECT_NAME} ${SOURCES})

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${CMAKE_C_FLAGS} -D_CRT_SECURE_NO_WARNINGS)
endif()

add_subdirectory(core)
add_subdirectory(macro)
add_subdirectory(algorithm)
#add_subdirectory(collection)
add_subdirectory(util)

target_link_libraries(${PROJECT_NAME}
    PRIVATE yslibs::core
    PRIVATE yslibs::macro
    PRIVATE yslibs::algorithm
    #PRIVATE yslibs::collection
    PRIVATE yslibs::util
)

if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(test)
endif(BUILD_TESTING)