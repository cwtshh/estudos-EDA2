#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb;
    int M;
    int N;
} TH;


void THinsere (TH *h, int ch) {
    int position = ch % h->M;

    celula *nova = malloc(sizeof(celula));
    nova->dado = ch;
    nova->prox = h->tb[position].prox;

    h->tb[position].prox = nova;
}

int THremove (TH *h, int ch) {
    int position = ch % h->M;

    celula *pAnt, *pPost;
    pAnt = &h->tb[position];

    while(pAnt->prox->dado != ch) {
        if(pAnt->prox == NULL) return -1;
        pAnt = pAnt->prox;
    }
    
    pPost = pAnt->prox->prox;

    free(pAnt->prox);
    pAnt->prox = pPost;

    return 1;
}

int THbusca (TH *h, int ch) {
    int position = ch % h->M;

    celula *p = h->tb[position].prox;

    

    while(p->dado != ch) {
        if(p->prox == NULL) return 0;
        p = p->prox;
    }

    return 1;
}