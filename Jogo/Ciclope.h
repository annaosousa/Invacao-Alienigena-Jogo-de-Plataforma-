#pragma once
#include "Inimigo.h"
#include "Ids.h"

/*
    Def: Inimigo mais forte considerado o Boss do jogo, localizado na última fase.
*/

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        class Ciclope : public Inimigo{

        public:
            Ciclope(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
            Ciclope(nlohmann::json fonte); //posição e velocidade passadas para o json
            ~Ciclope();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            
        };
    }
}
