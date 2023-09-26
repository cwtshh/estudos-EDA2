#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


celula * busca(celula *le, int x) {
    celula *aux = le->prox;

    while(aux != NULL) {
        if(aux->dado == x) {
            return aux;
        }
        aux = aux->prox;
    }

    return aux;
}

celula * busca_rec(celula *le, int x) {
    if(le->prox == NULL) {
        return NULL;
    }

    if(le->prox->dado == x) {
        return le->prox;
    }

    return busca_rec(le->prox, x);
}

