#include "Transacao.h"   // Inclui o arquivo de cabeçalho da classe Transacao.
#include <iostream>      // Inclui a biblioteca necessária para imprimir no console.

Transacao::Transacao(std::string tipo, double valor)
    : tipo(tipo), valor(valor) {  // Inicializa os atributos tipo e valor com os parâmetros passados.
    time_t now = time(0);  // Obtém o tempo atual (em segundos desde a época Unix).
    data = ctime(&now);    // Converte o tempo obtido para uma string legível (data e hora).
}

void Transacao::exibir() const {  // Método para exibir as informações da transação.
    std::cout << "Transação: " << tipo << " | Valor: " << valor << " | Data: " << data;
    // Exibe o tipo, o valor e a data da transação no console.
}

std::string Transacao::getTipo() const { return tipo; }  // Retorna o tipo da transação.
double Transacao::getValor() const { return valor; }    // Retorna o valor da transação.
std::string Transacao::getData() const { return data; }  // Retorna a data da transação.
