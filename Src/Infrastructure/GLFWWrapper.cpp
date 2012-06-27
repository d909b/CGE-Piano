/*
 * GLFWWrapper.cpp
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */


#include "GLFWWrapper.h"

int GLFWCALL windowCloseCallback()
{
	return GL_TRUE;
}

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

	glfwSetWindowCloseCallback(windowCloseCallback);
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

void GLFWWrapper::enable(int option)
{
	glfwEnable(option);
}

void GLFWWrapper::sleep(double time)
{
	glfwSleep(time);
}

double GLFWWrapper::getTime()
{
	return glfwGetTime();
}

void GLFWWrapper::swapBuffers()
{
	glfwSwapBuffers();
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
