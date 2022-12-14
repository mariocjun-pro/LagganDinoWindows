#pragma once

#include "stdafx.h"
#include "Entidade.h"
#include "Projetil.h"

using namespace Abstratas;
using namespace Auxiliares;

namespace Personagens {
    class Personagem : public Entidade {
    public:
        explicit Personagem(Gerenciador_Grafico *gerenciador = nullptr);

        ~Personagem() override;

        void imprimir() override;

        void executar() override;

        virtual void animar(Vector2f movimento);

    protected:
        float velocidade;

        bool atacando;
        float totalT;

        bool aDireita;
        short int lado;

        bool tomaDano;
        bool ferido;

        bool ataquePronto;
        Projetil *hitbox;
    };
}

