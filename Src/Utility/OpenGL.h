/*
 * OpenGL.h
 *
 * @date: Jun 25, 2012
 * @author: patrick
 */

#if __CDT_PARSER__
	#include <gl.h>
	#include <glu.h>
#else
	#if __APPLE__
		#include <OpenGL/gl.h>
		#include <OpenGL/glu.h>
	#else
		#include <GL/gl.h>
		#include <GL/glu.h>
	#endif
#endif
