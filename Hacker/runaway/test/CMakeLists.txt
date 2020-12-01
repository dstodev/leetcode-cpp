include(GoogleTest)

set(target_name Hacker_test_runaway)

add_executable(${target_name}
	test_request

	windows/test_exceptions
	windows/test_socket
)

target_link_libraries(${target_name}
	PRIVATE
		runaway
		gtest_main
)

gtest_discover_tests(${target_name})
