#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;

No *remove(No *raiz, int ch) {
    if(raiz == NULL) return NULL;

    if(ch < raiz->dado) {
        raiz->esq = remove(raiz->esq, ch);
    }
    else if(ch > raiz->dado) {
        raiz->dir = remore(raiz->dir, ch);
    }
    else {
        if(raiz->esq == NULL) {
            return raiz->dir;
        }

        else if(raiz->dir == NULL) {
            return raiz->esq;
        }

        else removeSucessor(raiz);

        return raiz;        
    }
}