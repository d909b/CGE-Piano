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
#include "../Sound/SoundManager.h"
#include "../Input/InputManager.h"

class ApplicationManager : public InputListener
{
public:
	ApplicationManager(int framesPerSecond, int numMultiSamples);
	virtual ~ApplicationManager();

	void mouseMoved(int x, int y);
	void keyPressed(int key, int action);

	void terminateApplication();
	int windowClosed();

	void applicationStarted(int argc, char** argv);
	void applicationEnded();

	void addUpdateListener(UpdateListener* listener) const;
	void removeUpdateListener(UpdateListener* listener) const;
private:
	void mainLoop();

	mutable std::list<UpdateListener*> listeners_;

	int framesPerSecond_;
	int numMultiSamples_;
	bool isRunning_;

	GLFWWrapper glfwWrapper_;
	SceneManager sceneManager_;
	RenderManager renderManager_;
	SoundManager soundManager_;
	InputManager inputManager_;
};

