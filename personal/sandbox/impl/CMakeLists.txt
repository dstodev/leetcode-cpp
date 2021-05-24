project(ImplTesting)

set(target_private "${PROJECT_NAME}_private")
set(target_public "${PROJECT_NAME}_public")
set(target_consumer "${PROJECT_NAME}_consumer")

add_library(${target_private}
	private.hxx
	private.cxx
)

add_library(${target_public}
	public.hxx
	public.cxx
)
target_link_libraries(${target_public}
	PRIVATE
		${target_private}
)

add_executable(${target_consumer}
	consumer.cxx
)
target_link_libraries(${target_consumer}
	PRIVATE
		${target_public}
)
