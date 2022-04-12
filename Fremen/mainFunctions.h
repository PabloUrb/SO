#ifndef _mainFunctions_h_
#define _mainFunctions_h_

#include "fremen.h"
#include "socket.h"
#include "communication.h"
#include "tools.h"

void initMainFunctions();

void login();
void search();
void send();
void photo();
void logout();

void ls(int espais);
void ps();
void cat();
void rm();
void head();
void whoami();
void who();
void pwd();
void wc();

#endif