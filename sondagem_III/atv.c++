#include <iostream>
#include <iomanip>
using namespace std;

// Definição da struct para armazenar dados do funcionário
struct Funcionario {
    int codigo;
    double salario;
    double novoSalario;
};

// Protótipos das funções
double calcularNovoSalario(int codigo, double salario);
void contarCargos(Funcionario funcionarios[], int total, int &qtdGerentes, int &qtdEngenheiros, int &qtdOutros);
double calcularCustoTotal(Funcionario funcionarios[], int total);
void exibirDados(Funcionario funcionarios[], int total);

int main() {
    const int MAX_FUNCIONARIOS = 10;
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int totalFuncionarios = 0;
    char continuar;
    
    // Leitura dos dados dos funcionários
    do {
        if (totalFuncionarios >= MAX_FUNCIONARIOS) {
            cout << "Limite máximo de funcionários atingido!" << endl;
            break;
        }
        
        cout << "\n--- Dados do Funcionário " << totalFuncionarios + 1 << " ---" << endl;
        
        cout << "Digite o código do cargo (101 para Gerente, 102 para Engenheiro): ";
        cin >> funcionarios[totalFuncionarios].codigo;
        
        cout << "Digite o salário atual: ";
        cin >> funcionarios[totalFuncionarios].salario;
        
        // Cálculo do novo salário usando a função
        funcionarios[totalFuncionarios].novoSalario = 
            calcularNovoSalario(funcionarios[totalFuncionarios].codigo, 
                               funcionarios[totalFuncionarios].salario);
        
        totalFuncionarios++;
        
        if (totalFuncionarios < MAX_FUNCIONARIOS) {
            cout << "\nDeseja cadastrar outro funcionário? (s/n): ";
            cin >> continuar;
        }
        
    } while((continuar == 's' || continuar == 'S') && totalFuncionarios < MAX_FUNCIONARIOS);
    
    // Exibir dados armazenados
    exibirDados(funcionarios, totalFuncionarios);
    
    // Calcular e mostrar quantidades de cargos
    int qtdGerentes, qtdEngenheiros, qtdOutros;
    contarCargos(funcionarios, totalFuncionarios, qtdGerentes, qtdEngenheiros, qtdOutros);
    
    cout << "\n\n--- ESTATÍSTICAS DA EMPRESA ---" << endl;
    cout << "Quantidade de Gerentes: " << qtdGerentes << endl;
    cout << "Quantidade de Engenheiros: " << qtdEngenheiros << endl;
    cout << "Quantidade de Outros Cargos: " << qtdOutros << endl;
    
    // Calcular e mostrar custo total após aumento
    double custoDepois = calcularCustoTotal(funcionarios, totalFuncionarios);
    cout << "Custo total depois do aumento: R$ " << fixed << setprecision(2) << custoDepois << endl;
    
    return 0;
}

// Função para calcular o novo salário
double calcularNovoSalario(int codigo, double salario) {
    switch(codigo) {
        case 101: // Gerente - 10%
            return salario * 1.10;
        case 102: // Engenheiro - 20%
            return salario * 1.20;
        default: // Outros cargos - 40%
            return salario * 1.40;
    }
}

// Função para contar quantos gerentes e engenheiros existem
void contarCargos(Funcionario funcionarios[], int total, int &qtdGerentes, int &qtdEngenheiros, int &qtdOutros) {
    qtdGerentes = 0;
    qtdEngenheiros = 0;
    qtdOutros = 0;
    
    for (int i = 0; i < total; i++) {
        if (funcionarios[i].codigo == 101) {
            qtdGerentes++;
        } else if (funcionarios[i].codigo == 102) {
            qtdEngenheiros++;
        } else {
            qtdOutros++;
        }
    }
}

// Função para calcular o custo total após o aumento
double calcularCustoTotal(Funcionario funcionarios[], int total) {
    double custoTotal = 0;
    for (int i = 0; i < total; i++) {
        custoTotal += funcionarios[i].novoSalario;
    }
    return custoTotal;
}

// Função para exibir os dados armazenados
void exibirDados(Funcionario funcionarios[], int total) {
    cout << "\n\n--- RELATÓRIO DE FUNCIONÁRIOS ---" << endl;
    for (int i = 0; i < total; i++) {
        string cargo;
        switch(funcionarios[i].codigo) {
            case 101: cargo = "Gerente"; break;
            case 102: cargo = "Engenheiro"; break;
            default: cargo = "Outro Cargo";
        }
        
        cout << "\nFuncionário " << i+1 << ":" << endl;
        cout << "Código: " << funcionarios[i].codigo << " (" << cargo << ")" << endl;
        cout << fixed << setprecision(2);
        cout << "Salário antigo: R$ " << funcionarios[i].salario << endl;
        cout << "Novo salário: R$ " << funcionarios[i].novoSalario << endl;
    }
}