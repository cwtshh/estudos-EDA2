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

int hashPosition(int ch, int m) {
    return ch % m;
}

void THinsere (TH *h, int ch) {
    int position = hashPosition(ch, h->M);

    celula *nova = (celula *) calloc(1, sizeof(celula));
    nova->dado = ch;
    
    if(h->tb[position].prox) {
        nova->prox = h->tb[position].prox;
    } else {
        nova->prox = NULL;
    }

    h->tb[position].prox = nova;
    h->N = h->N + 1;
}

int THremove (TH *h, int ch) {
    int position = hashPosition(ch, h->M);

    celula *pAnt, *pPost;
    pAnt = h->tb[position].prox;

    int i = 0;
    while(i <= h->N) {
        if(pAnt->prox->dado == ch) {
            pPost = pAnt->prox->prox;
            free(pAnt->prox);
            pAnt->prox = pPost;
            h->N = h->N - 1;

            return 0;
        }
        pAnt = pAnt->prox;
        i++;
    }

    return -1;
}

int THbusca (TH *h, int ch) {
    int postion = hashPosition(ch, h->M);

    celula *aux = h->tb[postion].prox;

    int i = 0;
    while(i <= h->N) {
        if(aux->dado == ch) {
            return 1;
        }
        aux = aux->prox;
        i++;
    }

    return 0;
}



