/*
 * Object.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "Object.h"

Object::Object(std::vector<Mesh>& meshes) :
	Actor(),
	meshes_(meshes)
{
	;
}

Object::~Object()
{
	;
}

std::vector<Mesh> Object::getMeshes() const
{
	return meshes_;
}


