#pragma once
#include "Kahlo.h"
#include "Frida.h"
#include "GerenciadorEstados.h"
#include "CampoTexto.h"

/*
    Respons�vel pelo processamento de telas, identidicando o c�digo para pilha de estados de tela.
*/

namespace InvasaoAlienigena {
    class Heroi;
    enum CodigoRetorno { /*Constantes que auxiliam na identifica��o da opera��o a ser realizada pela pilha de estados*/
        continuar,
        terminarJogo,
        salvarJogo,
        comecarPrimeiraFase,
        comecarSegundaFase,
        comecarFaseFinal,
        classificacao,
        carregarJogo,
        configuracoes,
        irMenuPrincipal,
        irMenuPausa,
        sairMenuPausa,
        umJogador,
        doisJogadores,
        selecionarJogador,
        fimDeJogo,
        nome,
        comecar,
        
    };
   
    namespace Gerenciador {
        class GerenciadorGrafico;
        
        class GerenciadorTelas : public GerenciadorEstados {
        private:
            GerenciadorGrafico& gerenciadorGrafico;
            Desenhaveis::Kahlo* jogador1;
            Desenhaveis::Frida* jogador2;
            bool multiplosJogadores;

        public:
            GerenciadorTelas(GerenciadorGrafico& gg, Desenhaveis::Kahlo* jogador1 = nullptr, Desenhaveis::Frida* jogador2 = nullptr);
            //Construtor sem par�metros n�o � necess�rio pois ele n�o existe em classes com atributos que s�o refer�ncias
            bool processarCodigo(int codigoRetorno) override; //gerencia qual tela ser� exibida

        };
    }
}