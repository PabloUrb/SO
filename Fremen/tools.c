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

int extreuCadena (char * origen, int posicio, char limit, char option[MAX_INPUT]){
    int i = 0;
    while (origen[posicio] != limit && origen[posicio] != '\0'){
        option[i]=origen[posicio];
        i++;
        posicio++;
    }
    option[i]='\0';
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

void printaInt(int i){
    char aux[10];
    sprintf(aux, "\nInt: %d\n\n", i);
    printa(aux);
}

int myStrlen(char * cadena){
    int i = 0;
    while(cadena[i] != '\0'){
        i++;
    }
    return i;
}

void myToLowerCase(char * input){
    for(int i = 0; i < myStrlen(input); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = input[i] + ('a' - 'A');
        }
    }
}

/*
 *
 * return:  1 si son iguals
 *          -1 si no son iguals
 */
int myStrcmp(char * cad1, char * cad2){
    //printa(cad1);
    //printa(cad2);
    for (int i = 0; cad1[i] != '\0' || cad2[i] != '\0'; i++) {
        if(cad1[i] != cad2[i]) return -1;
    }
    return 1;
}

void printa(char * cadena){
    write(1, cadena, myStrlen(cadena));
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

/*
 *
 * return:  0 si no hi ha espais
 *          1 si ...
 */
int prepareData(char * input, char option[MAX_INPUT]){
    int n_espais = 0;
    int index = 0;

    myToLowerCase(input);

    for (int i = 0; input[i] != '\0'; ++i) {
        if(input[i] == ' ') n_espais++;
    }

    if(n_espais == 0){
        for (int i = 0; i < myStrlen(input); ++i) {
            option[i] = input[i];
        }
    }else{
        index = extreuCadena(input, index, ' ', option);
        for (int i = 0; input[index] != '\0'; i++) {
            input[i] = input[index];
            index++;
        }
    }
    //printa("\nInput: ");
    //printa(input);
    //printa("\nOption: ");
    //printa(option);
    //printa("\n");
    return n_espais;
}

void freeAllMem(Config * config){
    free(config->nom_carpeta);
    free(config->ipServer);
    free(config);


    close(0);
    close(1);
    close(2);
}

