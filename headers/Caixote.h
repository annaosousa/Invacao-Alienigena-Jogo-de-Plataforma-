#pragma once
#include "Obstaculo.h"
#include "Ids.h"

/*
Def: Segundo obstáculo do jogo simula uma caixa em que o jogador tem a capacidade de empurra-la para
auxiliar na subida em plataformas mais altas ou atrapalhar sua passagem
*/

namespace InvasaoAlienigena {
	namespace Obstaculo {
		class Caixote : public Obstaculo{

		public:
			Caixote(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
			Caixote(nlohmann::json fonte);
			~Caixote();
			void atualizar(float t);
			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
		};
	}
}

