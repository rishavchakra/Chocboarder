#include "headers/RasterImg.h"

RasterImg::RasterImg() {
	// Creating one image buffer per Image object may not be efficient,
	// but the alternative would be a nightmare.
	glGenFramebuffers(1, &m_imgBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, m_imgBuffer);

	
}

RasterImg::~RasterImg() {
	glDeleteFramebuffers(1, &m_imgBuffer);
}
