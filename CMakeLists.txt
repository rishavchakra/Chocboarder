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
add_subdirectory(lib/GLAD)

add_subdirectory(src)


#[[         External libraries          ]]

#           wxWidgets GUI library
CHOC_DBG("Building wxWidgets GUI library...")

set(wxWidgets_CONFIGURATION mswu)
set(wxWidgets_USE_STATIC ON)
set(WX_VERBOSE false)
find_package(wxWidgets COMPONENTS gl core base)
CHOC_DBG("wxWidgets find successful: ${wxWidgets_FOUND}")
if(wxWidgets_FOUND)
	target_include_directories(Chocboarder PUBLIC ${wxWidgets_INCLUDE_DIRS})
	target_link_libraries(Chocboarder PUBLIC ${wxWidgets_LIBRARIES})
else(wxWidgets_FOUND)
	message(FATAL_ERROR "wxWidgets not found!
	Fix FindwxWidgets.cmake in [CMake]/share/cmakeXXX/Modules. /
	Add file paths to wxWidgets include, library, and root in the PATHS of any find_path()")
endif(wxWidgets_FOUND)

CHOC_DBG("Finished building CMake modules")