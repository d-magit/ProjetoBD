#ifndef MINSH
#define MINSH
using namespace std;

namespace Entidade{
    struct Ministro: public Politico{
        string FormacaoAcademica;

        Presidente(Politico & pol){
            Nome = pol.Nome;
            ID = pol.ID;
            Salario;

        }

    };
}

#endif 