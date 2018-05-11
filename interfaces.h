#ifndef TRABALHO_INTERFACES_H
#define TRABALHO_INTERFACES_H

#include "entidades.h"
#include "auxiliares.h"


#ifdef _WIN32
#define CLEAR "cls"
#define PAUSE "pause"
#else
#define CLEAR "clear"
#define PAUSE "read -p \"Digite Enter para continuar...\" saindo"
#endif

class InterfaceServicoAutenticacao;

class InterfaceApresentacaoAutenticacao {
  public:
    virtual ResultadoAutenticar Autenticar() = 0;
    virtual void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *) = 0;
    virtual ~InterfaceApresentacaoAutenticacao() = default;
};

class InterfaceServicoAutenticacao {
  public:
    virtual Resultado Autenticar(const Email &, const Senha &) = 0;
    virtual ~InterfaceServicoAutenticacao() = default;
};

#endif //TRABALHO_INTERFACES_H
