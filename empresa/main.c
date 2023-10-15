#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcionario.h"

void main() {
    FILE *arquivo;
    Funcionario dados;
    int opcao;
    criarArquivo(&arquivo);
    do {
        printf("1 - Adicionar funcionario\n");
        printf("2 - Ler funcionarios\n");
        printf("3 - Atualizar funcionario\n");
        printf("4 - Deletar funcionario\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                preencherDados(&dados);
                adicionarDados(arquivo, &dados);
                break;
            case 2:
                lerDados(arquivo);
                break;
            case 3:
                atualizarDados(arquivo, &dados);
                break;
            case 4:
                deletarDados(arquivo, &dados);
                break;
            case 0:
                fecharArquivo(arquivo);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);
}