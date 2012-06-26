/*
 * GLFWWrapper.h
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */

#pragma once

#include <string>
#include <exception>
#include <glew.h>
#include <glfw.h>
#include "../Utility/MessagedException.h"

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
		#include <GL/glu.h>
		#include <GL/gl.h>
		#include <AL/al.h>
	#endif
#endif


/**
 * @class GLFWWrapper
 *
 * A thin wrapper class for the GLFW library.
 *
 * @author Patrick Schwab
 */
class GLFWWrapper
{
public:
	GLFWWrapper();

	void initialize() const;
	void terminate()  const;

	void enable(int option);
	void sleep(double time);
	double getTime();

	void setWindowTitle(std::string title);
	void openWindowHint(int target, int hint);
	void swapBuffers();

	void openWindow(int width, int height,
					int redbits, int greenbits, int bluebits,
					int alphabits, int depthbits, int stencilbits,
					int mode) const;
};

class GLFWException : public MessagedException
{
public:
	GLFWException(std::string reason) throw() :
		MessagedException(reason)
	{;}
};

