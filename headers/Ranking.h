#pragma once
#include <map>
#include <iostream>
#include <string>
#include <vector>

namespace exercicio
{
	class Ranking
	{
	private:
		std::multimap<float, std::string, std::greater<float> >pontuacoes;
		std::pair<std::multimap<float, std::string>::iterator,
			std::multimap<float, std::string>::iterator > opcoes;

	public:
		Ranking();
		~Ranking();

		void carregaPontuacoes();
		void preencheOpcoes(std::vector<Opcao*>& opcoes);
		void atualizaOpcoes(std::vector<Opcao*>& opcoes, int direcao);
	};
}
