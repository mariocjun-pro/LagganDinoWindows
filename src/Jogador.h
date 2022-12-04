#pragma once

#include "stdafx.h"
#include "Personagem.h"
#include "Projetil.h"

using namespace Personagens;
using namespace Auxiliares;

namespace Jogadores {
    class Jogador : public Personagem {
    public:
        explicit Jogador(Gerenciador_Grafico *gerenciador = nullptr);

        ~Jogador() override;

        void morrer();

        void morrer(Vector2f pos);

        void imprimir() override;

        void executar() override = 0;

        //Sets e Gets

        [[nodiscard]] bool getAtacando() const { return atacando; }

        Projetil *getProjetil() { return hitbox; }

        void setPontos(const int p) { pontos = p; }

        [[nodiscard]] int getPontos() const { return pontos; }

    protected:
        Vector2f posInicial;
        Projetil *hitbox;
        bool ataquePronto;
        short ladoAtaque;

        int pontos;
        float pulo;

        //Auxiliares
        float vJog;
    };
}

