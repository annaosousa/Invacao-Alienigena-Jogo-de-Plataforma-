#pragma once
#include "Menu.h"
#include "CampoTexto.h"
#include "GerenciadorGrafico.h"

/*Respons�vel pelo menu que apresenta op��es de fase ao jogador*/

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

