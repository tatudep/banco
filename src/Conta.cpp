#include "Conta.h"
#include <iostream>

Conta::Conta(int id) : id(id), saldo(0) {}

void Conta::depositar(double valor) {
    saldo += valor;
    transacoes.emplace_back("Depósito", valor);
}

void Conta::sacar(double valor) {
    if (valor <= saldo) {
        saldo -= valor;
        transacoes.emplace_back("Saque", valor);
    } else {
        std::cout << "Saldo insuficiente!\n";
    }
}

void Conta::transferir(double valor, Conta &destino) {
    if (valor <= saldo) {
        saldo -= valor;
        destino.depositar(valor);
        transacoes.emplace_back("Transferência", valor);
    } else {
        std::cout << "Saldo insuficiente para transferência!\n";
    }
}

void Conta::extrato(const std::string& nomeCliente) const {
    std::cout << "\n=== Extrato da Conta " << id << " ===\n";
    std::cout << "Titular: " << nomeCliente << "\n";
    for (const Transacao &transacao : transacoes) {
        transacao.exibir();
    }
    std::cout << "Saldo atual: " << saldo << "\n";
}

int Conta::getId() const { return id; }
double Conta::getSaldo() const { return saldo; }