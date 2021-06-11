#include "MenuPrincipal.h"
#include "GerenciadorTelas.h"
#include <iostream>

namespace InvasaoAlienigena {
    namespace Menu {
        MenuPrincipal::MenuPrincipal(Gerenciador::GerenciadorGrafico& GG) : Menu(GG), imprimiu{ false },
            campoTexto{ ge, 15, {200.0f, 50.0f}, {200, 40} } {
            gb.adicionarBotao(new Botao({ 100.0f, 100.0f }, { 100, 40 }, "Jogar", [this] {setCodigoRetorno(selecionarJogador); }));
            gb.adicionarBotao(new Botao({ 100.0f, 200.0f }, { 100, 40 }, "Classificacao", [this] {setCodigoRetorno(classificacao); }));
            gb.adicionarBotao(new Botao({ 300.0f, 100.0f }, { 100, 40 }, "Carregar jogo", [this] {setCodigoRetorno(carregarJogo); }));
            gb.adicionarBotao(new Botao({ 300.0f, 200.0f }, { 100, 40 }, "Sair do jogo", [this] {setCodigoRetorno(terminarJogo); }));
        }
        
        int MenuPrincipal::executar() {
            
            int ret = Menu::executar();
            gg.desenharTexto("INVASÃO ALIENIGENA", { 200.0f, 50.0f }, 17);
            
            return ret;
        }
        
    }
}