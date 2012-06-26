/*
 * TextureLoader.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#pragma once

#include <glfw.h>
#include <map>
#include "glfw.h"
#include "assimp/aiScene.h"

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();
	bool loadTextures(const aiScene* scene);
	void setAiScene(const aiScene* scene);
	std::map<std::string, GLuint> getTextureIdMap() const {
		return textureIdMap;
	}
private:
	const aiScene* scene_;
	std::map<std::string, GLuint> textureIdMap;
};
