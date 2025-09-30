#include <iostream>
#include <string>
using namespace std;

class Funcionario
  {
  private:
      string nome;
      string cargo;
      int idade;
      float salario;
  public:
      void set_nome(string n) { nome = n; };
      void set_idade(int i) { idade = i; };
      void set_cargo(string c) { cargo = c; };
      void set_salario(float s) { salario = s; };
      string get_nome() { return nome; };
      int get_idade() { return idade; };
      string get_cargo() { return cargo; };
      float get_salario() { return salario; };

      void print(int indice);
  } ;
 
void Funcionario::print(int indice)
  {
    cout << "Nome do funcionário " << indice << ": " << nome << endl;
    cout << "Idade do funcionário " << indice << ": " << idade << endl;
    cout << "Cargo do funcionario " << indice << ": " << cargo << endl;
    cout << "Salario do funcionario " << indice << ": " << salario << endl;
  };

int main()
  {
    string nome, cargo;
    int idade, numFunc;
    float salario;

    Funcionario funcionarios[10];
    
    for (int i = 0; i < 10; i++) {
        numFunc = i + 1;

        cout << "- - - - - - - - - - - - -" << endl;
        cout << "Digite o nome do funcionario " << numFunc << ": ";
        cin >> nome;
        funcionarios[i].set_nome(nome);
        
        cout << "Digite a idade do funcionário " << numFunc << ": ";
        cin >> idade;
        funcionarios[i].set_idade(idade);

        cout << "Digite o cargo do funcionário " << numFunc << ": ";
        cin >> cargo;
        funcionarios[i].set_cargo(cargo);

        cout << "Digite o salario do funcionario " << numFunc << ": ";
        cin >> salario;
        funcionarios[i].set_salario(salario);
    }

    for(int i = 0; i < 10; i++) {
      numFunc = i + 1;
      cout << "- - - - - - - - - - - - -" << endl;
      cout << "O nome do funcionário " << numFunc << " informado foi: " << funcionarios[i].get_nome() << endl;
      cout << "A idade do funcionário " << numFunc << " informado foi: " << funcionarios[i].get_idade() << endl;
      cout << "O cargo do funcionário " << numFunc << " informado foi: " << funcionarios[i].get_cargo() << endl;
      cout << "O salario do funcionário " << numFunc << " informado foi: " << funcionarios[i].get_salario() << endl;
      
    
    }

  }