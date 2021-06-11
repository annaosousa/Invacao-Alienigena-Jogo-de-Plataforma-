#pragma once
#include "Serializavel.h"

/*
    Classe criada na tentativa de efetuar o salvamento de jogada e nome da classificação.
*/

namespace InvasaoAlienigena {
    class Salvavel : public Serializavel {
    public:
        virtual ~Salvavel();
        bool salvar(const std::string& caminho);
        virtual void carregar(const std::string& caminho) = 0;
    };
}
