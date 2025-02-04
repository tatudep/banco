#include "Transacao.h"
#include <iostream>

Transacao::Transacao(std::string tipo, double valor)
    : tipo(tipo), valor(valor) {
    time_t now = time(0);
    data = ctime(&now);
}

void Transacao::exibir() const {
    std::cout << "Transação: " << tipo << " | Valor: " << valor << " | Data: " << data;
}

std::string Transacao::getTipo() const { return tipo; }
double Transacao::getValor() const { return valor; }
std::string Transacao::getData() const { return data; }