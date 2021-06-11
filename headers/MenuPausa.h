#pragma once

#include "MenuPrincipal.h"
#include "GerenciadorGrafico.h"


/*
   Aguarda o ouvinte ESC do teclado durante a execu��o da fase para contruir o menu e disponibilizar
   suas op��es.
*/

namespace InvasaoAlienigena {
    namespace Menu {
        class MenuPausa : public Menu{
        public:
            MenuPausa(Gerenciador::GerenciadorGrafico& gg);
        };
    }
}

