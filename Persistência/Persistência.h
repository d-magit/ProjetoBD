#ifndef UNIDADEPERSISTENCIA_H_INCLUDED
#define UNIDADEPERSISTENCIA_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>
#include <vector>
#include <string>
#include <stdio.h>

#include "sqlite3.h"           // Incluir cabeçalho da biblioteca SQLite.

using namespace std;


class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
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
        ComandoSQL() { nomeBancoDados = "cinema.db"; }
        int executar();
};

//Sala
class ComandoVisualizarSalas: public ComandoSQL {
public:
        ComandoVisualizarSalas();
        vector<Sala> getValor();
};

class ComandoCadastrarSala: public ComandoSQL {
public:
        ComandoCadastrarSala(const Sala&);
};

class ComandoEditarSala: public ComandoSQL {
public:
        ComandoEditarSala(const Sala&);
};

class ComandoExcluirSala: public ComandoSQL {
public:
        ComandoExcluirSala(const Codigo&);
};

class ComandoPesquisarSala: public ComandoSQL{
public:
        ComandoPesquisarSala(const Codigo&);
        Sala getResultado();
};

#endif // UNIDADEPERSISTENCIA_H_INCLUDED
