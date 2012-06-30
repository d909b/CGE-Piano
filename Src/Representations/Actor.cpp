/*
 * Actor.cpp
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#include "Actor.h"

Actor::Actor() :
	scale_(1.f),
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

void Actor::scale(glm::vec3 factor)
{
	scale_.x *= factor.x;
	scale_.y *= factor.y;
	scale_.z *= factor.z;
}

glm::vec3 Actor::getScale() const
{
	return scale_;
}

void Actor::setRotation(float angle, glm::vec3 axis)
{
	rotation_ = glm::mat3( glm::rotate(glm::mat4(1.f), angle, axis) );
}

