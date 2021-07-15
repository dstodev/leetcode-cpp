# Non-solution auxiliary code; re-implemented to given spec
add_library(${PROJECT_NAME}_given INTERFACE)
target_include_directories(${PROJECT_NAME}_given
	INTERFACE
		.
)

# Solution code
add_library(${PROJECT_NAME}_solution
	helpers.hxx
	helpers.cxx
)
target_include_directories(${PROJECT_NAME}_solution
	INTERFACE
		.
)
