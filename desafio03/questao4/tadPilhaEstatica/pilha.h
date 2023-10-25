#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#define TAMANHO_MAXIMO 100

typedef struct {
    char itens[TAMANHO_MAXIMO];
    int topo;
} Pilha;

void inicializar(Pilha *pilha);
int estaVazia(Pilha *pilha);
int estaCheia(Pilha *pilha);
void empilhar(Pilha *pilha, char item);
char remover(Pilha *pilha);
int estaBalanciada(char texto[]);

#endif