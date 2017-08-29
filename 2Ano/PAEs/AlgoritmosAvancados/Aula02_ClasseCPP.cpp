#include <iostream>

using namespace std;

class Dados {
  // Elementos só conhecidos pela classe
  private:
    string nome;
    float valor;

  // Tudo que é publico da classe, todos tem acesso
  public:
    // Pegar os valores da classe
    string getNome() {
      return nome;
    }
    float getValor() {
      return valor;
    }

    // Colocar os valores nos atributos
    void setNome(string n) {
      nome = n;
    }
    void setValor(float v) {
      valor = v;
    }
};

int main() {
  // Declara um objeto da classe Dados
  Dados dados;

  // Pede para o usuário falar um nome
  cout << "Informar um nome: ";
  string str;
  cin >> str;

  // Colocar o valor informado dentro do objeto
  dados.setNome(str);

  // Pede para o usuário falar um valor
  cout << "Informar um valor: ";
  float x;
  cin >> x;

  // Colocar o valor informado dentro do objeto
  dados.setValor(x);

  // Exibir o valor informado pelo usuário
  cout << "Nome no objeto: " << dados.getNome() << endl;
  cout << "Valor no objeto: " << dados.getValor();

  return 0; 
}
