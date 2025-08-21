cmake_minimum_required(VERSION 3.16)

project(qt-ui-lint VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(qt-ui-lint
    src/main.cpp
)

target_link_libraries(qt-ui-lint PRIVATE Qt6::Core)
