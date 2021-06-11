#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Botao.h"
#include <vector>

/*
    Controla os botões presentes no jogo, além de monitorar o clique do usuário nos itens do menu.
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
            GerenciadorBotoes(GerenciadorEventos& GE, GerenciadorGrafico& gg, std::vector<Menu::Botao*> Botoes = {}); //Construtor sem parâmetros, não é necessário pois ele não existe em classes com atributos que são referências
            ~GerenciadorBotoes();
            void desenhar() const; 
            void ouvinteMouse(const sf::Event& e); // verifica se houve interação com o botão
            void adicionarBotao(Menu::Botao* b);
        };
    }
}