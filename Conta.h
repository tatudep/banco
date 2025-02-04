#ifndef CONTA_H
#define CONTA_H

#include "Transacao.h"
#include <string>
#include <vector>

class Conta {
protected:
    int id;
    double saldo;
    std::vector<Transacao> transacoes;

public:
    Conta(int id);
    virtual void depositar(double valor);
    virtual void sacar(double valor);
    virtual void transferir(double valor, Conta &destino);
    void extrato(const std::string& nomeCliente) const; // Adicionado parâmetro para o nome do cliente
    int getId() const;
    double getSaldo() const;
};

#endif