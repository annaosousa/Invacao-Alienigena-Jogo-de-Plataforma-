#include "Manicomio.h"
#include "Caixote.h"
#include "LagartoVerde.h"
#include "Robotao.h"
#include "Ciclope.h"
#include "BuracoInfinito.h"

namespace InvasaoAlienigena {
    namespace Fase {
        Manicomio::Manicomio(Gerenciador::GerenciadorGrafico& gg, Desenhaveis::Kahlo* jogador1, Desenhaveis::Frida* jogador2) : Fase{ gg,
        new Gerenciador::GerenciadorTiles{
         {
             new Tile::Tile(Ids::armadilha_direita, "../imagens/armadilha_direita.png"),
             new Tile::Tile(Ids::armadilha_esquerda,"../imagens/armadilha_esquerda.png"),
             new Tile::Tile(Ids::espinho,"../imagens/espinho.png"),
             new Tile::Tile(Ids::espinho_direita,"../imagens/espinho_direita.png"),
             new Tile::Tile(Ids::espinho_esquerda,"../imagens/espinho_esquerda.png"),
             new Tile::Tile(Ids::teste_fundo2,"../imagens/teste_fundo2.png"),
             new Tile::Tile(Ids::parede_up, "../imagens/parede_up.png"),
             new Tile::Tile(Ids::parede, "../imagens/parede.png"),
             new Tile::Tile(Ids::espinho_fundo,"../imagens/espinho_fundo2.png"),
             new Tile::Tile(Ids::esquerda2,"../imagens/esquerda2.png"),
             new Tile::Tile(Ids::fundo,"../imagens/fundo.png"),
             new Tile::Tile(Ids::fundo1,"../imagens/fundo1.png"),
             new Tile::Tile(Ids::parede_clara,"../imagens/parede_clara.png"),
             new Tile::Tile(Ids::parede_up,"../imagens/parede_clara.png"),
             new Tile::Tile(Ids::porta,"../imagens/porta.png"),
             new Tile::Tile(Ids::teste_fundo,"../imagens/teste_fundo.png"),
             new Tile::Tile(Ids::espinho_fundo,"../imagens/espinho_fundo.png"),
             new Tile::Tile(Ids::teste_chama,"../imagens/teste_chama.png"),
             new Tile::Tile(Ids::teste_fundo2,"../imagens/teste_fundo2.png"),
             new Tile::Tile(Ids::espinho_fundo2,"../imagens/espinho_fundo2.png"),
             new Tile::Tile(Ids::esquerda2,"../imagens/esquerda2.png"),
            },
            {32.0f, 32.0f}, "../TileMap/TileMap.json"
          }
          , jogador1, jogador2 } {

        }

        nlohmann::json Manicomio::paraJSON() {
            nlohmann::json json;

            json["amigos"] = listaAmigos.paraJSON();

            return json;

        }

        void Manicomio::carregar(const std::string& caminho) {
            std::ifstream arquivo(caminho);

            if (arquivo.fail()) throw "arquivo nao encontrado!";
            nlohmann::json j;
            arquivo >> j;

            for (nlohmann::json amigo : j["amigos"]) {
                switch (static_cast<int> (amigo["id"]))
                {
                case Ids::kahlo:
                        jogador1->inicializarComJSON(amigo);
                        listaAmigos.inserir(jogador1);
                    break;
                case Ids::frida:
                        jogador2->inicializarComJSON(amigo);
                        listaAmigos.inserir(jogador2);
                case Ids::robotao:
                    listaAmigos.inserir(new Desenhaveis::Robotao(amigo));
                    break;
                case Ids::lagartoVerde:
                    listaAmigos.inserir(new Desenhaveis::LagartoVerde(amigo));
                    break;
                default:
                    break;
                }
            }

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
        }

        void Manicomio::inicializar() {
            srand(time(NULL));
            
            //Jogadores
            listaAmigos.inserir(new Desenhaveis::Kahlo(Vetor::Vetor2F(70.0f, 120.0f)));
            
            if (jogador2) 
                listaAmigos.inserir(new Desenhaveis::Frida(Vetor::Vetor2F(110.0f, 120.0f)));

            //Inserção do obstáculo Caixote na presente fase
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(180.0f, 130.0f), Vetor::Vetor2F(0, 10)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(205.0f, 305.0f), Vetor::Vetor2F(0, 10)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(305.0f, 580.0f), Vetor::Vetor2F(0, 10)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(725.0f, 715.0f), Vetor::Vetor2F(0, 10)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(200.0f, 515.0f), Vetor::Vetor2F(0, 10)));

            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(250.0f, 100.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(300.0f, 180.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(550.0f, 300.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(250.0f, 450.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(700.0f, 550.0f), Vetor::Vetor2F(10, 10)));

            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(240.0f, 207.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(420.0f, 250.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(180.0f, 440.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(770.0f, 130.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(730.0f, 600.0f), Vetor::Vetor2F(15, 0), this));

            for (int i = 0; i < 15; i++) {
                listaAmigos.inserir(new Coletavel(Vetor::Vetor2F(100 + rand() % 800, 50 + rand() % 600)));
            }

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

        }
    }
}