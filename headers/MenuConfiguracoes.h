#pragma once
#include "Menu.h"
#include "CampoTexto.h"
#include "GerenciadorGrafico.h"

/*Responsável pelo menu que apresenta opções de fase ao jogador*/

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuConfiguracoes : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;
        public:
            MenuConfiguracoes(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
    }
}

