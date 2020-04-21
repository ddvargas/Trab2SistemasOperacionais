//
// Created by Daniel Vargas on 20/04/2020.
// Faz o processamento de um LED na estrutura do circuito
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

const int  NUM_POSICOES_FLOAT = 16;

/**
 * Função que converte um float para uma string
 * @param num numero em ponto flutuante a ser convertido
 * @param str ponteiro para o vetor de carcteres no qual serão colocados os caracteres do float
 */
void floatToString(float num, char str[]){
    sprintf(str, "%f", num);
}



int main(int argc, char *args[]){
    float voltagem = atof(args[0]);

    printf("Eu sou o LED %d, filho de %d e estou: ", getpid(), getppid());

    //testar a voltagem
    if (voltagem < 10){
        printf("desligado\n");
    } else{
        printf("ligado\n");
    }

    return 0;
}

