#include "EntidadesApresentacao"
using namespace std;
using namespace Entidade;
class IAApresentacaoServico{
    public:
    virtual bool Autenticar(Usuario*);
    virtual bool Cadastrar(Usuario*);
    virtual void ListarPoliticos(int enumpol);
    virtual bool CriarAvaliacao(Avaliacao*));
    virtual bool EditarAvaliacao(Avaliacao*));
    virtual bool ExluirAvaliacao(string IDaval));
    virtual bool ListarAvaliacao(string IDuser));
    virtual void ListarMediaSalarial(string IDuser));
    virtual void ListarPaises());

}