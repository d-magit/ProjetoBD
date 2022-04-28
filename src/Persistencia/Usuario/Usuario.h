#ifndef USUARIO_PERSISTENCIA_H_INCLUDED
#define USUARIO_PERSISTENCIA_H_INCLUDED

#include "Persistencia.h"
#include "../EntidadeImports.h"

using namespace std;
using namespace Persistencia;
using namespace Entidade;

namespace Persistencia {
    class UsuarioRepository {
    private:
        class GetUsuarioByName : public SQLCommand {
            public:
                GetUsuarioByName(string*);
        };
    public:
        Usuario GetUsuario(string*);
    };
}

#endif // USUARIO_PERSISTENCIA_H_INCLUDED