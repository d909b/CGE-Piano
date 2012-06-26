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

boost::shared_ptr<Object> ModelManager::loadModel(std::string file)
{	
	//import the model
	const aiScene* scene = scene_ = importer_.ReadFile(file, aiProcessPreset_TargetRealtime_MaxQuality);

	if(!scene)
	{
		std::string text = "Reading File failed\n";
		std::cout << text;
		throw ModelManagerException(text);
	}
	else
	{
		std::cout << "Import of model succeeded" << std::endl;
	}
	
	getBoundingBox(&scene_min_, &scene_max_);

	scene_center_.x = (scene_min_.x + scene_max_.x) / 2.0f;
	scene_center_.y = (scene_min_.y + scene_max_.y) / 2.0f;
	scene_center_.z = (scene_min_.z + scene_max_.z) / 2.0f;

	setScaleFactor(scene_min_, scene_max_);

	/** Obtain meshes. */
	std::vector<Mesh> meshes = getMeshesFromAiScene(scene);

	return boost::shared_ptr<Object>(new Object(meshes));
}

std::vector<Mesh> ModelManager::getMeshesFromAiScene(const aiScene* scene)
{
    std::vector<Mesh> meshes;

    for(unsigned int i = 0; i != scene->mNumMeshes; ++i)
    {
        aiMesh* aimesh = scene->mMeshes[i];

        Mesh mesh = createMeshFromAiMesh(scene, aimesh);

        meshes.push_back(mesh);
    }

    return meshes;
}

Mesh ModelManager::createMeshFromAiMesh(const aiScene* scene, aiMesh* mesh)
{
	Texture texture;
	std::vector<Vertex> vertices;
	std::vector<Index> indices;

	/** Fill mesh data (vertices, indices and texture) here */

	return Mesh(vertices, indices, texture);
}
