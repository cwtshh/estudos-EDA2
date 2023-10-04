#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *aux = le;

    if(aux == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", aux->dado);

    while(aux->prox != NULL) {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }

    printf("NULL\n");
}

void imprime_rec(celula *le) {
    celula *aux = le;
    if(aux == NULL) {
        printf("NULL\n");
        return;
    }

    if(aux->prox == NULL) {
        printf("%d -> NULL\n", aux->dado);
        return;
    }

    printf("%d -> ", aux->dado);
    imprime_rec(aux->prox);
}

