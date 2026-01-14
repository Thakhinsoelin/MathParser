cmake_minimum_required(VERSION 3.10)

project(math LANGUAGES C)
# set(PROJECT_NAME math)
set(CMAKE_C_STANDARD 11)

file(GLOB SRC_FILES
    src/*.c
)

include_directories(${CMAKE_SOURCE_DIR}/includes)
add_executable(${PROJECT_NAME} ${SRC_FILES})
