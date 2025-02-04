#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include <ctime>

class Transacao {
private:
    std::string tipo;
    double valor;
    std::string data;

public:
    Transacao(std::string tipo, double valor);
    void exibir() const;
    std::string getTipo() const;
    double getValor() const;
    std::string getData() const;
};

#endif