cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME t9-spelling)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/library)
# Collecting a list of sources.
file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.cpp)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif (BUILD_TESTING)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})