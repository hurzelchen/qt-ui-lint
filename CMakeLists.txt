cmake_minimum_required(VERSION 3.16)

project(
    qt-ui-lint
    VERSION 0.1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 QUIET COMPONENTS Core Test)

if(Qt6_FOUND)
    set(QT_PREFIX "Qt6")
else()
    find_package(Qt5 REQUIRED COMPONENTS Core Test)

    if(Qt5_FOUND)
        set(QT_PREFIX "Qt5")
    endif()
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(qt-ui-lint src/main.cpp)

target_link_libraries(qt-ui-lint PRIVATE qt-ui-lint-obj)
