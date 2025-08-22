set(HEADERS
    Checker.h
    Fixer.h
    Tool.h
    ToolFactory.h
)

set(SOURCES
    Checker.cpp
    Fixer.cpp
    Tool.cpp
    ToolFactory.cpp
)

add_library(qt-ui-lint-obj
    OBJECT
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(qt-ui-lint-obj PUBLIC Qt6::Core)
