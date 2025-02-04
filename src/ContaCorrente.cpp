#include "ContaCorrente.h"
#include <iostream>

// Construtor da ContaCorrente, recebe um ID e a tarifa que será cobrada nas operações
ContaCorrente::ContaCorrente(int id, double tarifa)
    : Conta(id), tarifa(tarifa) {} // Chama o construtor da classe base (Conta) e define a tarifa

// Método para sacar dinheiro da conta corrente
void ContaCorrente::sacar(double valor) {
    double valorComTarifa = valor + tarifa; // Calcula o valor total a ser descontado (saque + tarifa)

    if (valorComTarifa <= saldo) { // Verifica se há saldo suficiente para cobrir o saque e a tarifa
        saldo -= valorComTarifa; // Deduz o valor total do saldo
        transacoes.emplace_back("Saque", valor); // Registra a transação do saque
        transacoes.emplace_back("Tarifa", tarifa); // Registra a transação da tarifa cobrada
    } else {
        std::cout << "Saldo insuficiente!" << std::endl; // Mensagem de erro caso não tenha saldo suficiente
    }
}
