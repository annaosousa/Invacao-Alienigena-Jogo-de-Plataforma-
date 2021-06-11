#include "Coletavel.h"

namespace InvasaoAlienigena {

	Coletavel::Coletavel(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
		Colidivel(pos, vel, Ids::moeda, "../imagens/moeda.png")
	{
	
	}

	Coletavel::Coletavel(nlohmann::json fonte) : Coletavel({ fonte["posicao"] }, { fonte["velocidade"] })
	{

	}

	Coletavel::~Coletavel()
	{

	}

	void Coletavel::desenhar(Gerenciador::GerenciadorGrafico& g)
	{
		g.desenhar(caminho, posicao);
	}

	void Coletavel::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc)
	{
		gf.carregarTextura(caminho);
		dimensoes = gf.getTamanho(caminho);
		gc.adicionarColidivel(this);
	}

	void Coletavel::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro)
	{
		
		if (idOutro == Ids::frida || idOutro == Ids::kahlo)
		{
			posicao = { -1000 , -1000 };
		}

		if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara) {
			Vetor::Vetor2F dist = posicao - posicaoOutro;


			float sobr_x = std::abs(dist.x) - (dimensoes.x + dimensoesOutro.x) * 0.5;
			float sobr_y = std::abs(dist.y) - (dimensoes.y + dimensoesOutro.y) * 0.5;

			if (sobr_x > sobr_y) {
				posicao.x += (dist.x > 0 ? -1 : 1) * sobr_x;
			}

			else {
				posicao.y += (dist.y > 0 ? -1 : 1) * sobr_y;
			}

		}
	}
}