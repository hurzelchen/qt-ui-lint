include_guard(GLOBAL)

include(CMakeParseArguments)

# Wrapper function to create and register a test application and setup dependencies
function(qt_ui_lint_add_test test_name)
    string(TOLOWER "${test_name}" output_name)

    qt_add_executable("${test_name}" ${ARGN})

    set_target_properties("${test_name}" PROPERTIES OUTPUT_NAME "${output_name}")

    target_link_libraries("${test_name}" PRIVATE qt-ui-lint-obj)

    target_link_libraries("${test_name}" PRIVATE Qt6::Core)
    target_link_libraries("${test_name}" PRIVATE Qt6::Test)

    add_test(NAME "${test_name}" COMMAND "${output_name}")
endfunction(qt_ui_lint_add_test)
