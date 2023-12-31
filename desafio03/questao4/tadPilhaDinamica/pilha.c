#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./pilha.h"

void inicializar(Pilha *pilha) {
    pilha->topo = NULL;
};

int estaVazia(Pilha *pilha) {
    if (pilha->topo == NULL) {
        return 1;
    } 
    return 0;
};

void empilhar(Pilha *pilha, char caractere) {
    Nodo *N = (Nodo*)malloc(sizeof(Nodo));
    N->item = caractere;
    N->proximo = pilha->topo;
    pilha->topo = N;
};

char remover(Pilha *pilha) {
    if (!estaVazia(pilha)){
        Nodo *temporario = pilha->topo;
        char removido = temporario->item;
        pilha->topo = temporario->proximo;
        free(temporario);
        return removido;
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