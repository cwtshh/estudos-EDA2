typedef int Item;

typedef struct {
    Item data;
    Cell *next;
} Cell;

typedef struct {
    Cell *ht;
    int m;
} HashList;

int insertH(Item key);

int removeH(Item key);

int searchH(Item key);

void createTable(int M);

int hash(Item key);