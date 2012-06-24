/*
 * ApplicationManager.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include "GLFWWrapper.h"
#include "../Scene/SceneManager.h"
#include "../Rendering/RenderManager.h"

class ApplicationManager
{
public:
	ApplicationManager(int framesPerSecond, int numMultiSamples);
	virtual ~ApplicationManager();

	void terminateApplication();

	void applicationStarted(int argc, char** argv);
	void applicationEnded();
private:
	void mainLoop();

	int framesPerSecond_;
	int numMultiSamples_;
	bool isRunning_;

	GLFWWrapper glfwWrapper_;
	SceneManager sceneManager_;
	RenderManager renderManager_;
};

