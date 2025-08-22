cmake_minimum_required(VERSION 3.16)

project(
    qt-ui-lint
    VERSION 0.1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(qt-ui-lint src/main.cpp)

target_link_libraries(qt-ui-lint PRIVATE qt-ui-lint-obj)
