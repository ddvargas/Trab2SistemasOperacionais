#include <stdio.h>
#include <unistd.h>
//#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

const int NUM_POSICOES_FLOAT = 16;


/**
 * Função que converte um float para uma string
 * @param num numero em ponto flutuante a ser convertido
 * @return ponteiro da string
 */
void floatToString(float num, char str[]){
    sprintf(str, "%f", num);
}



int main() {
    //eu sou a bateria, preciso criar dois processos nó e passar a altura e a voltagem/2
    float voltagem = 0;
    char strVoltagem[NUM_POSICOES_FLOAT];
    pid_t no1, no2;

    printf("Defina a voltagem da bateria: ");
    scanf("%f", &voltagem);

    floatToString(voltagem, strVoltagem);
    printf("Valor convertido pra string: %s", strVoltagem);


    no1 = fork();
    if (no1 < 0){//erro
        perror("Erro ao criar processo do primeiro nó");
        exit(1);
    } else if (no1 == 0){ //filho
        //aqui trocar o código do filho para um processo nó passando a altura da arvore e a voltagem/2
        execl("nodo", strVoltagem, NULL);
    } else {
        //criar outro nó
        no2 = fork();
        if (no2 < 0){ //erro
            perror("Erro ao criar processo do segundo nó");
            exit(1);
        } else if (no2 == 0){
            //filho 2
            execl("nodo", strVoltagem, NULL);
        } else{
            //esperar pelo nó 2
            wait(NULL);
        }
        //esperar pelo nó 1
        wait(NULL);
    }


    printf("Encerrando execução do programa principal\n");
    exit(0);
}
