//
// Created on Jan 30, 2021.
//
#pragma once

#include "glob/values.hpp"

#define GLEW_STATIC
#include "gl/glew.h"
#include "wx/wx.h"
#include "wx/glcanvas.h"

class glCanvas : public wxGLCanvas
{
public:
	glCanvas(wxFrame*);
	~glCanvas();

public:
	wxGLContext *m_glContext;
};

