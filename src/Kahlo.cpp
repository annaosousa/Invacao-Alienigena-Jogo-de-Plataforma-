#include "Kahlo.h"
#include "Desenhavel.h"
//#include "GerenciadorTelas.h"
#include "Hospital.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Kahlo::Kahlo(Vetor::Vetor2F pos) :
            Jogador(pos, Vetor::Vetor2F(), Ids::kahlo, "../imagens/Kahlo.png") {
            vel_x = 100;
            vel_y = 100;
            alt_pulo = 110;
            vidas = 3;
            pontuacao = 0;
        }

        Kahlo::~Kahlo() {

        }

        void Kahlo::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event& e) {tratarEvento(e); });
            gc.adicionarColidivel(this);

        }

        void Kahlo::desenhar(Gerenciador::GerenciadorGrafico& g) {

            g.desenhar(caminho, posicao);
            g.centralizar(posicao);
        }

        void Kahlo::inicializarComJSON(nlohmann::json fonte) {
            posicao = { fonte["posicao"] };
            v = { fonte["velocidade"] };

            nlohmann::json json;
        }

        void Kahlo::tratarEvento(const sf::Event& f) {
            if (f.type == sf::Event::KeyPressed) {

                switch (f.key.code) {
                case sf::Keyboard::Key::Right:
                    this->v.x += this->vel_x;
                    break;
                case sf::Keyboard::Key::Left:
                    this->v.x -= this->vel_x;
                    break;
                case sf::Keyboard::Key::Up:
                    //v.y -= vel_y;
                    this->v.y = -sqrtf(2 * gravidade * this->alt_pulo);
                    break;
                case sf::Keyboard::Key::Down:
                    this->v.y += this->vel_y;
                    break;
                default:
                    break;
                }
            }
            else if (f.type == sf::Event::KeyReleased) {
                switch (f.key.code) {
                case sf::Keyboard::Key::Right:
                    this->v.x -= this->vel_x;
                    break;
                case sf::Keyboard::Key::Left:
                    this->v.x += this->vel_x;
                    break;
                case sf::Keyboard::Key::Up:
                    this->v.y = sqrtf(2 * gravidade * this->alt_pulo);
                    break;
                case sf::Keyboard::Key::Down:
                    this->v.y -= this->vel_x;
                    break;
                default:
                    break;
                }
            }
        }

        const int Kahlo::getVidas() const
        {
            return this->vidas;
        }


    }
}