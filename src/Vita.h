#pragma once

#include "stdafx.h"
#include "Jogador.h"
#include "Animadora.h"
#include "Corpo_Grafico.h"

using namespace GerenciadoresEntidades;

namespace Jogadores {
    class Vita : public Jogador {
    public:
        explicit Vita(Gerenciador_Grafico *g = nullptr);

        ~Vita() override;

        void mover() override;

        void executar() override;

        [[nodiscard]] int getVelocidade_Vita() const { return velocidade_Vita; }

    private:
        int velocidade_Vita;
    };
}
