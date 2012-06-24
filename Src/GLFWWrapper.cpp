/*
 * GLFWWrapper.cpp
 *
 * @date: Jun 22, 2012
 * @author: Patrick Schwab
 */

#include "glm/glm.hpp"
#include "GLFWWrapper.h"
#include <AL/al.h>
#include "assimp/assimp.h"
#include "assimp/aiPostProcess.h"
#include "assimp/aiScene.h"

GLFWWrapper::GLFWWrapper()
{
	//test assimp model loader
	aiGetMaterialColor(0, AI_MATKEY_COLOR_AMBIENT, 0);

	//test gl Math
	glm::vec2(-1.0f,-1.0f);

	//test OpenAL
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
