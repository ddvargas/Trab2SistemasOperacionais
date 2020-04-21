//
// Created by Daniel Vargas on 20/04/2020.
// Faz o processamento do nó dentro da árvore do circuito
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

const int NUM_POSICOES_FLOAT = 16;


/**
 * Função que converte um float para uma string
 * @param num numero em ponto flutuante a ser convertido
 * @param str ponteiro para o vetor de carcteres no qual serão colocados os caracteres do float
 */
void floatToString(float num, char str[]){
    sprintf(str, "%f", num);
}



int main(int argc, char *argv[]){
    pid_t led1, led2;
    float voltagem = atof(argv[0]);
    char strVoltagem[NUM_POSICOES_FLOAT];

    floatToString(voltagem/2, strVoltagem);
    printf("Eu sou um nó (%d), e meu pai é %d\n", getpid(), getppid());

    //criar dois LEDs
    led1 = fork();
    if (led1 < 0){
        perror("Erro ao criar nó 1 do nó");
    } else if (led1 == 0) { //filho
        execl("led", strVoltagem, NULL);
    } else{ //pai
        led2 = fork();
        if (led2 < 0){
            //erro
            perror("Erro ao criar led 2 do processo de nodo");
        } else if (led2 == 0){
            execl("led", strVoltagem, NULL);
        } else {
            wait(NULL);
        }
        wait(NULL);
    }
}


