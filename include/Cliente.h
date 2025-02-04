#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>

// Definição da classe Cliente, que representa um cliente do banco.
class Cliente {
private:
    std::string nome;   // Nome do cliente
    std::string cpf;    // CPF do cliente (documento de identificação)
    std::string email;  // E-mail do cliente
    std::vector<int> contas; // Lista de IDs das contas que pertencem ao cliente

public:
    // Construtor que recebe nome, CPF e e-mail do cliente
    Cliente(std::string nome, std::string cpf, std::string email);

    // Método para adicionar uma conta ao cliente
    void adicionarConta(int idConta);

    // Método que verifica se o cliente possui uma conta específica
    bool temConta(int idConta) const; 

    // Métodos para obter informações do cliente
    std::string getNome() const;
    std::string getCpf() const;
    std::string getEmail() const;
};

#endif // Finaliza a definição da classe Cliente
