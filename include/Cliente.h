#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>

class Cliente {
private:
    std::string nome;
    std::string cpf;
    std::string email;
    std::vector<int> contas; // IDs das contas associadas ao cliente

public:
    Cliente(std::string nome, std::string cpf, std::string email);
    void adicionarConta(int idConta);
    bool temConta(int idConta) const; // Novo método
    std::string getNome() const;
    std::string getCpf() const;
    std::string getEmail() const;
};

#endif