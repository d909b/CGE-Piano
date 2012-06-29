/*
 * GLFWWrapper.h
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */

#pragma once

#include <string>
#include <exception>
#include <boost/function.hpp>
#include <glfw.h>
#include "../Utility/MessagedException.h"
#include "../Utility/OpenGL.h"
#include "../Utility/OpenAL.h"
#include <il.h>

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

	void setWindowCloseCallback(boost::function<int (void)> callback);
	void setMouseMoveCallback(boost::function<void (int, int)> callback);
	void setButtonPressedCallback(boost::function<void (int, int)> callback);

	void setWindowTitle(std::string title);
	void openWindowHint(int target, int hint);
	void swapBuffers();

	void getWindowSize(int* width, int* height);
	void setMousePosition(int x, int y);

	void openWindow(int width, int height,
					int redbits, int greenbits, int bluebits,
					int alphabits, int depthbits, int stencilbits,
					int mode) const;

	static boost::function<int ()> windowCloseCallback_;
	static boost::function<void (int, int)> mouseMoveCallback_;
	static boost::function<void (int, int)> buttonPressedCallback_;
};

class GLFWException : public MessagedException
{
public:
	GLFWException(std::string reason) throw() :
		MessagedException(reason)
	{;}
};

