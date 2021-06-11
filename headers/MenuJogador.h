#pragma once
#include "Menu.h"
#include "CampoTexto.h"

/*
    Disponibiliza ao usu�rio a op��o de single ou multiplayer local.
*/

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuJogador : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;

        public:
            MenuJogador(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
            bool usarDoisJogadores(int codigoRetorno);
        };
    }

}

