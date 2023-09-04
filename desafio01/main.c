#include <stdio.h>
#include <math.h>

int LINHAS = 3, COLUNAS = 3;

int dimensionar(int x, int y)
{
    LINHAS = x;
    COLUNAS = y;
    return LINHAS * COLUNAS;
}

int calculoPos(int indLinha, int indColuna)
{
    return (indLinha - 1) * COLUNAS + (indColuna - 1);
}

int buscaEspecifica(int vet[], int indLinha, int indColuna)
{
    return vet[calculoPos(indLinha, indColuna)];
}

void preencherMat(int vet[], int num, int indLinha, int indColuna)
{
    vet[calculoPos(indLinha, indColuna)] = num;
}



void zerarMatriz(int vet[])
{
    int k;
    for (k = 0; k < LINHAS * COLUNAS; k++)
    {
        vet[k] = 0;
    }
}



void imprimirMatriz(int vet[])
{
    int k, g, a;
    for (k = 1; k <= LINHAS; k++)
    {
        for(g=1; g <= COLUNAS; g++){
            a = buscaEspecifica(vet, k, g);
            printf("%d ", a);
        }
        printf("\n");
    }
    printf("\n");
    
}

void somaMatrizes(int vet1[], int vet2[], int vet3[])
{
    int k;
    for (k = 0; k < LINHAS * COLUNAS; k++)
    {
        vet3[k] = vet1[k] + vet2[k];
    }
}

void main()
{
    int tam = dimensionar(3, 3);

    int vetor1[tam];
    int vetor2[tam];
    int vetor3[tam];

    zerarMatriz(vetor1);
    zerarMatriz(vetor2);
    zerarMatriz(vetor3);

    preencherMat(vetor1, 15, 1, 1);
    preencherMat(vetor1, 25, 2, 2);
    preencherMat(vetor1, 35, 3, 3);

    preencherMat(vetor2, 10, 1, 1);
    preencherMat(vetor2, 12, 2, 2);
    preencherMat(vetor2, 45, 3, 3);

    imprimirMatriz(vetor1);
    imprimirMatriz(vetor2);
    imprimirMatriz(vetor3);

    int a = buscaEspecifica(vetor1, 1, 1);
    printf("Valor da posição 1, 1 do vetor 1: %d\n\n", a);

    somaMatrizes(vetor1, vetor2, vetor3);

    printf("Após somar as matrizes:\n");
    imprimirMatriz(vetor1);
    imprimirMatriz(vetor2);
    imprimirMatriz(vetor3);

}
