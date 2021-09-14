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

	Pilha px;
	Pilha py;

	//-> Entrada
	int x = 10;
	int y = 0;
	labirinto[x][y];

	// x + 1 = desce 1 casa
	// x - 1 = sobe 1 casa
	// y + 1 = direita 1 casa
	// y - 1 = esquerda 1 casa
	//   *   = caminho percorrido

	//-> Condicao de chegada
	//while (labirinto[x][y] != 'S')

	if (labirinto[x][0]) {
		if (labirinto[x - 1][y] != 'X') {
			--x;
			px.push(x);
			py.push(y);
			labirinto[x][y] = '*';
		}
		if (labirinto[x][y + 1] != 'X') {
			++y;
			px.push(x);
			py.push(y);
			labirinto[x][y] = '*';
		}
		if (labirinto[x + 1][y] != 'X') {
			++x;
			px.push(x);
			py.push(y);
			labirinto[x][y] = '*';
		}
	}
	else {
		if (labirinto[x - 1][y] != 'X') {
			--x;
			px.push(x);
			py.push(y);
			labirinto[x][y] = '*';
		}
		if (labirinto[x][y + 1] != 'X') {
			++y;
			px.push(x);
			py.push(y);
			labirinto[x][y] = '*';
		}
		if (labirinto[x + 1][y] != 'X') {
			++x;
			px.push(x);
			py.push(y);
			labirinto[x][y] = '*';
		}
		if (labirinto[x][y - 1] != 'X') {
			--y;
			px.push(x);
			py.push(y);
			labirinto[x][y] = '*';
		}

		if (labirinto[x][y] == 'S') return -1;
	}
 
	cout << "\n* * * MAZE * * *";
	cout << "\n- Mateus Ferro -\n" << endl;
	for (int i = 0; i < labirinto.size(); i++) {
		cout << labirinto[i] << endl;
	}

	/*while (!p.vazia()) {
	    cout << "Desempilhando o valor " << p.topo() << endl;
	    p.pop();
	}*/
}
