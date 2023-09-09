#include<stdio.h>
#include<string.h>

// Variável que guarda o nome do arquivo
char localFileName[100];

// Abre o arquivo e o cria caso não exista
FILE * openFile(char fileName[100]){
    FILE * file = fopen(fileName, "a");
    strcpy(localFileName, fileName);
    return file;
}

// Fecha o arquivo
void closeFile(FILE * file){
    fclose(file);
}

// Adiciona algum texto no arquivo
void writeFile(FILE * file, char text[100]){
    freopen(localFileName, "a", file);
    fputs(text, file);
    fputs("\n",file);
   
}

// Lê o conteudo do arquivo
void readFile(FILE * file){
    freopen(localFileName, "r", file);
    char text[100];
    while(fgets(text, 100, file) != NULL){
        printf("%s", text);
    }
}

// Deleta o conteudo do arquivo
void deleteFileContent(FILE * file){
    freopen(localFileName, "w", file); 
}



void main(){
    FILE * file = openFile("teste.txt");
 
    writeFile(file, "Primeira linha");
    writeFile(file, "Segunda linha");
    writeFile(file, "Terceira linha");

    readFile(file);
   
    // deleteFileContent(file);

    closeFile(file);
}


