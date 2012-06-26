/*
 * MeshLoader.h
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#include "TextureLoader.h"
#include "MyMesh.h"
#include "MyMaterial.h"
#include <map>

class MeshLoader
{
public:
	MeshLoader();
	~MeshLoader();
	bool loadVertexArrayObjects(const aiScene* sc, TextureLoader textureLoader);
	void color4_to_float4(const struct aiColor4D *c, float f[4]);
	void set_float4(float f[4], float a, float b, float c, float d);

	std::vector<MyMesh> getMyMeshes() const {
		return myMeshes_;
	}
	void setTextureIdMap(std::map<std::string, GLuint> textureIdMap) {
		this->textureIdMap = textureIdMap;
	}

	void setScene(const aiScene* scene) {
		this->scene_ = scene;
	}

private:
	const aiScene* scene_;
	std::vector<MyMesh> myMeshes_;
	std::map<std::string, GLuint> textureIdMap;
};
