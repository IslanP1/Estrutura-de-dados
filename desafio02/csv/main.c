#include <stdio.h>
#include <string.h>

// crud
// create -> OK
// read -> OK
// update -> OK
// delete -> OK

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
    printf("Matricula: ");
    scanf("%ld", &dados->matricula);
    printf("Nome: ");
    scanf("%s", dados->nome);
    printf("Curso: ");
    scanf("%s", dados->curso);
    printf("Idade: ");
    scanf("%d", &dados->idade);
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
    printf("Matricula: ");
    scanf("%ld", &novosDados->matricula);
    printf("Nome: ");
    scanf("%s", novosDados->nome);
    printf("Curso: ");
    scanf("%s", novosDados->curso);
    printf("Idade: ");
    scanf("%d", &novosDados->idade);
}

void deletarDados(FILE **arquivo, long int matriculaDeletar) {
    // Abre o arquivo de entrada para leitura
    *arquivo = fopen("dados.csv", "r");

    if (*arquivo == NULL) {
        printf("Impossivel abrir o arquivo para leitura.\n");
        return;
    }

    // Cria um arquivo temporário para escrever os dados excluindo o registro
    FILE *tempArquivo = fopen("temp.csv", "w");

    if (tempArquivo == NULL) {
        printf("Impossível criar o arquivo temporario.\n");
        fecharArquivo(*arquivo);
        return;
    }

    struct Colunas dados;

    while (fscanf(*arquivo, "%ld,%[^,],%[^,],%d\n", &dados.matricula, dados.nome, dados.curso, &dados.idade) == 4) {
        if (matriculaDeletar != dados.matricula) {
            // Se a matrícula não coincide, escreva os dados no arquivo temporário
            fprintf(tempArquivo, "%ld,%s,%s,%d\n", dados.matricula, dados.nome, dados.curso, dados.idade);
        }
    }

    // Fecha ambos os arquivos
    //fclose(*arquivo);
    fclose(tempArquivo);

    // Remove o arquivo original e renomeia o arquivo temporário para o original
    remove("dados.csv");
    rename("temp.csv", "dados.csv");
}

void main() {
    FILE *arquivo;
    struct Colunas dados;
    struct Colunas novosDados;

    criarArquivo(&arquivo);

    //preencherDados(&dados);

    //adicionarDados(arquivo, &dados);

    //lerDados(arquivo);

    //preencherNovosDados(&novosDados);
    //adicionarNovosDados(arquivo, 2001, &novosDados);

    //deletarDados(&arquivo, 2000);
    
    fecharArquivo(arquivo);
}
