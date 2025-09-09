#include <iostream>
#include <string>   
#include <vector>  
#include <limits>  
#include <clocale> 

struct Cliente {
    std::string nome;
};

Cliente cadastrarCliente() {
    Cliente c;
    std::cout << "\n--- Sistema Cadastrar Clientes ---" << std::endl;
    std::cout << "Informe o nome: ";
    
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    std::getline(std::cin, c.nome); 
    
    return c;
}

void exibirClientes(const std::vector<Cliente>& cad) {
    std::cout << "\n--- Exibição de Clientes Cadastrados ---" << std::endl;
    if (cad.empty()) {
        std::cout << "Nenhum cliente cadastrado." << std::endl;
        return;
    }

    for (size_t i = 0; i < cad.size(); ++i) {
        std::cout << "\n    CÓDIGO: " << i + 1;
        std::cout << "\n    Nome ...: " << cad[i].nome << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int opc;
    std::vector<Cliente> clientes; 

    do {
        std::cout << "\n===== SISTEMA DE CADASTRO =====\n" << std::endl;
        std::cout << "1 - CADASTRAR CLIENTE" << std::endl;
        std::cout << "2 - EXIBIR CLIENTES" << std::endl;
        std::cout << "3 - SAIR" << std::endl;
        std::cout << "\nDigite a opção: ";
        std::cin >> opc;

        switch (opc) {
            case 1:
                clientes.push_back(cadastrarCliente());
                std::cout << "\nCliente cadastrado com sucesso!" << std::endl;
                break;
            case 2:
                exibirClientes(clientes);
                break;
            case 3:
                std::cout << "Saindo do sistema..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida! Tente novamente." << std::endl;
                break;
        }
    } while (opc != 3);

    return 0;
}