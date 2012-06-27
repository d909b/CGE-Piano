/*
 * Object.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "Object.h"

Object::Object(std::vector<Mesh>& meshes) :
	translation_(glm::vec3(0.f, 0.f, 0.f)),
	rotation_(glm::mat3(1.f, 0.f, 0.f,
						0.f, 1.f, 0.f,
						0.f, 0.f, 1.f)),
	meshes_(meshes)
{
	;
}

Object::~Object()
{
	;
}

glm::vec3 Object::getTranslation() const
{
	return translation_;
}

glm::mat3 Object::getRotation() const
{
	return rotation_;
}

std::vector<Mesh> Object::getMeshes() const
{
	return meshes_;
}

void Object::translate(glm::vec3 translation)
{
	translation_ += translation;
}

void Object::rotate(float angle, glm::vec3 axis)
{
	glm::mat4 res = glm::rotate(glm::mat4(rotation_), angle, axis);

	rotation_ = glm::mat3(res);
}


