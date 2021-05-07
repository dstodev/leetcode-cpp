project(ImplTesting)

set(target_name_private "${PROJECT_NAME}_private")
set(target_name_public "${PROJECT_NAME}_public")
set(target_name_consumer "${PROJECT_NAME}_consumer")

add_library(${target_name_private}
	private.hxx
	private.cxx
)

add_library(${target_name_public}
	public.hxx
	public.cxx
)
target_link_libraries(${target_name_public}
	PRIVATE
		private
)

add_executable(${target_name_consumer}
	consumer.cxx
)
target_link_libraries(${target_name_consumer}
	PRIVATE
		public
)
