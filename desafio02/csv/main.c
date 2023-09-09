#include <stdio.h>
#include <string.h>

// crud
// create -> OK
// read -> Falta resolver o bug de não aparecer o anterior
// update -> OK
// delete -> PENDENTE

//Metas:
//1- Otimizar o código na parte de criação do arquivo, para ficar somente uma função e passar a ação como parâmetro
//2- Organizar as funções preencherDados e preencherNovosDados para receber seus devidos dados como parâmetro
//3- Criar o procedimento de deletar uma linha a partir da matrícula
//4- Terminar o read

//struct para operações de crud
struct Colunas {
    long int matricula;
    char nome[100];
    char curso[50];
    int idade;
};

//cria o arquivo
void criarArquivo(FILE **arquivo) {     //recebe um ponteiro para o ponteiro de File
    *arquivo = fopen("dados.csv", "a"); //escrita e leitura e também atribui o ponteiro resultante a variavel apontada por arquivo
}

//fechar o arquivo 
void fecharArquivo(FILE *arquivo) {   
    if(arquivo != NULL) {
        fclose(arquivo);               //diferentemente do fopen, o fclose só espera um ponteiro do arquivo de seu argumento
    }
}

//preenche os dados do struct
void preencherDados(struct Colunas *dados) {  
    dados->matricula = 2002;
    strcpy(dados->nome, "Teste2");
    strcpy(dados->curso, "ADS");
    dados->idade = 18;
}

//pega os dados preenchidos e adiciona no .csv
void adicionarDados(FILE *arquivo, const struct Colunas *dados) {
    fprintf(arquivo, "%ld,%s,%s,%d\n", dados->matricula, dados->nome, dados->curso, dados->idade);
}

//ler dados
void lerDados(FILE *arquivo) {
    struct Colunas dados;
    arquivo = fopen("dados.csv", "r");
    rewind(arquivo);
    while (fscanf(arquivo, "%ld,%[^,],%[^,],%d\n", &dados.matricula, dados.nome, dados.curso, &dados.idade) == 4) {
        printf("Matricula: %ld, Nome: %s, Curso: %s, Idade: %d\n", dados.matricula, dados.nome, dados.curso, dados.idade);
    }

    // %[^,] é para ler string até chegar na "," , foi preciso passar por referência os números,
    //pois eles não passam por padrão, diferente dos arrays

    // a condição é igual a 4 porque o fscanf vai ler as 4 partes de dados do struct
}

void adicionarNovosDados(FILE *arquivo, long int matriculaBuscada, const struct Colunas *novosDados) {
    //abre o arquivo no modo leitura e escrita
    arquivo = fopen("dados.csv", "r+");

    if (arquivo == NULL){
        printf("impossivel editar um arquivo nulo");
        return;
    }

    struct Colunas dados;
    long int posicao = ftell(arquivo);

    while (fscanf(arquivo, "%ld,%[^,],%[^,],%d\n", &dados.matricula, dados.nome, dados.curso, &dados.idade) == 4) {
        if(matriculaBuscada == dados.matricula) {
            //se encontrou a matricula, vai atualizar diretamente no arquivo, o seek deve receber o arquivo, a posicao que é captada
            //pelo ftell e seek_set que vai para o inicio do arquivo
            fseek(arquivo, posicao, SEEK_SET);
            fprintf(arquivo, "%ld,%s,%s,%d\n", novosDados->matricula, novosDados->nome, novosDados->curso, novosDados->idade);
            break;                            //olhar
        }
        posicao = ftell(arquivo);
    }
    fecharArquivo(arquivo);
}

void preencherNovosDados(struct Colunas *novosDados) {
    novosDados->matricula = 2050;
    strcpy(novosDados->nome, "hahaha");
    strcpy(novosDados->curso, "ADS");
    novosDados->idade = 18;
}

void main() {
    FILE *arquivo;
    struct Colunas dados;
    struct Colunas novosDados;

    criarArquivo(&arquivo);

    //preencherDados(&dados);

    //adicionarDados(arquivo, &dados);

    //lerDados(arquivo);

    preencherNovosDados(&novosDados);

    adicionarNovosDados(arquivo, 2000, &novosDados);

    fecharArquivo(arquivo);
}