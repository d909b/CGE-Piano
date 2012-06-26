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
		std::cout << "Import of model succeeded\n";
	}

	return loadMeshes();
}

Texture ModelManager::loadTexture(int index)
{
	return textureLoader_.loadTexture(scene_,index);
}

boost::shared_ptr<Object> ModelManager::loadMeshes()
{
	/** Obtain meshes. */
	std::vector<Mesh> meshes = getMeshesFromAiScene(scene_);

	std::cout << "Loaded all Meshes for Imported Object\n";

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

	/* get textures for Mesh */
	bool hasTexture = false;
	if(mesh->mTextureCoords[0] != NULL)
	{
		hasTexture = true;

		texture = loadTexture(mesh->mMaterialIndex);
		std::cout << "Loaded all Textures for Imported Object\n";
	}

	/* get indices for Mesh */
	unsigned int size = 0;
	unsigned int numFaces = mesh->mNumFaces;
	for(unsigned int i = 0;i<numFaces;i++)
	{
		size += mesh->mFaces[i].mNumIndices;
	}

	indices = std::vector<Index>(size);

	unsigned int index = 0;
	for(unsigned int i=0;i<numFaces;i++)
	{
		for(unsigned int x=0;x < mesh->mFaces[i].mNumIndices;x++)
		{
			indices[index++] = mesh->mFaces[i].mIndices[x];
		}
	}

	/* get vertices for Mesh */
	vertices = std::vector<Vertex>(mesh->mNumVertices);

	for(unsigned int i=0;i < mesh->mNumVertices;i++)
	{
		vertices[i].positions[0] = mesh->mVertices[i].x;
		vertices[i].positions[1] = mesh->mVertices[i].y;
		vertices[i].positions[2] = mesh->mVertices[i].z;

		if(hasTexture)
		{
			vertices[i].textureCoordinates[0] = mesh->mTextureCoords[0][i].x;
			vertices[i].textureCoordinates[1] = 1 - mesh->mTextureCoords[0][i].y;
		}

		vertices[i].normals[0] = mesh->mNormals[i].x;
		vertices[i].normals[1] = mesh->mNormals[i].y;
		vertices[i].normals[2] = mesh->mNormals[i].z;
	}

	return Mesh(vertices, indices, texture);
}
