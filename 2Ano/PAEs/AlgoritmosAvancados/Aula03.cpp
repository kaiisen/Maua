#include <iostream>
#include <list>

using namespace std;

class Dado {
	public:
		int valor;
		string nome;
};

// Estrutura para ordenacao
struct OrdenaDado {
	bool operator() (Dado *d1, Dado *d2) {
		return d1->valor > d2->valor;
	}
	bool operator() (Dado d1, Dado d2) {
		return d1.valor < d2.valor;
	}
};


struct OrdenaDado2 {
	bool operator() (Dado *d1, Dado *d2) {
		return d1->valor > d2->valor;
	}
	bool operator() (Dado d1, Dado d2) {
		if (d1.nome == d2.nome)
			return (d1.valor < d2.valor);
		return (d1.nome < d2.nome);
	}
};


int main() {
	// Criar uma lista de Dado
	list<Dado> lista;
	// Criar um objeto Dado
	Dado dado;
	// Colocar os valores dentro do objeto
	dado.nome = "Goku";
	dado. valor = 8000;
	// Coloca dado na lista
	lista.push_back(dado);

	// Colocar os valores dentro do objeto
	dado.nome = "Vegeta";
	dado. valor =7999;
	// Coloca dado na lista
	lista.push_back(dado);
	
	// Colocar os valores dentro do objeto
	dado.nome = "Gohan";
	dado. valor =7000;
	// Coloca dado na lista
	lista.push_back(dado);
	
	cout << "Lista nao ordenada:" << endl;
	// Criar um iterador para a lista
	list<Dado>::iterator it;
	for (it = lista.begin(); it != lista.end(); ++it)
		cout << "Nome: " << it->nome << "\tValor: " << it->valor << endl;
	
	// Ordernar a lista
	lista.sort(OrdenaDado2());
	
	cout << "Lista ordenada:" << endl;
	for (it = lista.begin(); it != lista.end(); ++it)
		cout << "Nome: " << it->nome << "\tValor: " << it->valor << endl;
	

	return 0; 
}
