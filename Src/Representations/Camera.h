/*
 * Camera.h
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#pragma once

#include <map>
#include "../Infrastructure/UpdateListener.h"
#include "../Input/InputListener.h"
#include "Actor.h"

class Camera : public Actor, public InputListener, public UpdateListener
{
public:
	Camera();
	virtual ~Camera();

	void initializeMousePosition(int x, int y);

	void mouseMoved(int x, int y);
	void keyPressed(int key, int action);

	void update(double deltaTime);
	void handleTranslation(double deltaTime);
	void handleRotation(double deltaTime);

	glm::vec2 getViewingAngles() const;
private:
	bool isPressed(int key);
	std::map<int, int> buttonMap_;
	glm::vec2 lastMousePosition_;
	glm::vec2 mousePosition_;
	glm::vec2 viewingAngles_;
};

