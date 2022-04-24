#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <vector>

using namespace std;

//Autenticacao
class IApresentacaoAutenticacao {
    public:
        virtual int autenticar(Login*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};
class IServicoAutenticacao {
    public:
        virtual int autenticar(const Login&, const Senha&) = 0;
        virtual ~IServicoAutenticacao(){}
};

//Participante
class IApresentacaoParticipante {
    public:
        virtual void cadastrar() = 0;
        virtual bool executar(const Login&) = 0;
        virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
        virtual ~IApresentacaoParticipante(){}
};
class IServicoParticipante {
    public:
        virtual int cadastrarUsuario(const Participante&) = 0;
        virtual ~IServicoParticipante(){}
};

#endif // INTERFACE_H_INCLUDED
