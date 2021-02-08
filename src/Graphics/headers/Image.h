//
// Created on Jan 31, 2021.
//
#pragma once


// Superclass for the RasterImg and VectorImg image types
// Frames only hold pointers to images, so this will make
// raster/vector images interchangeable
class Image
{
public:
	// Vector libraries: Look for Cairo, OpenVG (Khronos group), or ShivaVG
	// Raster libraries: GLEW? SDL, if I can get that to work? plain OpenGL?

	// Drawing: Create a single buffered window, don't clear the front buffer
	// Then: Draw to frame buffer-attached texture so window movement doesn't
	// destroy the drawing
	// Set viewport->window size, ortho projection to window bounds, no glClear

	virtual int draw() = 0;
	// hxrender?
};

