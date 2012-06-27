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

boost::shared_ptr<Object> ModelManager::loadModel(std::string file)
{	
	Assimp::Importer importer;

	//import the model
	const aiScene* scene = importer.ReadFile(file,  aiProcess_JoinIdenticalVertices |
													aiProcess_RemoveComponent |
													aiProcess_Triangulate |
													aiProcess_GenSmoothNormals |
													aiProcess_ValidateDataStructure |
													aiProcess_RemoveRedundantMaterials |
													aiProcess_GenUVCoords);

	if(!scene)
	{
		std::string text = "Reading File " + file + " failed\n";
		std::cout << text;
		throw ModelManagerException(text);
	}
	else
	{
		std::cout << "Import of model at " << file << " succeeded\n";
	}

	std::vector<Mesh> meshes = getMeshesFromAiScene(scene);

	return boost::shared_ptr<Object>(new Object(meshes));
}

Texture ModelManager::loadTexture(const aiScene* scene, int index)
{
	return textureLoader_.loadTexture(scene, index);
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

	/* get textures for Mesh */
	bool hasTexture = false;
	if(mesh->mTextureCoords[0] != NULL)
	{
		printf("Loading texture..\n");

		hasTexture = true;

		texture = loadTexture(scene, mesh->mMaterialIndex);
	}
	else
	{
		printf("The mesh contains no texture.\n");
	}

	/* get indices for Mesh */
	unsigned int size = 0;
	unsigned int numFaces = mesh->mNumFaces;

	for(unsigned int i = 0;i<numFaces;i++)
	{
		size += mesh->mFaces[i].mNumIndices;
	}

	if(mesh->HasFaces())
	{
		indices = std::vector<Index>(size);

		unsigned int index = 0;
		for(unsigned int i=0;i<numFaces;i++)
		{
			for(unsigned int x=0;x < mesh->mFaces[i].mNumIndices;x++)
			{
				indices[index++] = mesh->mFaces[i].mIndices[x];
			}
		}
	}
	else
	{
		printf("The mesh contains no indices.");
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
			vertices[i].textureCoordinates[1] = mesh->mTextureCoords[0][i].y;
		}

		vertices[i].normals[0] = mesh->mNormals[i].x;
		vertices[i].normals[1] = mesh->mNormals[i].y;
		vertices[i].normals[2] = mesh->mNormals[i].z;
	}

	return Mesh(vertices, indices, texture);
}
