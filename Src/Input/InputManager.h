/*
 * InputManager.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <list>
#include "InputListener.h"

class InputManager
{
public:
	InputManager();
	virtual ~InputManager();

	void mouseMoved(int x, int y);
	void keyPressed(int key, int action);

	void addInputListener(InputListener* listener) const;
	void removeInputListener(InputListener* listener) const;
private:
	mutable std::list<InputListener*> listeners_;
};

