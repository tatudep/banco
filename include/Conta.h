#ifndef CONTA_H
#define CONTA_H

#include "Transacao.h" // Inclui a classe responsável por registrar transações
#include <string>
#include <vector>

// Classe que representa uma conta bancária
class Conta {
protected:
    int id; // Identificador único da conta
    double saldo; // Saldo disponível na conta
    std::vector<Transacao> transacoes; // Lista de transações realizadas na conta

public:
    // Construtor que cria uma conta a partir de um ID
    Conta(int id);

    // Método para adicionar dinheiro à conta
    virtual void depositar(double valor);

    // Método para retirar dinheiro da conta
    virtual void sacar(double valor);

    // Método para transferir dinheiro para outra conta
    virtual void transferir(double valor, Conta &destino);

    // Método para exibir o extrato da conta, incluindo o nome do cliente
    void extrato(const std::string& nomeCliente) const;

    // Retorna o ID da conta
    int getId() const;

    // Retorna o saldo atual da conta
    double getSaldo() const;
};

#endif // Finaliza a definição da classe Conta
``
