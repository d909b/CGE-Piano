/*
 * SceneManager.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <list>
#include <boost/shared_ptr.hpp>
#include "../Representations/Object.h"
#include "../Representations/Camera.h"
#include "../ModelLoader/ModelManager.h"
#include "../Input/InputManager.h"

#define ROOMMODEL "Resources/3dModels/floor.dae"
#define PIANOMODEL "Resources/3dModels/grand_piano.3DS"


class SceneManager : public InputListener
{
public:
	SceneManager(InputManager& inputManager);
	virtual ~SceneManager();

	void initialize();
	void update(double deltaTime);

	void mouseMoved(int x, int y);
	void keyPressed(int key, int action);

	Camera getCamera() const;

	std::list<boost::shared_ptr<Object> > getObjects() const;
private:
	std::list<boost::shared_ptr<Object> > objects_;
	ModelManager modelManager_;
	InputManager& inputManager_;

	Camera camera_;
	boost::shared_ptr<Object> piano_;
	boost::shared_ptr<Object> metronom_;
	boost::shared_ptr<Object> room_;
};

