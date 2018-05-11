#ifndef TRABALHO__CONTROLADORAS__H__
#define TRABALHO__CONTROLADORAS__H__

#include "interfaces.h"

class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao {
  public:
    ResultadoAutenticar Autenticar() override;
    inline void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) override {
      this->CtrlServicoAutenticacao_ = isa;
    }

  private:
    InterfaceServicoAutenticacao *CtrlServicoAutenticacao_;
};

class CtrlApresentacaoControle : public InterfaceApresentacaoControle {
  public:
    void Inicializar() override;
    void Logado() override;
    inline void SetCtrlAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override {
      this->ctrl_apresentacao_autenticacao_ = iaa;
    }
    
  private:
    InterfaceApresentacaoAutenticacao *ctrl_apresentacao_autenticacao_;
    enum Options {
      null, 
      kentrar,
      kcadastrar,
      ksair
    };
};

#endif // TRABALHO__CONTROLADORAS__H__

