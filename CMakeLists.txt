cmake_minimum_required(VERSION 3.20)

project(tiny-renderer
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(TINY_RENDERER_SOURCES
    src/camera/camera.cpp
    src/film/film.cpp
    src/math/geometry.cpp
    src/scene/scene.cpp
    src/shapes/sphere.cpp
    src/main.cpp
)

add_library(tiny-renderer-objects OBJECT
    ${TINY_RENDERER_SOURCES}
)

target_include_directories(tiny-renderer-objects
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(tiny-renderer-objects
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

add_executable(tiny-renderer
    $<TARGET_OBJECTS:tiny-renderer-objects>
)
