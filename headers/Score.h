#pragma once
#include "GerenciadorGrafico.h"
#include "Menu.h"
#include "CampoTexto.h"
#include "Lista.h"
#include "Jogador.h"

/*
	Classe utilizada para marcar a pontuação
*/

namespace InvasaoAlienigena {
	namespace Menu {
		class Score : public Menu{
		protected:
			CampoTexto campoTexto;
			Lista::Lista<Desenhaveis::Jogador*> ObjLJogador;

		public:
			Score(Gerenciador::GerenciadorGrafico& GG);
			int executar() override;

			void setNome(const char* n);
			const char* getNome();

			void incluaJogador(Desenhaveis::Jogador* pj);
			void listeJogador();
		};
	}
}

