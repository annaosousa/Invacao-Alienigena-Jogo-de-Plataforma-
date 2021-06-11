#include "GerenciadorGrafico.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Gerenciador {
        GerenciadorGrafico::GerenciadorGrafico() :
            janela{ new sf::RenderWindow(sf::VideoMode(800, 600), "Game") },
            camera{ sf::Vector2f(400, 300), sf::Vector2f(400,300) },
            text{ nullptr }
        {
            janela->setView(camera);

            try {
                fonte.loadFromFile("CantoraOne-Regular.ttf");
            }
            catch(int erro) {
                std::cout << "Erro, fonte nao carregada" << std::endl;
                exit(0);
            }
        }

        GerenciadorGrafico::~GerenciadorGrafico() {
            delete janela;

            for (auto i : texturas) {
                delete i.second;
            }
        }

        void GerenciadorGrafico::mostrar() const {
            janela->display();
        }

        void GerenciadorGrafico::limpar(int r, int g, int b) {
            janela->clear(sf::Color(r, g, b));
        }

        void GerenciadorGrafico::desenhar(const std::string& caminho, const Vetor::Vetor2F posicao) {

            if (texturas.count(caminho) == 0) {
                std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
                exit(121);
            }

            text = texturas[caminho];

            sprite.setTexture(*text, true);
            sprite.setOrigin(text->getSize().x * 0.5, text->getSize().x * 0.5);
            sprite.setPosition(posicao.x, posicao.y);

            janela->draw(sprite);
        }

        void GerenciadorGrafico::desenhar(const std::string& caminho, const Vetor::Vetor2F posicao, const Vetor::Vetor2U numeroFrames, const Vetor::Vetor2U frame) {

            if (texturas.count(caminho) == 0) {
                std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
                exit(121);
            }

            text = texturas[caminho];

            sprite.setTexture(*text);

            sf::Vector2i tamanho = { (int)text->getSize().x / (int)numeroFrames.y, (int)text->getSize().y / (int)numeroFrames.x };
            sf::Vector2i posicaoFrame = { (int)tamanho.x * (int)frame.y, (int)tamanho.y * (int)frame.x };

            sprite.setTextureRect({ posicaoFrame, tamanho });

            sprite.setOrigin({ tamanho.x * 0.5f, tamanho.y * 0.5f });
            sprite.setPosition(posicao.x, posicao.y);

            janela->draw(sprite);
        }

        bool GerenciadorGrafico::carregarTextura(const std::string& caminho) {
            if (texturas.count(caminho) == 1) return true;
            else {


                sf::Texture* text = new sf::Texture();
                if (!text->loadFromFile(caminho)) {
                    std::cout << "Atencao! imagem em " << caminho << "nao encontrada!" << std::endl;
                    exit(120);
                }

                //texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
                texturas.emplace(caminho, text); //c++11
                return true;
            }
        }

        /*bool GerenciadorGrafico::carregarTextura(const std::string& caminho) {
            try {
                sf::Texture* text = new sf::Texture();
                if (!text->loadFromFile(caminho)) {
                    std::cout << "Atencao! imagem em " << caminho << "nao encontrada!" << std::endl;
                    throw "deu ruim";
                        
                }
            }
            catch (const char* e) {

                if (texturas.count(caminho) == 1) return true;
            }

            //texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
            texturas.emplace(caminho, text); //c++11
            return true;
            
            }
        }*/

        void GerenciadorGrafico::centralizar(const Vetor::Vetor2F centro) {
            camera.setCenter(sf::Vector2f(centro.x, centro.y));
            janela->setView(camera); //A RenderWindow faz uma c�pia da View ao inv�s de usar o ponteiro, ent�o � preciso a sobre-escrever sempre que for modificada.
        }

        const Vetor::Vetor2F GerenciadorGrafico::getTamanhoTela() const {
            return { camera.getSize().x, camera.getSize().y };
        }

        sf::RenderWindow* GerenciadorGrafico::getJanela() const {
            return janela;
        }

        const Vetor::Vetor2F GerenciadorGrafico::getTamanho(const std::string& caminho) const {

            if (texturas.count(caminho) == 0) {
                std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
                exit(121);
            }

            sf::Vector2u dimensoes = (texturas.at(caminho))->getSize();

            return Vetor::Vetor2F(dimensoes.x, dimensoes.y);
        }

        void GerenciadorGrafico::desenharRetanguloSolido(const Vetor::Vetor2F centro, const Vetor::Vetor2F dimensao, const Cor cor) const {
            sf::RectangleShape retangulo = sf::RectangleShape({ dimensao.x, dimensao.y });
            retangulo.setFillColor({ cor.r, cor.g, cor.b, cor.a });
            retangulo.setOrigin(dimensao.x / 2, dimensao.y / 2);
            retangulo.setPosition(centro.x, centro.y);
            janela->draw(retangulo);
        }

        void GerenciadorGrafico::desenharTexto(const std::string texto, const Vetor::Vetor2F posicao, unsigned int tamanho, const bool centralizar/* = true*/) const {
            sf::Text txt = sf::Text(texto, fonte, tamanho);
            txt.setFillColor(sf::Color::White);
            if (centralizar) {
                sf::FloatRect tam = txt.getGlobalBounds();
                txt.setOrigin(tam.width / 2, tam.height / 2);
            }
            txt.setPosition(posicao.x, posicao.y);
            janela->draw(txt);
        }

        Vetor::Vetor2F GerenciadorGrafico::getPosicaoMouse() const {
            sf::Vector2i posRelacaoJanela = sf::Mouse::getPosition(*janela);
            sf::Vector2u tamanhoJanela = janela->getSize();
            sf::Vector2f tamanhoCamera = camera.getSize();
            sf::Vector2f posicaoCamera = camera.getCenter() - tamanhoCamera / 2.0f;

            return {
              (posRelacaoJanela.x / (float)tamanhoJanela.x) * tamanhoCamera.x + posicaoCamera.x,
              (posRelacaoJanela.y / (float)tamanhoJanela.y) * tamanhoCamera.y + posicaoCamera.y
            };

        }
    }
}