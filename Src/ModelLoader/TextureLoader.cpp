/*
 * TextureLoader.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#include "TextureLoader.h"

TextureLoader::TextureLoader()
{
	/* initialization of DevIL */
	ilInit();
}

TextureLoader::~TextureLoader()
{
	;
}

Texture TextureLoader::loadTexture(const aiScene* scene, unsigned int index)
{
	ILboolean success;

	Texture texture;

	std::string filename;
	int texIndex = 0;
	aiString path;	// filename

	aiReturn texFound = scene->mMaterials[index]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
	if(texFound == AI_SUCCESS)
	{
		filename = path.data;
		//TODO: don't know if this works, adapted it from MeshFactory.cpp
		filename = filename.substr(filename.find_last_of("/\\") +1);

		//save filename for texture
		texture.setFilename(filename);
	}

	int numTextures = 1;

	/* create and fill DevIL texture id */
	ILuint* imageId = 0;
	ilGenImages(numTextures, imageId);

	/* create and fill GL texture id */
	GLuint* textureId = 0;
	glGenTextures(numTextures, textureId); /* Texture name generation */

	//save generated textureId for texture
	texture.setTextureId(textureId);

	//TODO: don't know if this part is needed here
	//Binding of DevIL image name
	ilBindImage((unsigned int)imageId);
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	success = ilLoadImage((ILstring)textureId);

	if (success) {
		// Convert image to RGBA
		ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

		// Create and load textures to OpenGL
		glBindTexture(GL_TEXTURE_2D, (unsigned int)textureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ilGetInteger(IL_IMAGE_WIDTH),
				ilGetInteger(IL_IMAGE_HEIGHT), 0, GL_RGBA, GL_UNSIGNED_BYTE,
				ilGetData());
	}
	else
		printf("Couldn't load Image: %i\n", (int)textureId);

	// Because we have already copied image data into texture data
	//	we can release memory used by image.
	ilDeleteImages(numTextures, imageId);

	//Cleanup
	delete imageId;
	delete textureId;

	//return the texture Object;
	return texture;
}
