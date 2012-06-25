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
#endif /* MODELMANAGER_H_ */

class ModelManager
{
public:
	ModelManager();
	virtual ~ModelManager();
	void loadModel(std::string file);
private:
	const aiScene* scene;
	Assimp::Importer importer;
};
