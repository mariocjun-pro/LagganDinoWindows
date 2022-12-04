#include "Jogo.h"

using namespace Controladoras;

int main() {
    Jogo *jogo;
    jogo = Jogo::CriarJogo();

    jogo->executar();
    return 0;
}