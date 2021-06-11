#pragma once
#include "Vetor2D.h"
#include "Colidivel.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "../Json/json.hpp"
#include <math.h>

/*
    Classe responsável pelos personagens jogáveis, atribuí características base como a velocidade, altitude do
    pulo, vidas, gravidade e pontuação.
*/

namespace InvasaoAlienigena {
    namespace Desenhaveis {
        class Jogador : public Colidivel
        {
        protected:
            float vel_x;
            float vel_y;
            float alt_pulo;
            float velmax_y;
            int vidas;
            int pontuacao;
            bool taPulando;
            unsigned int chaveOuvinte; //identifica interação via teclado
            sf::Clock clock;
            sf::Time elapsed;

        public:
            Jogador(Vetor::Vetor2F pos = { 0.0f , 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
            ~Jogador();
            void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
            void atualizar(float t); //atualiza posição dos jogadores
            void desenhar(Gerenciador::GerenciadorGrafico& g);
            void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro); //verifica colisão dos jogadores com o mapa, bem como inimigos e projétil
        };
    }
        
}

