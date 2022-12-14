#include "FabricaMontanha.h"

using namespace Fabricas;

FabricaMontanha::FabricaMontanha(Jogo *jogo) :
        FabricaFase(jogo) {
    idFase = 0;
}

FabricaMontanha::~FabricaMontanha() = default;

Fase *FabricaMontanha::criar() {
    fase = static_cast<Fase *>(new Montanha(pJogo, doisJogadores));

    if (carrega) {
        carregar();
    } else {
        instanciaJogadoresMontanha();
        instanciaPlataformasMontanha();
    }

    instanciaFundoMontanha();
    limpar();

    return fase;
}

void FabricaMontanha::instanciaJogadoresMontanha() {

    if (not j1) {
        j1 = new Vita(pJogo->getGerenciador());
    }
    if (not j2) {
        if (doisJogadores) {
            j2 = new Tard(pJogo->getGerenciador());
        }
    }
    fase->incluirEntidade(static_cast<Entidade *>(j1));
    fase->incluirEntidade(static_cast<Entidade *>(j2));
    fase->setJogador1(j1);
    fase->setJogador2(j2);
}

void FabricaMontanha::instanciaPlataformasMontanha() {
    ifstream plats("../arquivos/PlataformasMontanha.txt", ios::in);
    Vector2f pos, tam;
    Plataforma *plat;
    AtiradinoThread *atrT;
    int tipo;

    if (!plats) {
        cerr << "Erro ao carregar o arquivo";
    }

    //Instancia as outras plataformas

    while (plats >> tam.x >> tam.y) {
        plats >> pos.x >> pos.y;
        plats >> tipo;
        //tipo = 0;

        plat = new Plataforma(tam);
        plat->setGerenciador(pJogo->getGerenciador());
        plat->getCorpoGraf()->setPosicao(pos);
        fase->incluirEntidade(static_cast<Entidade *>(plat));


        int aleatorio = rand() % 3;

        if (tipo == 1) {
            if (aleatorio == 0) {
                instanciaInimigosMontanha(plat);
                instanciaObstaculosMontanha(plat);
            } else if (aleatorio == 1)
                instanciaObstaculosMontanha(plat);
            else if (aleatorio == 2)
                instanciaInimigosMontanha(plat);
        } else if (tipo == 2) {
            if (aleatorio) {
                atrT = new AtiradinoThread(plat);
                fase->incluirEntidade(static_cast<Entidade *>(atrT));
                fase->incluirEntidade(static_cast<Entidade *>(atrT->getProjetil()));
            }
        }
    }

    plats.close();
}

void FabricaMontanha::instanciaInimigosMontanha(Plataforma *plat) {
    Andino *andi;
    AtiradinoThread *atrT;

    std::random_device dev;
    std::uniform_int_distribution<uint32_t> distribuicao(0, 1);

    int aleatorio;
    aleatorio = rand() % 2;

    if (aleatorio == 0) {
        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade *>(andi));

        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade *>(andi));
    } else if (aleatorio == 1) {
        atrT = new AtiradinoThread(plat);
        fase->incluirEntidade(static_cast<Entidade *>(atrT));
        fase->incluirEntidade(static_cast<Entidade *>(atrT->getProjetil()));

        andi = new Andino(plat);
        fase->incluirEntidade(static_cast<Entidade *>(andi));
    }
}

void FabricaMontanha::instanciaObstaculosMontanha(Plataforma *plat) {
    Espinho *carn;
    Pedra *pedra;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<uint32_t> distribuicao(0, 1);

    int aleatorio;
    aleatorio = rand() % 3;

    if (aleatorio == 0) {
        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 200.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 200.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));
    } else if (aleatorio == 1) {
        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 110.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x - 40.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 30.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));

        carn = new Espinho(pJogo->getGerenciador());
        carn->getCorpoGraf()->setPosicao(Vector2f(plat->getPosicao().x + 100.0f, plat->getPosicao().y - 70.0f));
        fase->incluirEntidade(static_cast<Entidade *>(carn));
    } else if (aleatorio == 2) {
        pedra = new Pedra(plat);
        fase->incluirEntidade(static_cast<Entidade *>(pedra));

        pedra = new Pedra(plat);
        fase->incluirEntidade(static_cast<Entidade *>(pedra));

        pedra = new Pedra(plat);
        fase->incluirEntidade(static_cast<Entidade *>(pedra));
    }
}

void FabricaMontanha::instanciaFundoMontanha() {
    auto *fundo = new Fundo(5, pJogo->getGerenciador());

    fundo->setTextura("../arquivos/texturas/bg-montanha/parallax-mountain-bg.png", 0);
    fundo->setTextura("../arquivos/texturas/bg-montanha/parallax-mountain-montain-far.png", 1);
    fundo->setTextura("../arquivos/texturas/bg-montanha/parallax-mountain-mountains.png", 2);
    fundo->setTextura("../arquivos/texturas/bg-montanha/parallax-mountain-trees.png", 3);
    fundo->setTextura("../arquivos/texturas/bg-montanha/parallax-mountain-foreground-trees.png", 4);

    fundo->setTamanho(Vector2f(1280.0f, 960.0f));

    fase->setFundo(fundo);
}
