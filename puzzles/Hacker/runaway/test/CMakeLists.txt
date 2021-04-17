include(GoogleTest)

add_subdirectory(mock)

set(target_name Hacker_test_runaway)

add_executable(${target_name}
	test_request.cxx

	windows/test_exceptions.cxx
	windows/test_server.hxx
	windows/test_server.cxx
	windows/test_client.hxx
	windows/test_client.cxx
	windows/test_socket.hxx
	windows/test_socket.cxx
)

target_link_libraries(${target_name}
	PRIVATE
		runaway
		mock
		gtest_main
)

gtest_discover_tests(${target_name})
