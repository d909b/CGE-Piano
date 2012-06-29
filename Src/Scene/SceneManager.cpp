/*
 * SceneManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "SceneManager.h"
#include "../Infrastructure/ApplicationManager.h"
#include "../Infrastructure/GLFWWrapper.h"
#include <cstdio>

SceneManager::SceneManager(const ApplicationManager& appManager,
						   InputManager& inputManager,
						   GLFWWrapper& glfwWrapper) :
	appManager_(appManager),
	inputManager_(inputManager),
	glfwWrapper_(glfwWrapper)
{
	;
}

SceneManager::~SceneManager()
{
	;
}

void SceneManager::initialize()
{
	int x, y;

	//needed for metronome sound loop
	ismetronome = false;

	glfwWrapper_.getWindowSize(&x, &y);

	x /= 2;
	y /= 2;

	glfwWrapper_.setMousePosition(x, y);
	camera_.initializeMousePosition(x, y);

	appManager_.addUpdateListener(&camera_);
	inputManager_.addInputListener(&camera_);

	//load the sound manager and play intro music
	soundManager_.loadSoundBuffers();
	//play two chords as intro music
	soundManager_.playSound(14);
	soundManager_.playSound(15);

	try
	{
		piano_ = modelManager_.loadModel(PIANOMODEL);

		wall_ = modelManager_.loadModel(WALLMODEL);

		floor_ = modelManager_.loadModel(ROOMMODEL);

		metronome_ = modelManager_.loadModel(METRONOMMODEL);

		swinger_ = modelManager_.loadModel(SWINGER);
	}
	catch(const ModelManagerException& e)
	{
		std::cerr << "Could not initialize models, because " << e.what() << std::endl;
	}

	objects_.push_back(piano_);
	objects_.push_back(wall_);
	objects_.push_back(floor_);
	objects_.push_back(metronome_);
	objects_.push_back(swinger_);
}

void SceneManager::update(double deltaTime)
{
	// Update object states here.

	piano_->rotate(deltaTime * 15, glm::vec3(1, 0, 0));

	swinger_->rotate(deltaTime * 15, glm::vec3(0, 1, 0));

}

void SceneManager::mouseMoved(int x, int y)
{
	;
}

void SceneManager::keyPressed(int key, int action)
{
	if(action == GLFW_PRESS)
	{
		switch(key)
		{
		case 'F':
			soundManager_.playSound(1);
			break;
		case 'T':
			soundManager_.playSound(2);
			break;
		case 'G':
			soundManager_.playSound(3);
			break;
		case 'Z':
			soundManager_.playSound(4);
			break;
		case 'H':
			soundManager_.playSound(5);
			break;
		case 'J':
			soundManager_.playSound(6);
			break;
		case 'I':
			soundManager_.playSound(7);
			break;
		case 'K':
			soundManager_.playSound(8);
			break;
		case 'O':
			soundManager_.playSound(9);
			break;
		case 'L':
			soundManager_.playSound(10);
			break;
		case 'P':
			soundManager_.playSound(11);
			break;
		case 214: //'Ö'
			soundManager_.playSound(12);
			break;
		case 196: //'Ä'
			soundManager_.playSound(13);
			break;
		//play metronome
		case 'M':
			if(ismetronome)
			{
				soundManager_.stopMetronome();
				ismetronome = false;
			}
			else
			{
				soundManager_.startMetronome();
				ismetronome = true;
			}
			break;
		default:
			break;
		}
	}
}

Camera SceneManager::getCamera() const
{
	return camera_;
}

std::list<boost::shared_ptr<Object> > SceneManager::getObjects() const
{
	return objects_;
}



