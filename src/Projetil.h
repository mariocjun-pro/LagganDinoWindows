#pragma once

#include "stdafx.h"
#include "Entidade.h"

using namespace Abstratas;
using namespace Auxiliares;

namespace Auxiliares {
    class Projetil : public Entidade {
    public:
        explicit Projetil(Gerenciador_Grafico *g = nullptr);

        ~Projetil() override;

        void executar() override {}

    private:
        bool projetil_podeMatar;
        float empurrao_projetil;
    };
}