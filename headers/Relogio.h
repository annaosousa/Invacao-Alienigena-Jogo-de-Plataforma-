#pragma once
#include <time.h>

/*
    Classe utilizada para inst�nciar o rel�gio da biblioteca SFML.
*/

namespace InvasaoAlienigena {
    namespace Entidades {
        class Relogio {
        private:
            clock_t ultimo;
            clock_t atual;
            double dt;
            bool pausado;

        public:
            Relogio();
            ~Relogio();
            double getTempo();
            void reiniciar();
            void pausar();


        };
    }
}

