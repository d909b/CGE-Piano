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
	glfwWrapper_(glfwWrapper),
	isMetronomeOn_(false)
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

	//load the sound manager and play intro music
	soundManager_.loadSoundBuffers();
	//play two chords as intro music
	soundManager_.playSound(14);
	soundManager_.playSound(15);

	try
	{
		piano_ = modelManager_.loadModel(PIANOMODEL);

		wall_front_ = modelManager_.loadModel(WALLMODEL);
		wall_back_  = modelManager_.loadModel(WALLMODEL);
		wall_left_  = modelManager_.loadModel(WALLMODEL);
		wall_right_ = modelManager_.loadModel(WALLMODEL);

		floor_ = modelManager_.loadModel(ROOMMODEL);
		roof_  = modelManager_.loadModel(ROOMMODEL);

		metronome_ = modelManager_.loadModel(METRONOMMODEL);

		swinger_   = modelManager_.loadModel(SWINGER);
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
	objects_.push_back(roof_);
	objects_.push_back(metronome_);
	objects_.push_back(swinger_);
}

void SceneManager::setupWalls()
{
	glm::vec3 scaleFactor(5.f, 5.f, 5.f);
	float halfRoomWidth = 4.22f;
	float halfRoamLength = 2.67f;

	wall_front_->scale(scaleFactor);
	wall_front_->translate(glm::vec3(0, 0.2, halfRoomWidth));
	wall_front_->rotate(90.f, glm::vec3(0, 0, 1));

	wall_back_->scale(scaleFactor);
	wall_back_->translate(glm::vec3(0, 0.2, -halfRoomWidth));
	wall_back_->rotate(90.f, glm::vec3(0, 0, 1));

	glm::vec3 sideScaleFactor(5.f, 7.85f, 5.f);
	wall_left_->scale(sideScaleFactor);
	wall_left_->translate(glm::vec3(-halfRoamLength, 0.2, 0));
	wall_left_->rotate(90.f, glm::vec3(0, 0, 1));
	wall_left_->rotate(90.f, glm::vec3(1, 0, 0));

	wall_right_->scale(sideScaleFactor);
	wall_right_->translate(glm::vec3(halfRoamLength, 0.2, 0));
	wall_right_->rotate(90.f, glm::vec3(0, 0, 1));
	wall_right_->rotate(90.f, glm::vec3(1, 0, 0));

	glm::vec3 floorScale(scaleFactor * 1.569f);
	floor_->scale(floorScale);
	floor_->translate(glm::vec3(0, -1.5, 0));
	floor_->rotate(90.f, glm::vec3(1, 0, 0));

	roof_->scale(floorScale);
	roof_->translate(glm::vec3(0, 1.5, 0));
	roof_->rotate(90.f, glm::vec3(1, 0, 0));
}

void SceneManager::setupItems()
{
	piano_->translate(glm::vec3(0, -1, -2.3));
	piano_->rotate(-90.f, glm::vec3(1, 0, 0));

	glm::vec3 commonTranslation(0.5f, -0.5f, -2.f);

	metronome_->translate(commonTranslation);
	swinger_->translate(commonTranslation);

	metronome_->rotate(-90.f, glm::vec3(1, 0, 0));
	metronome_->scale(glm::vec3(0.1f, 0.1f, 0.1f));

	swinger_->translate(glm::vec3(0.09f, 0.1f, 0.05f));
	swinger_->rotate(-90.f, glm::vec3(1, 0, 0));
	swinger_->scale(glm::vec3(0.1f, 0.1f, 0.1f));
}

void SceneManager::update(double deltaTime)
{

	static float rotation = 0.f;
	static bool goingRight = true;

	if(isMetronomeOn_)
	{
		const float rotationStep = 1.4f;
		const float maxSwingerDegrees = 30.f;

		if(rotation > maxSwingerDegrees)
		{
			goingRight = false;
		}
		else if(rotation < -maxSwingerDegrees)
		{
			goingRight = true;
		}

		float currentRotation;
		if(goingRight)
		{
			currentRotation = rotationStep;
		}
		else
		{
			currentRotation = -rotationStep;
		}

		swinger_->rotate(currentRotation, glm::vec3(0, 1, 0));
		rotation += currentRotation;
	}
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
			if(isMetronomeOn_)
			{
				soundManager_.stopMetronome();
				isMetronomeOn_ = false;
			}
			else
			{
				soundManager_.startMetronome();
				isMetronomeOn_ = true;
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



