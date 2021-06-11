#pragma once
#include "Menu.h"
#include "CampoTexto.h"

/*
    Classe criada com finalidade de atribuir nome ao jogador na inicialização da fase com o âmbito de salvar sua pontuação.
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

