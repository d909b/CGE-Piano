/*
 * Mesh.cpp
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices,
		std::vector<Index>& indices,
		Texture& texture) :
	vertices_(vertices),
	indices_(indices),
	texture_(texture)
{
	;
}

Mesh::~Mesh()
{
	;
}

Texture Mesh::getTexture() const
{
	return texture_;
}

std::vector<Vertex> Mesh::getVertices() const
{
	return vertices_;
}

std::vector<Index> Mesh::getIndices() const
{
	return indices_;
}


