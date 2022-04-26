// #ifndef CONTROLADORESAPRESENTACAO_H_INCLUDED
// #define CONTROLADORESAPRESENTACAO_H_INCLUDED

// #include <string.h>
// #include "curses.h"
// #include "dominios.h"
// #include "entidades.h"
// #include "interfaces.h"

// // Declarações de classes controladoras e implementações de métodos.
// //--------------------------------------------------------------------------------------------
// class CntrApresentacaoControle {
//     private:
//         Matricula matricula;
//         IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
//         IApresentacaoParticipante *cntrApresentacaoParticipante;
//     public:
//         void executar();
//         void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
//         void setCntrApresentacaoParticipante(IApresentacaoParticipante*);
// };

// inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntrApresentacaoAutenticacao){
//     this->cntrApresentacaoAutenticacao = cntrApresentacaoAutenticacao;
// }

// inline void CntrApresentacaoControle::setCntrApresentacaoParticipante(IApresentacaoParticipante *cntrApresentacaoParticipante){
//     this->cntrApresentacaoParticipante = cntrApresentacaoParticipante;
// }

// //--------------------------------------------------------------------------------------------
// class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
//     private:
//         IServicoAutenticacao *cntrServicoAutenticacao;
//     public:
//         int autenticar(Matricula*);
//         void setCntrServicoAutenticacao(IServicoAutenticacao*);
// };

// inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntrServicoAutenticacao){
//     this->cntrServicoAutenticacao = cntrServicoAutenticacao;
// }

// //--------------------------------------------------------------------------------------------
// class CntrApresentacaoParticipante:public IApresentacaoParticipante{
//     private:
//         IServicoParticipante *cntrServicoParticipante;
//         void consultarDadosPessoais(const Matricula& );
//         void editarUsuario(const Matricula&);
//         void excluirUsuario(const Matricula&);
//         void cadastrarcomoparticipante(const Matricula&);
//     public:
//         void cadastrar();
//         bool executar(const Matricula&);
//         void setCntrServicoParticipante(IServicoParticipante*);
// };

// inline void CntrApresentacaoParticipante::setCntrServicoParticipante(IServicoParticipante *cntrServicoParticipante){
//     this->cntrServicoParticipante = cntrServicoParticipante;
// }

// //--------------------------------------------------------------------------------------------
// class CntrApresentacaoPSS:public IApresentacaoPSS{
//     private:
//         IServicoPSS *cntrServicoPSS;
//         void listarPecas();
//         void listarSessoes();
//         void listarSalas();
//         //Peca
//         void incluirPeca();
//         void editarPeca();
//         void excluirPeca();
//         void visualizarPeca();
//         //Sessões
//         void incluirSessao();
//         void editarSessao();
//         void excluirSessao();
//         void visualizarSessao();
//         //Salas
//         void incluirSala();
//         void editarSala();
//         void excluirSala();
//         void visualizarSala();
//     public:
//         void executar();
//         void executar(const Matricula&);
//         void setCntrServicoPSS(IServicoPSS*); //possível bug
// };

// inline void CntrApresentacaoPSS::setCntrServicoPSS(IServicoPSS *cntrServicoPSS){
//     this->cntrServicoPSS = cntrServicoPSS;
// }

// #endif // CONTROLADORESAPRESENTACAO_H_INCLUDED
