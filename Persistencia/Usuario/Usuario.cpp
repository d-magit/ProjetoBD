#include "Persistencia.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace Persistencia;

int Persistencia::SQLCommand::connect() {
    rc = sqlite3_open(dbName, &db);
    if( rc != SQLITE_OK )
        return 1;
    return 0;
}

Persistencia::ComandoLerSenha::ComandoLerSenha(Matricula matricula) {
    comandoSQL = "SELECT senha FROM participantes WHERE matricula = '";
    comandoSQL += matricula.getValor()+"';";
}

Senha Persistencia::ComandoLerSenha::getResultado() {
    ElementoResultado resultado;
    Senha senha;

    //Remover senha;
    if (listaResultado.empty())
        throw PersistenciaException("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha.setValor(resultado.getValorColuna());

    return senha;
}