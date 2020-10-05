add_library(impl_private
	impl_private
)

add_library(impl_public
	impl_public
)
target_link_libraries(impl_public
	PRIVATE
		impl_private
)

add_executable(impl_consumer
	impl_consumer
)
target_link_libraries(impl_consumer
	PRIVATE
		impl_public
)
