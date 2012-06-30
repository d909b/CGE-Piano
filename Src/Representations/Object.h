/*
 * Object.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include "assimp/aiScene.h"
#include "Actor.h"
#include "Mesh.h"

class Object : public Actor
{
public:
	Object(std::vector<Mesh>& meshes);
	virtual ~Object();

	std::vector<Mesh> getMeshes() const;
	virtual void scale(glm::vec3 scale);

private:
	std::vector<Mesh> meshes_;
};

