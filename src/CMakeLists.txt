#[[         Setting source file lists          ]]
set(graphics_source
		Graphics/Tools.cpp
		Graphics/Image.cpp
		Graphics/RasterImg.cpp
		Graphics/Frame.cpp
		Graphics/Sequence.cpp
		)
set(graphics_headers
		Graphics/headers/Tools.h
		Graphics/headers/Image.h
		Graphics/headers/RasterImg.h
		Graphics/headers/Frame.h
		Graphics/headers/Sequence.h
		)

set(window_source
		GUI/App.cpp
		GUI/WindowMain.cpp
		GUI/Canvas.cpp
		)
set(window_headers
		GUI/headers/App.h
		GUI/headers/WindowMain.h
		GUI/headers/Canvas.h
		)

set(additional_dependencies
		glob/values.hpp
		GUI/Functions.cpp)

add_executable(Chocboarder WIN32
		${graphics_source}
		${graphics_headers}
		
		${window_source}
		${window_headers}
		
		${additional_dependencies}
		)

target_link_libraries(Chocboarder PUBLIC GLAD)

#Include project directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


#[[         External libraries          ]]

#           wxWidgets GUI library
#[[
DBG_SAY("Starting Building wxWidgets GUI library...")

set(wxWidgets_CONFIGURATION mswd)
set(wxWidgets_USE_STATIC ON)
DBG_SAY("Starting search for wxWidgets")
find_package(wxWidgets COMPONENTS gl core base REQUIRED)
if(wxWidgets_FOUND)
	DBG_SAY("Found wxWidgets")
	include(${wxWidgets_USE_FILE})
	target_link_libraries(Chocboarder ${wxWidgets_LIBRARIES})
else(wxWidgets_FOUND)
	message(FATAL_ERROR "wxWidgets not found!
	Fix FindwxWidgets.cmake in [CMake]/share/cmakeXXX/Modules. Add file paths to wxWidgets include, library, and root in the PATHS of any find_path()")
endif(wxWidgets_FOUND)

DBG_SAY("Built wxWidgets")
]]