#pragma once

#include "stdafx.h"
#include "Atiradino.h"
#include "PThread.h"

using namespace GerenciadoresEntidades;

namespace Inimigos {
    class AtiradinoThread : public Atiradino, public PThread {
    public:
        explicit AtiradinoThread(Plataforma *p);

        ~AtiradinoThread() override;

        void executar() override;

        void atirar() override;

    private:
        void funcaoThread() override;

        static float tempoAtirar;

        bool threadFechada;
    };
}