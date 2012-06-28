/*
 * InputListener.h
 *
 * @date: Jun 28, 2012
 * @author: patrick
 */

#pragma once

class InputListener
{
public:
	virtual ~InputListener() {;}
	virtual void mouseMoved(int x, int y) = 0;
	virtual void keyPressed(int key, int action) = 0;
};


