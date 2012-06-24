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
	glfwWrapper_.setWindowTitle("Piano Scene");
	glfwWrapper_.openWindow(1280, 720,  // width, height
							8, 8, 8, 8,  // r, g, b, a
							8, 8,	     // depth, stencil
							GLFW_WINDOW);

	glfwEnable( GLFW_STICKY_KEYS );

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

		bool escPressed = glfwGetKey( GLFW_KEY_ESC );

		if(escPressed == true)
		{
			terminateApplication();
		}

		glfwSwapBuffers();

		double loopTime = currentTime - glfwGetTime();
		lastTime = currentTime;

		glfwSleep(timePerFrame - loopTime);
	}

	applicationEnded();
}


