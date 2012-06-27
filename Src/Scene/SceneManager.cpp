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
	try
	{
		piano_ = modelManager_.loadModel(PIANOMODEL);

		piano_->rotate(-90, glm::vec3(1, 0, 0));
		piano_->translate(glm::vec3(0, -40, -200));
		/**
		 * metronom_ = modelManager.loadModel(METRONOMMODEL);
		 * room_ = modelManager.loadModel(ROOMMODEL);
		 */
	}
	catch(const ModelManagerException& e)
	{
		std::cerr << "Could not initialize models, because " << e.what() << std::endl;
	}

	objects_.push_back(piano_);
}

void SceneManager::update(double deltaTime)
{
	// Update object states here.

	piano_->rotate(deltaTime * 15, glm::vec3(0, 0, 1));

	/**
	 * e.g.:
	 * metronom_.rotate(35.f, 0, 1, 0);
	 */
}

std::list<boost::shared_ptr<Object> > SceneManager::getObjects() const
{
	return objects_;
}



