#ifndef GOVERH
#define GOVERH
#include "Politico.h"
using namespace std;

namespace Entidade {
    struct Deputado: public Politico {
        string LeiAprovada;

        Presidente(Politico &pol){
            Nome = pol.Nome;
            ID = pol.ID;
            Salario;
        }
    };
}

#endif 