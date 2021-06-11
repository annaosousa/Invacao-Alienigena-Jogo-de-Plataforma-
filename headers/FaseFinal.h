#pragma once
#include "Fase.h"
#include "Frida.h"
#include"../Json/json.hpp"

namespace InvasaoAlienigena {
    namespace Fase {
        class FaseFinal : public Fase {
        public:
            FaseFinal(Gerenciador::GerenciadorGrafico& gg, Desenhaveis::Kahlo* jogador1 = nullptr, Desenhaveis::Frida* jogador2 = nullptr);
            nlohmann::json paraJSON() override;
            void carregar(const std::string& caminho) override;
            void inicializar() override;
        };
    }
}
