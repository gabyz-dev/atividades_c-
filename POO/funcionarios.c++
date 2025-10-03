#include <iostream>
#include <string>
using namespace std;

class Funcionario {
private:
    string nome;
    string cargo;
    int idade;
    float salario, novosalario;
    int codigo;

public:
    void set_nome(string n) { nome = n; }
    void set_idade(int i) { idade = i; }
    void set_salario(float s) { salario = s; }
    void set_codigo(int f) { codigo = f; adicionar_cargo(); }
    void set_novosalario(float ns) { novosalario = ns; }

    string get_nome() { return nome; }
    int get_idade() { return idade; }
    string get_cargo() { return cargo; }
    float get_salario() { return salario; }
    int get_codigo() { return codigo; }
    float get_novosalario() { return novosalario; }

    void print(int indice);
    float calcular_salarionovo();
    void adicionar_cargo();
};

void Funcionario::print(int indice) {
    cout << "- - - - - - - - -" << endl;
    cout << "Nome do funcionário " << indice << ": " << nome << endl;
    cout << "Idade do funcionário " << indice << ": " << idade << endl;
    cout << "Cargo do funcionário " << indice << ": " << cargo << endl;
    cout << "Salário antigo do funcionário " << indice << ": " << salario << endl;
    cout << "Salário reajustado do funcionário " << indice << ": " << novosalario << endl;
}

void Funcionario::adicionar_cargo() {
    switch (codigo) {
        case 101:
            cargo = "Gerente";
            break;
        case 102:
            cargo = "Engenheiro";
            break;
        default:
            cargo = "Outro";
            break;
    }
}

float Funcionario::calcular_salarionovo() {
    float novo = 0.0;
    switch (codigo) {
        case 101:
            novo = salario * 1.10;
            break;
        case 102:
            novo = salario * 1.20;
            break;
        default:
            novo = salario * 1.40;
            break;
    }
    set_novosalario(novo);
    return novo;
}

void contar_funcionarios(Funcionario funcionarios[], int tamanho, int &gerentes, int &engenheiros, int &outros) {
    gerentes = 0;
    engenheiros = 0;
    outros = 0;
    for (int i = 0; i < tamanho; i++) {
        int codigo = funcionarios[i].get_codigo();
        if (codigo == 101) gerentes++;
        else if (codigo == 102) engenheiros++;
        else outros++;
    }
}

void exibir_dados(Funcionario funcionarios[], int tamanho) {
    int gerentes, engenheiros, outros;
    contar_funcionarios(funcionarios, tamanho, gerentes, engenheiros, outros);
    cout << "\nDADOS DOS FUNCIONÁRIOS" << endl;
    cout << "Total de gerentes: " << gerentes << endl;
    cout << "Total de engenheiros: " << engenheiros << endl;
    cout << "Total de outros: " << outros << endl;
    cout << "Total geral de funcionários: " << gerentes + engenheiros + outros << endl;
}

int main() {
    const int tamanho = 10;
    Funcionario funcionarios[tamanho];
    string nome;
    int idade, codigo;
    float salario;
    float custototal = 0.0;

    for (int i = 0; i < tamanho; i++) {
        int numFunc = i + 1;
        cout << "- - - - - - - - - - - - -" << endl;
        cout << "Digite o nome do funcionário " << numFunc << ": ";
        cin >> nome;
        funcionarios[i].set_nome(nome);

        cout << "Digite a idade do funcionário " << numFunc << ": ";
        cin >> idade;
        funcionarios[i].set_idade(idade);

        cout << "Digite o salário do funcionário " << numFunc << ": ";
        cin >> salario;
        funcionarios[i].set_salario(salario);

        cout << "Digite o código do funcionário " << numFunc << " (101=Gerente, 102=Engenheiro, outro=Outro): ";
        cin >> codigo;
        funcionarios[i].set_codigo(codigo);

    }

    for (int i = 0; i < tamanho; i++) {
        funcionarios[i].calcular_salarionovo();
        funcionarios[i].print(i + 1);
        custototal += funcionarios[i].get_novosalario();
        cout << "- - - - - - - -" << endl;
    }

    cout << "O custo total com os salários reajustados é: " << custototal << endl;

    exibir_dados(funcionarios, tamanho);

    return 0;
}