#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include <ctime>

// Classe que representa uma transação bancária, como depósitos, saques e transferências
class Transacao {
private:
    std::string tipo; // Tipo da transação (ex: "Depósito", "Saque", "Transferência")
    double valor; // Valor envolvido na transação
    std::string data; // Data em que a transação foi realizada

public:
    // Construtor que cria uma transação com um tipo e um valor
    Transacao(std::string tipo, double valor);

    // Método para exibir os detalhes da transação
    void exibir() const;

    // Métodos para obter informações da transação
    std::string getTipo() const;
    double getValor() const;
    std::string getData() const;
};

#endif // Finaliza a definição da classe Transacao
