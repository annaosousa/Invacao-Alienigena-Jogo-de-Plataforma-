#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Botao.h"
#include <vector>

/*
    Controla os bot�es presentes no jogo, al�m de monitorar o clique do usu�rio nos itens do menu.
*/

namespace InvasaoAlienigena {
    namespace Gerenciador {
        class GerenciadorBotoes {

        private:
            std::vector<Menu::Botao*> botoes;
            GerenciadorEventos& ge;
            GerenciadorGrafico& gg;
            unsigned int idOuvinteMouse;

        public:
            GerenciadorBotoes(GerenciadorEventos& GE, GerenciadorGrafico& gg, std::vector<Menu::Botao*> Botoes = {}); //Construtor sem par�metros, n�o � necess�rio pois ele n�o existe em classes com atributos que s�o refer�ncias
            ~GerenciadorBotoes();
            void desenhar() const; 
            void ouvinteMouse(const sf::Event& e); // verifica se houve intera��o com o bot�o
            void adicionarBotao(Menu::Botao* b);
        };
    }
}