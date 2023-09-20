typedef int Item;

typedef struct {
    Item dado;
    Celula *prox;
}Celula;

typedef struct {
    Celula *ht;
    int m;
}hash;

void insere(Item chave);

int remove(Item chave);

int busca(Item chave);

void criaTable(int M);

int hashKey(int chave);