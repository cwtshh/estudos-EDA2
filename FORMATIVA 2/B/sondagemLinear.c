#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *tb;
    int M; 
    int N; 
} TH;

int aumentaTamanho(int M) {}

int hash(int ch, int M) {
    return ch % M;
}

void THinsere (TH *h, int ch) {
    if(h->N > (h->M/2)) {
        h->M = aumentaTamanho(h->M);
    }

    int position = hash(ch, h->M);

    if(h->tb[position] == -1) {
        h->tb[position] = ch;
    } else {
        for(int i = position; i < h->M; i++) {
            if(h->tb[i] == -1) {
                h->tb[i] = ch;
                break;
            }
        }
    }
}

int THremove(TH *h, int ch) {
    int position = hash(ch, h->M);

    if(h->tb[position] == ch) {
        h->tb[position] = -1;

        return 0;
    } else {
        for(int i = position; i < h->M; i++) {
            if(h->tb[i] == ch) {
                h->tb[i] = -1;
                return 0;
            }

            if(h->tb[i] == -1) {
                return -1;
            }
        }
    }
    return -1;
}

int THbusca (TH *h, int ch) {
    int position = hash(ch, h->M);

    if(h->tb[position] == ch) {
        return position;
    } else {
        for(int i = position; i < h->M; i++) {
            if(h->tb[i] == ch) {
                return i;
            }

            if(h->tb[i] == -1) {
                return 0;
            }
        }
    }
    return 0;
}

