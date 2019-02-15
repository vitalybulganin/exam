cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME t9-spelling)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
# Collecting a list of sources.
file(GLOB_RECURSE SOURCE_FILES src/*.h src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} src/common/t9-converter.h src/common/convertable.h src/common/t9-converter.cpp)