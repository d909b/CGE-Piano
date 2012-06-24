/*
 * RenderManager.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include "RenderManager.h"
#include "../Utility/foreach.h"

RenderManager::RenderManager()
{
	;

}

RenderManager::~RenderManager()
{
	;
}

void RenderManager::renderObjects(const std::list<boost::shared_ptr<Object> > objects)
{
	foreach(boost::shared_ptr<Object> object, objects)
	{
		// render object here
	}
}


