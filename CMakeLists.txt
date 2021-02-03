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
src/Graphics/Tools.cpp
src/Graphics/Image.cpp
src/Graphics/Frame.cpp
src/Graphics/Sequence.cpp
)
set(graphics_headers
src/Graphics/headers/Tools.h
src/Graphics/headers/Image.h
src/Graphics/headers/Frame.h
src/Graphics/headers/Sequence.h
)

set(window_source
src/GUI/App.cpp
src/GUI/WindowMain.cpp
src/GUI/Canvas.cpp
)
set(window_headers
src/GUI/headers/App.h
src/GUI/headers/WindowMain.h
src/GUI/headers/Canvas.h
)

set(additional_dependencies
#		lib/GLAD/src/glad.c
		
		src/glob/values.hpp
		src/GUI/Functions.cpp)

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