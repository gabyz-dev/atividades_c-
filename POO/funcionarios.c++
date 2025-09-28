#include <iostream>
#include <string>
using namespace std;

class Funcionario
  {
  private:
      string nome;
      int idade;
  public:
      void set_nome(string n) { nome = n; };
      void set_idade(int i) { idade = i; };
      void print(int indice);
  } ;
 
void Funcionario::print(int indice)
  {
    cout << "Nome do funcionário " << indice << ": " << nome << endl;
    cout << "Idade do funcionário " << indice << ": " << idade << endl;
  };

int main()
  {
    string nome;
    int idade;
    Funcionario funcionarios[10];
    
    for (int i = 0; i < 10; i++) {
        cout << "Digite o nome do funcionario " << i + 1 << ": ";
        cin >> nome;
        
        cout << "Digite a idade do funcionário " << i + 1 << ": ";
        cin >> idade;
        
        funcionarios[i].set_nome(nome);
        funcionarios[i].set_idade(idade);
    }
    
    for (int i = 0; i < 10; i++) {
        funcionarios[i].print(i + 1);
    }
  }