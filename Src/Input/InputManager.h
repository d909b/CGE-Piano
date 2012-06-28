/*
 * InputManager.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <list>

class InputListener
{
public:
	virtual ~InputListener() {;}
	virtual void mouseMoved(int x, int y) = 0;
	virtual void keyPressed(int key, int action) = 0;
};

class InputManager
{
public:
	InputManager();
	virtual ~InputManager();

	void mouseMoved(int x, int y);
	void keyPressed(int key, int action);

	void addInputListener(InputListener* listener);
	void removeInputListener(InputListener* listener);
private:
	std::list<InputListener*> listeners_;
};

