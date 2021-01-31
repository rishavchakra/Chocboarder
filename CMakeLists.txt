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
		src/Graphics/Canvas.cpp
		src/Graphics/Tools.cpp)
set(graphics_headers
		src/Graphics/headers/Canvas.h
		src/Graphics/headers/Tools.h)

set(window_source
		src/Window/App.cpp
		src/Window/WindowMain.cpp
		)
set(window_headers
		src/Window/headers/App.h
		src/Window/headers/WindowMain.h)

set(additional_dependencies
#		lib/GLAD/src/glad.c
		
		src/misc/values.hpp
		src/Window/Functions.cpp)

#[[         Adding executables          ]]
add_executable(Chocboarder WIN32
		${graphics_source}
		${graphics_headers}

		${window_source}
		${window_headers}

		${additional_dependencies}
		)

#Include project directories
include_directories(src)

#[[         External libraries          ]]

set(BUILD_GLFW false)
set(BUILD_GLEW false)
set(BUILD_WX true)

#           GLFW OpenGL Framework
if(BUILD_GLFW)
	DBG_SAY("Building GLFW OpenGL library from source...")
	
	set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
	set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
	set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
	add_subdirectory(lib/GLFW)
	include_directories(lib/GLFW/include)
	target_link_libraries(Chocboarder glfw)
else(BUILD_GLFW)
	DBG_SAY("Not building GLFW OpenGL framework, may cause errors")
endif(BUILD_GLFW)

#           GLAD OpenGL extension library
include_directories(lib/GLAD/include)

#           GLEW OpenGL extension library
if(BUILD_GLEW)
	DBG_SAY("Building GLEW OpenGL Extension library...")
	
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
else(BUILD_GLEW)
	DBG_SAY("Not building GLEW OpenGL Extension Library, may cause errors")
endif(BUILD_GLEW)

#           wxWidgets GUI library
if(BUILD_WX)
	DBG_SAY("Building wxWidgets GUI library...")
	
	set(wxWidgets_CONFIGURATION mswd)
	set(wxWidgets_USE_STATIC ON)
	find_package(wxWidgets COMPONENTS gl core base REQUIRED)
	if(wxWidgets_FOUND)
		include(${wxWidgets_USE_FILE})
		target_link_libraries(Chocboarder ${wxWidgets_LIBRARIES})
	else(wxWidgets_FOUND)
		message(FATAL_ERROR "wxWidgets not found!
		Fix FindwxWidgets.cmake in [CMake]/share/cmakeXXX/Modules. Add filepaths to wxwidgets include, library, and root in the PATHS of any find_path()")
	endif(wxWidgets_FOUND)
else(BUILD_WX)
	DBG_SAY("Not building wxWidgets GUI library, may cause errors")
endif(BUILD_WX)