#ifndef _fremen_h_
#define _fremen_h_

#include "tools.h"
#include "socket.h"
#include "communication.h"
#include "mainFunctions.h"

#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <dirent.h>

#define FD_READER 0
#define FD_SPEAKER 1

#define MAX_INPUT 100
#define LOGIN "login\0"
#define SEARCH "search\0"
#define SEND "send\0"
#define PHOTO "photo\0"
#define LOGOUT "logout\0"
#define LS "ls\0"
#define PS "ps\0"
#define CAT "cat\0"
#define RM "rm\0"
#define HEAD "head\0"
#define WHOAMI "whoami\0"
#define WHO "who\0"
#define PWD "pwd\0"
#define WC "wc\0"

#define BENVINGUT "\nBenvingut a Fremen\n"

/*
typedef struct{
	int tNeteja;
	char * ipServer;
	int port;
	char * nom_carpeta;
}Config;
*/

#endif
