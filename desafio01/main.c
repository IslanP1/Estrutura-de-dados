#include <stdio.h>

const LINHAS = 3, COLUNAS = 3;

void preencherMat(int vet[]) {
    int num, posicao, indLinha, indColuna;
    printf("\nDigite as posicoes X e Y que deseja preencher na matriz: ");
    scanf("%d %d", &indLinha, &indColuna);
    printf("\nDigite o numero que deseja colocar: ");
    scanf("%d", &num);
    posicao = ((indLinha - 1) * 3) + (indColuna - 1);
    vet[posicao] = num;
}

void imprimirMatriz(int vet[]) {
    int k;
    for (k = 0; k < LINHAS * COLUNAS; k++) {
        printf("%d ", vet[k]);
        if ((k + 1) % COLUNAS == 0) { 
            printf("\n");
        }
    }
    printf("\n");
}

void zerarMatriz(int vet[]) {
    int k;
    for (k = 0; k < LINHAS * COLUNAS; k++) {
        vet[k] = 0;
    }
}

void buscaEspecifica(int vet[]) {
    int posicao, indLinha, indColuna;
    printf("\nDigite as posicoes X e Y para saber qual numero ocupa: ");
    scanf("%d %d", &indLinha, &indColuna);
    posicao = ((indLinha - 1) * 3) + (indColuna - 1);
    printf("\nO numero da posicao %d e %d eh %d\n", indLinha, indColuna, vet[posicao]);
}

void main() {
    int vetor[9], escolha = 0;
    zerarMatriz(vetor);

    printf("\nDigite uma opcao:\n1-Inserir dados,\n2-Imprimir,\n3-Zerar,\n4-Busca detalhada,\n5-Sair ");
    scanf("%d", &escolha);
    while (escolha != 0) {
        if (escolha == 1) {
            preencherMat(vetor);
        } else if (escolha == 2) {
            imprimirMatriz(vetor);
        } else if (escolha == 3) {
            zerarMatriz(vetor);
        } else if (escolha == 4) {
            buscaEspecifica(vetor);
        } else {
            printf("\nDigite um numero valido!\n");
        }
        printf("\nDigite uma opcao:\n1-Inserir dados,\n2-Imprimir,\n3-Zerar,\n4-Busca detalhada,\n5-Sair ");
        scanf("%d", &escolha);
    }
}