/*
 * Object.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <glm/glm.hpp>
#include "assimp/aiScene.h"

class Object
{
public:
	Object();
	virtual ~Object();

	glm::vec3 getTranslation() const;
	glm::mat3 getRotation() const;
	void setAiScene(const aiScene* scene);
	const aiScene* getAiScene();
	void setMyMeshes(std::vector<struct MyMesh> myMeshes) {
		myMeshes_ = myMeshes;
	}
private:
	const aiScene* scene_;
	glm::vec3 translation_;
	glm::mat3 rotation_;

	// Information to render each assimp node
	struct MyMesh{

		GLuint vao;
		GLuint texIndex;
		GLuint uniformBlockIndex;
		int numFaces;
	};

	std::vector<struct MyMesh> myMeshes_;
};

