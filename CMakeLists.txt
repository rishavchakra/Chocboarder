cmake_minimum_required(VERSION 3.15)
project(Chocboarder
		VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 14)

#[[         Helpers         ]]
set(CHOC_VERBOSE true)
if(CHOC_VERBOSE)
	macro(CHOC_DBG _MSG)
		message("  << " ${_MSG} " >>  ")
	endmacro()
else()
	macro(CHOC_DBG _MSG)
	endmacro()
endif()


#Adding project and library subdirectories

add_subdirectory(src)


#[[         External libraries          ]]

#           wxWidgets GUI library
CHOC_DBG("Linking wxWidgets GUI library...")

set(wxWidgets_CONFIGURATION mswu)
set(wxWidgets_USE_STATIC ON)
set(WX_VERBOSE false)
find_package(wxWidgets COMPONENTS gl core base)
if(wxWidgets_FOUND)
	CHOC_DBG("wxWidgets linking successful")
	target_include_directories(Chocboarder PUBLIC ${wxWidgets_INCLUDE_DIRS})
	target_link_libraries(Chocboarder PUBLIC ${wxWidgets_LIBRARIES})
else(wxWidgets_FOUND)
	message(FATAL_ERROR "wxWidgets not found!
	Fix FindwxWidgets.cmake in [CMake]/share/cmakeXXX/Modules. /
	Add file paths to wxWidgets include, library, and root in the PATHS of any find_path()")
endif(wxWidgets_FOUND)


#			GLEW OpenGL library
CHOC_DBG("Linking GLEW OpenGL library...")

set(GLEW_VERBOSE true)
set(GLEW_USE_STATIC_LIBS true)
find_package(GLEW)
if(GLEW_FOUND)
	CHOC_DBG("GLEW linking successful")
	target_include_directories(Chocboarder PUBLIC ${GLEW_INCLUDE_DIRS})
	target_link_libraries(Chocboarder PUBLIC ${GLEW_STATIC_LIBRARIES})
else(GLEW_FOUND)
	message("GLEW not found!
	Fix FindGLEW.cmake in [CMake]/share/cmakeXXX/Modules.")
endif(GLEW_FOUND)

CHOC_DBG("Finished building CMake modules")