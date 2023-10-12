#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
    struct No *pai;
} No;

/* Criacao */

No * cria_arvore(int dado, No *esq, No *dir) {
    No *raiz = (No *) malloc(sizeof(No));
    raiz->esq = esq;
    raiz->dir = dir;
    raiz->dado = dado;

    return raiz; 
}

No * busca(No *raiz, int x) {
    No *esq;
    if(raiz == NULL || raiz->dado == x) return raiz;

    esq = busca(raiz->esq, x);

    if(esq != NULL) return esq;

    return busca(raiz->dir, x);
}


int main() {

    /* Usando a funcao cria_arvore() para criar uma arvore */

    /* Segundo a arovre

                    3
                /       \
                4       7
            /   \      /    \
            6    8    2      1
                /
              10       
    
    */

   No *p1 = cria_arvore(10, NULL, NULL);

   p1 = cria_arvore(8, p1, NULL);
   /*   Ponteiros apontam para enderecos de memoria
        Portanto, podemos redirecionar, pois o endereco nao será perdido
        porque nao demos free(); nele,,
        entao, apos o retorno da funcao, p1 agora aponta, na esquerda, para
        o endereco anterior de p1.
    */
   No *p2 = cria_arvore(6, NULL, NULL);

   p1 = cria_arvore(4, p2, p1);

   /* Agora terminamos a subarvore esquerda */

   p2 = cria_arvore(2, NULL, NULL);

   No *p3 = cria_arvore(1, NULL, NULL);

   p2 = cria_arvore(7, p2, p3);

   /* Agora terminamos a arvore da direita */

   p1 = cria_arvore(3, p1, p2);
   /* Agora criamos a raiz */


   /* Busca */




    


    return 0;
}