#include <iostream>
#include <iomanip>
using namespace std;

// Definição da struct para armazenar dados do funcionário
struct Funcionario {
    int codigo;
    double salario;
    double novoSalario;
};

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
        
        // Cálculo do novo salário
        switch(funcionarios[totalFuncionarios].codigo) {
            case 101:
                funcionarios[totalFuncionarios].novoSalario = funcionarios[totalFuncionarios].salario * 1.10;
                break;
            case 102:
                funcionarios[totalFuncionarios].novoSalario = funcionarios[totalFuncionarios].salario * 1.20;
                break;
            default:
                funcionarios[totalFuncionarios].novoSalario = funcionarios[totalFuncionarios].salario * 1.40;
        }
        
        totalFuncionarios++;
        
        if (totalFuncionarios < MAX_FUNCIONARIOS) {
            cout << "\nDeseja cadastrar outro funcionário? (s/n): ";
            cin >> continuar;
        }
        
    } while((continuar == 's' || continuar == 'S') && totalFuncionarios < MAX_FUNCIONARIOS);
    
    // Impressão dos dados armazenados
    cout << "\n\n--- RELATÓRIO DE FUNCIONÁRIOS ---" << endl;
    for (int i = 0; i < totalFuncionarios; i++) {
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
    
    // Cálculo de estatísticas
    int qtdGerentes = 0, qtdEngenheiros = 0, qtdOutros = 0;
    double custoAntes = 0, custoDepois = 0;
    
    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].codigo == 101) {
            qtdGerentes++;
        } else if (funcionarios[i].codigo == 102) {
            qtdEngenheiros++;
        } else {
            qtdOutros++;
        }
        
        custoAntes += funcionarios[i].salario;
        custoDepois += funcionarios[i].novoSalario;
    }
    
    // Exibição das estatísticas
    cout << "\n\n--- ESTATÍSTICAS DA EMPRESA ---" << endl;
    cout << "Quantidade de Gerentes: " << qtdGerentes << endl;
    cout << "Quantidade de Engenheiros: " << qtdEngenheiros << endl;
    cout << "Quantidade de Outros Cargos: " << qtdOutros << endl;
    cout << "Custo total antes do aumento: R$ " << fixed << setprecision(2) << custoAntes << endl;
    cout << "Custo total depois do aumento: R$ " << custoDepois << endl;
    cout << "Aumento total de custos: R$ " << custoDepois - custoAntes << endl;
    
    return 0;
}