#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contaLetra(char * palavra) {
    int i = 0;
    while(palavra[i] != '\0') {
        i++;
    }
    return i;
}

int eCaracterEspecial(char letra) {
    char allowedChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";

    return strchr(allowedChars, letra) != NULL;
}

void removerCaracterEspecial(char * palavra) {
    int tamanho = strlen(palavra);
    int i, j = 0;

    for(i = 0; i < tamanho; i++) {
        if(eCaracterEspecial(palavra[i])) {
            palavra[j] = palavra[i];
            j++;
        }
    }

    palavra[j] = '\0';
}

int main() {

    FILE *arq = fopen("textoDeLeitura.txt", "r");
    FILE *saida = fopen("saida1.txt", "w");

    if(!arq) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    char palavra[100];

    while(fscanf(arq, "%s", palavra) != EOF) {
        removerCaracterEspecial(palavra);

        if(contaLetra(palavra) > 3) {
            fprintf(saida, "%s\n", palavra);
        }
    } 

    fclose(arq);
    fclose(saida);

    return 0;
}