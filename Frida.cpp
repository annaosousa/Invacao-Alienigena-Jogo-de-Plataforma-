#include "Frida.h"
#include "Desenhavel.h"
#include <iostream>


namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Frida::Frida(Vetor::Vetor2F pos) :
            Jogador(pos, Vetor::Vetor2F(), Ids::frida, "../imagens/Frida.png") {
            vel_x = 100;
            vel_y = 100;
            alt_pulo = 110;
            vidas = 3;
            pontuacao = 0;
        }

        Frida::~Frida() {

        }

        void Frida::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });

            gc.adicionarColidivel(this);

        }

        void Frida::desenhar(Gerenciador::GerenciadorGrafico& g) {

            g.desenhar(caminho, posicao);
        }

        void Frida::inicializarComJSON(nlohmann::json fonte) {
            posicao = { fonte["posicao"] };
            v = { fonte["velocidade"] };
        }

        void Frida::tratarEvento(const sf::Event& e) {

            if (e.type == sf::Event::KeyPressed) {

                switch (e.key.code) {
                case sf::Keyboard::Key::D:
                    this->v.x += this->vel_x;
                    break;
                case sf::Keyboard::Key::A:
                    this->v.x -= this->vel_x;
                    break;
                case sf::Keyboard::Key::W:
                    this->v.y = -sqrtf(2 * gravidade * this->alt_pulo);
                    break;
                case sf::Keyboard::Key::S:
                    this->v.y += this->vel_y;
                    break;
                default:
                    break;
                }
            }
            else if (e.type == sf::Event::KeyReleased) {
                switch (e.key.code) {
                case sf::Keyboard::Key::D:
                    this->v.x -= this->vel_x;
                    break;
                case sf::Keyboard::Key::A:
                    this->v.x += this->vel_x;
                    break;
                case sf::Keyboard::Key::W:
                    this->v.y = sqrtf(2 * gravidade * this->alt_pulo);
                    break;
                case sf::Keyboard::Key::S:
                    this->v.y -= this->vel_y;
                    break;
                default:
                    break;
                }
            }
        }
    }
}