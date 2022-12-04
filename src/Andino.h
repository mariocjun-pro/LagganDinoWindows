#pragma once

#include "stdafx.h"
#include "Inimigo.h"
#include "Plataforma.h"

using namespace Auxiliares;

namespace Inimigos {
    class Andino : public Inimigo {
    public:
        explicit Andino(Plataforma *p);

        ~Andino() override;

        void mover() override;

    private:
        float pulo;
    };
}