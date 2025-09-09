#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <clocale>

struct Cliente {
    std::string nome;
    std::string email;
    std::string cpf;
    int perfil;
};

Cliente cadastrarCliente() {
    Cliente c;
    std::cout << "\n--- Sistema Cadastrar Clientes ---" << std::endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    std::cout << "Informe o nome: ";
    std::getline(std::cin, c.nome);

    do {
        std::cout << "Informe o CPF (11 dígitos, somente números): ";
        std::cin >> c.cpf;
        if (c.cpf.length() != 11) {
            std::cout << "Erro: O CPF deve conter exatamente 11 dígitos. Tente novamente.\n";
        }
    } while (c.cpf.length() != 11);

    std::cout << "Informe o e-mail: ";
    std::cin >> c.email;

    std::cout << "Informe o Perfil do Cliente (digite um número, ex: 1 para Comum): ";
    std::cin >> c.perfil;

    return c;
}

void exibirClientes(const std::vector<Cliente>& cad) {
    std::cout << "\n--- Exibição de Clientes Cadastrados ---" << std::endl;
    if (cad.empty()) {
        std::cout << "Nenhum cliente cadastrado." << std::endl;
        return;
    }

    for (size_t i = 0; i < cad.size(); ++i) {
        std::cout << "\n----------------------------------------";
        std::cout << "\n    CÓDIGO..: " << i + 1;
        std::cout << "\n    Nome....: " << cad[i].nome;
        std::cout << "\n    CPF.....: " << cad[i].cpf;
        std::cout << "\n    E-mail..: " << cad[i].email;
        std::cout << "\n    Perfil..: " << cad[i].perfil;
        std::cout << "\n----------------------------------------" << std::endl;
    }
}

void buscarPorCPF(const std::vector<Cliente>& clientes) {
    std::string cpfBusca;
    bool encontrado = false;

    std::cout << "\n--- Busca de Cliente por CPF ---" << std::endl;
    std::cout << "Digite o CPF que deseja buscar: ";
    std::cin >> cpfBusca;

    for (const auto& cliente : clientes) {
        if (cliente.cpf == cpfBusca) {
            std::cout << "\nCliente encontrado!" << std::endl;
            std::cout << "----------------------------------------";
            std::cout << "\n    Nome....: " << cliente.nome;
            std::cout << "\n    CPF.....: " << cliente.cpf;
            std::cout << "\n    E-mail..: " << cliente.email;
            std::cout << "\n    Perfil..: " << cliente.perfil;
            std::cout << "\n----------------------------------------" << std::endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "Cliente com o CPF " << cpfBusca << " não encontrado." << std::endl;
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
        std::cout << "3 - BUSCAR CLIENTE POR CPF" << std::endl;
        std::cout << "4 - SAIR" << std::endl;
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
                buscarPorCPF(clientes);
                break;
            case 4:
                std::cout << "Saindo do sistema..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida! Tente novamente." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    } while (opc != 4);

    return 0;
}