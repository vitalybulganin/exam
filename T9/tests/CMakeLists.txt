cmake_minimum_required(VERSION 3.1.0)
set(PROJECT_NAME gtest-t9)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

if (BUILD_TESTING)
    set(GTEST_LIBS ${GTEST_LIBS} gtest)
else()
    set(GTEST_LIBS ${GTEST_LIBS} "")
endif()
# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
include_directories("{CMAKE_SOURCE_DIR}")
include_directories("./src")
# Collecting a list of sources.
file(GLOB_RECURSE FILES_INC *.h ../src/library/*.h)
file(GLOB_RECURSE FILES_SRC *.cpp ../src/library/*.cpp)

add_executable(${PROJECT_NAME} ${FILES_INC} ${FILES_SRC})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBS} pthread)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} WORKING_DIRECTORY ${PROJECT_BINARY_DIR})

