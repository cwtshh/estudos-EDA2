#include <stdio.h>
#include "hashT1.h"

static HashList t;

void createTable(int m) {
    t.m = m;
    t.ht = malloc(m * sizeof(Cell));
}

int hash(Item key) {
    return key % t.m;
}

int insert(Item key) {
    int position = hash(key);

    if(t.ht == NULL) {
        
    }
}


int main() {


    return 0;
}