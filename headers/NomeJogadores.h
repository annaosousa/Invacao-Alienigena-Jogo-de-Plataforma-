#pragma once
#include "Menu.h"
#include "CampoTexto.h"

/*
    Classe criada com finalidade de atribuir nome ao jogador na inicializa��o da fase com o �mbito de salvar sua pontua��o.
*/

namespace InvasaoAlienigena {
	namespace Menu {
		class NomeJogadores: public Menu
		{
        protected:
            bool imprimiu;
            CampoTexto campoTexto;

        public:
            NomeJogadores(Gerenciador::GerenciadorGrafico& GG);
            int executar() override;
        };
	};
}

