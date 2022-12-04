#pragma once

#include "stdafx.h"
#include "Obstaculo.h"
#include "Plataforma.h"

using namespace Obstaculos;
using namespace Auxiliares;

namespace Obstaculos {
    class Pedra : public Obstaculo {
    public:
        explicit Pedra(Plataforma *plat);

        ~Pedra() override;

        void executar() override;

    private:
        float dificuldade_empurrar;
    };
}


