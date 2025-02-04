#include "Cliente.h"
#include <algorithm> // Para std::find

Cliente::Cliente(std::string nome, std::string cpf, std::string email)
    : nome(nome), cpf(cpf), email(email) {}

void Cliente::adicionarConta(int idConta) {
    contas.push_back(idConta);
}

bool Cliente::temConta(int idConta) const {
    return std::find(contas.begin(), contas.end(), idConta) != contas.end();
}

std::string Cliente::getNome() const { return nome; }
std::string Cliente::getCpf() const { return cpf; }
std::string Cliente::getEmail() const { return email; }