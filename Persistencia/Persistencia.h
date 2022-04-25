#ifndef PERSISTENCIA_H_INCLUDED
#define PERSISTENCIA_H_INCLUDED

#include "entidades.h"

#include <list>
#include <vector>
#include <string>
#include <stdio.h>

#include "sqlite3.h"

using namespace std;

namespace Persistencia {
    class ComandoSQL {
    private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        int conectar();
        int desconectar();
        static int callback(void *, int, char **, char **);

    protected:
        list<ElementoResultado> listaResultado;
        string comandoSQL;
    public:
        ComandoSQL() { nomeBancoDados = "gov.db"; }
        int executar();
    };

    class ElementoResultado {
    private:
        string nomeColuna;
        string valor;
    public:
        ElementoResultado(string&, string&);
        string getNomeColuna() const;
        string getValorColuna() const;
    };
    inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
    }

    inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
    }

    class EErroPersistencia {
    private:
        string errMsg;
    public:
        EErroPersistencia(string);
        string what();
    };
}

#endif // PERSISTENCIA_H_INCLUDED