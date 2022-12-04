#include "Entidade.h"
#include "Plataforma.h"

using namespace Abstratas;

Entidade::Entidade(Gerenciador_Grafico *g) :
        empurrao(1.0f), noChao(true), podeMatar(true), podeMorrer(true), morto(false), movimento(0.0f, 0.0f) {
    id = -1;
    vidas = 10;
    plat = nullptr;
    pGG = g;
}

Entidade::~Entidade() = default;

void Entidade::imprimir() {
    pGG->desenhar(corpo.getCorpo());
}

bool Entidade::tomarDano() {
    vidas--;
    if (vidas < 0)
        return true;
    return false;
}
