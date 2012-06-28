/*
 * Actor.cpp
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#include "Actor.h"

Actor::Actor() :
	translation_(glm::vec3(0.f, 0.f, 0.f)),
	rotation_(glm::mat3(1.f, 0.f, 0.f,
						0.f, 1.f, 0.f,
						0.f, 0.f, 1.f))
{
	;
}

Actor::~Actor()
{
	;
}

glm::vec3 Actor::getTranslation() const
{
	return translation_;
}

glm::mat3 Actor::getRotation() const
{
	return rotation_;
}

void Actor::translate(glm::vec3 translation)
{
	translation_ += translation;
}

void Actor::rotate(float angle, glm::vec3 axis)
{
	glm::mat4 res = glm::rotate(glm::mat4(rotation_), angle, axis);

	rotation_ = glm::mat3(res);
}
