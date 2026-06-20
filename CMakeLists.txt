cmake_minimum_required(VERSION 3.20)

project(MyRenderer
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(myrenderer
    src/main.cpp
)

target_include_directories(myrenderer
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(myrenderer
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)
