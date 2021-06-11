#include "LagartoVerde.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        LagartoVerde::LagartoVerde(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Inimigo(pos, vel, Ids::lagartoVerde, "../imagens/LagartoVerde.png") {

        }

        LagartoVerde::LagartoVerde(nlohmann::json fonte) : LagartoVerde({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        LagartoVerde::~LagartoVerde() {

        }

        void LagartoVerde::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }

        void LagartoVerde::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) {
            if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::frida || idOutro == Ids::kahlo || idOutro == Ids::armadilha_direita || idOutro == Ids::armadilha_esquerda) {
                Vetor::Vetor2F dist = posicao - posicaoOutro;

                float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
                float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

                if (sobr_x > sobr_y) {
                    posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
                    v.x *= -1;
                }
                else {
                    posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
                    v.x *= -1;
                }
            }
        }

    }
}