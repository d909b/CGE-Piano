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

	glfwWrapper_.getWindowSize(&x, &y);

	x /= 2;
	y /= 2;

	glfwWrapper_.setMousePosition(x, y);
	camera_.initializeMousePosition(x, y);

	appManager_.addUpdateListener(&camera_);
	inputManager_.addInputListener(&camera_);

	try
	{
		piano_ = modelManager_.loadModel(ROOMMODEL);

		//piano_->rotate(-90, glm::vec3(0, 1, 1));
		//piano_->translate(glm::vec3(0, -10, -10));

		/**
		 * metronom_ = modelManager.loadModel(METRONOMMODEL);
		 */

		//room_ = modelManager_.loadModel(ROOMMODEL);

	}
	catch(const ModelManagerException& e)
	{
		std::cerr << "Could not initialize models, because " << e.what() << std::endl;
	}

	objects_.push_back(piano_);
}

void SceneManager::update(double deltaTime)
{
	// Update object states here.

	piano_->rotate(deltaTime * 15, glm::vec3(0, 0, 1));

	/**
	 * e.g.:
	 * metronom_.rotate(35.f, 0, 1, 0);
	 */
}

void SceneManager::mouseMoved(int x, int y)
{
	;
}

void SceneManager::keyPressed(int key, int action)
{
	;
}

Camera SceneManager::getCamera() const
{
	return camera_;
}

std::list<boost::shared_ptr<Object> > SceneManager::getObjects() const
{
	return objects_;
}



