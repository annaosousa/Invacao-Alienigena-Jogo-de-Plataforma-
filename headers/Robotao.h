#pragma once
#include <iostream>
#include "Inimigo.h"
#include "Colidivel.h"
#include "Ids.h"
#include "ListaDesenhaveis.h"
#include "Projetil.h"
#include "Fase.h"

/*
    Inimigo presente em todos os estágios responsável por cumprir o requisito de soltar um projétil.
*/

namespace InvasaoAlienigena {
    namespace Fase { class Fase; }
    namespace Desenhaveis {
        class Robotao : public Inimigo {
        private:
            sf::Clock clock;
            sf::Time elapsed;
            Fase::Fase* f;

        public:
            Robotao(Vetor::Vetor2F pos = { 0.0 , 0.0 }, Vetor::Vetor2F vel = { 0.0 , 0.0 }, Fase::Fase* F = NULL);
            Robotao(nlohmann::json fonte);
            ~Robotao();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void atualizar(float t); //atualiza posição do inimigo
            void desenhar(Gerenciador::GerenciadorGrafico& g) override;
        };
    }
}
/*Os atributos clock e elapsed, auxiliam a determinar o tempo em que o Robotao deverá liberar o projétil*/
