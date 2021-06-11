#include "Ciclope.h"

#include <iostream>

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        Ciclope::Ciclope(Vetor::Vetor2F pos, Vetor::Vetor2F vel) :
            Inimigo(pos, vel, Ids::ciclope, "../imagens/Ciclope.png") {
            
        }

        Ciclope::Ciclope(nlohmann::json fonte) : Ciclope({ fonte["posicao"] }, { fonte["velocidade"] }) {

        }

        Ciclope::~Ciclope() {

        }

        void Ciclope::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc) {
            gf.carregarTextura(caminho);

            dimensoes = gf.getTamanho(caminho);

            gc.adicionarColidivel(this);
        }
    }
}