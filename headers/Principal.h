#pragma once

#include "GerenciadorGrafico.h"
#include "Kahlo.h"
#include "Frida.h"
#include "GerenciadorTelas.h"


/*
    Classe que inst�ncia os principais objetos do c�digo.
*/

namespace InvasaoAlienigena {
    class Principal {
    private:
        Gerenciador::GerenciadorGrafico gerenciadorGrafico;
        Desenhaveis::Kahlo jogador1;
        Desenhaveis::Frida jogador2;
        Gerenciador::GerenciadorTelas gerenciadorTelas;
        bool terminar;

    public:
        Principal();
        ~Principal();
        int executar();
        void janelaFechada(const sf::Event& e);

    };

}