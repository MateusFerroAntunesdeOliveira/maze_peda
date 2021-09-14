#include <iostream>
#include "Pilha.h"

using namespace std;

int main() {

    Pilha p;

    p.push(5);
    p.push(7);
    p.push(9);
    p.push(1);
    p.push(2);

    cout << "\nTamanho atual da pilha: " << p.tamanho_pilha() << "\n" << endl;
    while (!p.vazia()) {
        cout << "Desempilhando o valor " << p.topo() << endl;
        p.pop();
    }
    cout << "\nTamanho atual da pilha: " << p.tamanho_pilha() << "\n" << endl;
}
