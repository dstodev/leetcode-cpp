add_library(mock OBJECT
	mockcallable.hxx
	mocksockclient.hxx
	mocksockclient.cxx
	mocksockserver.hxx
	mocksockserver.cxx
)
target_include_directories(mock
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(mock
	PRIVATE
		runaway
)
