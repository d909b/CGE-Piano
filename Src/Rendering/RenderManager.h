/*
 * RenderManager.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <list>
#include <boost/smart_ptr.hpp>
#include "../Representations/Object.h"
#include "../Representations/Camera.h"

class RenderManager
{
public:
	RenderManager();
	virtual ~RenderManager();

	void initialize(int width, int height);
	void renderObjects(const Camera& camera, const std::list<boost::shared_ptr<Object> > objects);
private:
	int width_;
	int height_;
};

