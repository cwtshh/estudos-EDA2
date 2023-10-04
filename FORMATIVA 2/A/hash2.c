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
    int position = ch % h->M;

    celula *pAnt, *pPost;
    pAnt = h->tb[position].prox;

    if(pAnt->dado == ch) {
        pPost = pAnt->prox;
        free(pAnt);
        h->tb[position].prox = pPost;
        h->N = h->N - 1;
        return 0;
    }

    int i = 0;

    while(pAnt->prox->dado != ch || i == h->N) {
        if(pAnt->prox == NULL) {return -1;}
        pAnt = pAnt->prox;
        i++;
    }

    pPost = pAnt->prox->prox;
    free(pAnt->prox);
    pAnt->prox = pPost;
    h->N = h->N - 1;
    return 0;
}

int THbusca (TH *h, int ch) {
    int position = ch % h->M;

    celula *p = h->tb[position].prox;

    int i = 0;

    while(p->dado != ch || i == h->N) {
        if(p->prox == NULL) {return 0;}
        p = p->prox;
        i++;
    }

    return 1;
}

int main() {


    TH *h = (TH *) malloc(sizeof(TH));
    h->M = 2;
    h->N = 0;

    h->tb = (celula *) malloc(h->M * sizeof(celula));

    THinsere(h, 10);
    THinsere(h, 20);
    THinsere(h, 30);
    THinsere(h, 40);

    printf("N: %d\n", h->N);

    celula *pAux = h->tb[0].prox;

    int i = 0;

    while(i < h->N) {
        printf("%d ", pAux->dado);
        pAux = pAux->prox;
        i++;
    }

    /* while(pAux != NULL) {
        printf("%d ", pAux->dado);
        pAux = pAux->prox;
    } */


    /* TH *h = (TH *) malloc(sizeof(TH));
    h->M = 10;
    h->N = 0;
    h->tb = (celula *) malloc(h->M * sizeof(celula));

    THinsere(h, 10);
    THinsere(h, 20);
    THinsere(h, 30);
    THinsere(h, 40);
    THinsere(h, 50);
    THinsere(h, 60);
    THinsere(h, 70);
    THinsere(h, 80);
    THinsere(h, 90);
    THinsere(h, 100);

    printf("N: %d\n", h->N);

    celula *pAux = h->tb[0].prox;

    int i = 0;

    while(pAux != NULL || i == h->N) {
        printf("%d ", pAux->dado);
        pAux = pAux->prox;
    }

    printf("\n");

    THremove(h, 10);
    THremove(h, 20);
    THremove(h, 30);

    printf("N: %d\n", h->N);

    pAux = h->tb[0].prox;

    int j = 0;
    while(pAux != NULL || j == h->N) {
        printf("%d ", pAux->dado);
        pAux = pAux->prox;
        j++;
    }

    printf("\n");

    THbusca(h, 10); */



    return 0;
}


