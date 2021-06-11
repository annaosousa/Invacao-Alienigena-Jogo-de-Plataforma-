#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <functional>

/*
    Def: Identifica intera��es com o teclado e mouse, a partir da biblioteca map com o auxilio da bibliteca functional.
         Al�m de ser respons�vel por criar a janela de renderiza��o do jogo.
*/

namespace InvasaoAlienigena {
    namespace Gerenciador{
        class GerenciadorEventos {
        private:

            static unsigned int proximoID;
            sf::RenderWindow* janela;
            std::map<unsigned int, std::function<void(const sf::Event&)>> ouvintesMouse;
            std::map<unsigned int, std::function<void(const sf::Event&)>> ouvintesTeclado;
            std::map<unsigned int, std::function<void(const sf::Event&)>> ouvintesOutros;
            sf::Event evento;

        public:

            GerenciadorEventos();
            ~GerenciadorEventos();
            void tratarEventos(); //identifica o evento ocorrido, seja a��es com o mouse, bot�es precionados, entre outros.
            void setJanela(sf::RenderWindow* j); //aciona apenas um evento, mesmo quando mantida a tecla precionada

            unsigned int adicionarOuvinteMouse(std::function<void(const sf::Event&)> chamada);
            void removerOuvinteMouse(int id);

            unsigned int adicionarOuvinteTeclado(std::function<void(const sf::Event&)> chamada);
            void removerOuvinteTeclado(int id);

            unsigned int adicionarOuvinteOutro(std::function<void(const sf::Event&)> chamada);
            void removerOuvinteOutro(int id);
        };
    }
}
/*Os m�tdos adicionar, s�o utilizados com intuito da inclus�o no map de novas chamadas/eventos.
Da mesma forma, ocorre para os m�todos remover.*/