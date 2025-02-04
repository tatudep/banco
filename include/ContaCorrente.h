#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
private:
    double tarifa;

public:
    ContaCorrente(int id, double tarifa);
    void sacar(double valor) override; // Sobrescreve o método da classe base
};

#endif