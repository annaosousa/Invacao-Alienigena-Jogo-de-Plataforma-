#pragma once
#include "../Json/json.hpp"

/*
    Classe abstrata utilizada na tentativa de salvar a jogada.
*/

namespace InvasaoAlienigena {
    class Serializavel {
    public:
        virtual ~Serializavel();
        virtual nlohmann::json paraJSON() = 0;
    };
}
