#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

typedef struct nodo {
    char item;
    struct nodo *proximo;
} Nodo;

typedef struct{
    Nodo *topo;
} Pilha;

void inicializar(Pilha *pilha);
int estaVazia(Pilha *pilha);
void empilhar(Pilha *pilha, char item);
char remover(Pilha *pilha);
int estaBalanciada(char texto[]);

#endif