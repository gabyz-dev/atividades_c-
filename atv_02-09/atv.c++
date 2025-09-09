#include <iostream>   
#include <clocale>     
#include <string>     

using namespace std;  

int i = 0;            
int cont = 0;          

struct cliente {
    char nome[30];
};

cliente cadastrarcliente() {
    cliente c;
    cout << "\nSistema Cadastrar Clientes ";
    cout << "\nInforme o nome: ";
    
    cin.ignore(); 
    cin.getline(c.nome, 30);
    
    cont++;
    return c;
}

void exibircliente(cliente cad[]) {
    cout << "\nExibição de Cadastro Cliente\n";
    for (int j = 0; j < cont; j++) {
        cout << "\n     CODIGO:   " << j + 1;
        cout << "\nNome ...........: " << cad[j].nome << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "portuguese"); 
    int opc;
    cliente cad[50];  

    do {
        cout << "\nSISTEMA CADASTRO \n\n1 - CADASTRAR CLIENTE\n2 - EXIBIR CLIENTE\n3 - SAIR";
        cout << "\n\nDigite a opção: ";
        cin >> opc;

        switch (opc) {
            case 1:
                if (i < 50) { 
                    cad[i] = cadastrarcliente();
                    i++;
                } else {
                    cout << "Limite de clientes atingido!\n";
                }
                break;
            case 2:
                exibircliente(cad);
                break;
            case 3:
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opc != 3);

    return 0; 
}