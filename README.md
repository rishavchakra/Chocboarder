# Chocboarder
Chocboarder is (will be) a program for creating storyboards and animatics.
<br>All project code is written in C++.
<br>It's not done yet.

## Building
I build this with MSVC, but I don't think there should be any issue with using Clang, MinGW or any other build system as long as the dependencies are built correctly for it.

## Dependencies
* wxWidgets GUI
* GLEW OpenGL

wxWidgets and GLEW are linked externally through CMake. If it's not linking properly, there are a couple of ways to fix it. 
* wxWidgets: Try setting an environment variable called WXWIN, which should be recognized by the wxWidgets CMake module.
* GLEW: Try setting an environment variable called GLEW_ROOT.
* If these don't work, find the Find[package-name].cmake file in the CMake shared directory and change it to accommodate your package installation directory. (I don't think this second option is a good idea, but if necessary, it works)
