#ifndef PRESH
#define PRESH
#include "Politico.h"
using namespace std;

namespace Entidade{
    struct Presidente: public Politico{
        string DataInicioMandato;

        Presidente(Politico & pol){
            Nome = pol.Nome;
            ID = pol.ID;
            Salario;

        }

    };
}

#endif 