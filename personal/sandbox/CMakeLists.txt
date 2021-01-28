project(Sandbox)

add_subdirectory(downcast)
add_subdirectory(impl)
add_subdirectory(interface_destructor)

if (FUTURE)
	# These things cannot compile because the required features do not exist yet.
	add_subdirectory(static_assert)
endif ()
