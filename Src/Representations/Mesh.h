/*
 * Mesh.h
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#pragma once

#include <vector>
#include "Texture.h"

typedef struct Vertex_s
{
	float positions[3];
	float normals[3];
	float textureCoordinates[2];
} Vertex;

typedef unsigned short Index;

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	Texture getTexture() const;
	std::vector<Vertex> getVertices() const;
	std::vector<Index> getIndices() const;
private:
	Texture texture_;
	std::vector<Vertex> vertices_;
	std::vector<Index> indices_;
};

