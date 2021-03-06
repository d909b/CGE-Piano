ADD_DEFINITIONS(-O0 -Werror -Wall -std=c++0x)

SET(EXECUTABLE_OUTPUT_PATH "Bin/Linux/")

INCLUDE_DIRECTORIES("Lib/Include")
INCLUDE_DIRECTORIES("Lib/Header")

FILE(GLOB_RECURSE PIANO_SCENE_SOURCES "Src/*.cpp")

ADD_EXECUTABLE(PianoScene ${PIANO_SCENE_SOURCES})

FIND_PACKAGE(OpenGL REQUIRED)

ADD_LIBRARY(glfw STATIC IMPORTED)

SET_PROPERTY(TARGET glfw 
		     PROPERTY
             IMPORTED_LOCATION "Lib/Linux/libglfw.a")

ADD_LIBRARY(libjpeg STATIC IMPORTED)

SET_PROPERTY(TARGET libjpeg 
		     PROPERTY
             IMPORTED_LOCATION "Lib/Linux/libjpeg.a")

             
ADD_LIBRARY(assimp STATIC IMPORTED)

SET_PROPERTY(TARGET assimp 
		     PROPERTY
             IMPORTED_LOCATION "Lib/Linux/libassimp.a")
             

ADD_LIBRARY(devIL STATIC IMPORTED)
             
SET_PROPERTY(TARGET devIL 
		     PROPERTY
             IMPORTED_LOCATION "Lib/Linux/libIL.a")
             
TARGET_LINK_LIBRARIES(PianoScene devIL libjpeg glfw ${OPENGL_LIBRARIES} assimp openal alut)
