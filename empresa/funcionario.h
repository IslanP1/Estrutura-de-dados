#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>

typedef struct funcionario {
    int cpf;
    char nome[100];
    int idade;
    char cargo[50];
    float salario;
    struct funcionario *prox;
} Funcionario;

void criarArquivo(FILE **arquivo);
void fecharArquivo(FILE *arquivo);
void preencherDados(Funcionario *dados);
void adicionarDados(FILE *arquivo, const Funcionario *dados);
void lerDados(FILE *arquivo);
void atualizarDados(FILE *arquivo, Funcionario *dados);
void deletarDados(FILE *arquivo, Funcionario *dados);

#endif