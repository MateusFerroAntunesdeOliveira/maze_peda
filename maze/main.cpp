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

	Pilha px;
	Pilha py;

	//-> Entrada
	int x = 10;
	int y = 0;
	int cont = 0;
	int cont_show = 0;
	labirinto[x][y];
	labirinto_show[x][y];

	// x + 1 = desce 1 casa
	// x - 1 = sobe 1 casa
	// y + 1 = direita 1 casa
	// y - 1 = esquerda 1 casa
	//   *   = caminho percorrido

	cout << "\n* * * MAZE * * *";
	cout << "\n- Mateus Ferro -\n" << endl;

	cout << "Entrada: " << "(" << x << "," << y << ")" << endl << endl;

	while (labirinto[x][y] != 'S') {

		if (check_next(labirinto[x + 1][y])) {
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
		else if (check_next(labirinto[x - 1][y])) {
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

	cout << "\nMovimentos usados no total para encontrar o caminho: " << cont << endl;
	cout << "Movimentos usados no caminho certo: " << cont_show << endl;

	//TODO printar a pilha com a combinacao dos movimentos

	for (int a = 0; a < px.tamanho_pilha() && a < py.tamanho_pilha(); ++a) {
		cout << "Posicao X: " << px.topo() << " - ";
		px.pop();
		cout << "Posicao Y: " << py.topo() << endl;
		py.pop();
	}
}

