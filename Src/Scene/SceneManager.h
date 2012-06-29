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
#include "../Infrastructure/UpdateListener.h"

class ApplicationManager;
class GLFWWrapper;

#define ROOMMODEL "Resources/3dModels/floor.dae"
#define PIANOMODEL "Resources/3dModels/grand_piano.3DS"
#define METRONOMMODEL "Resources/3dModels/metronome.obj"
#define SWINGER "Resources/3dModels/swingding.dae"

class SceneManager : public InputListener, public UpdateListener
{
public:
	SceneManager(const ApplicationManager& appManager, InputManager& inputManager, GLFWWrapper& glfwWrapper);
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

	const ApplicationManager& appManager_;
	InputManager& inputManager_;
	GLFWWrapper& glfwWrapper_;

	Camera camera_;
	boost::shared_ptr<Object> piano_;
	boost::shared_ptr<Object> metronom_;
	boost::shared_ptr<Object> swinger_;
	boost::shared_ptr<Object> roomfloor_;
	boost::shared_ptr<Object> roomwall1_;
	boost::shared_ptr<Object> roomwall2_;
	boost::shared_ptr<Object> roomwall3_;
	boost::shared_ptr<Object> roomwall4_;
};

