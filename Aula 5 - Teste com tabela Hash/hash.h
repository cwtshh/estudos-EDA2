typedef int Item;


typedef struct Cell{
    Item dado;
    Cell *next;
}Cell;

typedef struct {
    Cell *ht;
    int size;
} HashNode;

/* void insert(Item key);

void remove(Item key);

int search(Item key);

void createTable(int m);

int hash(Item key); */