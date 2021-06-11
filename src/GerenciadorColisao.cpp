#include "GerenciadorColisao.h"
#include "Colidivel.h"
#include "Vetor2D.h"
#include <math.h>
#include <iostream>

namespace InvasaoAlienigena {
    namespace Gerenciador {
        GerenciadorColisoes::GerenciadorColisoes() : gt{ nullptr } {

        }

        GerenciadorColisoes::~GerenciadorColisoes() {

        }

        bool GerenciadorColisoes::estaoColidindo(Colidivel* p1, Colidivel* p2) {

            Vetor::Vetor2F posicao1 = p1->getPosicao();
            Vetor::Vetor2F dimensoes1 = p1->getDimensoes();

            Vetor::Vetor2F posicao2 = p2->getPosicao();
            Vetor::Vetor2F dimensoes2 = p2->getDimensoes();

            Vetor::Vetor2F distancia = posicao1 - posicao2;

            if (p1 == p2) return false;

            return (fabs(distancia.x) < (dimensoes1.x + dimensoes2.x) / 2.) && (fabs(distancia.y) < (dimensoes1.y + dimensoes2.y) / 2.);


        }

        void GerenciadorColisoes::adicionarColidivel(Colidivel* p) {
            colidiveis.insert(p);
        }

        void GerenciadorColisoes::removerColidivel(Colidivel* p) {
            colidiveis.erase(p);
        }

        void GerenciadorColisoes::removerTodos() {
            colidiveis.clear();
        }

        void GerenciadorColisoes::verificarColisoes() {

            for (auto primeiro = colidiveis.begin(); primeiro != colidiveis.end(); primeiro++) {

                Colidivel* p1 = *primeiro;

                auto tilesColidindo = gt->checarColisoes(p1->getId(), p1->getPosicao(), p1->getDimensoes());

                for (auto colisao : tilesColidindo)
                    p1->colidir(colisao.id, colisao.posicao, colisao.tamanho);

                auto segundo = primeiro;
                segundo++;

                for (; segundo != colidiveis.end(); segundo++) {
                    Colidivel* p2 = *segundo;

                    if (estaoColidindo(p1, p2)) {
                        p1->colidir(p2->getId(), p2->getPosicao(), p2->getDimensoes());
                        p2->colidir(p1->getId(), p1->getPosicao(), p1->getDimensoes());

                    }
                }

            }
        }

        void GerenciadorColisoes::setGerenciadorTiles(Gerenciador::GerenciadorTiles* Gt) {
            gt = Gt;
        }
    }
}