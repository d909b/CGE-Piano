/*
 * UpdateListener.h
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#pragma once

class UpdateListener
{
public:
	UpdateListener();
	virtual ~UpdateListener();

	virtual void update(double deltaTime) = 0;
};

