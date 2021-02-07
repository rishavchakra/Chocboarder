// 
// Created on Feb 3, 2021.
// 
#pragma once

#include "Image.h"

#include "gl/glew.h"

class RasterImg : public Image {
public:
	RasterImg();
	~RasterImg();

public:
	GLuint m_imgBuffer;

	// Try using glTexImage2D?
		// Probably a much better idea to use glTexImage2D instead of array of colors
		// because gl uses VRAM instead of RAM. Better way to store images for caching?
};