/*
 * GLFWWrapper.h
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */

#pragma once

#include <glfw.h>

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
	virtual ~GLFWWrapper();

	void initialize() const;
	void terminate() const;

	void openWindow(int width, int height,
					int redbits, int greenbits, int bluebits,
					int alphabits, int depthbits, int stencilbits,
					int mode ) const;


};

