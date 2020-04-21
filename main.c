//
// Created by Daniel Vargas on 20/04/2020.
// Simula um circuito integrado com leds e o uso de processos
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

const int NUM_POSICOES_FLOAT = 16;


bool validaVoltagem(float voltagem);

bool validaAltura(int arvore);

/**
 * Função que converte um float para uma string
 * @param num numero em ponto flutuante a ser convertido
 * @param str ponteiro para o vetor de carcteres no qual serão colocados os caracteres do float
 */
void floatToString(float num, char str[]){
    sprintf(str, "%f", num);
}



int main() {
    //eu sou a bateria, preciso criar dois processos nó e passar a altura e a voltagem/2
    float voltagem = 0;
    char strVoltagem[NUM_POSICOES_FLOAT];
    char strAltura[] = {};
    pid_t no1, no2;
    int altura_arvore;

    //pegar e validar a voltagem da bateria
    do {
        printf("Defina a voltagem da bateria (0 para encerrar): ");
        scanf("%f", &voltagem);

        if (!validaVoltagem(voltagem))
            printf("Voltagem deve ser maior que zero\n");

        if (voltagem == 0){
            exit(0);
        }
    }while (!validaVoltagem(voltagem));

    //pegar e validar a altura da arvore
    do {
        printf("Defina a altura da arvore (0 para encerrar): ");
        scanf("%d", &altura_arvore);

        if (!validaAltura(altura_arvore))
            printf("Altura deve ser maior que zero\n");

        if (altura_arvore == 0){
            exit(0);
        }
    }while (!validaAltura(altura_arvore));

    floatToString(voltagem/2, strVoltagem);
    floatToString(altura_arvore-1, strAltura);

    if (altura_arvore-1 > 1){
        //criar nos

        printf("Bateria Criando novos nós");

        no1 = fork();
        if (no1 < 0){//erro
            perror("Erro ao criar processo do primeiro nó");
            exit(1);
        } else if (no1 == 0){ //filho
            // faz a troca do das instruções para instruções de nodo
            execl("nodo", strVoltagem, strAltura, NULL);
        } else {
            //criar outro nó
            no2 = fork();
            if (no2 < 0){ //erro
                perror("Erro ao criar processo do segundo nó");
                exit(1);
            } else if (no2 == 0){
                //filho 2
                execl("nodo", strVoltagem, strAltura, NULL);
            } else{
                //esperar pelo nó 2
                wait(NULL);
            }
            //esperar pelo nó 1
            wait(NULL);
        }
    } else{
        //criar leds

        no1 = fork();

        if (no1 < 0){
            //erro
            perror("Erro ao criar led 1 a partir da bateria");
        } else if (no1 == 0){
            execl("led", strVoltagem, strAltura, NULL);
        }else{
            //pai
            no2 = fork();
            if (no2 < 0){
                perror("Erro ao criar led 2 a partir da bateria");
            } else if ( no2 == 0){
                //filho
                execl("led", strVoltagem, strAltura, NULL);
            } else{
                //pai
                wait(NULL);
            }
            wait(NULL);
        }
    }



    printf("\nEncerrando execução do programa principal\n");
    exit(0);
}

bool validaAltura(int arvore) {
    return arvore > 0 ? true : false;
}

bool validaVoltagem(float voltagem) {
    return  voltagem > -1 ? true : false;
}
