#include <stdlib.h>

typedef struct {
    int key;
    int read;
    HashNode *next;
} HashNode;

int hash(int value) {
    return value % 31;
}


int main() {

    int numList[100];

    HashNode hashedList[50];


    for(int i = 0; i <= 100; i++) {
        numList[i] = i;
    }

    for(int i = 0; i<= 50; i++) {
        hashedList[i].key = 0;
        hashedList[i].read = 0;
    }

    for(int j = 0; j <= 100; j++) {
        int position = hash(numList[j]);

        if(hashedList[position].read == 0) {
            hashedList[position].key = numList[j];
            hashedList[position].read = 1;
            hashedList[position].next = NULL;

        }

        if(hashedList[position].read == 1) {
            if(hashedList[position].next != NULL) {

                HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
                newNode->key = numList[j];
                newNode->read = 1;
                newNode->next = NULL;
                
                HashNode *aux = hashedList[position].next;

                while(aux->next != NULL) {
                    aux = aux->next;
                }

                aux->next = newNode;
            } else {
                HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
                newNode->key = numList[j];
                newNode->read = 1;
                newNode->next = NULL;

                hashedList[position].next = newNode;
            }
        }
    }



    return 0;
}
