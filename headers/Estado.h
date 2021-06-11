#pragma once

/*
	Def: Classe abstrata responsável por executar mudanças de tela em geral.
*/

namespace InvasaoAlienigena{
	class Estado 
	{
	public:
		virtual ~Estado();
		virtual int executar() = 0;
		int codigoRetorno;
	};
	
}
