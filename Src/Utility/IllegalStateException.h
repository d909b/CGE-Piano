/*
 * IllegalStateException.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include "MessagedException.h"

class IllegalStateException : public MessagedException
{
public:
	IllegalStateException(std::string message) throw() :
		MessagedException(message)
	{;}
};

