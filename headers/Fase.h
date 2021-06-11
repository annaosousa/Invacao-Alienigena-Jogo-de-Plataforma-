#pragma once
#include "Estado.h"
#include "Salvavel.h"

/*Gerenciadores*/
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "GerenciadorTile.h"
#include "GerenciadorTelas.h"

/*Renderizar*/
#include "ListaDesenhaveis.h"
#include "Desenhavel.h"
#include "Tile.h"

#include "Relogio.h"
#include "../Json/json.hpp"

/*Ambientação e personagens
    ----Jogadores----    */
#include "Kahlo.h"
#include "Frida.h"
    /*    ----Vilões----     */
#include "LagartoVerde.h"
#include "Robotao.h"
/*   ----Obstáculo----    */
#include "BuracoInfinito.h"
#include "Caixote.h"
/*   ----Objetos----      */
#include "Coletavel.h"
#include "Projetil.h"

/*
    Classe utilizada como polimorfismo para os estágios do jogo, guarda a lista de desenhaveis responsável por
    imprimir os personagens em cada fase, monitora o tempo de execução do estágio para atualizações de movimento e
    tambem aguarda o ouvinte do teclado para chamar o menu pause ou fechar o jogo em tempo de execução do estágio.
*/

namespace InvasaoAlienigena {
    namespace Fase {
        class Fase : public Estado, public Salvavel {
        protected:
            Gerenciador::GerenciadorGrafico& gerenciadorGrafico;
            Desenhaveis::Kahlo* jogador1;
            Desenhaveis::Frida* jogador2;
            Gerenciador::GerenciadorEventos gerenciadorEventos;
            Gerenciador::GerenciadorColisoes gerenciadorColisoes;
            Gerenciador::GerenciadorTiles* gerenciadorTiles;
            Entidades::Relogio relogio; 
            bool continuarFase;
            int codigoRetorno;
            void setCodigoRetorno(int codigo);

        public:
            Fase(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorTiles* gt, Desenhaveis::Kahlo* jogador1 = nullptr, Desenhaveis::Frida* jogador2 = nullptr);
            //Construtor sem parâmetros não é necessário pois ele não existe em classes com atributos que são referências
            ~Fase();
            int executar() override;
            virtual void inicializar() = 0;
            void inserirProjetil(Projetil::Projetil* projetil); //insere projétil na fase
            Lista::ListaDesenhaveis listaAmigos;

        private:
            unsigned int IdOuvinteFecharTela; //capta interações relacionado ao fechamento da tela
            unsigned int IdOuvinteEntrarMenu; //capta interações via teclado
            void botaoFecharTelaApertado(const sf::Event evento);
            void botaoEntrarMenuApertado(const sf::Event evento);
            void initFont();
            int pontos; //contabiliza os pontos do jogador
            sf::Font font;
            sf::Text texto;
        };
    }
}
