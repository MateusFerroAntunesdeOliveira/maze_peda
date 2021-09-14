#include <iostream>
#include "Pilha.h"

using namespace std;

Pilha::Pilha() { topo_ = -1; }

void Pilha::push(TipoDado elem) {
    if (!cheia()) {
        ++topo_;
        pilha[topo_] = elem;
    }
    else cerr << "Pilha cheia!" << endl;
}

void Pilha::pop() {
    if (!vazia()) --topo_;
    else cerr << "Pilha vazia!" << endl;
}

TipoDado Pilha::topo() {
    if (!vazia()) return pilha[topo_];
    else {
        cerr << "Pilha vazia!" << endl;
        return -1;
    }
}

bool Pilha::vazia() { return (topo_ == -1); }

bool Pilha::cheia() { return (topo_ == MAXPILHA - 1); }

int Pilha::tamanho_pilha() { return topo_ + 1; }
