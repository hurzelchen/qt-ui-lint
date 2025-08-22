set(HEADERS
    Checker.h
    Finding.h
    Fixer.h
    NoOp.h
    Tool.h
    Toolchain.h
    ToolFactory.h)

set(SOURCES
    Checker.cpp
    Finding.cpp
    Fixer.cpp
    NoOp.cpp
    Tool.cpp
    Toolchain.cpp
    ToolFactory.cpp)

add_library(qt-ui-lint-obj OBJECT ${HEADERS} ${SOURCES})

target_link_libraries(qt-ui-lint-obj PUBLIC Qt6::Core)

target_include_directories(qt-ui-lint-obj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
