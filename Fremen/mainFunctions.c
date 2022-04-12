#include "mainFunctions.h"

void initMainFunctions(){
    printa("Init Main Functions\n");
}

void login(){

}

void search(){

}

void send(){

}

void photo(){

}

void logout(){

}

void ls(int espais){
    char * argument_list[] = {"ls", NULL};
    switch (espais) {
        case 0:

            execvp("ls", argument_list);
            break;
        case 1:
            break;
        case 2:
            break;
    }
}
void ps(){}
void cat(){}
void rm(){}
void head(){}
void whoami(){
    char * argument_list[] = {"whoami", NULL};
    execvp("whoami", argument_list);
}
void who(){
    char* argument_list[] = {"who", NULL};
    execvp("who", argument_list);
}
void pwd(){
    char* argument_list[] = {"pwd", NULL};
    execvp("pwd", argument_list);
}
void wc(){}