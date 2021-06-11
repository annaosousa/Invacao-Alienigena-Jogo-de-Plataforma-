#pragma once
#include "Desenhavel.h"
#include "Lista.h"
#include "Serializavel.h"

#include "../Json/json.hpp"

/*
    Implementação do template lista para classe desenhaveis.
*/

namespace InvasaoAlienigena {

    class GerenciadorGrafico;
    class GerenciadorEventos;
    class GerenciadorColisoes;

    namespace Lista {
        class ListaDesenhaveis : public Serializavel {
        private:
            Lista<Desenhavel*>  lista;

        public:

            ListaDesenhaveis();
            ~ListaDesenhaveis();

            void inserir(Desenhavel* info);
            void removerPrimeiro(Desenhavel* p);

            //Desenhavel* voltarInicio(); //retorna para o início e retorna o primeiro elemento da lista
            //Desenhavel* irProximo(); //vai para o próximo elemento da lista e retorna o próximo
            Desenhavel* getInicio();
            bool estaVazia();

            void inicializarDesenhaveis(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void atualizarDesenhaveis(float t);
            void desenharDesenhaveis(Gerenciador::GerenciadorGrafico& g);
            void destruirDesenhaveis();
            nlohmann::json paraJSON() override;

        };
    }
}


