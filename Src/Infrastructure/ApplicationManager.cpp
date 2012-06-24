/*
 * ApplicationManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "ApplicationManager.h"

ApplicationManager::ApplicationManager(int framesPerSecond, int numMultiSamples) :
	framesPerSecond_(framesPerSecond),
	numMultiSamples_(numMultiSamples),
	isRunning_(true),
	glfwWrapper_()
{
	;
}

ApplicationManager::~ApplicationManager()
{
	;
}

void ApplicationManager::applicationStarted(int argc, char** argv)
{
	glfwWrapper_.initialize();

	glfwWrapper_.openWindowHint(GLFW_FSAA_SAMPLES, numMultiSamples_);
	glfwWrapper_.openWindow(1280, 720,  // width, height
							8, 8, 8, 8,  // r, g, b, a
							8, 8,	     // depth, stencil
							GLFW_FULLSCREEN);

	mainLoop();
}

void ApplicationManager::applicationEnded()
{
	glfwWrapper_.terminate();
}

void ApplicationManager::terminateApplication()
{
	isRunning_ = false;
}

void ApplicationManager::mainLoop()
{
	static double lastTime = glfwGetTime();
	static double timePerFrame = (double) 1. / framesPerSecond_;

	while(isRunning_)
	{
		double currentTime = glfwGetTime();
		double deltaTime = currentTime - lastTime;

		sceneManager_.update(deltaTime);
		renderManager_.renderObjects(sceneManager_.getObjects());

		isRunning_ = !glfwGetKey( GLFW_KEY_ESC ) &&
					  glfwGetWindowParam( GLFW_OPENED );

		double loopTime = currentTime - glfwGetTime();
		lastTime = currentTime;

		glfwSleep(timePerFrame - loopTime);
	}
}


