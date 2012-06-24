/*
 * main.cpp
 *
 * @date: Jun 24, 2012
 * @author: patrick
 */

#include <cstdlib>
#include <csignal>
#include "Infrastructure/ApplicationManager.h"
#include "Infrastructure/GLFWWrapper.h"

static ApplicationManager* appMgr = new ApplicationManager(60, 4);

void handleSignal(int signr)
{
	appMgr->applicationEnded();

	exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	signal(SIGTERM, handleSignal);
	signal(SIGINT,  handleSignal);
	signal(SIGKILL, handleSignal);

	appMgr->applicationStarted(argc, argv);

	appMgr->applicationEnded();

	return EXIT_SUCCESS;
}
