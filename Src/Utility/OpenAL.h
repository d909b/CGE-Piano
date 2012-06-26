/*
 * OpenAL.h
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#pragma once

#if __CDT_PARSER__
	#include <al.h>
#else
	#if __APPLE__
		#include <OpenAL/al.h>
	#else
		#include <AL/al.h>
	#endif
#endif


