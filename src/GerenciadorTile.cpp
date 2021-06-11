#include "GerenciadorTile.h"

namespace InvasaoAlienigena {
    namespace Gerenciador {
        
        GerenciadorTiles::GerenciadorTiles(std::vector<Tile::Tile*> Tiles, Vetor::Vetor2F dimensoes, const char* caminhoArquivo) : tiles{ Tiles },
            dimensoesTiles{ dimensoes },
            caminho{ caminhoArquivo },
            tileMap{ caminhoArquivo }
        {

        }

        GerenciadorTiles::~GerenciadorTiles() {
            for (Tile::Tile* t : tiles)
                delete t;
        }


        void GerenciadorTiles::inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge) {
            for (Tile::Tile* t : tiles)
                t->inicializar(gg, ge);
        }

        void GerenciadorTiles::desenhar(GerenciadorGrafico& gg) const {
            for (unsigned int i = 0; i < dimensoesTiles.y; ++i) {
                for (unsigned int j = 0; j < dimensoesTiles.x; ++j) {
                    short indice = tileMap[i][j] - 1;
                    if (indice >= 0 && indice < (long)tiles.size()) tiles[indice]->desenhar(gg, converterCoordenadasMapaParaTela(Vetor::Vetor2U{ j, i }));
                }
            }

        }

        std::vector<IdPosicaoTamanho> GerenciadorTiles::checarColisoes(const Ids::Ids id, Vetor::Vetor2F posicao, Vetor::Vetor2F tamanho) {
            int cima = (int)floor((posicao.y - tamanho.y / 2) / dimensoesTiles.y);
            int baixo = (int)ceil((posicao.y + tamanho.y / 2) / dimensoesTiles.y);
            int esquerda = (int)floor((posicao.x - tamanho.x / 2) / dimensoesTiles.x);
            int direita = (int)ceil((posicao.x + tamanho.x / 2) / dimensoesTiles.x);

            std::vector<IdPosicaoTamanho> colisoes;

            //objeto parcialmente fora do mapa: � ignorado.
            if (cima < 0 || esquerda < 0 || baixo >= (int)tileMap.getDimensoesMapa().y || esquerda >= (int)tileMap.getDimensoesMapa().x) return colisoes;



            for (int i = cima; i < baixo; ++i)
                for (int j = esquerda; j < direita; ++j) {

                    short indice = tileMap[i][j] - 1; // o -1 � um offset, pois 0 no formato do tilemap indica a falta de um tile e n�o o tile no �ndice 0
                    if (0 <= indice && indice < (long)tiles.size()) {
                        Tile::Tile* t = tiles[indice];

                        t->colidir(id, posicao, { (unsigned int)j, (unsigned int)i });

                        colisoes.push_back({ t->getId(), converterCoordenadasMapaParaTela({(unsigned int)j, (unsigned int)i}) , dimensoesTiles });

                    }
                }
            return colisoes;
        }

        const Vetor::Vetor2F GerenciadorTiles::converterCoordenadasMapaParaTela(const Vetor::Vetor2U pos) const {
            return dimensoesTiles.operator*(0.5f) + Vetor::Vetor2F(dimensoesTiles.x * pos.x, dimensoesTiles.y * pos.y);
        }
    }
}