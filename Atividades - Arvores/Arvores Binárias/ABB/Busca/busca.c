#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;

No *busca(No *raiz, int ch) {
    while(raiz != NULL && raiz->dado != ch) {
        if(raiz->dado > ch) raiz = raiz->esq;
        else raiz = raiz->dado;
    } 

    return raiz;
}