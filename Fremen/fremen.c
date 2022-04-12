#include "fremen.h"
#include "tools.h"
#include "socket.h"
#include "communication.h"
#include <stdlib.h>


Config * config;

void RSI_sigint(){
    printa("Sigint\n");
    freeAllMem(config);
}

void RSI_alarm(){
    printa("Alarm\n");
}

void ksinghandler(int signum){
    switch(signum){
        case SIGINT:
            RSI_sigint();
            raise(9);
            break;

        case SIGALRM:
            RSI_alarm();
            alarm(config->tNeteja);
            break;
    }
    signal(signum, ksinghandler);
}

void initSignals(Config * config){
    signal(SIGINT, ksinghandler);
    signal(SIGALRM, ksinghandler);
    printa("Init Signals\n");
    alarm(config->tNeteja);
}

int main(int argc, char ** argv){
    int opcio = 0;
    int n_espais = 0;
    char * input;
    char option[MAX_INPUT] = {'a','b'};

    if(argc != 2){
        perror("ERROR: Input invalid\n");
        return 0;
    }

    initSocket();       //Inicialitzem Socket
    initCom();          //Inicialitzem communicacions
    config = llegirFitxer(argv[1]);     //Llegim fitxer configruacio
    initSignals(config);    //Inicialitzem signals
    initMainFunctions();    //Inicialitzem Main Functions

    printa(BENVINGUT);
    while(!opcio){
        input = read_until(FD_READER, '\n');
        //printa(input);
        n_espais = prepareData(input, option);
        //printa("\nOption: ");
        //printa(option);
        //printa("\n");

        if(myStrcmp(option, LOGIN) == 1){               //LOGIN
            printa("\nLogin\n");
            login(n_espais);
        }else if(myStrcmp(option, SEARCH) == 1){        //SEARCH
            printa("\nSearch\n");
            search(n_espais);
        }else if(myStrcmp(option, SEND) == 1){
            printa("\nSend\n");
            send(n_espais);
        }else if(myStrcmp(option, PHOTO) == 1){
            printa("\nPhoto\n");
            photo(n_espais);
        }else if(myStrcmp(option, LOGOUT) == 1) {
            printa("\nLogout\n");
            logout(n_espais);
        } else if(myStrcmp(option, LS) == 1) {          //LS
            printa("\nLs\n");
            ls(n_espais);
        }else if(myStrcmp(option, PS) == 1) {
            printa("\nPs\n");

        }else if(myStrcmp(option, CAT) == 1) {
            printa("\nCat\n");

        }else if(myStrcmp(option, RM) == 1) {
            printa("\nRm\n");

        }else if (myStrcmp(option, HEAD) == 1) {
            printa("\nHead\n");

        }else if(myStrcmp(option, WHOAMI) == 1) {
            printa("\nWhoami\n");

        }else if(myStrcmp(option, WHO) == 1) {
            printa("\nWho\n");

        }else if(myStrcmp(option, PWD) == 1) {
            printa("\nPwd\n");
            pwd();
        }else if(myStrcmp(option, PWD) == 1){
            printa("\nWc\n");

        }else{
            printa("Comanda KO. Comanda no correcte\n");
        }


        free(input);
        opcio = 1;
    }

    freeAllMem(config);

}
