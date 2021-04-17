project(StaticAssertTesting)

add_executable(vector_size
	vector_size.cxx
)

target_compile_features(vector_size
	PRIVATE
		cxx_std_20
)
