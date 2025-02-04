#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h" // Inclui a definição da classe Conta

// Classe que representa uma conta poupança, que é um tipo de conta bancária
class ContaPoupanca : public Conta {
private:
    double taxaRendimento; // Porcentagem de rendimento da poupança

public:
    // Construtor que cria uma conta poupança com um ID e uma taxa de rendimento específica
    ContaPoupanca(int id, double taxaRendimento);

    // Método que aplica o rendimento ao saldo da conta, baseado na taxa definida
    void aplicarRendimento();
};

#endif // Finaliza a definição da classe ContaPoupanca
