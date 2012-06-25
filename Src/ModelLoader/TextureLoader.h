/*
 * TextureLoader.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <glfw.h>
#include "assimp/aiScene.h"

#endif /* TEXTURELOADER_H_ */

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();
	bool loadTextures(const aiScene* scene);
	void setAiScene(const aiScene* scene);
private:
	const aiScene* scene_;
	std::map<std::string, GLuint> textureIdMap;
};
