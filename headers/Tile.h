#pragma once
#include "Vetor2D.h"
#include "Ids.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

/*
    Classe abstrata utilizada para definir a base dos tiles passando a textura, o caminho , o id e o tamanho do tile.
*/

namespace InvasaoAlienigena {
    namespace Tile {
        class Tile {
        private:
            const Ids::Ids id;
            const char* caminho; // caminho das imagens do TileMap utilizado
            Vetor::Vetor2F tamanho;

        public:
            Tile(const Ids::Ids ID = Ids::semID, const char* caminhoArquivo = nullptr, Vetor::Vetor2F Tamanho = { 32.0f, 32.0f });
            virtual ~Tile();
            virtual void inicializar(Gerenciador::GerenciadorGrafico& gg, Gerenciador::GerenciadorEventos& ge);
            void desenhar(Gerenciador::GerenciadorGrafico& gg, const Vetor::Vetor2F posicao) const;
            const Ids::Ids getId() const;
            virtual void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2U posicao);

        };
    }
}
