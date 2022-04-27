#ifndef GOVERH
#define GOVERH
using namespace std;

namespace Entidade {
    struct Governador: public Politico {
        string ObraTerminada;

        Presidente(Politico &pol) {
            Nome = pol.Nome;
            ID = pol.ID;
            Salario;
        }
    };
}

#endif 