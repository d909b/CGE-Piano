/*
 * GLFWWrapper.h
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */

#pragma once

#include <string>
#include <exception>
#include <glfw.h>
#include "../Utility/MessagedException.h"

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

