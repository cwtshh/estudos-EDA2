#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;


/* Pre Ordem */
/* raiz-esquerda-direita. */
void preOrdem(No *raiz) {
    if(raiz == NULL) {
        return;
    }

    printf(raiz->dado);

    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

/* Em Ordem */
/* esquerda-raiz-direta */
void emOrdem(No *raiz) {
    if(raiz == NULL) {
        return;
    }
    emOrdem(raiz->esq);
    printf(raiz->dado);
    emOrdem(raiz->dir);
}

/* Pos Ordem */
/* esquerda-direita-raiz */
void posOrdem(No *raiz) {
    if(raiz == NULL) {
        return;
    }
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf(raiz->dado);
}




