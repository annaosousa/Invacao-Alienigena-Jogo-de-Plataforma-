#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Vetor2D.h"
#include "Cor.h"

/*
    Controla o que vai ser apresentado ao usuário em tela, renderizando a janela, centralizando a câmera no jogador
    mapeia e carrega a textura. Auxilia na parte do Menu desenhando os retângulos e estipulando o texto que é apresentado.
*/

namespace InvasaoAlienigena {
    namespace Gerenciador {
        class GerenciadorGrafico {
        private:
            sf::RenderWindow* janela;
            sf::View camera;
            std::map<const std::string, sf::Texture*> texturas;
            sf::Texture* text;
            sf::Sprite sprite;
            sf::Font fonte;

        public:
            GerenciadorGrafico();
            ~GerenciadorGrafico();
            void mostrar() const; //exibe na tela o que foi renderizado
            void limpar(int r = 0, int g = 0, int b = 0); //limpa toda a tela com uma única cor
            void desenhar(const std::string& caminho, const Vetor::Vetor2F posicao); //desenha imagens
            void desenhar(const std::string& caminho, const Vetor::Vetor2F posicao, const Vetor::Vetor2U numeroFrames, const Vetor::Vetor2U frame); //desenha frames
            bool carregarTextura(const std::string& caminho);
            void centralizar(const Vetor::Vetor2F centro);
            const Vetor::Vetor2F getTamanhoTela() const;
            sf::RenderWindow* getJanela() const;
            const Vetor::Vetor2F getTamanho(const std::string& caminho) const;
            void desenharRetanguloSolido(const Vetor::Vetor2F centro, const Vetor::Vetor2F dimensao, const Cor cor) const; //desenha a estrutura dos botões
            void desenharTexto(const std::string texto, const Vetor::Vetor2F posicao, unsigned int tamanho, const bool centralizar = true) const; //desenha fonte
            Vetor::Vetor2F getPosicaoMouse() const;
        };
    }
}

