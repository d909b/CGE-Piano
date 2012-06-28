/*
 * Camera.cpp
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#include "Camera.h"

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
	printf("Mouse moved: %d %d\n", x, y);
}

void Camera::keyPressed(int key, int action)
{
	printf("Key pressed: %d\n", key);
}
