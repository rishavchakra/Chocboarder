//
// Created on Jan 30, 2021.
//
#include "headers/Canvas.h"

glCanvas::glCanvas(wxFrame *parent) 
: wxGLCanvas(parent, ID::Canvas, {}, wxDefaultPosition, wxDefaultSize, 0, wxT("Storyboard Canvas")) {
	GLenum err_init = glewInit();
	if(err_init != GLEW_OK) {

	}
}

glCanvas::~glCanvas() {

}