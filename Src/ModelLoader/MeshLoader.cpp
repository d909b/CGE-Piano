/*
 * MeshLoader.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: steindl
 */

#include "MeshLoader.h"

MeshLoader::MeshLoader() {
	;
}

MeshLoader::~MeshLoader() {
	;
}

void MeshLoader::set_float4(float f[4], float a, float b, float c, float d)
{
	f[0] = a;
	f[1] = b;
	f[2] = c;
	f[3] = d;
}

void MeshLoader::color4_to_float4(const struct aiColor4D *c, float f[4])
{
	f[0] = c->r;
	f[1] = c->g;
	f[2] = c->b;
	f[3] = c->a;
}

//generates Vertex Array Objects (VAO)
bool MeshLoader::loadVertexArrayObjects(const struct aiScene* sc, TextureLoader textureLoader) {
/* currently not working because of some GLEW stuff. does not know certain gl methods
 *
	setScene(sc);
	setTextureIdMap(textureLoader.getTextureIdMap());

	MyMesh aMesh;
	MyMaterial aMat;
	//GLuint buffer;

	// Vertex Attribute Locations
	//GLuint vertexLoc=0, normalLoc=1, texCoordLoc=2;

	//for apple maybe PFNGLGENVERTEXARRAYSAPPLEPROC my_glGenVertexArrays = (PFNGLGENVERTEXARRAYSAPPLEPROC)glfwGetProcAddress("glGe nVertextArrays");
	PFNGLGENVERTEXARRAYSPROC my_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glfwGetProcAddress("glGe nVertextArrays");
	PFNGLBINDVERTEXARRAYPROC my_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glfwGetProcAddress("glBi ndVertextArray");
	PFNGLGENBUFFERSPROC my_glGenBuffers = (PFNGLGENBUFFERSPROC)glfwGetProcAddress("glGe NBuffers");
	PFNGLBINDBUFFERPROC my_glBindBuffer = (PFNGLBINDBUFFERPROC)glfwGetProcAddress("glBi ndBuffer");
	PFNGLBUFFERDATAPROC my_glBufferData = (PFNGLBUFFERDATAPROC)glfwGetProcAddress("glBu fferData");
	PFNGLENABLEVERTEXATTRIBARRAYPROC my_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glfwGetProcAddress("glEn ableVertexAttribArray");
	PFNGLVERTEXATTRIBPOINTERPROC my_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glfwGetProcAddress("glVe rtexAttribPointer");

	// For each mesh
	for (unsigned int n = 0; n < scene_->mNumMeshes; ++n) {
		const struct aiMesh* mesh = scene_->mMeshes[n];

		// create array with faces
		// have to convert from Assimp format to array
		unsigned int *faceArray;
		faceArray = (unsigned int *) malloc(
				sizeof(unsigned int) * mesh->mNumFaces * 3);
		unsigned int faceIndex = 0;

		for (unsigned int t = 0; t < mesh->mNumFaces; ++t) {
			const struct aiFace* face = &mesh->mFaces[t];

			memcpy(&faceArray[faceIndex], face->mIndices, 3 * sizeof(float));
			faceIndex += 3;
		}
		aMesh.setNumFaces(sc->mMeshes[n]->mNumFaces);

		GLuint vao = aMesh.getVao();
		// generate Vertex Array for mesh
		my_glGenVertexArrays(1, &(vao));
		aMesh.setVao(vao);
		my_glBindVertexArray(aMesh.getVao());

		// buffer for faces
		//my_glGenBuffers(1, &buffer);
		//my_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
		//my_glBufferData(GL_ELEMENT_ARRAY_BUFFER,
				//sizeof(unsigned int) * mesh->mNumFaces * 3, faceArray,
				//GL_STATIC_DRAW);

		// buffer for vertex positions
		if (mesh->HasPositions()) {
			//my_glGenBuffers(1, &buffer);
			//my_glBindBuffer(GL_ARRAY_BUFFER, buffer);
			//my_glBufferData(GL_ARRAY_BUFFER,
					//sizeof(float) * 3 * mesh->mNumVertices, mesh->mVertices,
					//GL_STATIC_DRAW);
			//my_glEnableVertexAttribArray(vertexLoc);
			//my_glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, 0, 0, 0);
		}

		// buffer for vertex normals
		if (mesh->HasNormals()) {
		//	my_glGenBuffers(1, &buffer);
			//my_glBindBuffer(GL_ARRAY_BUFFER, buffer);
			//my_glBufferData(GL_ARRAY_BUFFER,
				//	sizeof(float) * 3 * mesh->mNumVertices, mesh->mNormals,
					//GL_STATIC_DRAW);
			//my_glEnableVertexAttribArray(normalLoc);
			//my_glVertexAttribPointer(normalLoc, 3, GL_FLOAT, 0, 0, 0);
		}

		// buffer for vertex texture coordinates
		if (mesh->HasTextureCoords(0)) {
			float *texCoords = (float *) malloc(
					sizeof(float) * 2 * mesh->mNumVertices);
			for (unsigned int k = 0; k < mesh->mNumVertices; ++k) {

				texCoords[k * 2] = mesh->mTextureCoords[0][k].x;
				texCoords[k * 2 + 1] = mesh->mTextureCoords[0][k].y;

			}
			//my_glGenBuffers(1, &buffer);
			//my_glBindBuffer(GL_ARRAY_BUFFER, buffer);
			//my_glBufferData(GL_ARRAY_BUFFER,
				//	sizeof(float) * 2 * mesh->mNumVertices, texCoords,
					//GL_STATIC_DRAW);
			//my_glEnableVertexAttribArray (texCoordLoc);
			//my_glVertexAttribPointer(texCoordLoc, 2, GL_FLOAT, 0, 0, 0);
		}

		// unbind buffers
		//my_glBindVertexArray(0);
		//my_glBindBuffer(GL_ARRAY_BUFFER, 0);
		//my_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		// create material uniform buffer
		struct aiMaterial *mtl = scene_->mMaterials[mesh->mMaterialIndex];

		aiString texPath;	//contains filename of texture
		if(AI_SUCCESS == mtl->GetTexture(aiTextureType_DIFFUSE, 0, &texPath)){
				//bind texture
				unsigned int texId = textureIdMap[texPath.data];
				aMesh.setTexIndex(texId);
				aMat.setTexCount(1);
			}
		else
			aMat.setTexCount(0);

		float c[4];
		set_float4(c, 0.8f, 0.8f, 0.8f, 1.0f);
		aiColor4D diffuse;
		if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
			color4_to_float4(&diffuse, c);
		memcpy(aMat.diffuse, c, sizeof(c));

		set_float4(c, 0.2f, 0.2f, 0.2f, 1.0f);
		aiColor4D ambient;
		if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &ambient))
			color4_to_float4(&ambient, c);
		memcpy(aMat.ambient, c, sizeof(c));

		set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
		aiColor4D specular;
		if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &specular))
			color4_to_float4(&specular, c);
		memcpy(aMat.specular, c, sizeof(c));

		set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
		aiColor4D emission;
		if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_EMISSIVE, &emission))
			color4_to_float4(&emission, c);
		memcpy(aMat.emissive, c, sizeof(c));

		float shininess = 0.0;
		unsigned int max;
		aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS, &shininess, &max);
		aMat.setShininess(shininess);

		GLuint uniformBlockIndex = aMesh.getUniformBlockIndex();
		//my_glGenBuffers(1,&(uniformBlockIndex));
		aMesh.setUniformBlockIndex(uniformBlockIndex);

		//my_glBindBuffer(GL_UNIFORM_BUFFER,aMesh.getUniformBlockIndex());
		//my_glBufferData(GL_UNIFORM_BUFFER, sizeof(aMat), (void *)(&aMat), GL_STATIC_DRAW);

		myMeshes_.push_back(aMesh);
	}
	*/
	return true;
}

