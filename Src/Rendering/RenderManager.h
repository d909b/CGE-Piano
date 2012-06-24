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

class RenderManager
{
public:
	RenderManager();
	virtual ~RenderManager();

	void renderObjects(const std::list<boost::shared_ptr<Object> > objects);
};

