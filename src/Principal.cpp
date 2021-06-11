#include "Principal.h"
#include "Kahlo.h"
#include "Robotao.h"
#include "Tile.h"
#include <iostream>

namespace InvasaoAlienigena {

    Principal::Principal() :
        jogador1{ Desenhaveis::Kahlo(Vetor::Vetor2F(20.0f, 20.0f)) },
        jogador2{ Desenhaveis::Frida(Vetor::Vetor2F(20.0f, 20.0f)) },
        gerenciadorTelas{ gerenciadorGrafico, &jogador1, &jogador2 },
        terminar{ false }
    {

    }

    Principal::~Principal() {

    }

    int Principal::executar() {
        while (!terminar) {

            gerenciadorGrafico.limpar();
            terminar = gerenciadorTelas.executar();
            gerenciadorGrafico.mostrar();
        }
        return 0;
    }

}