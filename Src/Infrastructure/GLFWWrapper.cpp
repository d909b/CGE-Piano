/*
 * GLFWWrapper.cpp
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */

#if __CDT_PARSER__
	#include <gl.h>
	#include <glu.h>
	#include <al.h>
#else
	#if __APPLE__
		#include <OpenGL/gl.h>
		#include <OpenGL/glu.h>
		#include <OpenAL/al.h>
	#else
		#include <GL/glut.h>
		#include <GL/gl.h>
		#include <GL/glu.h>
		#include <AL/al.h>
	#endif
#endif

#include "glm/glm.hpp"
#include "GLFWWrapper.h"


GLFWWrapper::GLFWWrapper()
{
	;
}

void GLFWWrapper::initialize() const
{
	if(glfwInit() != GL_TRUE)
	{
		throw GLFWException("Failed to initialize GLFW.");
	}
}

void GLFWWrapper::terminate() const
{
	glfwCloseWindow();
	glfwTerminate();
}

void GLFWWrapper::setWindowTitle(std::string title)
{
	glfwSetWindowTitle(title.c_str());
}

void GLFWWrapper::openWindowHint(int target, int hint)
{
	glfwOpenWindowHint(target, hint);
}

void GLFWWrapper::openWindow(int width, int height, int redbits, int greenbits,
						     int bluebits, int alphabits, int depthbits, int stencilbits,
						     int mode) const
{
	int success = glfwOpenWindow(width, height, redbits, greenbits, bluebits, alphabits, depthbits, stencilbits, mode);

	if(success != GL_TRUE)
	{
		throw GLFWException("Failed to open the GLFW window.");
	}
}
