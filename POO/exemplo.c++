#include <iostream>
#include <string>
using namespace std;

class Aluno
  {
  private:
      string nome;
      int idade;
  public:
      void set_idade(int i) {idade = i; };
      void set_name(string s) {nome = s; };
      int get_idade() { return idade; };
      void print() ;
  } ;
 
void Aluno::print()
  {
  cout << "Nome: " << nome << endl;
  cout << "Idade: " << idade << " anos\n";
  };

int main()
  {
  Aluno bruna;                                                                                              
  bruna.set_name("Bruna Gabrielly");
  bruna.set_idade(19);
  bruna.print();
  }