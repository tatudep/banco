#include "Cliente.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include <iostream>
#include <vector>
#include <memory> // Para std::unique_ptr e std::make_unique
#include <algorithm> // Para std::remove_if

// Funcao para exibir o menu
void exibirMenu() {
    std::cout << "\n=== Menu ===\n";
    std::cout << "1. Criar cliente\n";
    std::cout << "2. Criar conta\n";
    std::cout << "3. Depositar\n";
    std::cout << "4. Sacar\n";
    std::cout << "5. Transferir\n";
    std::cout << "6. Aplicar rendimento (poupanca)\n";
    std::cout << "7. Exibir extrato\n";
    std::cout << "8. Sair\n";
    std::cout << "Escolha uma opcao: ";
}

// Funcao para buscar uma conta pelo ID
Conta* buscarContaPorId(const std::vector<std::unique_ptr<Conta>>& contas, int id) {
    for (const auto& conta : contas) {
        if (conta->getId() == id) {
            return conta.get(); // Retorna o ponteiro para a conta
        }
    }
    return nullptr; // Retorna nullptr se a conta nao for encontrada
}

// Funcao para buscar um cliente pelo CPF
Cliente* buscarClientePorCpf(std::vector<Cliente>& clientes, const std::string& cpf) {
    for (auto& cliente : clientes) {
        if (cliente.getCpf() == cpf) {
            return &cliente; // Retorna o ponteiro para o cliente
        }
    }
    return nullptr; // Retorna nullptr se o cliente nao for encontrado
}

// Funcao para remover caracteres nao numericos do CPF
std::string limparCpf(const std::string& cpf) {
    std::string cpfLimpo = cpf;
    cpfLimpo.erase(std::remove_if(cpfLimpo.begin(), cpfLimpo.end(), [](char c) {
        return !isdigit(c);
    }), cpfLimpo.end());
    return cpfLimpo;
}

