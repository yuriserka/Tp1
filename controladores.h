#ifndef TRABALHO__CONTROLADORAS__H__
#define TRABALHO__CONTROLADORAS__H__

#include "interfaces.h"

class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao {
 public:
  ResultadoAutenticar Autenticar() override;
  inline void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) override {
    this->ctrl_servico_autenticacao_ = isa;
  }

 private:
  InterfaceServicoAutenticacao *ctrl_servico_autenticacao_;
};

class CtrlApresentacaoControle : public InterfaceApresentacaoControle {
 public:
  void Inicializar() override;
  void ControleLogado(const Email &) override;
  inline void SetCtrlAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override {
    this->ctrl_apresentacao_autenticacao_ = iaa;
  }

  inline void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *iau) override {
    this->ctrl_apresentacao_usuario_ = iau;
  }

 private:
  InterfaceApresentacaoAutenticacao *ctrl_apresentacao_autenticacao_;
  InterfaceApresentacaoUsuario *ctrl_apresentacao_usuario_;
  enum Controle {
    knullc,
    kentrar,
    kcadastrar,
    ksair
  };

  enum ControleLogado {
    knullcl,
    kgestao_usuario,
    kgestao_vocabulo,
    kvoltar
  };
};

class CtrlApresentacaoUsuario : public InterfaceApresentacaoUsuario {
 public:
  void Executar(const Email &_email) override;
  void inline SetCtrlServicoUsuario(InterfaceServicoUsuario *isu) override {
    this->ctrl_servico_usuario_ = isu;
  }
 private:
  InterfaceServicoUsuario *ctrl_servico_usuario_;
  enum {
    null,
    keditar,
    kexcluir,
    kmostrar,
    kvoltar
  };
};

#endif // TRABALHO__CONTROLADORAS__H__

