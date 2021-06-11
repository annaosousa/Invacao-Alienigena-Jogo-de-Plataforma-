#pragma once
#include "Tile.h"
#include "TileMap.h"
#include "Vetor2D.h"
#include "Ids.h"
#include <vector>

/*
    Controla a localização, dimensão, caminhos e ids dos tiles a serem impressos em tela.
*/

namespace InvasaoAlienigena {
    namespace Gerenciador {
        class GerenciadorEventos;
        class GerenciadorGrafico;
        class GerenciadorColisao;

        class GerenciadorTiles {
        public:
            typedef struct idpostam {
                const Ids::Ids id;
                const Vetor::Vetor2F posicao;
                const Vetor::Vetor2F tamanho;
            } IdPosicaoTamanho;

        private:
            std::vector<Tile::Tile*> tiles;
            Vetor::Vetor2F dimensoesTiles;
            const char* caminho; //caminho das imagens utilizadas
            Tile::TileMap tileMap;

        public:
            GerenciadorTiles(std::vector<Tile::Tile*> Tiles = {}, Vetor::Vetor2F dimensoes = { 0.0f, 0.0f }, const char* caminhoArquivo = nullptr);
            ~GerenciadorTiles();
            void inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge);
            void desenhar(GerenciadorGrafico& g) const; //desenha o mapa
            std::vector<IdPosicaoTamanho> checarColisoes(const Ids::Ids id, Vetor::Vetor2F posicao, Vetor::Vetor2F tamanho);//verifica se a colisão ocorreu dentro do mapa

        private:
            const Vetor::Vetor2F converterCoordenadasMapaParaTela(const Vetor::Vetor2U pos) const;
        };
        using IdPosicaoTamanho = GerenciadorTiles::IdPosicaoTamanho;
    }
}
