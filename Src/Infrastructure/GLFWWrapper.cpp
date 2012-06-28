/*
 * GLFWWrapper.cpp
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */


#include "GLFWWrapper.h"

boost::function<int ()> GLFWWrapper::windowCloseCallback_;
boost::function<void (int, int)> GLFWWrapper::mouseMoveCallback_;
boost::function<void (int, int)> GLFWWrapper::buttonPressedCallback_;

int GLFWCALL windowCloseCallback()
{
	return GLFWWrapper::windowCloseCallback_();
}

void GLFWCALL buttonPressedCallback(int key, int action)
{
	GLFWWrapper::buttonPressedCallback_(key, action);
}

void GLFWCALL mouseMoveCallback(int x, int y)
{
	GLFWWrapper::mouseMoveCallback_(x, y);
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
}

void GLFWWrapper::setWindowCloseCallback(boost::function<int (void)> callback)
{
	GLFWWrapper::windowCloseCallback_ = callback;
	glfwSetWindowCloseCallback(windowCloseCallback);
}

void GLFWWrapper::setMouseMoveCallback(boost::function<void (int, int)> callback)
{
	GLFWWrapper::mouseMoveCallback_ = callback;
	glfwSetMousePosCallback(mouseMoveCallback);
}

void GLFWWrapper::setButtonPressedCallback(boost::function<void (int, int)> callback)
{
	GLFWWrapper::buttonPressedCallback_ = callback;
	glfwSetKeyCallback(buttonPressedCallback);
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

void GLFWWrapper::getWindowSize(int* width, int* height)
{
	glfwGetWindowSize(width, height);
}

void GLFWWrapper::setMousePosition(int x, int y)
{
	glfwSetMousePos(x, y);
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
