#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"

/*
	Classe que atribu� valores e inicializa��o ao proj�til lan�ado pelo Robot�o.
*/

class ListaDesenhaveis;

namespace InvasaoAlienigena {
	namespace Projetil {
		class Projetil : public Colidivel
		{
		private:
			float aUniforme;

		public:
			Projetil(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);

			Projetil(nlohmann::json fonte);
			virtual ~Projetil();

			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void atualizar(float t) override; //atualiza a posi��o do proj�til
			void desenhar(Gerenciador::GerenciadorGrafico& g);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) override;
		};
	}
}
