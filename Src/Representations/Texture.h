/*
 * Texture.h
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#pragma once

#include <string.h>
#include <iostream>
#include <glfw.h>

class Texture
{
public:
	Texture();
	virtual ~Texture();

	void setFilename(std::string filename) {
		filename_ = filename;
	}

	void setTextureId(GLuint* textureId) {
		textureId_ = textureId;
	}

	std::string getFilename() const {
		return filename_;
	}

	GLuint* getTextureId() const {
		return textureId_;
	}


private:
	std::string filename_;
	GLuint* textureId_;
};

