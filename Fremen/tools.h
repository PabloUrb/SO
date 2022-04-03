#ifndef _tools_h_
#define _tools_h_

#include "fremen.h"
#include "socket.h"
#include "communication.h"

/*
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
*/

typedef struct{
    int tNeteja;
    char * ipServer;
    int port;
    char * nom_carpeta;
}Config;


char * read_until(int fd, char delimiter);
void printa(char * cadena);
Config *llegirFitxer(char * fileConfig);
void prepareData(char * input, char * option);
void freeAllMem(Config * config);

#endif
