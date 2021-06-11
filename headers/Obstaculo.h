#pragma once
#include "Colidivel.h"
#include "Ids.h"

/*
	Classe abstrata criada com propósito de ser uma base para os objetos que são obstáculos e organizar o código
	com à aplicação do namespace.
*/

namespace InvasaoAlienigena {
	namespace Obstaculo {
		class Obstaculo : public Colidivel {
		public:
			Obstaculo(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
			~Obstaculo();
			void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
		};
	}
}
