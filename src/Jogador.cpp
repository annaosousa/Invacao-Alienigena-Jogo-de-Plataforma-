#include "Jogador.h"
#include <stdlib.h>
#include <iostream>


namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Jogador::Jogador(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
            Colidivel(pos, vel, ID, caminhoTextura) {


        }

        Jogador::~Jogador() {

        }

        void Jogador::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void Jogador::atualizar(float t) {

            posicao += v * t;
        }

        void Jogador::desenhar(Gerenciador::GerenciadorGrafico& g) {

            g.desenhar(caminho, posicao);
            g.centralizar(posicao);
        }


        void Jogador::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro)
        {
            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara)
            {
                Vetor::Vetor2F dist = posicao - posicaoOutro;


                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                }

                else {
                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                }

            }

            else if (idOutro == Ids::robotao || idOutro == Ids::lagartoVerde)
            {
                Vetor::Vetor2F dist = posicao - posicaoOutro;
                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                }

                else {
                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                }
            }

            else if (idOutro == Ids::buracoInfinito)
            {
                posicao.x = 280.0f;
                posicao.y = 150.0f;

                system("cls");
                pontuacao -= 100;
                std::cout << "pontuacao - 100" << std::endl;
                std::cout << "Pontuação atual: " << pontuacao << std::endl;
            }

            else if (idOutro == Ids::espinho_fundo)
            {
                //vidas--;
                Vetor::Vetor2F dist = posicao - posicaoOutro;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

                posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;

                system("cls");
                pontuacao -= 100;
                std::cout << "pontuacao - 100" << std::endl;
                std::cout << "Pontuação atual: " << pontuacao << std::endl;
            }

            else if (idOutro == Ids::porta)
            {
                //Fase::Fase
                //faseAtual->finalFase();
            }

            else if (idOutro == Ids::moeda)
            {
                system("cls");
                pontuacao += 100;
                std::cout << "pontuacao + 100" << std::endl;
                std::cout << "Pontuação atual: " << pontuacao << std::endl;
            }

            else if (idOutro == Ids::projetil)
            {
                system("cls");
                pontuacao -= 100;
                std::cout << "pontuacao - 100" << std::endl;
                std::cout << "Pontuação atual: " << pontuacao << std::endl;
            }
        }

    }
}