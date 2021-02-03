set(GLAD_SOURCE
		src/glad.c)

set(GLAD_INCLUDES
		include/glad/glad.h
		include/KHR/khrplatform.h)

add_library(GLAD
		${GLAD_SOURCE}
		${GLAD_INCLUDES})

target_include_directories(GLAD PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)