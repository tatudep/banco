#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h" // Inclui a definição da classe Conta

// Classe que representa uma conta corrente, que é um tipo de conta bancária
class ContaCorrente : public Conta {
private:
    double tarifa; // Tarifa cobrada por operações na conta

public:
    // Construtor que cria uma conta corrente com um ID e uma tarifa específica
    ContaCorrente(int id, double tarifa);

    // Método para sacar dinheiro, sobrescrevendo a versão da classe Conta
    void sacar(double valor) override;
};

#endif // Finaliza a definição da classe ContaCorrente
