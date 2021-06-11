#pragma once
#include "Botao.h"
#include "PromessaTexto.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "Vetor2D.h"
#include "Cor.h"

#include <string>

/*
    Requisito primeiramente planejado para efetuar o salvamento do nome para a classificação, infelizmente
    não houve tempo de terminar a estrutura de classificação.
*/

namespace InvasaoAlienigena {
    namespace Menu {
        class CampoTexto : public Botao {

        private:
            PromessaTexto promessa; //texto capturado

        public:
            CampoTexto(Gerenciador::GerenciadorEventos& ge, unsigned short comprimentoMaximo, Vetor::Vetor2F Posicao = { 0.0f, 0.0f }, Vetor::Vetor2F Tamanho = { 0.0f, 0.0f }, unsigned int tamTexto = 15U, Cor c = { 128, 128, 128 });
            ~CampoTexto();
            const std::string& getTexto() const;
            bool getTextoPronto() const;
            void desenhar(Gerenciador::GerenciadorGrafico& gg) const override; //desenha retângulo, o qual é o espaço que contém a string bem como o texto
            void iniciarCaptura();
            void terminarCaptura();
            void Score(const int score, const std::string nome);

        };
    }
}