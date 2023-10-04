#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{
    int key;
    struct Cell *next;
}Cell;

typedef struct HashList {
    struct Cell *head;
    int size;
} HashList;

static HashList t;

int hashKey(int key) {
    return key % t.size;
}

void createTable(int key) {
    t.size = key;
    t.head = (struct Cell*) calloc(key, sizeof(struct Cell));
}

void insert(int key) {
    int position = hashKey(key);

    struct Cell *newCell = (struct Cell*) malloc(sizeof(struct Cell));
    newCell->key = key;
    newCell->next = NULL;

    if(t.head[position].next == NULL) {
        t.head[position].next = newCell;
    } else {
        struct Cell *aux = t.head[position].next;

        t.head[position].next = newCell;

        newCell->next = aux;
    }

}

void removeKey(int key) {
    int position = hashKey(key);

    if(t.head[position].next == NULL) {
        printf("Elemento nâo encontrado!\n");
        return;
    }

    struct Cell *aux = t.head[position].next;

    if(aux->key == key) {
        t.head[position].next = aux->next;
        free(aux);
        return;
    }

    while(aux->next != NULL) {
        if(aux->next->key == key) {
            struct Cell *aux2 = aux->next;

            aux->next = aux2->next;

            free(aux2);

            break;
        }
    }
}

void search(int key) {
    int position = hashKey(key);

    if(t.head[position].next == NULL) {
        printf("Elemento nâo encontrado!\n");
        return;
    }

    Cell *aux = t.head[position].next;

    while(aux != NULL) {
        if(aux->key == key) {
            printf("Elemento encontrado! %d\n", aux->key);
            break;
        }

        aux = aux->next;
    }
}

void getCollisions(int position) {
    int counter = 0;

    Cell *aux = t.head[position].next;

    while(aux->next != NULL) {
        printf("Elemento presente na colisão: %d\n", aux->key);
        counter++;
        aux = aux->next;
    }

    printf("Colisoes: %d", counter);
}


int main() {

    createTable(10);

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    



    return 0;
}