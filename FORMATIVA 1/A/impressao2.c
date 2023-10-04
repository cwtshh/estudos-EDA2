#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    while(le)
    {
        printf("%d -> ", le->dado);
        le = le->prox;
    }

    printf("NULL");
}


void imprime_rec(celula *le)
{
    if(le)
    {
        if(le->prox == NULL)
        {
            printf("%d -> NULL", le->dado);
            return;
        }

        printf("%d -> ", le->dado);
        imprime_rec(le->prox);    
    }
    
    else
    {
        printf("NULL");
        return;
    }
}
