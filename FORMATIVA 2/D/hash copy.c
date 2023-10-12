#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Pessoa {
    int id;
    char *fisrtName;
    char *lastName;
    char *birthDate;
    char *phoneNumber;
    struct Pessoa *next;
} Pessoa;

typedef struct {
    int M;
    int N;
    Pessoa *tb;
} TH;

int hashPosition(int id, int M) {
    return id % M;
}

void inicializarLista(TH *h) {
    for(int i = 0; i <= h->M - 1; i++) {
        h->tb[i].next = NULL;
    }
}

void add(int id, char *firstName, char *lastName, char *birthDate, char *phoneNumber, TH *h) {
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
    p->id = id;
    p->fisrtName = firstName;
    p->lastName = lastName;
    p->birthDate = birthDate;
    p->phoneNumber = phoneNumber;

    if(!p) {
        printf("Erro ao alocar memoria\n");
        return;
    }

    int position = hashPosition(id, h->M);

    p->next = h->tb[position].next;
    h->tb[position].next = p;

    h->N++;
}

int del(int id, TH *h) {
    int position = hashPosition(id, h->M);

    Pessoa *pAnt, *pPost;
    pAnt = &h->tb[position];

    while(pAnt->next != NULL) {
        if(pAnt->next->id == id) {
            pPost = pAnt->next->next;
            free(pAnt->next);
            pAnt->next = pPost;
            h->N--;
            printf("Pessoa removida\n");
            return 1;
        }
        pAnt = pAnt->next;
    }

    printf("ERRO NA REMOCAO");
    return 0;
}

void query(char *comando, char *value,TH *h) {
    /* Pessoa *aux = &h->tb;
    if(strcmp(comando, "fn") == 1) {
        for(int i = 0; i <= h->M - 1; i++) {
            while(aux[i].next != NULL) {
                if(strcmp(aux->next->fisrtName, value)) {
                }
            }
        }
        printf("\n");
    } */
}



void info(int id, TH *h) {
    int positiion = hashPosition(id, h->M);

    Pessoa *aux = &h->tb[positiion];

    while(aux->next != NULL) {
        if(aux->next->id == id) {
            printf("%s %s ", aux->next->fisrtName, aux->next->lastName);
            printf("%s %s ", aux->next->birthDate, aux->next->phoneNumber);
        }
        aux = aux->next;
    }   

}


int main() {

    int exit = 0;
    TH *h = (TH *) malloc(sizeof(TH));
    h->M = 10;
    h->N = 0;
    h->tb = (Pessoa *) malloc(h->M * sizeof(Pessoa));

    inicializarLista(h);


    while(exit != 1) {
        char command[100];
        int id;
        char firstName[100];
        char lastName[100];
        char birthDate[100];
        char phoneNumber[100];

        fgets(command, sizeof(command), stdin);

        if(strncmp(command, "add", 3) == 0) {
            if(sscanf(command, "add %d %s %s %s %s", &id, firstName, lastName, birthDate, phoneNumber) == 5) {
                add(id, firstName, lastName, birthDate, phoneNumber, h);
            } else {
                printf("Erro ao ler comando\n");
            }
            
        }

        else if(strncmp(command, "del", 3) == 0) {
            if(sscanf(command, "del %d", &id) == 1) {
                del(id, h);
            } else {
                printf("Erro ao ler comando\n");
            }
        }

        else if(strncmp(command, "info", 4) == 0) {
            int searchId;
            if(sscanf(command, "info %d", &searchId) == 1) {
                info(searchId, h);
            } else {
                printf("Erro ao ler comando\n");
            }
        }

        else if(strncmp(command, "query", 4) == 0) {
            char queryValue[100];
            char queryCommand[100];

            printf("QUERY\n");

            if(sscanf(command, "query %s:%s", queryCommand, queryValue) == 0) {
               /*  query(queryCommand, queryValue, h); */

               printf("%s %s", queryCommand, queryValue);
            }
        }

        if(strncmp(command, "exit", 4) == 0) {
            exit = 1;
        }

    }


    


    return 0;

}