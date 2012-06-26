/*
 * Mesh.h
 * Information to render each assimp node
 *
 *
 *  Created on: Jun 26, 2012
 *      Author: steindl
 */
#ifndef MYMESH_H_
#define MYMESH_H_

#include <glfw.h>

class MyMesh
{
public:
	MyMesh();
	~MyMesh();

	int getNumFaces() const {
		return numFaces;
	}

	void setNumFaces(int numFaces) {
		this->numFaces = numFaces;
	}

	GLuint getTexIndex() const {
		return texIndex;
	}

	void setTexIndex(GLuint texIndex) {
		this->texIndex = texIndex;
	}

	GLuint getUniformBlockIndex() const {
		return uniformBlockIndex;
	}

	void setUniformBlockIndex(GLuint uniformBlockIndex) {
		this->uniformBlockIndex = uniformBlockIndex;
	}

	GLuint getVao() const {
		return vao;
	}

	void setVao(GLuint vao) {
		this->vao = vao;
	}
private:
	GLuint vao;
	GLuint texIndex;
	GLuint uniformBlockIndex;
	int numFaces;
};
#endif
