#include <iostream>

using namespace std;

class Cell {
    public:
        int key;
        Cell *next;

        Cell() {
            key = 0;
            next = NULL;
        }
};

class HashList {
    public:
        Cell *head;
        int size;

        HashList() {}
};

static HashList t;

int hashKey(int key) {
    return key % t.size;
}

void createTable(int key) {
    t.size = key;
    t.head = new Cell[t.size];
}

void insert(int key) {
    int position = hashKey(key);

    Cell *newCell = new Cell();
    newCell->key = key;

    /* Se a posiçao apontar para NULL, sera criado uma nova casa para esta celula */
    if(t.head[position].next == NULL) {
        t.head[position].next = newCell;

    } else {
        /* cria um auxiliar apontando para o proximo elemento da posicao */
        Cell *aux = t.head[position].next;

        /* aponta o primeiro elemento para o novo elemento */
        t.head[position].next = newCell;

        /* aponta o novo elemento para o auxiliar, mantendo a continuidade da lista */
        newCell->next = aux;
    }
}

void remove(int key) {
    int position = hashKey(key);

    if(t.head[position].next == NULL) {
        cout << "Elemento nao encontrado" << endl;
        return;
    }

    Cell *aux = t.head[position].next;

    /* Se o primeiro elemento for o elemento a ser removido */
    if(aux->key == key) {
        t.head[position].next = aux->next;
        delete aux;
        return;
    }

    /* Se o elemento a ser removido nao for o primeiro */
    while(aux->next != NULL) {
        if(aux->next->key == key) {
            /* cria um aux para apontar para o elemento a ser deletado */
            Cell *aux2 = aux->next;

            /* faz o ponteiro anterior apontar para o prox depois do excluido */
            aux->next = aux2->next;

            /* desaloca o vetor */
            delete aux2;

            return;
        }
    }
}

void search(int key) {
    int position = hashKey(key);

    if(t.head[position].next == NULL) {
        cout << "Elemento nao encontrado" << endl;
        return;
    }

    Cell *aux = t.head[position].next;

    while(aux != NULL) {
        /* Verifica se o elemento atual tem a chave igual a chave buscada */
        if(aux->key == key) {
            cout << "Elemento encontrado! " << aux->key << endl;
            return;
        }

        /* caso nao seja, passa para o proximo elemento */
        aux = aux->next;
    }
}

void getCollisions(int position) {
    int counter = 0;

    Cell *aux = t.head[position].next;

    while(aux != NULL) {
        cout << "elemento da colisão: " << aux->key << endl;
        counter++;
        aux = aux->next;
    }

    cout << "Colisoes: " << counter << endl;
}


int main() {

    createTable(10);

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    insert(11);
    insert(21);
    insert(31);
    insert(41);

    getCollisions(0);

    search(43);


    return 0;
}