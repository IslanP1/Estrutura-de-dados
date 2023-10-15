#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./funcionario.h"

void criarArquivo(FILE **arquivo) {
    *arquivo = fopen("dados.csv", "a");
}

void fecharArquivo(FILE *arquivo) {
    if(arquivo != NULL) {
        fclose(arquivo);
    }
}

void preencherDados(Funcionario *dados) {
    printf("CPF: ");
    scanf("%d", &dados->cpf);
    printf("Nome: ");
    scanf("%s", dados->nome);
    printf("Idade: ");
    scanf("%d", &dados->idade);
    printf("Cargo: ");
    scanf("%s", dados->cargo);
    printf("Salario: ");
    scanf("%f", &dados->salario);
}

void adicionarDados(FILE *arquivo, const Funcionario *dados) {
    fprintf(arquivo, "%d,%s,%d,%s,%.2f\n", dados->cpf, dados->nome, dados->idade, dados->cargo, dados->salario);
}

void lerDados(FILE *arquivo) {
    Funcionario dados;
    arquivo = fopen("dados.csv", "r");
    rewind(arquivo);
    while (fscanf(arquivo, "%d,%[^,],%d,%[^,],%f\n", &dados.cpf, dados.nome, &dados.idade, dados.cargo, &dados.salario) == 5) {
        printf("CPF: %d, Nome: %s, Idade: %d, Cargo: %s, Salario: %.2f\n", dados.cpf, dados.nome, dados.idade, dados.cargo, dados.salario);
    }
}

void atualizarDados(FILE *arquivo, Funcionario *dados) {
    int cpf;
    printf("Digite o CPF do funcionario que deseja atualizar: ");
    scanf("%d", &cpf);
    arquivo = fopen("dados.csv", "r+");
    rewind(arquivo);
    while (fscanf(arquivo, "%d,%[^,],%d,%[^,],%f\n", &dados->cpf, dados->nome, &dados->idade, dados->cargo, &dados->salario) == 5) {
        if (cpf == dados->cpf) {
            printf("CPF: %d, Nome: %s, Idade: %d, Cargo: %s, Salario: %.2f\n", dados->cpf, dados->nome, dados->idade, dados->cargo, dados->salario);
            printf("Digite o novo salario: ");
            scanf("%f", &dados->salario);
            fseek(arquivo, -sizeof(Funcionario), SEEK_CUR);
            fprintf(arquivo, "%d,%s,%d,%s,%.2f\n", dados->cpf, dados->nome, dados->idade, dados->cargo, dados->salario);
            break;
        }
    }
}

void deletarDados(FILE *arquivo, Funcionario *dados) {
    int cpf;
    printf("Digite o CPF do funcionario que deseja deletar: ");
    scanf("%d", &cpf);
    arquivo = fopen("dados.csv", "r");
    FILE *tempArquivo = fopen("temp.csv", "w");
    rewind(arquivo);
    while (fscanf(arquivo, "%d,%[^,],%d,%[^,],%f\n", &dados->cpf, dados->nome, &dados->idade, dados->cargo, &dados->salario) == 5) {
        if (cpf != dados->cpf) {
            fprintf(tempArquivo, "%d,%s,%d,%s,%.2f\n", dados->cpf, dados->nome, dados->idade, dados->cargo, dados->salario);
        }
    }
    fclose(arquivo);
    fclose(tempArquivo);
    remove("dados.csv");
    rename("temp.csv", "dados.csv");
}
