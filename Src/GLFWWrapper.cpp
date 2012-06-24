/*
 * GLFWWrapper.cpp
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */

#include "glm/glm.hpp"
#include "GLFWWrapper.h"
#include <AL/al.h>

GLFWWrapper::GLFWWrapper()
{
	glm::vec2(-1.0f,-1.0f);
	alGetError();
}

GLFWWrapper::~GLFWWrapper()
{
	;
}

void GLFWWrapper::initialize() const
{
}

void GLFWWrapper::terminate() const
{
}

void GLFWWrapper::openWindow(int width, int height, int redbits, int greenbits,
						     int bluebits, int alphabits, int depthbits, int stencilbits,
						     int mode) const
{
}

int main(int argc, char** argv)
{
	glfwInit();
	return 0;
}
