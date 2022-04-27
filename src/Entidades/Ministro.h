#ifndef MINSH
#define MINSH
#include "Politico.h"

using namespace std;

namespace Entidade {
    struct Ministro: public Politico {
        string FormacaoAcademica;

        Presidente(Politico &pol) {
            Nome = pol.Nome;
            ID = pol.ID;
            Salario;
        }
    };
}

#endif 