#pragma once
#include <array>

#ifndef FILA_H
#define FILA_H

using namespace std;

using TipoDado = int;
constexpr int MAXPILHA = 15;

class Pilha {
private:
    array<TipoDado, MAXPILHA> dados;
    int topo_;

public:
    Pilha();
    void push(TipoDado elem);
    void pop();
    TipoDado topo();
    bool vazia();
    bool cheia();
};

#endif
#pragma once