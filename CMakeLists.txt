cmake_minimum_required (VERSION 3.12)

project ("yslibs" LANGUAGES C)

set(SOURCES "main.c")
#set(HEADERS "main.h")

add_executable (${PROJECT_NAME} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 23)

add_subdirectory(core)
add_subdirectory(macro)
add_subdirectory(util)
# add_subdirectory(algorithm)
# add_subdirectory(collection)
# add_subdirectory(task1)
# add_subdirectory(task2)
# add_subdirectory(task3)

if (MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC -D_CRT_SECURE_NO_WARNINGS)
endif()

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}::core)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}::macro)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}::util)
##target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}::algorithm)
