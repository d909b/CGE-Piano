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
	Mesh(std::vector<Vertex>& vertices,
		 std::vector<Index>& indices,
	  	 Texture& texture);

	virtual ~Mesh();

	std::vector<Vertex> getVertices() const;
	std::vector<Index> getIndices() const;
	Texture getTexture() const;
private:
	std::vector<Vertex> vertices_;
	std::vector<Index> indices_;
	Texture texture_;
};

