#include "Conta.h"
#include <iostream>

// Construtor da classe Conta, inicializa o ID da conta e o saldo como zero
Conta::Conta(int id) : id(id), saldo(0) {}

// Método para depositar dinheiro na conta
void Conta::depositar(double valor) {
    saldo += valor; // Adiciona o valor ao saldo
    transacoes.emplace_back("Depósito", valor); // Registra a transação
}

// Método para sacar dinheiro da conta
void Conta::sacar(double valor) {
    if (valor <= saldo) { // Verifica se há saldo suficiente
        saldo -= valor; // Deduz o valor do saldo
        transacoes.emplace_back("Saque", valor); // Registra a transação
    } else {
        std::cout << "Saldo insuficiente!\n"; // Mensagem de erro caso o saldo seja insuficiente
    }
}

// Método para transferir dinheiro para outra conta
void Conta::transferir(double valor, Conta &destino) {
    if (valor <= saldo) { // Verifica se há saldo suficiente para a transferência
        saldo -= valor; // Deduz o valor do saldo
        destino.depositar(valor); // Deposita o valor na conta de destino
        transacoes.emplace_back("Transferência", valor); // Registra a transação
    } else {
        std::cout << "Saldo insuficiente para transferência!\n"; // Mensagem de erro
    }
}

// Método para exibir o extrato da conta
void Conta::extrato(const std::string& nomeCliente) const {
    std::cout << "\n=== Extrato da Conta " << id << " ===\n";
    std::cout << "Titular: " << nomeCliente << "\n";
    for (const Transacao &transacao : transacoes) { // Percorre todas as transações
        transacao.exibir(); // Exibe os detalhes de cada transação
    }
    std::cout << "Saldo atual: " << saldo << "\n"; // Mostra o saldo final
}

// Retorna o ID da conta
int Conta::getId() const { return id; }

// Retorna o saldo da conta
double Conta::getSaldo() const { return saldo; }
