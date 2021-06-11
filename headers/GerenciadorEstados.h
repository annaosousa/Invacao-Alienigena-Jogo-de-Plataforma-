#pragma once
#include "Estado.h"
#include <stack>

/*
    Pilha de estados, primordial para o funcionamento do gerenciador de telas, que conforme o usuário seleciona
    a opção de tela a pilha manipula seus dados conforme o funcionamento da biblioteca stack da STL.
*/

namespace InvasaoAlienigena {
    namespace Gerenciador {
        class GerenciadorEstados {
        private:
            std::stack<Estado*> pilhaEstados;

        public:
            virtual ~GerenciadorEstados();
            bool executar(); //executa a pilha de estados

        protected:
            void push(Estado* p);
            void pop();
            Estado* top();
            void esvaziarPilha();
            virtual bool processarCodigo(int codigoRetorno) = 0;

        };
    }
}
/*utiliza como princípios e recursos a biblioteca stack da STL*/

