#pragma once
#include "Menu.h"
#include "CampoTexto.h"

/*
    Primeira interação do usuário com a tela disponibiliza as opções de inicializar o jogo, sair do jogo, carregar jogo
    e a classificação guardada.
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


