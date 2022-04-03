#include "tools.h"


char *read_until(int fd, char delimiter){
    char *msg = (char *) malloc(1);
    char current;
    int i = 0;

    while (read(fd, &current, 1) > 0) {
        msg[i] = current;
        msg = (char *) realloc(msg, ++i + 1);

        if (current == delimiter) break;
    }

    msg[i-1] = '\0';

    return msg;
}

int extreuCadena (char * origen, int posicio, char limit, char * retorn){
    int i;
    i=0;
    while (origen[posicio] != limit && origen[posicio] != '\0'){
        retorn[i]=origen[posicio];
        i++;
        posicio++;
    }
    retorn[i]='\0';
    posicio++;
    return posicio;
}


int myAtoi(char * cadena){
    int retorn = 0;
    int i = 0;
    while(cadena[i] != '\0'){
        retorn = retorn*10 + cadena[i] - '0';
        i++;
    }
    return retorn;
}

void printa(char * cadena){
    write(1, cadena, strlen(cadena));
}

void printaInt(int i){
    char aux[10];
    sprintf(aux, "\nInt: %d\n\n", i);
    printa(aux);
}



Config *llegirFitxer(char * fileConfig){
    Config * config = (Config *)malloc(sizeof (Config));
    char * aux;
    char printaC[80];

	int fd_file = open(fileConfig, O_RDONLY);
	if(fd_file < 0){
		perror("ERROR: File descriptor\n");
	}

    aux = read_until(fd_file, '\n');
    config->tNeteja = myAtoi(aux);
    free(aux);

    config->ipServer = read_until(fd_file, '\n');

    aux = read_until(fd_file, '\n');
    config->port = myAtoi(aux);
    free(aux);

    config->nom_carpeta = read_until(fd_file, '\n');

    sprintf(printaC, "TNtejea: %d\nIP: %s\nPort: %d\nNom Carpeta: %s\n\n", config->tNeteja, config->ipServer, config->port, config->nom_carpeta);
    printa(printaC);


    printa("Llegir fitxer");
    close(fd_file);

    return config;
}

void prepareData(char * input, char * option){
    int espais = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        if(input[i] == ' ') espais++;
    }
    printaInt(espais);
}

void freeAllMem(Config * config){
    free(config->nom_carpeta);
    free(config->ipServer);
    free(config);


    close(0);
    close(1);
    close(2);
}

