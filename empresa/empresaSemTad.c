#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    int cpf;
    char nome[100];
    int idade;
    char cargo[50];
    float salario;
    struct funcionario *prox;
} Funcionario;

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

void menu() {
    printf("1 - Adicionar funcionario\n");
    printf("2 - Ler funcionarios\n");
    printf("3 - Atualizar funcionario\n");
    printf("4 - Deletar funcionario\n");
    printf("5 - Sair\n");
    printf("Digite uma opcao: ");
}

void adicionarFuncionario(Funcionario **lista, Funcionario *dados) {
    Funcionario *novoFuncionario = (Funcionario*) malloc(sizeof(Funcionario));
    novoFuncionario->cpf = dados->cpf;
    strcpy(novoFuncionario->nome, dados->nome);
    novoFuncionario->idade = dados->idade;
    strcpy(novoFuncionario->cargo, dados->cargo);
    novoFuncionario->salario = dados->salario;
    novoFuncionario->prox = NULL;
    if (*lista == NULL) {
        *lista = novoFuncionario;
    } else {
        Funcionario *aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoFuncionario;
    }
}

void adicionarListaNoArquivo(FILE *arquivo, Funcionario *lista) {
    Funcionario *aux = lista;
    while (aux != NULL) {
        fprintf(arquivo, "%d,%s,%d,%s,%.2f\n", aux->cpf, aux->nome, aux->idade, aux->cargo, aux->salario);
        aux = aux->prox;
    }
}

void lerLista(Funcionario *lista) {
    Funcionario *aux = lista;
    while (aux != NULL) {
        printf("CPF: %d, Nome: %s, Idade: %d, Cargo: %s, Salario: %.2f\n", aux->cpf, aux->nome, aux->idade, aux->cargo, aux->salario);
        aux = aux->prox;
    }
}

void atualizarFuncionario(Funcionario *lista) {
    int cpf;
    printf("Digite o CPF do funcionario que deseja atualizar: ");
    scanf("%d", &cpf);
    Funcionario *aux = lista;
    while (aux != NULL) {
        if (cpf == aux->cpf) {
            printf("CPF: %d, Nome: %s, Idade: %d, Cargo: %s, Salario: %.2f\n", aux->cpf, aux->nome, aux->idade, aux->cargo, aux->salario);
            printf("Digite o novo salario: ");
            scanf("%f", &aux->salario);
            break;
        }
        aux = aux->prox;
    }
}

void deletarFuncionario(Funcionario **lista) {
    int cpf;
    printf("Digite o CPF do funcionario que deseja deletar: ");
    scanf("%d", &cpf);
    Funcionario *aux = *lista;
    Funcionario *ant = NULL;
    while (aux != NULL) {
        if (cpf == aux->cpf) {
            if (ant == NULL) {
                *lista = aux->prox;
            } else {
                ant->prox = aux->prox;
            }
            free(aux);
            break;
        }
        ant = aux;
        aux = aux->prox;
    }
}

void main() {
    FILE *arquivo;
    Funcionario dados;
    Funcionario *lista = NULL;
    int opcao;
    criarArquivo(&arquivo);
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                preencherDados(&dados);
                adicionarFuncionario(&lista, &dados);
                break;
            case 2:
                lerLista(lista);
                break;
            case 3:
                atualizarFuncionario(lista);
                break;
            case 4:
                deletarFuncionario(&lista);
                break;
            case 5:
                adicionarListaNoArquivo(arquivo, lista);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 5);
    fecharArquivo(arquivo);
}