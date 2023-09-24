#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * getWord(char *line) {
    int i = 0;
    char word[20];
    while(line[i] != ' ') {
        word[i] = line[i];
        i++;
    }
    return word;
}

int getWordSize(char *word) {
    int i = 0;
    while(word[i] != '\0') {
        i++;
    }
    return i;
}


int main() {

    FILE *arq;
    FILE *out;

    out = fopen("saida.txt", "w");
    arq = fopen("textoDeLeitura.txt", "r");

    if(!arq) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    char line[100];

    fgets(line, 100, arq);
    printf("%s", line);


    while(fgets(line, 100, arq) != NULL) {
        int i = 0;

        char *word;

        word = strtok(line, " ");

       

        int wordSize = getWordSize(word);

        printf("%s\n", word);
        printf("%d\n", wordSize);

        char outputWord[100];
        strcpy(outputWord, word);

        printf(word);

        strcat(outputWord, "\n");

        if(wordSize > 3) {
            fputc(word, out);
        }

        
    }

    fclose(arq);
    fclose(out);


}