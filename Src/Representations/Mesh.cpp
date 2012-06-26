/*
 * Mesh.cpp
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#include "Mesh.h"

Mesh::Mesh()
{
	// TODO Auto-generated constructor stub
}

Mesh::~Mesh()
{
	// TODO Auto-generated destructor stub
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


