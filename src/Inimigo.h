#pragma once

#include "stdafx.h"
#include "Personagem.h"

using namespace Personagens;

namespace Inimigos {
    class Inimigo : public Personagem {
    public:
        explicit Inimigo(Gerenciador_Grafico *g = nullptr);

        ~Inimigo() override;

        void executar() override;

        void imprimir() override;

        bool tomarDano() override;

    protected:
        Vector3f fronteira;

        float posicaoInicial{};

        float danoT;
    };
}


