#include <stdio.h>
#include "hash.h"

static hash t;

void criaTabela(int M) {
    t.m = M;
    t.ht = malloc(M * sizeof(Celula));
}

int hashKey(int chave) {
    return chave % t.m;
}

void leInsere(int position, Item chave) {
    if(t.ht[position].dado != NULL) {
        
    }

}

int insere(Item chave) {
    int position = hashKey(chave);


    
}


int main() {


    return 0;
}