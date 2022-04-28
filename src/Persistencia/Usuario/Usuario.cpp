#include "Usuario.h"

Persistencia::UsuarioRepository::GetUsuarioByName(string* name) {
    command = "SELECT * FROM Usuario WHERE nome = '" + *name + "'";
}

Usuario Persistencia::UsuarioRepository::GetUsuario(string* name) {
    getUsuariobyName = new UsuarioRepository::GetUsuarioByName(name);
    getUsuariobyName.Execute();
    return getUsuariobyName.getResult();
}

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