cmake_minimum_required(VERSION 3.15)
project(Chocboarder
		VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 14)

#[[         Helpers         ]]
set(CHOC_VERBOSE true)
if(CHOC_VERBOSE)
	macro(DBG_SAY _MSG)
		message("  << " ${_MSG} " >>  ")
	endmacro()
else()
	macro(DBG_SAY _MSG)
	endmacro()
endif()

#[[         Setting source file lists          ]]
set(graphics_source
		)
set(graphics_headers
		)

set(window_source
		)
set(window_headers
		)

set(additional_dependencies
		lib/GLAD/src/glad.c src/cApp.cpp src/cApp.h)

#[[         Adding executables          ]]
add_executable(Chocboarder WIN32
		src/cApp.cpp src/cApp.h
#		${graphics_source}
#		${graphics_headers}
#
#		${window_source}
#		${window_headers}
#
#		${additional_dependencies}
		src/cMain.cpp src/cMain.h)

#Include project directories
include_directories(include)

#[[         External libraries          ]]
#           GLFW OpenGL Framework
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/GLFW)
include_directories(lib/GLFW/include)
target_link_libraries(Chocboarder glfw)

#           GLAD OpenGL extension library
include_directories(lib/GLAD/include)

#           GLEW OpenGL extension library
set(USING_GLEW false)
if(USING_GLEW)
	set(GLEW_USE_STATIC_LIBS true)
	set(GLEW_VERBOSE true)
	find_package(GLEW REQUIRED)
	if(GLEW_FOUND)
		include_directories(${GLEW_INCLUDE_DIRS})
		target_link_libraries(Chocboarder ${GLEW_LIBRARIES})
	else(GLEW_FOUND)
		message(FATAL_ERROR "GlEW OpenGL Extension Library not found
		Fix FindGLEW.cmake in [CMake]/share/cmakeXXX/Modules. Add your filepath to the built libraries in the PATHS of any find_path()")
	endif(GLEW_FOUND)
else(USING_GLEW)
	DBG_SAY("Not using GLEW OpenGL Extension Library")
endif()

#           wxWidgets GUI library
set(wxWidgets_CONFIGURATION mswd)
set(wxWidgets_USE_STATIC ON)
find_package(wxWidgets COMPONENTS gl core base REQUIRED)
include(${wxWidgets_USE_FILE})
target_link_libraries(Chocboarder ${wxWidgets_LIBRARIES})
