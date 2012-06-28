/*
 * InputManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "InputManager.h"
#include "../Utility/foreach.h"

InputManager::InputManager()
{
	// TODO Auto-generated constructor stub

}

InputManager::~InputManager()
{
	// TODO Auto-generated destructor stub
}

void InputManager::mouseMoved(int x, int y)
{
	foreach(InputListener* listener, listeners_)
	{
		listener->mouseMoved(x, y);
	}
}

void InputManager::keyPressed(int key, int action)
{
	foreach(InputListener* listener, listeners_)
	{
		listener->keyPressed(key, action);
	}
}

void InputManager::addInputListener(InputListener* listener) const
{
	listeners_.push_back(listener);
}

void InputManager::removeInputListener(InputListener* listener) const
{
	auto it = listeners_.begin();
	for(; it != listeners_.end(); ++it)
	{
		if(*it == listener)
		{
			listeners_.erase(it);
			break;
		}
	}
}



