#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./pilha.h"

void inicializar(Pilha *pilha) {
    pilha->topo = -1; 
}

int estaVazia(Pilha *pilha) {
    if (pilha->topo == -1) {
        return 1;
    }
    return 0;
}

int estaCheia(Pilha *pilha) {
    if (pilha->topo == TAMANHO_MAXIMO - 1) {
        return 1;
    }
    return 0;
};


void empilhar(Pilha *pilha, char item) {
    if (estaCheia(pilha)){
        printf("A pilha está cheia! \n\n");
    } else {
        pilha->itens[++pilha->topo] = item;
    }
};

char remover(Pilha *pilha) {
    if (!estaVazia(pilha)){
        return pilha->itens[pilha->topo--];
    }
};

int estaBalanciada(char texto[]) {
    Pilha pilha;
    inicializar(&pilha);
    int tamanho = strlen(texto);
    
    for (int i = 0; i < tamanho; i++) {
        if (texto[i] == '(' || texto[i] == '[' || texto[i] == '{' || (texto[i] == '/' && i+1 < tamanho && texto[i + 1] == '*')) {
            empilhar(&pilha, texto[i]);
           
        } else if (texto[i] == ')' || texto[i] == ']' || texto[i] == '}' || (texto[i] == '*' && i+1 < tamanho && texto[i + 1] == '/')) {
            if (estaVazia(&pilha)) {
                return 0;
            }
            char caractereRemovido = remover(&pilha);

            if ((texto[i] == ')' && caractereRemovido != '(') ||
                (texto[i] == ']' && caractereRemovido != '[') ||
                (texto[i] == '}' && caractereRemovido != '{') || 
                (texto[i] == '*' && caractereRemovido != '/')) {
                return 0;
            }
        }
    }

    return estaVazia(&pilha);
};
