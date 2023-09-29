#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

int remove_depois (celula *le) {
    celula *lixo;
    int x;

    if(le->prox == NULL) {
        return 0;
    }

    lixo = le->prox;
    x = lixo->dado;
    le->prox = lixo->prox;
    free(lixo);

    return 1;
}

void remove_elemento (celula *le, int x) {
    celula *lixo;
    celula *aux = le;

    while(aux->prox != NULL && aux->prox->dado != x) {
        aux = aux->prox;
    }

    if(aux->prox == NULL) {
        return;
    }

    lixo = aux->prox;
    aux->prox = lixo->prox;
    free(lixo);
}

void remove_todos_elementos (celula *le, int x) {
    celula *lixo;
    celula *aux = le;

    while(aux->prox != NULL) {
        if(aux->prox->dado == x) {
            lixo = aux->prox;
            aux->prox = lixo->prox;
            free(lixo);
        } else {
            aux = aux->prox;
        }
    }
}