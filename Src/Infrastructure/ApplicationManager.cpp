/*
 * ApplicationManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "ApplicationManager.h"
#include <boost/bind.hpp>
#include "../Utility/foreach.h"

ApplicationManager::ApplicationManager(int framesPerSecond, int numMultiSamples) :
	framesPerSecond_(framesPerSecond),
	numMultiSamples_(numMultiSamples),
	isRunning_(true),
	sceneManager_(*this, inputManager_, glfwWrapper_)
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
							8, 8, 8, 8,     // r, g, b, a
							24, 0,	        // depth, stencil
							GLFW_WINDOW);

	glfwWrapper_.enable(GLFW_STICKY_KEYS);

	/** Eclipse parser is not smart enough. */
#ifndef __CDT_PARSER__
	glfwWrapper_.setWindowCloseCallback(boost::bind(&ApplicationManager::windowClosed, this));
	glfwWrapper_.setMouseMoveCallback(boost::bind(&InputManager::mouseMoved, &inputManager_, _1, _2));
	glfwWrapper_.setButtonPressedCallback(boost::bind(&InputManager::keyPressed, &inputManager_, _1, _2));
#endif

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

	inputManager_.addInputListener(&sceneManager_);
	inputManager_.addInputListener(this);

	addUpdateListener(&sceneManager_);

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

void ApplicationManager::mouseMoved(int x, int y)
{
	// NOP
}

void ApplicationManager::keyPressed(int key, int action)
{
	if(key == GLFW_KEY_ESC && action == GLFW_PRESS)
	{
		terminateApplication();
	}
}

void ApplicationManager::addUpdateListener(UpdateListener* listener) const
{
	listeners_.push_back(listener);
}

void ApplicationManager::removeUpdateListener(UpdateListener* listener) const
{
	auto it = listeners_.begin();
	for(; it != listeners_.end(); ++it)
	{
		if(*it == listener)
		{
			listeners_.erase(it);
			break;
		}
	}
}

void ApplicationManager::mainLoop()
{
	static double lastTime = glfwWrapper_.getTime();
	static double timePerFrame = (double) 1. / framesPerSecond_;

	while(isRunning_)
	{
		double currentTime = glfwWrapper_.getTime();
		double deltaTime = currentTime - lastTime;

		foreach(UpdateListener* listener, listeners_)
		{
			listener->update(deltaTime);
		}

		renderManager_.renderObjects(sceneManager_.getCamera(), sceneManager_.getObjects());

		glfwWrapper_.swapBuffers();

		double loopTime = currentTime - glfwWrapper_.getTime();
		lastTime = currentTime;

		glfwWrapper_.sleep(timePerFrame - loopTime);
	}

	applicationEnded();
}

int ApplicationManager::windowClosed()
{
	terminateApplication();
	return GL_TRUE;
}



