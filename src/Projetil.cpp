#include "Projetil.h"

namespace InvasaoAlienigena {
	namespace Projetil {

		Projetil::Projetil(Vetor::Vetor2F pos, Vetor::Vetor2F vel, Ids::Ids ID, const char* caminhoTextura) :
			Colidivel(pos, vel, Ids::projetil, "../imagens/projetil.png")
		{
			aUniforme = 100;
		}

		Projetil::Projetil(nlohmann::json fonte) : Projetil({ fonte["posicao"] }, { fonte["velocidade"] })
		{

		}

		Projetil::~Projetil()
		{

		}

		void Projetil::atualizar(float t)
		{
			this->v += aUniforme * t;
			this->posicao += this->v * t;
		}

		void Projetil::desenhar(Gerenciador::GerenciadorGrafico& g)
		{
			g.desenhar(caminho, posicao);
		}

		void Projetil::inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc)
		{
			gf.carregarTextura(caminho);
			dimensoes = gf.getTamanho(caminho);
			gc.adicionarColidivel(this);
		}

		void Projetil::colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro)
		{
			if (idOutro == Ids::parede_up || idOutro == Ids::parede_clara || idOutro == Ids::frida || idOutro == Ids::kahlo || idOutro == Ids::parede || idOutro == Ids::armadilha_direita || idOutro == Ids::armadilha_esquerda) {
				posicao = { -1000,-1000 };
			}
		}
	}
}