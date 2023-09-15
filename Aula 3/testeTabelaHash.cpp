#include <iostream>


using namespace std;

class Node{
    public:
        Node *ant;
        int position;
        Node *next;

        Node(){}

        Node(Node *ant, int position, Node *prox){
            this->ant = ant;
            this->position = position;
            this->next = next;
        }
};

class HashList{
    public:
        Node *first;
        int lap = 0;

        HashList(){}

        HashList(Node* first) {
            this->first = first;
        }

        void passPosition() {
            Node *aux;

            while (first->next->position != first->position) {
                aux = first->next;
            }

            if(aux->next->position == first->position) {
                this->lap += 1;
            }
            
        }
};

int main(){



    return 0;
}