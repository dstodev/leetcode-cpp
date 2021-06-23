project(EnumStaticIteration)

set(target_name "${PROJECT_NAME}_main")

add_executable(${target_name}
	main.cxx

	values.hxx
	printer.hxx
	for_enum.hxx
)
