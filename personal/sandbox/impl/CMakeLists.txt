project(ImplTesting)

add_library(private
	private
)

add_library(public
	public
)
target_link_libraries(public
	PRIVATE
		private
)

add_executable(consumer
	consumer
)
target_link_libraries(consumer
	PRIVATE
		public
)
