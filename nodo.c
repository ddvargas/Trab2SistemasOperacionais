//
// Created by Daniel Vargas on 20/04/2020.
// Faz o processamento do nó dentro da árvore do circuito
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

const int NUM_POSICOES_FLOAT = 16;


char *floatToString(float num){
    char *str = malloc(NUM_POSICOES_FLOAT * sizeof(char));
    sprintf(str, "%f", num);

    return str;
}



int main(int argc, char *argv[]){
    pid_t led1, led2;
    float voltagem = atof(argv[0]) / 2;
    char *strVoltagem = floatToString(voltagem);


    printf("Eu sou um nó (%d), e meu pai é %d\n", getpid(), getppid());
    printf("Recebi o valor %f na voltagem\n", voltagem);

    //criar dois LEDs
    led1 = fork();
    if (led1 <0){
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


