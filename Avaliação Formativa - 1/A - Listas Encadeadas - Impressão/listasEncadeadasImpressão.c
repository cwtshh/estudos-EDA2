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

int main() {

    celula *le = malloc(sizeof(celula));
    celula *le2 = malloc(sizeof(celula));
    celula *le3 = malloc(sizeof(celula));
    celula *le4 = malloc(sizeof(celula));

    le->dado = 1;
    le2->dado = 2;
    le3->dado = 3;
    le4->dado = 4;

    le->prox = le2;
    le2->prox = le3;
    le3->prox = le4;
    le4->prox = NULL;

    imprime(le);

    imprime_rec(le);


    return 0;
}