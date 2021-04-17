set(target_name runaway)

add_library(${target_name}
	isocket.hxx
	isockserver.hxx
	isockclient.hxx
	gameboard.hxx
	gameboard.cxx
	request.hxx
	request.cxx
	response.hxx
	response.cxx
)

target_include_directories(${target_name}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(${target_name}
	PUBLIC
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
			windows/socket.hxx
			windows/socket.cxx
			windows/sockserver.hxx
			windows/sockserver.cxx
			windows/sockclient.hxx
			windows/sockclient.cxx
			windows/exceptions.hxx
			windows/exceptions.cxx
			windows/wsawrapper.hxx
			windows/wsawrapper.cxx
	)
endif ()
