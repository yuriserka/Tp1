#ifndef TRABALHO__STUBS_H__
#define TRABALHO__STUBS_H__

#include "interfaces.h"

class StubAutenticacao : public InterfaceServicoAutenticacao {
  public:
    const static string ktrigger_falha_;
    const static string ktrigger_erro_sistema_;
    Resultado Autenticar(const Email &, const Senha &) override;
};

#endif  // TRABALHO__STUBS_H__