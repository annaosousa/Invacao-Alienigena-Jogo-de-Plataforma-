#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"
#include "Jogador.h"
#include "GerenciadorEstados.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"

/*
    Classe para definir a personagem controlada pelo segundo jogador.
*/

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        class Frida : public Jogador {

        public:
            Frida(Vetor::Vetor2F pos = { 0.0f , 0.0f });
            ~Frida();

            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void desenhar(Gerenciador::GerenciadorGrafico& g);
            void tratarEvento(const sf::Event& e); //responsável pelo movimento do jogador via teclado
            void inicializarComJSON(nlohmann::json fonte);
        };
    }
}

