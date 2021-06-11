#pragma once
#include "Desenhavel.h"
#include "Ids.h"
#include "Vetor2D.h"

/*
    Def: Faz a rela��o entre as classes jogadores e inimigos com a classe dos Desenh�veis, al�m de definir o m�todo
         virtual colidir que � utilizada em todas as classes derivadas de desenhaveis.
*/

namespace InvasaoAlienigena {

    class Colidivel : public Desenhavel {
    public:
        Colidivel(Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, Ids::Ids ID = Ids::semID, const char* caminhoTextura = nullptr);
        virtual void colidir(Ids::Ids idOutro, Vetor::Vetor2F posicaoOutro, Vetor::Vetor2F dimensoesOutro) = 0;
    };
}