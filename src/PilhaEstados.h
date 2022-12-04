#pragma once

#include "stdafx.h"
#include "Estado.h"

using namespace Estados;

namespace Controladoras {
    class PilhaEstados {
    public:
        PilhaEstados();

        ~PilhaEstados();

        void tirarEstado(bool excluir = true);

        void colocarEstado(Estado *est) { estados.push(est); }

        [[nodiscard]] unsigned int pilhaTam() const { return estados.size(); }

        [[nodiscard]] Estado *getTopo() const {
            if (not estados.empty()) return estados.top();
            return nullptr;
        }

        bool executar();

    private:
        stack<Estado *> estados;
        stack<Estado *> coletorLixo;
    };
}

