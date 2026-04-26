cmake_minimum_required(VERSION 3.28.3)
project(PBFT_blockchain LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC ${PROJECT_SOURCE_DIR}/../Src)

add_executable(${PROJECT_NAME}
        ${SRC}/main.cpp
        ${SRC}/client.cpp
        ${SRC}/node.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${SRC}/
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../Bin
)
