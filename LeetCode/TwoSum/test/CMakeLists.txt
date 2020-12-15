include(GoogleTest)

add_executable(${PROJECT_NAME}_test_solution
	test_solution
)
target_link_libraries(${PROJECT_NAME}_test_solution
	PRIVATE
		${PROJECT_NAME}_solution
		gtest_main
)
target_compile_features(${PROJECT_NAME}_test_solution
	PRIVATE
		cxx_std_17
)

gtest_discover_tests(${PROJECT_NAME}_test_solution)
