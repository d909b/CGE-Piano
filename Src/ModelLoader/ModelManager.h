/*
 * ModelManager.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#ifndef MODELMANAGER_H_
#define MODELMANAGER_H_
#include <iostream>
#include "assimp/assimp.hpp"
#include "assimp/aiScene.h"
#include "assimp/aiPostProcess.h"
#include "TextureLoader.h"

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

#endif /* MODELMANAGER_H_ */

class ModelManager
{
public:
	ModelManager();
	virtual ~ModelManager();
	bool loadModel(std::string file);
	bool loadTextures();
	void getBoundingBox (struct aiVector3D* min, struct aiVector3D* max);
	void getBoundingBoxForNode (const struct aiNode* nd, struct aiVector3D* min, struct aiVector3D* max);
	void setScaleFactor(struct aiVector3D scene_min, struct aiVector3D scene_max);
	float getScaleFactor();
	aiVector3D getSceneCenter();
	const aiScene* getAiScene();
	std::vector<struct MyMesh> getMyMeshes();
private:
	TextureLoader textureLoader;
	const aiScene* scene_;
	Assimp::Importer importer_;
	struct aiVector3D scene_min_;
	struct aiVector3D scene_max_;
	struct aiVector3D scene_center_;
	float scaleFactor_;

	// Information to render each assimp node
	struct MyMesh{

		GLuint vao;
		GLuint texIndex;
		GLuint uniformBlockIndex;
		int numFaces;
	};

	std::vector<struct MyMesh> myMeshes_;
};
