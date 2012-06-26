/*
 * TextureLoader.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#include "TextureLoader.h"

TextureLoader::TextureLoader()
{
	;
}

TextureLoader::~TextureLoader()
{
	;
}

void TextureLoader::setAiScene(const aiScene* scene)
{
	scene_ = scene;
}

//unchecked
bool TextureLoader::loadTextures(const aiScene* scene)
{
	setAiScene(scene);

	/* scan scene's materials for textures */
	for (unsigned int m=0; m<scene_->mNumMaterials; ++m)
	{
		int texIndex = 0;
		aiString path;	// filename

		aiReturn texFound = scene_->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
		while (texFound == AI_SUCCESS) {
			//fill map with textures, OpenGL image ids set to 0
			textureIdMap[path.data] = 0;
			// more textures?
			texIndex++;
			texFound = scene_->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
		}
	}

	int numTextures = textureIdMap.size();

	/* create and fill array with GL texture ids */
	GLuint* textureIds = new GLuint[numTextures];
	glGenTextures(numTextures, textureIds); /* Texture name generation */

	/* get iterator */
	std::map<std::string, GLuint>::iterator itr = textureIdMap.begin();
	int i=0;
	for (; itr != textureIdMap.end(); ++i, ++itr)
	{
		//save IL image ID
		std::string filename = (*itr).first;  // get filename
		(*itr).second = textureIds[i];	  // save texture id for filename in map
	}

	//return success;
	return true;
}

