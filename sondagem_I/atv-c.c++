#include <iostream>
using namespace std;

int main() {
    char continuar;
    do {
        int codigo;
        double salario, novoSalario;
        
        cout << "Digite o código do cargo (101 para Gerente, 102 para Engenheiro): ";
        cin >> codigo;
        cout << "Digite o salário atual: ";
        cin >> salario;
        
        switch(codigo) {
            case 101:
                novoSalario = salario * 1.10;
                break;
            case 102:
                novoSalario = salario * 1.20;
                break;
            default:
                novoSalario = salario * 1.40;
        }
        
        cout << "\nSalário antigo: R$ " << salario << endl;
        cout << "Novo salário: R$ " << novoSalario << endl;
        
        cout << "\nDeseja continuar calculando para outro funcionário? (s/n): ";
        cin >> continuar;
        cout << endl;
        
    } while(continuar == 's' || continuar == 'S');
    
    return 0;
}