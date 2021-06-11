#pragma once

#include "Inimigo.h"
#include "Colidivel.h"
#include "Ids.h"

/*
    Classe que define o vil�o presente na primeira e segunda fase.
*/

namespace InvasaoAlienigena {
     namespace Desenhaveis {
        class LagartoVerde : public Inimigo {

        public:
            LagartoVerde(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            LagartoVerde(nlohmann::json fonte);
            ~LagartoVerde();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
        };
     }
}
