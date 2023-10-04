#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    int dado;
    struct celula *prox;

}celula;

int remove_depois(celula *p) {
<<<<<<< HEAD

=======
    if(p->prox == NULL) {
        return 0;
    }

    celula *aux = p->prox;

    if(aux->prox != NULL) {
        p->prox = aux->prox;
        free(aux);
        return 1;
    } else {
        p->prox = NULL;
        free(aux);
        return 1;
    }

}

void remove_emenento(celula *le, int x) {
    celula *aux = le;

    while(aux->prox != NULL) {
        if(aux->prox->dado == x) {

        }
    }

    free(aux);
}

void remove_todos_elementos(celula *le, int x) {
    
>>>>>>> d48c4b80b66de5bbf12ac1c966ff0158e81a9cb0
}

int main() {



    return 0;
}