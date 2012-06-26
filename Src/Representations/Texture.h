/*
 * Texture.h
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#pragma once

class Texture
{
public:
	Texture();
	virtual ~Texture();

	int getHandle() const;
private:
	int textureHandle_;
};

