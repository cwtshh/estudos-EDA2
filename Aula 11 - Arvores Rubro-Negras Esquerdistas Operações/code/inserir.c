#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;

No * rotacaoEsquerda(No *raiz){
    No *x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
}