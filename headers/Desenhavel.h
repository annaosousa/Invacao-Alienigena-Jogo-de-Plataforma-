#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "Ids.h"
#include "Serializavel.h"
#include <math.h>

/*
    Def: Classe abstrata utilizada como base para renderização dos objetos e personagens, além de iniciazação
         é responsável por obter a posição, as dimensões e intercessões dos elementos desenhados, e também
         ler o caminho da imagem a ser desenhada.
*/

namespace InvasaoAlienigena {
    class Desenhavel : public Serializavel {
    protected:
        Vetor::Vetor2F intercessao; //auxilia na verificãção da colisão
        Vetor::Vetor2F posicao;
        Vetor::Vetor2F v; //velocidade
        Vetor::Vetor2F dimensoes;
        const char* caminho; //caminho das imagens a serem executadas
        Ids::Ids id;
        float gravidade;

    public:

        Desenhavel(Ids::Ids ID = Ids::semID, Vetor::Vetor2F pos = { 0.0f, 0.0f }, Vetor::Vetor2F vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
        virtual ~Desenhavel();
        virtual void inicializar(Gerenciador::GerenciadorGrafico& gf, Gerenciador::GerenciadorEventos& ge, Gerenciador::GerenciadorColisoes& gc);
        virtual void atualizar(float t);
        virtual void desenhar(Gerenciador::GerenciadorGrafico& g);
        const Vetor::Vetor2F getPosicao() const;
        const Vetor::Vetor2F getDimensoes() const;
        const Vetor::Vetor2F getIntercessao() const;
        const Ids::Ids getId() const;
        nlohmann::json paraJSON() override; //id, velocidade, caminho, posição e dimensão são passadas ao json
    };
}
