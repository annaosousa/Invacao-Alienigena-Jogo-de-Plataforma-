#pragma once
#include "Fase.h"
#include "Vetor2D.h"

/*
	Def: Classe abstrata
*/

namespace InvasaoAlienigena{
	namespace Entidades{
		class Entidade
		{
		protected:
			Vetor::Vetor2F posicao;
			virtual void inicializacoesEspecificas() = 0;

		public:
			Entidade();
			virtual ~Entidade();
		};
	}
}