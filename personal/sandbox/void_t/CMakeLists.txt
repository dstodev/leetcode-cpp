project(VoidTTesting)

set(target_name "${PROJECT_NAME}_main")

add_executable(${target_name}
	main.cxx
)

target_compile_features(${target_name}
	PRIVATE
		cxx_std_20
)
