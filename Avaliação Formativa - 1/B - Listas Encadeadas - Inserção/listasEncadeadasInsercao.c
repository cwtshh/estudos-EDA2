#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    /* cria nova celula */
    celula *novo = malloc(sizeof(celula));

    /* atribui o valor de x a celula */
    novo->dado = x;

    /* aponta o prox da nova celula para o prox da celula le */
    novo->prox = le;
}

void insere_antes(celula *le, int x, int y) {
    int elementoEncontrado = 0;

    celula *novo = malloc(sizeof(celula));
    novo->dado = x;

    celula *aux = le;

    /* verificando o primeiro elemento */
    if(aux->dado = y) {
        novo->prox = aux;
        le = novo;
    }

    /* procura a posiçao de y, se n encontrar para na posuiçao q a prox e null */
    while(aux->prox != NULL) {
        if(aux->prox->dado == y) {
            novo->prox = aux->prox;
            aux->prox = novo;
            elementoEncontrado = 1;
            return;
        }
        aux = aux->prox;
    }

    if(elementoEncontrado == 0) {
        aux->prox = novo;
        novo->prox = NULL;
    }
}




int main() {




    return 0;
}