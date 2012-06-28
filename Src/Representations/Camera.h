/*
 * Camera.h
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#pragma once

#include "../Input/InputManager.h"
#include "Actor.h"

class Camera : public Actor, public InputListener
{
public:
	Camera();
	virtual ~Camera();

	void mouseMoved(int x, int y);
	void keyPressed(int key, int action);
};