int main() {
    std::vector<Cliente> clientes;
    std::vector<std::unique_ptr<Conta>> contas;

    // Dados pre-carregados
    clientes.emplace_back("Joao Silva", "12345678900", "joao@email.com");
    clientes.emplace_back("Maria Souza", "98765432100", "maria@email.com");

    contas.push_back(std::make_unique<ContaCorrente>(101, 5.0)); // Conta corrente com tarifa de R$ 5,00
    contas.push_back(std::make_unique<ContaPoupanca>(201, 0.01)); // Conta poupanca com 1% de rendimento

    // Associar contas aos clientes
    Cliente* joao = buscarClientePorCpf(clientes, "12345678900");
    if (joao) {
        joao->adicionarConta(101); // Joao Silva tem a conta 101
    }

    Cliente* maria = buscarClientePorCpf(clientes, "98765432100");
    if (maria) {
        maria->adicionarConta(201); // Maria Souza tem a conta 201
    }

    // Realizar algumas transacoes pre-carregadas
    contas[0]->depositar(1000); // Deposito de R$ 1000 na conta 101
    contas[0]->sacar(200);      // Saque de R$ 200 na conta 101
    contas[0]->transferir(300, *contas[1]); // Transferencia de R$ 300 da conta 101 para a conta 201

    // Aplicar rendimento na conta 201 (Conta Poupanca)
    ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(contas[1].get());
    if (cp) {
        cp->aplicarRendimento();
    } else {
        std::cout << "A conta nao e uma conta poupanca!\n";
    }

    int opcao;
    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1: { // Criar cliente
                std::string nome, cpf, email;
                std::cout << "Nome: ";
                std::cin >> nome;
                std::cout << "CPF (apenas numeros): ";
                std::cin >> cpf;
                std::cout << "Email: ";
                std::cin >> email;

                // Limpa o CPF (remove pontos e tracos)
                cpf = limparCpf(cpf);

                // Verifica se o CPF ja existe
                if (buscarClientePorCpf(clientes, cpf)) {
                    std::cout << "Erro: CPF ja cadastrado!\n";
                    break;
                }

                clientes.emplace_back(nome, cpf, email);
                std::cout << "Cliente criado com sucesso!\n";
                break;
            }

            case 2: { // Criar conta
                if (clientes.empty()) {
                    std::cout << "Crie um cliente primeiro!\n";
                    break;
                }

                std::string cpf;
                std::cout << "CPF do cliente (apenas numeros): ";
                std::cin >> cpf;

                // Limpa o CPF (remove pontos e tracos)
                cpf = limparCpf(cpf);

                // Busca o cliente pelo CPF
                Cliente* cliente = buscarClientePorCpf(clientes, cpf);
                if (!cliente) {
                    std::cout << "Erro: Cliente nao encontrado!\n";
                    break;
                }

                int tipoConta;
                std::cout << "Tipo de conta:\n";
                std::cout << "1. Conta Corrente\n";
                std::cout << "2. Conta Poupanca\n";
                std::cout << "Escolha: ";
                std::cin >> tipoConta;

                int idConta;
                std::cout << "ID da conta: ";
                std::cin >> idConta;

                if (tipoConta == 1) {
                    double tarifa;
                    std::cout << "Tarifa da conta corrente: ";
                    std::cin >> tarifa;
                    contas.push_back(std::make_unique<ContaCorrente>(idConta, tarifa));
                } else if (tipoConta == 2) {
                    double taxaRendimento;
                    std::cout << "Taxa de rendimento da conta poupanca: ";
                    std::cin >> taxaRendimento;
                    contas.push_back(std::make_unique<ContaPoupanca>(idConta, taxaRendimento));
                } else {
                    std::cout << "Opcao invalida!\n";
                    break;
                }

                // Associa a conta ao cliente
                cliente->adicionarConta(idConta);
                std::cout << "Conta criada e associada ao cliente!\n";
                break;
            }

            case 3: { // Depositar
                int idConta;
                double valor;
                std::cout << "ID da conta: ";
                std::cin >> idConta;
                std::cout << "Valor: ";
                std::cin >> valor;

                Conta* conta = buscarContaPorId(contas, idConta);
                if (conta) {
                    conta->depositar(valor);
                    std::cout << "Deposito realizado com sucesso!\n";
                } else {
                    std::cout << "ID da conta invalido!\n";
                }
                break;
            }

            case 4: { // Sacar
                int idConta;
                double valor;
                std::cout << "ID da conta: ";
                std::cin >> idConta;
                std::cout << "Valor: ";
                std::cin >> valor;

                Conta* conta = buscarContaPorId(contas, idConta);
                if (conta) {
                    conta->sacar(valor);
                } else {
                    std::cout << "ID da conta invalido!\n";
                }
                break;
            }

            case 5: { // Transferir
                int idContaOrigem, idContaDestino;
                double valor;
                std::cout << "ID da conta de origem: ";
                std::cin >> idContaOrigem;
                std::cout << "ID da conta de destino: ";
                std::cin >> idContaDestino;
                std::cout << "Valor: ";
                std::cin >> valor;

                Conta* contaOrigem = buscarContaPorId(contas, idContaOrigem);
                Conta* contaDestino = buscarContaPorId(contas, idContaDestino);

                if (contaOrigem && contaDestino) {
                    contaOrigem->transferir(valor, *contaDestino);
                    std::cout << "Transferencia realizada com sucesso!\n";
                } else {
                    std::cout << "ID da conta invalido!\n";
                }
                break;
            }

            case 6: { // Aplicar rendimento (poupanca)
                int idConta;
                std::cout << "ID da conta poupanca: ";
                std::cin >> idConta;

                Conta* conta = buscarContaPorId(contas, idConta);
                if (conta) {
                    ContaPoupanca* cp = dynamic_cast<ContaPoupanca*>(conta);
                    if (cp) {
                        cp->aplicarRendimento();
                        std::cout << "Rendimento aplicado com sucesso!\n";
                    } else {
                        std::cout << "A conta nao e uma conta poupanca!\n";
                    }
                } else {
                    std::cout << "ID da conta invalido!\n";
                }
                break;
            }

            case 7: { // Exibir extrato
                int idConta;
                std::cout << "ID da conta: ";
                std::cin >> idConta;

                Conta* conta = buscarContaPorId(contas, idConta);
                if (conta) {
                    // Busca o cliente associado a conta
                    std::string nomeCliente = "Cliente nao encontrado";
                    for (const auto& cliente : clientes) {
                        if (cliente.temConta(idConta)) {
                            nomeCliente = cliente.getNome();
                            break;
                        }
                    }
                    conta->extrato(nomeCliente); // Passa o nome do cliente para o extrato
                } else {
                    std::cout << "ID da conta invalido!\n";
                }
                break;
            }

            case 8: { // Sair
                std::cout << "Saindo...\n";
                break;
            }

            default: {
                std::cout << "Opcao invalida!\n";
                break;
            }
        }
    } while (opcao != 8);

    return 0;
}