#pragma once

/*
	Def: Classe abstrata respons�vel por executar mudan�as de tela em geral.
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
