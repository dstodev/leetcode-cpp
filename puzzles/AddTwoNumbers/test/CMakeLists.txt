include(GoogleTest)

# Test re-implemented given auxiliary code
add_executable(${PROJECT_NAME}_test_given
	test_given.cxx
)
target_link_libraries(${PROJECT_NAME}_test_given
	PRIVATE
		${PROJECT_NAME}_given
		gtest_main
)

gtest_discover_tests(${PROJECT_NAME}_test_given)

# Test solution
add_executable(${PROJECT_NAME}_test_solution
	test_helpers.cxx
	test_solution.cxx
)
target_link_libraries(${PROJECT_NAME}_test_solution
	PRIVATE
		${PROJECT_NAME}_given
		${PROJECT_NAME}_solution
		gtest_main
)

gtest_discover_tests(${PROJECT_NAME}_test_solution)
