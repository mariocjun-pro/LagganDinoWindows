#pragma once

#include "stdafx.h"
#include "Menu.h"
#include "Estado.h"
#include "Montanha.h"
#include "Floresta.h"
#include "FabricaMontanha.h"
#include "FabricaFloresta.h"

using namespace Fabricas;
using namespace Controladoras;
using namespace Estados;
using namespace Fases;


namespace Controladoras {
    class MenuPrincipal : public Menu {
    public:
        explicit MenuPrincipal(Jogo *j);

        ~MenuPrincipal() override;

        void executar() override;

    private:
        FabricaMontanha fab1;
        FabricaFloresta fab2;

    };
}
