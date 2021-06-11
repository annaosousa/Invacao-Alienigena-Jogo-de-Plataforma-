#pragma once

/*
Def: Classe utilizada para definir a colora��o dos bot�es do Menu e utiliza o padr�o RGBA.
*/

namespace InvasaoAlienigena {
    class Cor {
    public:

        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

        Cor(unsigned char R = 0, unsigned char G = 0, unsigned char B = 0, unsigned char A = 255);
    };
}
/*Cores definidas pelo padr�o RGBA(): red-green-blue-alpha, sendo o alpha o especificador de opacidade da cor*/

