#pragma once
#include <array>

#ifndef FILA_H
#define FILA_H

using namespace std;

using TipoDado = int;
constexpr int MAXPILHA = 15;

class Pilha {
private:
    array<TipoDado, MAXPILHA> pilha;
    int topo_;

public:
    Pilha();
    void push(TipoDado elem);
    void pop();
    TipoDado topo();
    bool vazia();
    bool cheia();
    int tamanho_pilha();
};

#endif
#pragma once