#pragma once
#include "GerenciadorTile.h"
#include <set>

/*
    Def: Funciona com base na biblioteca set, verifica a dist�cia entre o centro das imagens, utilizando
         desta informa��o para averiguar colis�es com os tiles e a dire��o em que est�o ocorrendo.
*/

namespace InvasaoAlienigena {
    class Colidivel;
    namespace Gerenciador {
        class GerenciadorColisoes {
        private:
            std::set<Colidivel*> colidiveis;
            bool estaoColidindo(Colidivel* p1, Colidivel* p2); // verifca se a distancia entre os itens analisados � menor que a distancia entre seus respectivos centros 
            Gerenciador::GerenciadorTiles* gt;

        public:
            GerenciadorColisoes();
            ~GerenciadorColisoes();
            void adicionarColidivel(Colidivel* p);
            void removerColidivel(Colidivel* p);
            void removerTodos();
            void verificarColisoes(); //verifica colis�es com o Tile
            void setGerenciadorTiles(Gerenciador::GerenciadorTiles* Gt);
        };
    }
}

/*os seguintes m�todos: adicionarColidivel, removerColidivel e removerTodos utilziam como recurso
o set componente da STL, com o intuito de inserir e remover itens do conjunto ou remover todos, respectivamente.
Sendo assim, � poss�vel inserir ou remover itens do conjunto de colis�es.*/