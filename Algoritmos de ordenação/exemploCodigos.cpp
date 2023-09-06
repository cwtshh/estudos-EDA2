#include <iostream>
#include <string>

using namespace std;

void insertion(int vet[], int tam) {
    int i, j, x;

    for(i = 2; i <= tam; i++) {
        x = vet[i];
        j = i - 1;
        vet[0] = x;

        while(x < vet[j]) {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = x;
    }
}

void selection(int vet[], int tam) {
    int i, j, min, x;

    for(i = 1; i <= tam - 1; i++) {
        min = i;
    }

    for(j = i + 1; j <= tam - 1; j++) {
        if(vet[j] < vet[min]) {
            min = j;
        }
    }
    x = vet[min];
    vet[i] = x;
}

int main() {

}