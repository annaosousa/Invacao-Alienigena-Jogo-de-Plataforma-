#pragma once
#include "Ciclope.h"
#include "Fase.h"

/*
    Fase final que incluí o boss
*/

namespace InvasaoAlienigena {
    namespace Fase {
        class Hospital : public Fase {
        public:
            Hospital(Gerenciador::GerenciadorGrafico& gg, Desenhaveis::Kahlo* jogador1 = nullptr, Desenhaveis::Frida* jogador2 = nullptr);
            nlohmann::json paraJSON() override;
            void carregar(const std::string& caminho) override; //carrega os jogadores e inimigos presentes na fase
            void inicializar() override; //inicializa os jogadores e inimigos presentes na fase
        };
    }
}

