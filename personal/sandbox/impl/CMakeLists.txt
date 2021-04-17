project(ImplTesting)

add_library(private
	private.hxx
	private.cxx
)

add_library(public
	public.hxx
	public.cxx
)
target_link_libraries(public
	PRIVATE
		private
)

add_executable(consumer
	consumer.cxx
)
target_link_libraries(consumer
	PRIVATE
		public
)
