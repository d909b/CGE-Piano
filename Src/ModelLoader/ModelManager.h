/*
 * ModelManager.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#include <iostream>
#include "assimp/assimp.hpp"
#include "assimp/aiScene.h"
#include "assimp/aiPostProcess.h"
#include "TextureLoader.h"
#include "MeshLoader.h"

#define aisgl_min(x,y) (x<y?x:y)
#define aisgl_max(x,y) (y>x?y:x)

class ModelManager
{
public:
	ModelManager();
	virtual ~ModelManager();
	bool loadModel(std::string file);
	bool loadMeshes();
	bool loadTextures();
	void getBoundingBox (struct aiVector3D* min, struct aiVector3D* max);
	void getBoundingBoxForNode (const struct aiNode* nd, struct aiVector3D* min, struct aiVector3D* max);
	void setScaleFactor(struct aiVector3D scene_min, struct aiVector3D scene_max);
	float getScaleFactor();
	aiVector3D getSceneCenter();
	const aiScene* getAiScene();
	std::vector<MyMesh> getMyMeshes();
private:
	MeshLoader meshLoader_;
	TextureLoader textureLoader_;
	const aiScene* scene_;
	Assimp::Importer importer_;
	struct aiVector3D scene_min_;
	struct aiVector3D scene_max_;
	struct aiVector3D scene_center_;
	float scaleFactor_;
};
