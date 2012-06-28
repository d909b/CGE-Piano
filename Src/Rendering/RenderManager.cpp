/*
 * RenderManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "RenderManager.h"
#include "../Utility/foreach.h"
#include "../Utility/OpenGL.h"

RenderManager::RenderManager()
{
	;

}

RenderManager::~RenderManager()
{
	;
}

void RenderManager::initialize(int width, int height)
{
	glViewport(0, 0, width, height);

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 5.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glClearColor(125.f/255.f, 125.f/255.f, 125.f/255.f, 1.0f);

	width_ = width;
	height_ = height;
}

void RenderManager::renderObjects(const std::list<boost::shared_ptr<Object> > objects)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect = (float)width_ / (float)height_;

	/** Set up the perspective transformation. */
	glm::mat4 projection = glm::perspective(85.f, aspect, 0.1f, 1000.f);

	glMultMatrixf(glm::value_ptr(projection));

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/** Set up the camera transformation. */

	foreach(boost::shared_ptr<Object> object, objects)
	{
		glPushMatrix();

		/** Set up the model-view transformation. */
		glm::mat4 translation = glm::translate(glm::mat4(1.f), object->getTranslation());
		glm::mat4 modelViewMatrix = translation * glm::mat4(object->getRotation());

		glMultMatrixf(glm::value_ptr(modelViewMatrix));

		/** Render all meshes belonging to this object. */
		foreach(Mesh mesh, object->getMeshes())
		{
			const std::vector<Vertex>& vertices = mesh.getVertices();
			const std::vector<Index>& indices = mesh.getIndices();
			const Texture& texture = mesh.getTexture();

			const Vertex& first = vertices[0];

			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &first.positions[0]);

			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, sizeof(Vertex), &first.normals[0]);

			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &first.textureCoordinates[0]);

			glBindTexture(GL_TEXTURE_2D, texture.getTextureId());
			glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, &indices[0]);
		}

		glPopMatrix();
	}
}


