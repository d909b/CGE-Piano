/*
 * Object.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "Object.h"

Object::Object()
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


