#include "ContaCorrente.h"
#include <iostream>

ContaCorrente::ContaCorrente(int id, double tarifa)
    : Conta(id), tarifa(tarifa) {}

void ContaCorrente::sacar(double valor) {
    double valorComTarifa = valor + tarifa;
    if (valorComTarifa <= saldo) {
        saldo -= valorComTarifa;
        transacoes.emplace_back("Saque", valor); // Cria um objeto Transacao
        transacoes.emplace_back("Tarifa", tarifa); // Cria um objeto Transacao
    } else {
        std::cout << "Saldo insuficiente!" << std::endl;
    }
}