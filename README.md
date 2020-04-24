# Simulador de Circuito Fechado

## Objetivo
Este simulador cria um circuito fechado para simular o acendimento ou não de lâmpadas (10mA) usando processos do sistema operacional Unix.
Para isso cria-se uma árvore de processos com nós e LEDs, os LEDs informam se a corrente recebida foi suficiente para o acendimento.
O número de LEDs é criado segundo a altura da árvore, com cada nodo do pénúltimo nível tendo dois nós folhas.

Trabalho desenvolvido para a disciplica de Sistemas Operacionais do curso de Sistemas de Informmação da Universidade Federal de Santa Maria - UFSM.

## Modo de uso
Ao executar o programa, será solicitado a voltagem da corrente inicial, após será solicitado a altura da árvore.
Ao inserir os valores, o programa criará quantos processos forem necessários e mostrará no terminal de linha de comando a saída resultante com os LEDs indicando se estão acesos ou não.

## Compilação
Projeto desenvolvido em linguagem C.
Para a compilação utilize o CMake ou compile individualmente cada arquivo:
  - O Arquivo "nodo.c" deve ser compilado e ter o executável nomeado para "nodo";
  - O arquivo "led.c" ser compilado e ter o executável nomeado para "led";
  - O arquivo "main.c" pode ter qualquer nome;
  - Pode usar o parâmetro -o nodo no gcc
