#include <stdio.h>

const LINHAS = 3, COLUNAS = 3;

void preencherMat(int vet[]) {
    int num, posicao, indLinha, indColuna;
    printf("\nDigite as posicoes X e Y que deseja preencher na matriz: ");
    scanf("%d %d", &indLinha, &indColuna);
    printf("\nDigite o numero que deseja colocar: ");
    scanf("%d", &num);
    posicao = ((indLinha - 1) * COLUNAS) + (indColuna - 1);
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
    posicao = ((indLinha - 1) * COLUNAS) + (indColuna - 1);
    printf("\nO numero da posicao %d e %d eh %d\n", indLinha, indColuna, vet[posicao]);
}

void somaMatrizes(int vet1[], int vet2[], int vet3[]){
    int k;
    for (k = 0; k < LINHAS * COLUNAS; k++) {
        vet3[k] = vet1[k] + vet2[k];
    }
}

int decisao(int vet1[], int vet2[]){
    printf("Qual matriz voce vai escolher (1, 2):");
    int dec;
    scanf("%d", &dec );
    return (dec == 1) ? 1 : 2;
}



void main() {
    int vetor[LINHAS*COLUNAS], escolha = 0;
    int vetor2[LINHAS*COLUNAS];
    int vetor3[LINHAS*COLUNAS];
    zerarMatriz(vetor);
    zerarMatriz(vetor2);
    zerarMatriz(vetor3);

    printf("\nDigite uma opcao:\n1-Inserir dados,\n2-Imprimir,\n3-Zerar,\n4-Busca detalhada,\n5-Soma Matrizes\n6-Imprimir Matriz C\n0-Sair ");
    scanf("%d", &escolha);
    while (escolha != 0) {
        if (escolha == 1) {
            int dec = decisao(vetor, vetor2);
            (dec == 1)? preencherMat(vetor) : preencherMat(vetor2); 
        } else if (escolha == 2) {
            int dec = decisao(vetor, vetor2);
            (dec == 1)? imprimirMatriz(vetor) : imprimirMatriz(vetor2); 
        } else if (escolha == 3) {
            int dec = decisao(vetor, vetor2);
            (dec == 1)? zerarMatriz(vetor) : zerarMatriz(vetor2); 
        } else if (escolha == 4) {
            int dec = decisao(vetor, vetor2);
            (dec == 1)? buscaEspecifica(vetor) : buscaEspecifica(vetor2);
        } else if(escolha == 5){
            somaMatrizes(vetor, vetor2, vetor3);
        } else if(escolha == 6){
            imprimirMatriz(vetor3);
        }else {
            printf("\nDigite um numero valido!\n");
        }
        printf("\nDigite uma opcao:\n1-Inserir dados,\n2-Imprimir,\n3-Zerar,\n4-Busca detalhada,\n5-Soma Matrizes\n6-Imprimir Matriz C\n0-Sair ");
        scanf("%d", &escolha);
    }
}
