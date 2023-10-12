#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


void imprime (celula *le) {
    celula *aux = le;

    while(aux->prox != NULL) {
        printf("%d ", aux->prox->dado);
        aux = aux->prox;
    }
}


int main() {

    celula *le = (celula *) malloc()



}