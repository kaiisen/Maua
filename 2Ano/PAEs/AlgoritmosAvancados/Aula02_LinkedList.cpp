#include <iostream>
#include <list>

using namespace std;

int main() {
  // Criar lista
  list<int> lista;
  cout << "Tamanho da lista: " << lista.size() << endl;
  
  // Colocar alguns valores na lista
  for (int i = 0; i < 10; i++)
    lista.push_back(i);

  // Cpçpcar elemento na lista
  lista.push_back(23);

  cout << "Tamanho da lista: " << lista.size() << endl;
  
  // Navegar na lista
  list<int>::iterator it;

  // Exibir toda a lista
  for (it = lista.begin(); it != lista.end(); it++)
    cout << *it << endl;

  cout << "Tamanho da lista: " << lista.size() << endl;

  // Inserir elemento na posição 3
  it = lista.begin();
  for (int i = 0; i < 3; i++)
    ++it;

  lista.insert(it, 135);
  cout << "Tamanho da lista: " << lista.size() << endl << endl;
  
  for (it = lista.begin(); it != lista.end(); it++)
    cout << *it << endl;

  // Ordenar a lista
  lista.sort();

  // Exibir a lista ordenada
  for (it = lista.begin(); it != lista.end(); it++)
    cout << *it << endl;
}
