#include "Hospital.h"
#include "Ciclope.h"
#include "Caixote.h"
#include "BuracoInfinito.h"
#include "LagartoVerde.h"
#include "Robotao.h"
#include <fstream>

namespace InvasaoAlienigena {
    namespace Fase {
        Hospital::Hospital(Gerenciador::GerenciadorGrafico& gg, Desenhaveis::Kahlo* jogador1, Desenhaveis::Frida* jogador2) : Fase{ gg,
        new Gerenciador::GerenciadorTiles{
        {
            new Tile::Tile(Ids::armadilha_direita, "../imagens/armadilha_direita.png"),
            new Tile::Tile(Ids::armadilha_esquerda,"../imagens/armadilha_esquerda.png"),
            new Tile::Tile(Ids::espinho,"../imagens/espinho.png"),
            new Tile::Tile(Ids::espinho_direita,"../imagens/espinho_direita.png"),
            new Tile::Tile(Ids::espinho_esquerda,"../imagens/espinho_esquerda.png"),
            new Tile::Tile(Ids::teste_fundo2,"../imagens/teste_fundo2.png"),
            new Tile::Tile(Ids::espinho_fundo,"../imagens/espinho_fundo2.png"),
            new Tile::Tile(Ids::esquerda2,"../imagens/esquerda2.png"),
            new Tile::Tile(Ids::fundo,"../imagens/fundo.png"),
            new Tile::Tile(Ids::fundo1,"../imagens/fundo1.png"),
            new Tile::Tile(Ids::parede, "../imagens/parede.png"),
            new Tile::Tile(Ids::parede_clara,"../imagens/parede_clara.png"),
            new Tile::Tile(Ids::parede_up,"../imagens/parede_clara.png"),
            new Tile::Tile(Ids::porta,"../imagens/porta.png"),
            new Tile::Tile(Ids::prisao,"../imagens/prisao.png"),
            new Tile::Tile(Ids::teste,"../imagens/teste.png"),
            new Tile::Tile(Ids::teste_fundo,"../imagens/teste_fundo.png"),
            new Tile::Tile(Ids::espinho_fundo,"../imagens/espinho_fundo.png"),
            },
             {32.0f, 32.0f}, "../TileMap/tilemapJogo.json"
           }
           , jogador1, jogador2 } {

        }

        nlohmann::json Hospital::paraJSON() {
            nlohmann::json json;

            json["amigos"] = listaAmigos.paraJSON();

            return json;

        }

        void Hospital::carregar(const std::string& caminho) {
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
                    break;
                case Ids::robotao:
                    listaAmigos.inserir(new Desenhaveis::Robotao(amigo));
                    break;
                case Ids::ciclope:
                    listaAmigos.inserir(new Desenhaveis::LagartoVerde(amigo));
                    break;
                case Ids::lagartoVerde:
                    listaAmigos.inserir(new Desenhaveis::Ciclope(amigo));
                    break;
                default:
                    break;
                }
            }

            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
        }

        void Hospital::inicializar() {

            //Inserção do obstaculo: Buraco Infinito, o qual leva o jogador ao início da fase presente
            listaAmigos.inserir(new Obstaculo::BuracoInfinito(Vetor::Vetor2F(700.0f, 260.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::BuracoInfinito(Vetor::Vetor2F(750.0f, 210.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::BuracoInfinito(Vetor::Vetor2F(550.0f, 270.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::BuracoInfinito(Vetor::Vetor2F(560.0f, 590.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::BuracoInfinito(Vetor::Vetor2F(850.0f, 380.0f), Vetor::Vetor2F(0, 0)));
            
            listaAmigos.inserir(new Desenhaveis::Kahlo(Vetor::Vetor2F(250.0f, 150.0f)));
            
            if (jogador2)
                listaAmigos.inserir(new Desenhaveis::Frida(Vetor::Vetor2F(280.0f, 150.0f)));
            //x,y//
            
            //Inserção do obstáculo Caixote
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(420.0f, 150.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(620.0f, 350.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(300.0f, 370.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(730.0f, 450.0f), Vetor::Vetor2F(0, 0)));
            listaAmigos.inserir(new Obstaculo::Caixote(Vetor::Vetor2F(850.0f, 115.0f), Vetor::Vetor2F(0, 0)));

            //Inserção dos inimigos
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(390.0f, 100.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(750.0f, 350.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(550.0f, 310.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(420.0f, 550.0f), Vetor::Vetor2F(10, 10)));
            listaAmigos.inserir(new Desenhaveis::LagartoVerde(Vetor::Vetor2F(550.0f, 640.0f), Vetor::Vetor2F(10, 10)));

            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(750.0f, 350.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(240.0f, 650.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(680.0f, 200.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(710.0f, 390.0f), Vetor::Vetor2F(15, 0), this));
            listaAmigos.inserir(new Desenhaveis::Robotao(Vetor::Vetor2F(345.0f, 640.0f), Vetor::Vetor2F(15, 0), this));
            
            //Inserção do Chefão
            listaAmigos.inserir(new Desenhaveis::Ciclope(Vetor::Vetor2F(970.0f, 640.0f), Vetor::Vetor2F(20, 10)));

            //Coletaveis
            for (int i = 0; i < 15; i++) {
                listaAmigos.inserir(new Coletavel(Vetor::Vetor2F(100 + rand() % 800, 50 + rand() % 600)));
            }
            
            listaAmigos.inicializarDesenhaveis(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);

        }
    }
}