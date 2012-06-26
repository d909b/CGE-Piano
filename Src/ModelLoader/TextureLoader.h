/*
 * TextureLoader.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#pragma once

// include DevIL for image loading
#include <il.h>
#include <glfw.h>
#include "assimp/aiScene.h"
#include "../Representations/Texture.h"

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();
	Texture loadTexture(const aiScene* scene, unsigned int index);
};
