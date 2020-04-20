//
// Created by Daniel Vargas on 20/04/2020.
// Faz o processamento de um LED na estrutura do circuito
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

const int  NUM_POSICOES_FLOAT = 16;

char *floatToString(float num){
    char *str = malloc(NUM_POSICOES_FLOAT * sizeof(char));
    sprintf(str, "%f", num);

    return str;
}

int main(int argc, char *args[]){
    float voltagem = atof(args[0]);


    printf("Eu sou o LED %d, filho de %d e estou: ", getpid(), getppid());
    printf("Recebi o valor %f na voltagem: %f", voltagem);

    //testar a voltagem
    if (voltagem < 10){
        printf("desligado\n");
    } else{
        printf("ligado\n");
    }

    return 0;
}

