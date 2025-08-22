qt_add_executable(ToolchainTest ToolchainTest.cpp)

set_target_properties(ToolchainTest PROPERTIES OUTPUT_NAME toolchaintest)

target_link_libraries(ToolchainTest PRIVATE qt-ui-lint-obj)

target_link_libraries(ToolchainTest PRIVATE Qt6::Core)
target_link_libraries(ToolchainTest PRIVATE Qt6::Test)

add_test(NAME ToolchainTest COMMAND toolchaintest)

qt_add_executable(ToolFactoryTest ToolFactoryTest.cpp)

set_target_properties(ToolFactoryTest PROPERTIES OUTPUT_NAME toolfactorytest)

target_link_libraries(ToolFactoryTest PRIVATE qt-ui-lint-obj)

target_link_libraries(ToolFactoryTest PRIVATE Qt6::Core)
target_link_libraries(ToolFactoryTest PRIVATE Qt6::Test)

add_test(NAME ToolFactoryTest COMMAND toolfactorytest)
