/*
 * ModelManager.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */


#pragma once

#include <iostream>
#include <boost/shared_ptr.hpp>
#include "assimp/assimp.hpp"
#include "assimp/aiScene.h"
#include "assimp/aiPostProcess.h"
#include "../Utility/MessagedException.h"
#include "../Representations/Object.h"
#include "TextureLoader.h"

class ModelManager
{
public:
	ModelManager();
	virtual ~ModelManager();

	boost::shared_ptr<Object> loadModel(std::string file);
private:
	TextureLoader textureLoader_;

	Mesh createMeshFromAiMesh(const aiScene* scene, aiMesh* mesh);
	std::vector<Mesh> getMeshesFromAiScene(const aiScene* scene);
	Texture loadTexture(const aiScene* scene, int index);
};

class ModelManagerException : public MessagedException
{
public:
	ModelManagerException(std::string message) :
		MessagedException(message)
	{;}
};
