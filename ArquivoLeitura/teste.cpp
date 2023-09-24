#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    string line;
    ifstream inFile ("textoDeLeitura.txt");

    if(!inFile) {
        cout << "Unable to open file";
        exit(1);
    }

    int i = 0;

    string word;

    while(getline(inFile, line)) {
        while(line[i] != ' ') {
            word[i] = line[i];
        }

        cout << word << endl;
    }


    return 0;
}