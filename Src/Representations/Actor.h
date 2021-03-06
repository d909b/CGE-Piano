/*
 * Actor.h
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Actor
{
public:
	Actor();
	virtual ~Actor();

	glm::vec3 getTranslation() const;
	glm::mat3 getRotation() const;
	glm::vec3 getScale() const;

	void translate(glm::vec3 translation);
	void rotate(float angle, glm::vec3 axis);
	virtual void scale(glm::vec3 scale);

	void setRotation(float angle, glm::vec3 axis);
private:
	glm::vec3 scale_;
	glm::vec3 translation_;
	glm::mat3 rotation_;
};

