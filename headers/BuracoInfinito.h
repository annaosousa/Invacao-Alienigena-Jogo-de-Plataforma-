#pragma once
#include "Obstaculo.h"
#include "Ids.h"
/*
Def: Obstáculo de cenário similar a um buraco negro, faz com que o jogador seja teletransportado
ao início da fase
*/

namespace InvasaoAlienigena {
	namespace Obstaculo {
		class BuracoInfinito : public Obstaculo {

		public:
			BuracoInfinito(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f });
			BuracoInfinito(nlohmann::json fonte); 
			~BuracoInfinito();
			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
			void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro);
		};
	}
}

