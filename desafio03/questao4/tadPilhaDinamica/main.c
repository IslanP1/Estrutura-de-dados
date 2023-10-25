#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./pilha.h"

void main () {
    char texto[50];
    printf("TAD PILHA DINAMICA ------------------\n\n");
    
    printf("Insira uma expressão a ser balanceada: ");
    scanf("%99[^\n]", texto);

    if (estaBalanciada(texto)) {
        printf("A expressao esta balanciada \n\n");
    } else {
        printf("A expressao nao esta balanciada \n\n");
    }
    
}