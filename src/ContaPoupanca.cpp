#include "ContaPoupanca.h"
#include <iostream>

// Construtor da ContaPoupanca, recebe um ID e a taxa de rendimento da conta
ContaPoupanca::ContaPoupanca(int id, double taxaRendimento)
    : Conta(id), taxaRendimento(taxaRendimento) {} // Chama o construtor da classe base (Conta) e define a taxa de rendimento

// Método que aplica o rendimento sobre o saldo da conta
void ContaPoupanca::aplicarRendimento() {
    double rendimento = saldo * taxaRendimento; // Calcula o valor do rendimento com base no saldo atual
    saldo += rendimento; // Adiciona o rendimento ao saldo da conta
    transacoes.emplace_back("Rendimento", rendimento); // Registra a transação do rendimento
}
