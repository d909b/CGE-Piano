/*
 * Object.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "Object.h"
#include "../Utility/foreach.h"

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

void Object::scale(glm::vec3 scale)
{
	Actor::scale(scale);

	/** Rescale normals. */
	foreach(Mesh mesh, meshes_)
	{
		foreach(Vertex v, mesh.getVertices())
		{
			v.normals[0] = v.normals[0] / scale.x;
			v.normals[1] = v.normals[1] / scale.x;
			v.normals[2] = v.normals[2] / scale.x;
		}
	}
}



