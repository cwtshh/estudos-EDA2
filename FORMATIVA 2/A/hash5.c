#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb;
    int M; /* Tamanho */
    int N; /* Chabes presentes */
} TH;


int hash(int ch, int M) {
    return ch % M;
}

void THinsere (TH *h, int ch) {
    int position = hash(ch, h->M);

    celula *nova = (celula *) malloc(sizeof(celula));
    nova->dado = ch;
    nova->prox = h->tb[position].prox;

    h->tb[position].prox = nova;
    h->N++;
}

int THremove (TH *h, int ch) {
    int position = hash(ch, h->M);

    celula *pAnt, *pProx;
    pAnt = h->tb[position].prox;

    int i = 0;
    while(i < h->N + 1) {
        if(pAnt->prox->dado == ch) {
            pProx = pAnt->prox->prox;
            free(pAnt->prox);
            pAnt->prox = pProx;

            return 0;
        }
        pAnt = pAnt->prox;
        i++;
    }

    return -1;
}

int THbusca (TH *h, int ch) {
    int position = hash(ch, h->M);

    celula *aux = h->tb[position].prox;

    int i = 0;
    while(i < h->N + 1) {
        if(aux->dado == ch) {
            return 0;
        }

        aux = aux->prox;
        i++;
    }

    return -1;
}