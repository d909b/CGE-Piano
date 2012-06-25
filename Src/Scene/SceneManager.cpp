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
	modelManager_.loadTextures();

	//create piano Object

	//set aiScene in piano object pianoObj.setAiScene(modelManager_.getAiScene());
	//set meshes in piano object pianoObj.setMeshes(modelManager_.getMyMeshes());

}

void SceneManager::update(double deltaTime)
{
	// Update object states here.
}

const std::list<boost::shared_ptr<Object> > SceneManager::getObjects() const
{
	return objects_;
}



