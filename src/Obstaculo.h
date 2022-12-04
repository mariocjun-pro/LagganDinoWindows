#pragma once

#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;

namespace Obstaculos {
    class Obstaculo : public Entidade {
    public:
        explicit Obstaculo(Gerenciador_Grafico *g);

        ~Obstaculo() override;

        void executar() override {}

    protected:
        bool obstaculo_danoso;
    };
}


