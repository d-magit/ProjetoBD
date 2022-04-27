// #include <string.h>
// #include "dominios.h"
// #include "entidades.h"
// #include "interfaces.h"
// #include "controladoresservico.h"
// #include "unidadepersistencia.h"

// // Implementa��es de m�todos de classes controladoras de apresenta��o.
// //--------------------------------------------------------------------------------------------
// // CntrServicoAutenticacao
// //--------------------------- Private ---------------------------
// //---------------------------- Public ----------------------------
// int CntrServicoAutenticacao::autenticar(const Matricula& matricula, const Senha& senha){
//     try {
//         ComandoLerSenha comando(matricula);
//         comando.executar();
//         Senha senhaReal = comando.getResultado();
//         if(senhaReal.getValor() == senha.getValor()) return 0;
//         else return 1;
//     }catch(...) {
//         return 2;
//     }
// }

// //--------------------------------------------------------------------------------------------
// // CntrServicoParticipante
// //--------------------------- Private ---------------------------
// //--------------------------- Public ----------------------------
// int CntrServicoParticipante::cadastrarUsuario(const Participante& participante){
//     ComandoCadastrarParticipante cadastrar(participante);
//     return cadastrar.executar();
// }
// int CntrServicoParticipante::editarUsuario(const Participante& participante){
//     ComandoEditarParticipante comando(participante);
//     return comando.executar();
// }
// int CntrServicoParticipante::excluirUsuario(const Matricula& matricula){
//     ComandoExcluirParticipante comando(matricula);
//     return comando.executar();
// }
// int CntrServicoParticipante::cadastrarComoParticipante(const Matricula& matricula, const Codigo& id){
//     ComandoCadastrarParticipanteEmPeca cadastrar(matricula, id);
//     return cadastrar.executar();
// }
// int CntrServicoParticipante::visualizarUsuario(const Matricula& matricula, Participante* participante){
//     ComandoPesquisarParticipante comando(matricula);
//     int ret = comando.executar();
//     if(ret==0){
//         try{
//             *participante = comando.getResultado();
//             return 0;
//         }catch(...){
//             return 1;
//         }
//     }else{
//         return 1;
//     }
// }

