#include <iostream>
#include <vector>
#include <string>
#include "Pilha.h"

using namespace std;

int main() {

	vector<string> labirinto = {
	"XXXXXXXXXXXXXXXXXXXXX",
	"X     X     X     X X",
	"XX XX XXXXX X X X   X",
	"X   X       XXX XXX X",
	"X X X XXXXXXX   X   X",
	"X X   X   X X X   X X",
	"X XXXXX X X   XXXXX X",
	"X X     X XXX  X    X",
	"X X X X X   XX XX XXX",
	"X X XXX X X     X   X",
	"E X X X X XXXXX XXX X",
	"X     X X   X X X   X",
	"X XXXXX XXX X XXX X X",
	"X X       X X   X X X",
	"X   XXX X X XXX X X X",
	"XXX X X X X X X X XXX",
	"X X   X X   X   X   X",
	"X XXX XXXXXXXXX XXX X",
	"X                 X X",
	"XXXXXXXXXXXXXXXXXXXSX"
	};

    Pilha p;

    p.push(5);
    p.push(7);
    p.push(9);
    p.push(1);
    p.push(2);

	cout << "\n* * * MAZE * * *";
	cout << "\n- Mateus Ferro -\n" << endl;

	for (int i = 0; i < labirinto.size(); i++) {
		cout << labirinto[i] << endl;
	}
    cout << "\nTamanho atual da pilha: " << p.tamanho_pilha() << "\n" << endl;
    while (!p.vazia()) {
        cout << "Desempilhando o valor " << p.topo() << endl;
        p.pop();
    }
    cout << "\nTamanho atual da pilha: " << p.tamanho_pilha() << "\n" << endl;
}
