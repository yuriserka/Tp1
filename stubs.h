#ifndef TRABALHO__STUBS_H__
#define TRABALHO__STUBS_H__

#include "interfaces.h"

class StubAutenticacao : public InterfaceServicoAutenticacao {
  public:
    const static string ktrigger_falha_;
    const static string ktrigger_erro_sistema_;
    const static string ktrigger_leitor_;
    const static string ktrigger_desenvolvedor_;
    const static string ktrigger_administrador_;
    Resultado Autenticar(const Email &, const Senha &) override;
};

#endif  // TRABALHO__STUBS_H__