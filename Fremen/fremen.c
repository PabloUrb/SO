#include "fremen.h"
#include "tools.h"
#include "socket.h"
#include "communication.h"

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
    char * input;
    char * option;

    if(argc != 2){
        perror("ERROR: Input invalid\n");
        return 0;
    }

    initSocket();
    initCom();

    config = llegirFitxer(argv[1]);

    initSignals(config);

    printa(BENVINGUT);
    while(!opcio){
        input = read_until(FD_READER, '\n');
        printa(input);
        option = (char *) malloc(sizeof (char ));

        prepareData(input, option);
        free(option);
        free(input);
        opcio = 1;
    }

    freeAllMem(config);

}
