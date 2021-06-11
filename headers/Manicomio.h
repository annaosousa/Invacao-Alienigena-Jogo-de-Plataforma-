#pragma once
#include "Fase.h"

/*
    Fase inicial inclu� os inimigos b�sicos Lagarto Verde e Robot�o al�m de todos os obst�culos
*/

namespace InvasaoAlienigena {
    namespace Fase {
        class Manicomio : public Fase {
        public:
            Manicomio(Gerenciador::GerenciadorGrafico& gg, Desenhaveis::Kahlo* jogador1 = nullptr, Desenhaveis::Frida* jogador2 = nullptr);
            nlohmann::json paraJSON() override;
            void carregar(const std::string& caminho) override; //carrega os jogadores e inimigos presentes na fase
            void inicializar() override; //inicializa os jogadores e inimigos presentes na fase
           
        };
    }
}
