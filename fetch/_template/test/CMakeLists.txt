include(GoogleTest)

add_executable(${PROJECT_NAME}_test_solution
		test_solution.cxx
)
target_link_libraries(${PROJECT_NAME}_test_solution
	PRIVATE
		${PROJECT_NAME}_solution
		gtest_main
)

gtest_discover_tests(${PROJECT_NAME}_test_solution)
