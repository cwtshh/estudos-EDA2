#include <iostream>


using namespace std;

void troca(int *vet, int j, int k){
    int aux = vet[j];
    vet[j] = vet[k];
    vet[k] = aux;
}

int separa(int *vet, int l, int r){
    int pivo = vet[r];
    int j = 0, k = 0;

    while(k < r){
        if(vet[k] <= pivo) {
           troca(vet, j, k); 
           j++;
        }
        k++;
    }

}
