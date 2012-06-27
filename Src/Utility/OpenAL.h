/*
 * OpenAL.h
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#if __CDT_PARSER__
	#include <al.h>
#else
	#if __APPLE__
		#include <OpenAL/al.h>
		#include <OpenAL/alut.h>
		#include <OpenAL/alc.h>
	#else
		#include <AL/al.h>
		#include <AL/alut.h>
		#include <AL/alc.h>
	#endif
#endif


