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

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	void initialize();
	void update(double deltaTime);

	const std::list<boost::shared_ptr<Object> > getObjects() const;
private:
	std::list<boost::shared_ptr<Object> > objects_;
};
