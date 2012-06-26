/*
 * ModelManager.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#include "ModelManager.h"

ModelManager::ModelManager()
{
	;
}

ModelManager::~ModelManager()
{
	;
}

void ModelManager::getBoundingBoxForNode (const struct aiNode* nd,
	struct aiVector3D* min,
	struct aiVector3D* max)
{
	struct aiMatrix4x4 prev;
	unsigned int n = 0, t;

	for (; n < nd->mNumMeshes; ++n) {
		const struct aiMesh* mesh = scene_->mMeshes[nd->mMeshes[n]];
		for (t = 0; t < mesh->mNumVertices; ++t) {

			struct aiVector3D tmp = mesh->mVertices[t];

			min->x = aisgl_min(min->x,tmp.x);
			min->y = aisgl_min(min->y,tmp.y);
			min->z = aisgl_min(min->z,tmp.z);

			max->x = aisgl_max(max->x,tmp.x);
			max->y = aisgl_max(max->y,tmp.y);
			max->z = aisgl_max(max->z,tmp.z);
		}
	}

	for (n = 0; n < nd->mNumChildren; ++n) {
		getBoundingBoxForNode(nd->mChildren[n],min,max);
	}
}

void ModelManager::getBoundingBox (struct aiVector3D* min, struct aiVector3D* max)
{
	min->x = min->y = min->z =  1e10f;
	max->x = max->y = max->z = -1e10f;
	getBoundingBoxForNode(scene_->mRootNode,min,max);
}

void ModelManager::setScaleFactor(struct aiVector3D scene_min,
		struct aiVector3D scene_max)
{
	//set scale factor to fit in window
	float tmp;
	tmp = scene_max.x-scene_min.x;
	tmp = scene_max.y - scene_min.y > tmp?scene_max.y - scene_min.y:tmp;
	tmp = scene_max.z - scene_min.z > tmp?scene_max.z - scene_min.z:tmp;
	scaleFactor_ = 1.f / tmp;
}

float ModelManager::getScaleFactor()
{
	return scaleFactor_;
}

aiVector3D ModelManager::getSceneCenter()
{
	return scene_center_;
}

const aiScene* ModelManager::getAiScene()
{
	return scene_;
}

bool ModelManager::loadModel(std::string file)
{	
	//import the model
	scene_ = importer_.ReadFile(file, aiProcessPreset_TargetRealtime_MaxQuality);

	if(!scene_)
	{
		std::cout << "Reading File failed";
		return false;
	}
	else
	{
		std::cout << "Import of model succeeded\n";
	}
	
	getBoundingBox(&scene_min_, &scene_max_);

	scene_center_.x = (scene_min_.x + scene_max_.x) / 2.0f;
	scene_center_.y = (scene_min_.y + scene_max_.y) / 2.0f;
	scene_center_.z = (scene_min_.z + scene_max_.z) / 2.0f;

	setScaleFactor(scene_min_, scene_max_);

	//if(loadTextures())
		//std::cout << "Succesfully loaded Textures\n";

	//if(loadMeshes())
		//std::cout << "Succesfully generated Meshes\n";

	return true;
}

bool ModelManager::loadMeshes()
{
	return meshLoader_.loadVertexArrayObjects(scene_, textureLoader_);
}

bool ModelManager::loadTextures()
{
	return textureLoader_.loadTextures(scene_);
}

std::vector<MyMesh> ModelManager::getMyMeshes()
{
	return meshLoader_.getMyMeshes();
}
