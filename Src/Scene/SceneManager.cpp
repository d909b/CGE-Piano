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
		piano_ = modelManager_.loadModel(PIANOMODEL);

		wall_front_ = modelManager_.loadModel(WALLMODEL);
		wall_back_ = modelManager_.loadModel(WALLMODEL);
		wall_left_ = modelManager_.loadModel(WALLMODEL);
		wall_right_ = modelManager_.loadModel(WALLMODEL);

		floor_ = modelManager_.loadModel(ROOMMODEL);

		metronome_ = modelManager_.loadModel(METRONOMMODEL);

		swinger_ = modelManager_.loadModel(SWINGER);
	}
	catch(const ModelManagerException& e)
	{
		std::cerr << "Could not initialize models, because " << e.what() << std::endl;
	}

	setupWalls();
	setupItems();

	objects_.push_back(piano_);
	objects_.push_back(wall_front_);
	objects_.push_back(wall_back_);
	objects_.push_back(wall_left_);
	objects_.push_back(wall_right_);
	objects_.push_back(floor_);
	objects_.push_back(metronome_);
	objects_.push_back(swinger_);
}

void SceneManager::setupWalls()
{
	float scaleFactor = 5.f;

	wall_front_->scaleUniform(scaleFactor);
	wall_front_->translate(glm::vec3(0, 0, 5));
	wall_front_->rotate(90.f, glm::vec3(0, 0, 1));

	wall_back_->scaleUniform(scaleFactor);
	wall_back_->translate(glm::vec3(0, 0, -5));
	wall_back_->rotate(90.f, glm::vec3(0, 0, 1));

	wall_left_->scaleUniform(scaleFactor);
	wall_left_->translate(glm::vec3(-5, 0, 0));
	wall_left_->rotate(90.f, glm::vec3(0, 0, 1));
	wall_left_->rotate(90.f, glm::vec3(1, 0, 0));

	wall_right_->scaleUniform(scaleFactor);
	wall_right_->translate(glm::vec3(5, 0, 0));
	wall_right_->rotate(90.f, glm::vec3(0, 0, 1));
	wall_right_->rotate(90.f, glm::vec3(1, 0, 0));

	floor_->scaleUniform(scaleFactor);
	floor_->translate(glm::vec3(0, -1.5, 0));
	floor_->rotate(90.f, glm::vec3(1, 0, 0));
}

void SceneManager::setupItems()
{
	piano_->translate(glm::vec3(0, -1, -2.5));
	piano_->rotate(-90.f, glm::vec3(1, 0, 0));
}

void SceneManager::update(double deltaTime)
{
	// Update object states here.
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



