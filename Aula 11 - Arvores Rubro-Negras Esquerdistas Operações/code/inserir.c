#include <stdio.h>
#include <stdlib.h>

enum cor {
    VERMELHO,
    PRETO
};

typedef struct No {
    int dado;
    struct No *esq, *dir;
    enum cor cor;
} No;

No * rotacaoEsquerda(No *raiz){
    /* complexidade O(1) */
    No *x = raiz->dir;
    raiz->dir = x->esq;
    x->cor = raiz->cor;
    x->esq = raiz;
    raiz->cor = VERMELHO;

    return x;
}

No * rotacaoDireita(No *raiz) {
    No *a = raiz->esq;
    raiz->esq = a->dir;
    a->dir = raiz;
    a->cor = raiz->cor;
    raiz->cor = VERMELHO;

    return a;
}

void sobeCor(No *raiz) {
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

No *corrige(No *raiz) {
    if(raiz->esq->cor == PRETO && raiz->dir->cor == VERMELHO) {
        return rotacaoEsquerda(raiz);
    }

    if(raiz->esq->cor == VERMELHO && raiz->dir->cor == VERMELHO) {
        sobeCor(raiz);
        return raiz;
    }

    if(raiz->esq->cor == VERMELHO && raiz->esq->esq->cor == VERMELHO) {
        raiz = rotacaoDireita(raiz);
        sobeCor(raiz);
        return raiz;
    }
}

No *insere_rec(No *raiz, int ch) {
    if(raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->dado = ch;
        novo->cor = VERMELHO;
        
        return novo;
    }

    if(ch < raiz->dado) raiz->esq = insere_rec(raiz->esq, ch);

    else raiz->dir = insere_rec(raiz->esq, ch);

    return corrige(raiz);
}

No *insere(No *raiz, int ch) {
    raiz = insere_rec(raiz, ch);
    raiz->cor = PRETO;
    
}
