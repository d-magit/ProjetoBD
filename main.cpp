#include <iostream>
#include "SQLite/sqlite3.h"

using namespace std;

int main(void) {
    sqlite3* db;
    sqlite3_open("gov.db", &db);
    // //Instanciar controladores de apresentação
    // CntrApresentacaoControle cntrApresentacaoControle;
    // CntrApresentacaoAutenticacao cntrApresentacaoAutenticacao;
    // CntrApresentacaoParticipante cntrApresentacaoParticipante;
    // CntrApresentacaoPSS cntrApresentacaoPSS;

    // //instranciar controladores de serviço
    // CntrServicoAutenticacao cntrServicoAutenticacao;
    // CntrServicoParticipante cntrServicoParticipante;
    // CntrServicoPSS cntrServicoPSS;
    // //Interligar
    // //Autenticação
    // cntrApresentacaoControle.setCntrApresentacaoAutenticacao(&cntrApresentacaoAutenticacao);
    // cntrApresentacaoAutenticacao.setCntrServicoAutenticacao(&cntrServicoAutenticacao);
    // //Participante
    // cntrApresentacaoControle.setCntrApresentacaoParticipante(&cntrApresentacaoParticipante);
    // cntrApresentacaoParticipante.setCntrServicoParticipante(&cntrServicoParticipante);
    // //Peça Sessão Sala
    // cntrApresentacaoControle.setCntrApresentacaoPSS(&cntrApresentacaoPSS);
    // cntrApresentacaoPSS.setCntrServicoPSS(&cntrServicoPSS);

    // initscr();

    // cntrApresentacaoControle.executar();
    // endwin();

    cout << "obrigado por usar o programa!" << endl;
    return 0;
}
