cmake_minimum_required(VERSION 3.28)

project(GameMaths)

set(CMAKE_CXX_STANDARD 17)

# Build raylib from your local raylib folder
add_subdirectory(../raylib raylib_build)

# --------------------
# Math Library
# --------------------
add_library(
    mathlib
    src/GameMath.cpp
)

target_include_directories(
    mathlib
    PUBLIC
    include
)

# --------------------
# Vector Demo
# --------------------
add_executable(
    vector_demo
    demos/vector_demo.cpp
)

target_link_libraries(
    vector_demo
    PRIVATE
    mathlib
    raylib
)

# --------------------
# Point Demo
# --------------------
add_executable(
    point_demo
    demos/point_demo.cpp
)

target_link_libraries(
    point_demo
    PRIVATE
    mathlib
    raylib
)

add_executable(
    normalize_demo
    demos/normalize_demo.cpp
)

target_link_libraries(
    normalize_demo
    PRIVATE
    mathlib
    raylib
)
add_executable(
    vector_add_demo
    demos/vector_add_demo.cpp
)

target_link_libraries(
    vector_add_demo
    PRIVATE
    mathlib
    raylib
)
add_executable(
    dot_demo
    demos/dot_demo.cpp
)

target_link_libraries(
    dot_demo
    PRIVATE
    mathlib
    raylib
)
add_executable(
    jump_demo
    demos/jump_demo.cpp
)

target_link_libraries(
    jump_demo
    PRIVATE
    mathlib
    raylib
)

add_executable(
    lerp_demo
    demos/lerp_demo.cpp
)

target_link_libraries(
    lerp_demo
    PRIVATE
    mathlib
    raylib
)