#pragma once

#include "stdafx.h"
#include "Obstaculo.h"
#include "Corpo_Grafico.h"

using namespace GerenciadoresEntidades;

namespace Obstaculos {
    class Espinho : public Obstaculo {
    public:
        explicit Espinho(Gerenciador_Grafico *g);

        ~Espinho() override;

    private:
        bool danoso;
    };
}


