#pragma once

#include "stdafx.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "Plataforma.h"
#include "Corpo_Grafico.h"
#include "Animadora.h"

using namespace Auxiliares;
using namespace GerenciadoresEntidades;

namespace Inimigos {
    class ChefeDino : public Inimigo {
    public:
        explicit ChefeDino(Plataforma *p);

        ~ChefeDino() override;

        void executar() override;

        void mover() override;

        void imprimir() override;

        Projetil *getProjetil() { return hitbox; }

    private:
        float pulo;
    };
}

