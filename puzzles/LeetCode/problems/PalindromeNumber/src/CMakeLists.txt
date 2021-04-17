add_library(${PROJECT_NAME}_solution
	solution.cxx
)
target_include_directories(${PROJECT_NAME}_solution
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)
