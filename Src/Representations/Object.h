/*
 * Object.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <glm/glm.hpp>

class Object
{
public:
	Object();
	virtual ~Object();

	glm::vec3 getTranslation() const;
	glm::mat3 getRotation() const;

private:
	glm::vec3 translation_;
	glm::mat3 rotation_;
};

