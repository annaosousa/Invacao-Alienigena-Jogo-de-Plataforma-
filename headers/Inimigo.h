#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"
#include <math.h>

/*
    Classe que controla os vil�es do jogo, colis�es, movimento, gravidade, posi��o.
*/

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        class Inimigo : public Colidivel
        {

        public:
            Inimigo(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
            ~Inimigo();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void atualizar(float t); //atualiza posi��o dos inimigos
            void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro); //verifica colis�o dos inimigos entre si, bem como com o mapa
        };
    };    
}
