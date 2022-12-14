#pragma once

#include "stdafx.h"
#include "Obstaculo.h"
#include "Plataforma.h"

using namespace Auxiliares;
using namespace Obstaculos;

namespace Obstaculos {
    class Galho : public Obstaculo {
    public:
        explicit Galho(Plataforma *plataforma = nullptr);

        ~Galho() override;

    private:
        bool obstaculo_destruivel;
    };
}

