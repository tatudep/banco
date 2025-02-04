#include "Cliente.h"
#include <algorithm> // Inclui a biblioteca para usar std::find

// Construtor da classe Cliente, inicializa os atributos nome, CPF e e-mail
Cliente::Cliente(std::string nome, std::string cpf, std::string email)
    : nome(nome), cpf(cpf), email(email) {}

// Método para adicionar uma nova conta ao cliente
void Cliente::adicionarConta(int idConta) {
    contas.push_back(idConta); // Adiciona o ID da conta à lista de contas do cliente
}

// Método que verifica se o cliente possui uma conta específica
bool Cliente::temConta(int idConta) const {
    // Usa std::find para procurar o ID da conta na lista de contas do cliente
    return std::find(contas.begin(), contas.end(), idConta) != contas.end();
}

// Métodos que retornam informações do cliente
std::string Cliente::getNome() const { return nome; }
std::string Cliente::getCpf() const { return cpf; }
std::string Cliente::getEmail() const { return email; }
