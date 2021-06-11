#pragma once
#include <SFML/Graphics.hpp>
#include "Desenhavel.h"
#include "Vetor2D.h"
#include "Colidivel.h"
#include "ListaDesenhaveis.h"

/*
Def: A fim de atribuir a pontuação do jogador sem realizar o anulamento dos inimigos, foi utilizado o recurso
dos coletáveis que em jogo se parecem com moedas e atribuem 100 pontos a cada coleta na pontuação do jogador.
*/

namespace InvasaoAlienigena {
	class Coletavel : public Colidivel{

	public:
		Coletavel(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
		Coletavel(nlohmann::json fonte);
		virtual ~Coletavel();
		void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
		void desenhar(Gerenciador::GerenciadorGrafico& g);
		void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) override;
	};
}

