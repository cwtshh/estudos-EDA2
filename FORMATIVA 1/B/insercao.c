#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    int dado;
    struct celula *prox;
}celula;


void insere_inicio (celula *le, int x) {
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = le->prox;
    le->prox = nova;
}

void insere_antes (celula *le, int x, int y) {
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->dado = x;

    celula *aux = le;
    while(aux->prox != NULL && aux->prox->dado != y) {
        aux = aux->prox;
    }

    nova->prox = aux->prox;
    aux->prox = nova;
}