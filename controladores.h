#ifndef TRABALHO__CONTROLADORAS__H__
#define TRABALHO__CONTROLADORAS__H__

#include "interfaces.h"

class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao {
  public:
    ResultadoAutenticar Autenticar() override;
    void inline SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) {
      this->CtrlServicoAutenticacao_ = isa;
    }

  private:
    InterfaceServicoAutenticacao *CtrlServicoAutenticacao_;
};

#endif // TRABALHO__CONTROLADORAS__H__

