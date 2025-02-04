#include "ContaPoupanca.h"
#include <iostream>

ContaPoupanca::ContaPoupanca(int id, double taxaRendimento)
    : Conta(id), taxaRendimento(taxaRendimento) {}

void ContaPoupanca::aplicarRendimento() {
    double rendimento = saldo * taxaRendimento;
    saldo += rendimento;
    transacoes.emplace_back("Rendimento", rendimento); // Cria um objeto Transacao
}