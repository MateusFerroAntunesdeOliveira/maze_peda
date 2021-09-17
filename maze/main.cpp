#include <iostream>
#include <vector>
#include <string>
#include "Pilha.h"

using namespace std;

bool check_next(char node) {
	return node == 'S' || node == ' ';
}

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

	vector<string> labirinto_show = {
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

	//-> Entrada
	int x = 10;
	int y = 0;

	Pilha px, py;
	int cont = 0, cont_show = 0;

	// x + 1 = desce 1 casa
	// x - 1 = sobe 1 casa
	// y + 1 = direita 1 casa
	// y - 1 = esquerda 1 casa
	//   *   = caminho percorrido

	cout << "\n* * * MAZE * * *";
	cout << "\n- Mateus Ferro -\n" << endl;

	cout << "Entrada: " << "(" << x << "," << y << ")" << endl << endl;

	while (labirinto[x][y] != 'S') {
		
		if (check_next(labirinto[x - 1][y])) {
			--x;
			px.push(x);
			py.push(y);
			if (labirinto[x][y] != 'S') {
				labirinto[x][y] = '*';
				labirinto_show[x][y] = '*';
			}
			++cont_show;
			++cont;
		}
		else if (check_next(labirinto[x][y + 1])) {
			++y;
			px.push(x);
			py.push(y);
			if (labirinto[x][y] != 'S') {
				labirinto[x][y] = '*';
				labirinto_show[x][y] = '*';
			}
			++cont_show;
			++cont;
		}
		else if (check_next(labirinto[x + 1][y])) {
			++x;
			px.push(x);
			py.push(y);
			if (labirinto[x][y] != 'S') {
				labirinto[x][y] = '*';
				labirinto_show[x][y] = '*';
			}
			++cont_show;
			++cont;
		}
		else if (check_next(labirinto[x][y - 1])) {
			--y;
			px.push(x);
			py.push(y);
			if (labirinto[x][y] != 'S') {
				labirinto[x][y] = '*';
				labirinto_show[x][y] = '*';
			}
			++cont_show;
			++cont;
		}
		else {
			x = px.topo();
			px.pop();
			y = py.topo();
			py.pop();
			--cont_show;
			labirinto_show[x][y] = ' ';
		}
	}

	for (int i = 0; i < labirinto_show.size(); i++) {
		cout << labirinto_show[i] << endl;
	}

	cout << "\nSaida: " << "(" << px.topo() << "," << py.topo() << ")" << endl;

	cout << "\nMovimentos usados no caminho certo: " << cont_show << endl;
	cout << "Movimentos usados no total para encontrar o caminho certo: " << cont << endl << endl;

	Pilha px2, py2;
	int a = 0;

	cout << "Combinacao dos movimentos para resolucao do labirinto: " << endl << endl;
	while (!px.vazia() && !py.vazia()) {
		px2.push(px.topo());
		px.pop();
		py2.push(py.topo());
		py.pop();
	}
	while (!px2.vazia() && !py2.vazia()) {
		cout << "Jogada: " << a+1 << " -> " << "Posicao X: " << px2.topo() << " - ";
		px2.pop();
		cout << "Posicao Y: " << py2.topo() << endl;
		py2.pop();
		++a;
	}
}
