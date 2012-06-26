/*
 * TextureLoader.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <glfw.h>
#include <map>
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
#endif /* TEXTURELOADER_H_ */
