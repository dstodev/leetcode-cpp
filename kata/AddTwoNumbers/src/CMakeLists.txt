# Non-solution auxiliary code; re-implemented to given spec
add_library(${PROJECT_NAME}_given INTERFACE)
target_include_directories(${PROJECT_NAME}_given
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)

# Solution code
add_library(${PROJECT_NAME}_solution
	helpers
)
target_include_directories(${PROJECT_NAME}_solution
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)
