list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(qt-ui-lint-tests)

qt_ui_lint_add_test(ToolchainTest ToolchainTest.cpp)
qt_ui_lint_add_test(ToolFactoryTest ToolFactoryTest.cpp)
