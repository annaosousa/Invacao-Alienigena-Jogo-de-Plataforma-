#pragma once
#include <string>
#include "GerenciadorEventos.h"

/*
    Identifica e padroniza os dados digitados pelo usuário nos campos de texto presentes .
*/

namespace InvasaoAlienigena {
    class PromessaTexto {
    private:
        std::string texto;
        unsigned int idOuvinteTeclado; //capta a interação via teclado
        bool capturaIniciada;
        bool textoPronto;
        Gerenciador::GerenciadorEventos& ge;
        unsigned short comprimentoMaximo;

    public:
        PromessaTexto(Gerenciador::GerenciadorEventos& GE, unsigned short comprimentoMax);
        ~PromessaTexto();
        void comecar();
        bool getTextoPronto() const;
        const std::string& getTexto() const;
        void adquirir(const sf::Event& e); //verifica o texto inserido
    };
}
