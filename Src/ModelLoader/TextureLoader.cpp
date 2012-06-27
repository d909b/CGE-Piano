/*
 * TextureLoader.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#include "TextureLoader.h"
#include "../Utility/OpenGL.h"

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

	aiReturn texFound = scene->mMaterials[index]->GetTexture(aiTextureType_UNKNOWN, texIndex, &path);
	if(texFound == AI_SUCCESS)
	{
		filename = path.data;
		//TODO: don't know if this works, adapted it from MeshFactory.cpp
		//filename = filename.substr(filename.find_last_of("/\\") +1);

		//save filename for texture
		texture.setFilename(filename);
	}

	int numTextures = 1;

	/* create and fill DevIL texture id */
	ILuint* imageId = new ILuint[numTextures];
	ilGenImages(numTextures, &imageId[0]);

	/* create and fill GL texture id */
	GLuint* textureId = new GLuint[numTextures];
	glGenTextures(numTextures, &textureId[0]); /* Texture name generation */

	//save generated textureId for texture
	texture.setTextureId(textureId[0]);

	//TODO: don't know if this part is needed here
	//Binding of DevIL image name
	ilBindImage(imageId[0]);
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	std::string fullPath = std::string("3dModels/" + filename);
	success = ilLoadImage(fullPath.c_str());

	if (success)
	{
		// Convert image to RGBA
		ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

		// Create and load textures to OpenGL
		glBindTexture(GL_TEXTURE_2D, textureId[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ilGetInteger(IL_IMAGE_WIDTH),
				ilGetInteger(IL_IMAGE_HEIGHT), 0, GL_RGBA, GL_UNSIGNED_BYTE,
				ilGetData());

		/** Unbind texture state after loading. */
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else
	{
		printf("Couldn't load Image: %u, error code: %x\n", textureId[0], ilGetError());
	}

	// Because we have already copied image data into texture data
	//	we can release memory used by image.
	ilDeleteImages(numTextures, imageId);

	//Cleanup
	delete[] imageId;
	delete[] textureId;

	int code;
	if( (code = glGetError()) != GL_NO_ERROR )
	{
		printf("OGL ERROR: %x\n", code);
	}

	if( (code = ilGetError()) != IL_NO_ERROR )
	{
		printf("IL ERROR: %x\n", code);
	}

	printf("Successfully loaded texture at %s with handle ID: %u\n", fullPath.c_str(), texture.getTextureId());

	//return the texture Object;
	return texture;
}
