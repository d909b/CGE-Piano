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
	static const float kMovementSpeed = 0.1f;

	glm::vec3 movement(0.f, 0.f, 0.f);

	glm::vec3 forward = glm::vec3(sinf(viewingAngles_.x), 0, cosf(viewingAngles_.x));
	glm::vec3 right   = glm::vec3(-forward.z, 0, forward.x);

	if( isPressed('A') )
	{
		movement += -right;
	}

	if( isPressed('D') )
	{
		movement += right;
	}

	if( isPressed('W') )
	{
		movement += forward;
	}

	if( isPressed('S') )
	{
		movement += -forward;
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
	static const float kRotationSpeed = .007f;

	viewingAngles_ += (lastMousePosition_ - mousePosition_) * kRotationSpeed;

	/**rotate(viewingAngles_.y, glm::vec3(1, 0, 0));
	rotate(viewingAngles_.x, glm::vec3(0, 1, 0));*/

	if(viewingAngles_.y < -M_PI / 2)
	{
		viewingAngles_.y = -M_PI / 2;
	}

	if(viewingAngles_.y > M_PI / 2)
	{
		viewingAngles_.y = M_PI / 2;
	}

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

