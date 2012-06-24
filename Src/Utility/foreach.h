/*
 * foreach.h
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#pragma once

#include <boost/foreach.hpp>

// Bypassing eclipse parser bug
#ifdef __CDT_PARSER__
	#define foreach(a, b) for(a : b)
#else
	#define foreach(a, b) BOOST_FOREACH(a, b)
#endif


