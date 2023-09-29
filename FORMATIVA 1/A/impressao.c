#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

void imprime(celula *le) {
    celula *p;
    p = le->prox;

    if(le->prox == NULL) {
        printf("NULL");
        return;
    }

    while(p) {
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL");
}

void imprime_rec(celula *le) {
    if(le->prox ==  NULL) {
        printf("NULL");
        return;
    }

    if(le->prox == NULL) {
        printf("NULL");
        return;
    }

    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}