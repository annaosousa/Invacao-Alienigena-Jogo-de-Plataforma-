#pragma once
//#include "Vetor2D.h"
#include "Estado.h"
//#include "Colidivel.h"
#include "Jogador.h"
//#include "GerenciadorGrafico.h"
//#include "GerenciadorEventos.h"
//#include "GerenciadorColisao.h"
//#include "ListaDesenhaveis.h"
//#include "Desenhavel.h"
//#include "../Json/json.hpp"
//#include "EntidadeFisica.h"

/*
Classe para definir a personagem controlada pelo primeiro jogador.
*/

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        class Kahlo : public Jogador {

        public:
            Kahlo(Vetor::Vetor2F pos = { 0.0f , 0.0f });
            ~Kahlo();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void desenhar(Gerenciador::GerenciadorGrafico& g);
            void tratarEvento(const sf::Event& f); //responsável pelo movimento do jogador via teclado
            void inicializarComJSON(nlohmann::json fonte);
            const int getVidas() const;
        };
    }
}