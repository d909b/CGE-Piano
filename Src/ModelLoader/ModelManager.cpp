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

void ModelManager::loadModel(std::string file)
{
	scene = importer.ReadFile(file, aiProcess_OptimizeMeshes);

	if(!scene)
	{
		std::cout << "Reading File failed";
	}
	else
	{
		std::cout << "Import of model succeeded";
	}
}
