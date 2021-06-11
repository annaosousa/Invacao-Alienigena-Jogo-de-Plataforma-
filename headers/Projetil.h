#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"

/*
	Classe que atribuí valores e inicialização ao projétil lançado pelo Robotão.
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
			void atualizar(float t) override; //atualiza a posição do projétil
			void desenhar(Gerenciador::GerenciadorGrafico& g);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) override;
		};
	}
}
