/*
 * MessagedException.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <exception>
#include <string>

class MessagedException: public std::exception
{
public:
	MessagedException(std::string message) throw() :
		message_(message)
	{;}

	virtual ~MessagedException() throw() {;}

	virtual const char* what() const throw()
	{
		return message_.c_str();
	}
private:
	std::string message_;
};

