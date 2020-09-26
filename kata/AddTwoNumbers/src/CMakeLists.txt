# Non-solution auxiliary code; re-implemented to given spec
add_library(given INTERFACE)
target_include_directories(given
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)

# Solution code
add_library(solution
	helpers
)
target_include_directories(solution
	INTERFACE
		${CMAKE_CURRENT_LIST_DIR}
)
