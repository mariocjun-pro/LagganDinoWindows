#pragma once

#include "stdafx.h"
#include "Jogador.h"
#include "Corpo_Grafico.h"
#include "Animadora.h"

using namespace Controladoras;
using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Tard : public Jogador {
    public:
        explicit Tard(Gerenciador_Grafico *g = nullptr);

        ~Tard() override;

        void mover() override;

        void executar() override;

        [[nodiscard]] float getPulo_Tard() const { return pulo_Tard; }

    private:
        float pulo_Tard;
    };
}

