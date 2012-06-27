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
#include "../ModelLoader/ModelManager.h"

#define DUCKMODEL "./3dModels/duck.dae"
#define PIANOMODEL "./3dModels/piano.3ds"
#define TESTMODEL "./3dModels/test.obj"

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	void initialize();
	void update(double deltaTime);

	std::list<boost::shared_ptr<Object> > getObjects() const;
private:
	std::list<boost::shared_ptr<Object> > objects_;
	ModelManager modelManager_;

	boost::shared_ptr<Object> piano_;
	boost::shared_ptr<Object> metronom_;
	boost::shared_ptr<Object> room_;
};

