project(Sandbox)

add_subdirectory(downcast)
add_subdirectory(getopt)
add_subdirectory(impl)
add_subdirectory(interface_destructor)
add_subdirectory(static_enum_iterator)
add_subdirectory(style)
add_subdirectory(specialization)
add_subdirectory(tree)
add_subdirectory(void_t)

if (FUTURE)
	# These things cannot compile because the required features do not exist yet.
	add_subdirectory(static_assert)
endif ()
