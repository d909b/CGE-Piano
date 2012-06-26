/*
 * ModelManager.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#pragma once

#include <iostream>
#include "assimp/assimp.hpp"
#include "assimp/aiScene.h"
#include "assimp/aiPostProcess.h"

class ModelManager
{
public:
	ModelManager();
	virtual ~ModelManager();
	void loadModel(std::string file);
private:
	/*const aiScene* scene;
	Assimp::Importer importer;*/
};
