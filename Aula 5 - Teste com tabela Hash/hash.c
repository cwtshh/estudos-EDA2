#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int chave;
    struct Node *prox;
} Node;


typedef struct {
    Node *ht;
    int size;
} HashNode;

static HashNode t;

void createTable(int m) {
    t.size = m;
    t.ht = (HashNode*) malloc(m * sizeof(HashNode));
}

int hash(int key) {
    return key % t.size;
}

void insert(int key) {
    int position = hash(key);
}

int main() {

    createTable(10);

    printf("%d\n", &t[0].ht.chave);


    return 0;
}
