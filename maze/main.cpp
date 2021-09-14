#include <iostream>
#include "Pilha.h"

using namespace std;

int main() {

    Pilha p;

    p.push(5);
    p.push(10);
    p.push(15);

    while (!p.vazia()) {
        cout << p.topo() << endl;
        p.pop();
    }
}
