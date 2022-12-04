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
    class Atiradino : public Inimigo {
    public:
        explicit Atiradino(Plataforma *p = nullptr);

        ~Atiradino() override;

        void executar() override;

        void imprimir() override;

        virtual void atirar();

        Projetil *getProjetil() { return hitbox; }

        void setVidas(const int v) override { vidas = v; }

    private:
        int vidas_inimigo;
    };
}

