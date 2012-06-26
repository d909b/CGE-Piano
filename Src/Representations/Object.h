/*
 * Object.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <glm/glm.hpp>
#include "Mesh.h"

class Object
{
public:
	Object(std::vector<Mesh>& meshes);
	virtual ~Object();

	glm::vec3 getTranslation() const;
	glm::mat3 getRotation() const;

	std::vector<Mesh> getMeshes() const;
private:
	glm::vec3 translation_;
	glm::mat3 rotation_;

	std::vector<Mesh> meshes_;
};

