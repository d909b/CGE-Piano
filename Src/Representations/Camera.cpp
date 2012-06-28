/*
 * Camera.cpp
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#include "Camera.h"
#include <glfw.h>
#include <cstdio>

Camera::Camera() :
	Actor()
{
	;
}

Camera::~Camera()
{
	;
}

void Camera::mouseMoved(int x, int y)
{
	mousePosition_ = glm::vec2(x, y);
}

void Camera::keyPressed(int key, int action)
{
	buttonMap_[key] = action;
}

void Camera::update(double deltaTime)
{
	handleRotation(deltaTime);
	handleTranslation(deltaTime);
}

void Camera::initializeMousePosition(int x, int y)
{
	lastMousePosition_ = mousePosition_ = glm::vec2(x, y);
}

void Camera::handleTranslation(double deltaTime)
{
	static const float kMovementSpeed = 5.f;

	glm::vec3 movement(0.f, 0.f, 0.f);

	if( isPressed('A') )
	{
		movement += glm::vec3(1, 0, 0);
	}

	if( isPressed('D') )
	{
		movement += glm::vec3(-1, 0, 0);
	}

	if( isPressed('W') )
	{
		movement += glm::vec3(0, 0, 1);
	}

	if( isPressed('S') )
	{
		movement += glm::vec3(0, 0, -1);
	}

	/** Only perform if there actually is movement. */
	if(fabs(glm::length(movement)) > 1e-8 )
	{
		movement = glm::normalize(movement) * kMovementSpeed;

		translate(movement);
	}
}

void Camera::handleRotation(double deltaTime)
{
	static const float kRotationSpeed = .1f;

	viewingAngles_.x = kRotationSpeed * (lastMousePosition_.x - mousePosition_.x);
	viewingAngles_.y = kRotationSpeed * (lastMousePosition_.y - mousePosition_.y);

	rotate(viewingAngles_.y, glm::vec3(1, 0, 0));
	rotate(viewingAngles_.x, glm::vec3(0, 1, 0));

	lastMousePosition_ = mousePosition_;
}

glm::vec2 Camera::getViewingAngles() const
{
	return viewingAngles_;
}

bool Camera::isPressed(int key)
{
	auto it = buttonMap_.find(key);

	if(it != buttonMap_.end())
	{
		if(it->second == GLFW_PRESS)
		{
			return true;
		}
	}

	return false;
}

