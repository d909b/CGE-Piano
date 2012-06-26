/*
 * Object.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <glm/glm.hpp>
#include "assimp/aiScene.h"
#include "../ModelLoader/MyMesh.h"
#include "Mesh.h"

class Object
{
public:
	Object(std::vector<Mesh>& meshes);
	virtual ~Object();

	glm::vec3 getTranslation() const;
	glm::mat3 getRotation() const;
	void setAiScene(const aiScene* scene);
	const aiScene* getAiScene();

	std::vector<MyMesh> getMyMeshes() const {
		return myMeshes_;
	}

	void setMyMeshes(std::vector<MyMesh> myMeshes) {
		myMeshes_ = myMeshes;
	}

private:
	const aiScene* scene_;
	std::vector<MyMesh> myMeshes_;
	glm::vec3 translation_;
	glm::mat3 rotation_;

	std::vector<Mesh> getMeshes() const;
private:
	glm::vec3 translation_;
	glm::mat3 rotation_;

	std::vector<Mesh> meshes_;
};

