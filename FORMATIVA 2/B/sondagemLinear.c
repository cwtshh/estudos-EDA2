#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *tb;
    int M;
    int N;
} TH;

int hashModular (int ch, int M) {
    return ch % M;
}

void THinsere (TH *h, int ch) {
    int position = hashModular(ch, h->M);

    if(h->N > (h->M/2)) {
        int novoTamanho = aumentaTamanho(h->M);
        h->M = novoTamanho;
        h->tb = realloc(h->tb, novoTamanho * sizeof(int));
    }

    if(h->tb[position] == -1) {
        h->tb[position] = ch;
        h->N++;
    } else {
        for(int i = position; i <= h->M; i++) {
            if(h->tb[i] == -1) {
                h->tb[i] = ch;
                h->N++;
                return;
            }

            if(i == h->M) {
                i = 0;
            }
        }
    }
}

int THremove (TH *h, int ch) {
    for(int i = 0; i <= h->M; i++) {
        if(h->tb[i] == ch) {
            h->tb[i] = -1;
            h->N--;
            return 0;
        }
    } 

    return -1;
}

int THbusca (TH *h, int ch) {
    for(int i = 0; i <= h->M; i++) {
        if(h->tb[i] == ch) {
            return 1;
        }
    }

    return 0;
}