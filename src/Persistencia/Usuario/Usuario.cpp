#include "Usuario.h"

using namespace std;
using namespace Persistencia;

// Persistencia::ComandoLerSenha::ComandoLerSenha(Matricula matricula) {
//     comandoSQL = "SELECT senha FROM participantes WHERE matricula = '";
//     comandoSQL += matricula.getValor()+"';";
// }

// Senha Persistencia::ComandoLerSenha::getResultado() {
//     ElementoResultado resultado;
//     Senha senha;

//     //Remover senha;
//     if (listaResultado.empty())
//         throw PersistenciaException("Lista de resultados vazia.");
//     resultado = listaResultado.back();
//     listaResultado.pop_back();
//     senha.setValor(resultado.getValorColuna());

//     return senha;
// }