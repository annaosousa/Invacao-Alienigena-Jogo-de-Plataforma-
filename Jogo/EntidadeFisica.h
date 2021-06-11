#pragma once
#include "Entidade.h"
#include "Vetor2D.h"
#include "Ids.h"
#include <string>

/*
	Def: Classe responsável por obter os valores da posição, tamanho e ID da imagem desenhada na tela.
*/

namespace InvasaoAlienigena{
	namespace Entidades{
		class EntidadeFisica: public Entidade
		{
		protected:
			int altura;
			int largura;
			
			std::string id;
			Vetor::Vetor2F ajuste;

		public:
			EntidadeFisica();
			virtual ~EntidadeFisica();

			virtual void colidiu(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) = 0;
			virtual void ajustar();

			void setPos(Vetor::Vetor2F pos);
			Vetor::Vetor2F getPos() const;
			Vetor::Vetor2F getTamanho() const;
			std::string getID() const;
		};
	}
}