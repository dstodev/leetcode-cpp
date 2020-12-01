add_library(runaway
	gameboard
	request
	response
)

target_include_directories(runaway
	PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(runaway
	PRIVATE
	cxx_std_17
	)

if (WIN32)
	target_include_directories(runaway
		PUBLIC
			${CMAKE_CURRENT_LIST_DIR}/windows
	)
	target_link_libraries(runaway
		PRIVATE
			ws2_32
	)
	target_sources(runaway
		PRIVATE
			windows/socket
			windows/exceptions
	)
endif ()
