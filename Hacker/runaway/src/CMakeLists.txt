set(target_name runaway)

add_library(${target_name}
	gameboard
	request
	response
)

target_include_directories(${target_name}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(${target_name}
	PRIVATE
		cxx_std_17
)

if (WIN32)
	target_include_directories(${target_name}
		PUBLIC
			${CMAKE_CURRENT_LIST_DIR}/windows
	)
	target_link_libraries(${target_name}
		PRIVATE
			ws2_32
	)
	target_sources(${target_name}
		PRIVATE
			windows/socket
			windows/exceptions
			windows/wsawrapper
	)
endif ()
