#pragma once

#include "stdafx.h"
#include "Gerenciador_Grafico.h"
#include "Corpo_Grafico.h"
#include "Gerenciador_Colisoes.h"

namespace Auxiliares {
    class Plataforma;
}

using namespace Auxiliares;
using namespace Controladoras;
using namespace GerenciadoresEntidades;
using namespace GerenciadoresFases;

namespace Abstratas {
    class Entidade {
    public:
        explicit Entidade(Gerenciador_Grafico *g = nullptr);

        virtual ~Entidade();

        virtual void executar() = 0;

        virtual void mover() {}

        virtual void imprimir();

        virtual bool tomarDano();

        void setPosicao(const Vector2f pos) { corpo = pos; }

        void setGerenciador(Gerenciador_Grafico *g) { pGG = g; }

        void setMovimento(Vector2f mov) { movimento = mov; }

        virtual void setVidas(int v) { vidas = v; }

        void setMorto() { morto = true; }

        void setChao(bool chao) { noChao = chao; }

        Gerenciador_Grafico *getGerenciador() { return pGG; }

        Corpo_Grafico *getCorpoGraf() { return &corpo; }

        Plataforma *getPlataforma() { return plat; }

        Vector2f getPosicao() { return corpo.getCorpo()->getPosition(); }

        Vector2f getTamanho() { return corpo.getCorpo()->getSize(); }

        Vector2f getMovimento() { return movimento; }

        [[nodiscard]] bool getMorto() const { return morto; }

        [[nodiscard]] bool getPodeMorrer() const { return podeMorrer; }

        [[nodiscard]] bool getPodeMatar() const { return podeMatar; }

        [[nodiscard]] float getEmpurrao() const { return empurrao; }

        [[nodiscard]] int getVidas() const { return vidas; }

        pair<Entidade *, int> gravar() {
            pair<Entidade *, int> p;
            p.first = this;
            p.second = id;
            return p;
        }

    protected:
        int id;

        int vidas;

        float empurrao;

        bool noChao;

        bool podeMatar;

        bool podeMorrer;

        bool morto;

        Gerenciador_Grafico *pGG;

        Corpo_Grafico corpo;

        Plataforma *plat;

        Vector2f movimento;
    };

}
