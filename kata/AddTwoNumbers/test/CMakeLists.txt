include(GoogleTest)

# Test re-implemented given auxiliary code
add_executable(test_given
	test_given
)
target_link_libraries(test_given
	PRIVATE
		given
		gtest_main
)
gtest_discover_tests(test_given)

# Test solution
add_executable(test_solution
	test_helpers
	test_solution
)
target_link_libraries(test_solution
	PRIVATE
		given
		solution
		gtest_main
)
gtest_discover_tests(test_solution)
