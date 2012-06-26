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
	//load the 3d piano model

	modelManager_.loadModel(PIANOMODEL);

	//create piano Object

	//set aiScene in piano object pianoObj.setAiScene(modelManager_.getAiScene());
	//set meshes in piano object pianoObj.setMyMeshes(modelManager_.getMyMeshes());

	try
	{
		//piano_ = modelManager_.loadModel(PIANOMODEL);
		/**
		 * metronom_ = modelManager.loadModel(METRONOMMODEL);
		 * room_ = modelManager.loadModel(ROOMMODEL);
		 */
	}
	catch(const ModelManagerException& e)
	{
		std::cerr << "Could not initialize models, because " << e.what() << std::endl;
	}

	/**
	 * objects_.push_back(piano_);
	 */
}

void SceneManager::update(double deltaTime)
{
	// Update object states here.

	/**
	 * e.g.:
	 * metronom_.rotate(35.f, 0, 1, 0);
	 */
}

std::list<boost::shared_ptr<Object> > SceneManager::getObjects() const
{
	return objects_;
}



