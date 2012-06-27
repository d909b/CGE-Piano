/*
 * ApplicationManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "ApplicationManager.h"

#define PIANOSOUND "/home/test.wav"

ApplicationManager::ApplicationManager(int framesPerSecond, int numMultiSamples) :
	framesPerSecond_(framesPerSecond),
	numMultiSamples_(numMultiSamples),
	isRunning_(true)
{
	;
}

ApplicationManager::~ApplicationManager()
{
	;
}

void ApplicationManager::applicationStarted(int argc, char** argv)
{
	int width = 1024, height = 600;

	glfwWrapper_.initialize();

	glfwWrapper_.openWindowHint(GLFW_FSAA_SAMPLES, numMultiSamples_);
	glfwWrapper_.setWindowTitle("Piano Scene");
	glfwWrapper_.openWindow(width, height,  // width, height
							8, 8, 8, 8,  // r, g, b, a
							8, 8,	     // depth, stencil
							GLFW_WINDOW);

	glfwWrapper_.enable(GLFW_STICKY_KEYS);

	//test the sound manager
	std::string files[] = {"Resources/Sounds/MetronomeSounds/0.wav",
			"Resources/Sounds/PianoSounds/1.wav",
			"Resources/Sounds/PianoSounds/2.wav"
			};

	soundManager_.loadSoundBuffers(files);
	soundManager_.playSound(1);
	soundManager_.playSound(2);

	//load all Objects in the application
	sceneManager_.initialize();

	renderManager_.initialize(width, height);

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
	static double lastTime = glfwWrapper_.getTime();
	static double timePerFrame = (double) 1. / framesPerSecond_;

	while(isRunning_)
	{
		double currentTime = glfwWrapper_.getTime();
		double deltaTime = currentTime - lastTime;

		sceneManager_.update(deltaTime);
		renderManager_.renderObjects(sceneManager_.getObjects());

		bool escPressed = glfwGetKey( GLFW_KEY_ESC );

		if(escPressed == true)
		{
			terminateApplication();
		}

		glfwWrapper_.swapBuffers();

		double loopTime = currentTime - glfwWrapper_.getTime();
		lastTime = currentTime;

		glfwWrapper_.sleep(timePerFrame - loopTime);
	}

	applicationEnded();
}


