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

add_executable(${PROJECT_NAME} ${SOURCE_FILES} src/library/converter/lowercase-converter.h src/library/common/convertable.h src/library/converter/lowercase-converter.cpp src/library/parser/file-stream.h src/library/parser/file-stream.cpp src/library/validator/small-validator.h src/library/common/validatable.h src/library/validator/abstract-validator.h src/library/validator/abstract-validator.cpp src/library/validator/small-validator.cpp src/library/validator/large-validator.cpp src/library/validator/validator-factory.h src/library/validator/validator-factory.cpp)