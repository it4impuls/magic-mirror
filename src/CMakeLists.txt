cmake_minimum_required(VERSION 3.23)
project(MagicMirror)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../bin")

INCLUDE_DIRECTORIES(dependency/restbed/include dependency/json dependency/simpleini)
LINK_DIRECTORIES(dependency/restbed/library)

add_subdirectory(dependency/gtest)

include_directories(
        ${PROJECT_SOURCE_DIR}/src/include
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/tests
        ${PROJECT_SOURCE_DIR}/src/code
)

file(GLOB all_run
        "${PROJECT_SOURCE_DIR}/src/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/source/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/source/*.c"
        "${PROJECT_SOURCE_DIR}/src/MagicMirror/*.cpp"
        )

file(GLOB all_tests
        "${PROJECT_SOURCE_DIR}/src/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/source/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/source/*.c"
        "${PROJECT_SOURCE_DIR}/src/tests/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/tests/*.c"
        )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

add_executable(MagicMirror ${all_run})
add_executable(MagicMirrorTests ${all_tests})


target_link_libraries(MagicMirrorTests gmock gmock_main restbed restbed-shared.dll)
target_link_libraries(MagicMirror restbed restbed-shared.dll)