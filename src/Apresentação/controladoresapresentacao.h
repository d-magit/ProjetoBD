 #ifndef CONTROLADORESAPRESENTACAO_H_INCLUDED
 #define CONTROLADORESAPRESENTACAO_H_INCLUDED

 #include <string.h>
 #include "curses.h"
 #include "Entidades.h"
using namespace Entidade

class CntrApresentacaoControle {
     private:
         Usuario usuario;
         IServicoAutenticacao *cntrServicoAutenticacao;
     public:
         void Executar();
         int Autenticar(Usuario);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
 };

// //--------------------------------------------------------------------------------------------

 inline void CntrApresentacaoControle::setCntrServicoAutenticacao(IServicoAutenticacao *cntrServicoAutenticacao){
     this->cntrServicoAutenticacao = cntrServicoAutenticacao;
 }


#endif 
