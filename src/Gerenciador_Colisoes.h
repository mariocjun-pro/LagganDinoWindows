#pragma once

#include "stdafx.h"

namespace GerenciadoresEntidades {
    class Corpo_Grafico;
}
using namespace GerenciadoresEntidades;

namespace Abstratas {
    class Entidade;
}

using namespace Abstratas;

namespace GerenciadoresFases {
    class Gerenciador_Colisoes {
    public:
        Gerenciador_Colisoes();

        ~Gerenciador_Colisoes();

        static bool verificarColisao(Corpo_Grafico *c1, Corpo_Grafico *c2, Vector2f &direcao, float f);

        static void colidindo(Entidade *e1, Vector2f direcao);

        static bool atacando(Entidade *e1, Entidade *e2, Vector2f &direcao);

        static bool colidir(Entidade *e1, Entidade *e2, Vector2f &direcao);

        static bool ataque(Entidade *e1, Entidade *e2, Vector2f &direcao);
    };
}