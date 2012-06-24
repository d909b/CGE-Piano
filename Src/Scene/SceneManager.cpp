/*
 * SceneManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "SceneManager.h"

SceneManager::SceneManager()
{
	;
}

SceneManager::~SceneManager()
{
	;
}

void SceneManager::initialize()
{
	// Create any needed objects here.
}

void SceneManager::update(double deltaTime)
{
	// Update object states here.
}

const std::list<boost::shared_ptr<Object> > SceneManager::getObjects() const
{
	return objects_;
}



