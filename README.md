# Chocboarder
Chocboarder is (will be) a program for creating storyboards and animatics.
<br>All project code is written in C++.
<br>It's not done yet.

## Dependencies
* wxWidgets GUI
* SDL Graphics (not yet, but most likely)
* If not SDL, then GLEW OpenGL

wxWidgets is linked externally through CMake, so there are a couple of ways to fix it. 
* Try setting an environment variable called WXWIN, which should be recognized by the wxWidgets CMake module. 
* If not, find the FindwxWidgets.cmake file in the CMake shared directory and change it to accommodate your wxWidgets installation directory. (I don't think this second option is a good idea, but if nothing else, it works)
