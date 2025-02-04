#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta {
private:
    double taxaRendimento;

public:
    ContaPoupanca(int id, double taxaRendimento);
    void aplicarRendimento(); // Método específico para conta poupança
};

#endif