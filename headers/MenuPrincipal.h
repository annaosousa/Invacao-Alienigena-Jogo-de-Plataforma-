#pragma once
#include "Menu.h"
#include "CampoTexto.h"

/*
    Primeira intera��o do usu�rio com a tela disponibiliza as op��es de inicializar o jogo, sair do jogo, carregar jogo
    e a classifica��o guardada.
*/

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuPrincipal : public Menu {
        protected:
            bool imprimiu;
            CampoTexto campoTexto;

        public:
            MenuPrincipal(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
    }
    
}


