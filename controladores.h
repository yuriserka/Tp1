#ifndef TRABALHO__CONTROLADORAS__H__
#define TRABALHO__CONTROLADORAS__H__

#include "interfaces.h"
#include "stubs.h"

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

  inline void SetCtrlApresentacaoVocabulario(InterfaceApresentacaoVocabulario *iav) override {
    this->ctrl_apresentacao_vocabulario_ = iav;
  }

 private:
  InterfaceApresentacaoAutenticacao *ctrl_apresentacao_autenticacao_;
  InterfaceApresentacaoUsuario *ctrl_apresentacao_usuario_;
  InterfaceApresentacaoVocabulario *ctrl_apresentacao_vocabulario_;
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

class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao {
 public:
  ResultadoAutenticar Autenticar() override;
  inline void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) override {
    this->ctrl_servico_autenticacao_ = isa;
  }

 private:
  InterfaceServicoAutenticacao *ctrl_servico_autenticacao_;
};

class CtrlApresentacaoUsuario : public InterfaceApresentacaoUsuario {
 public:
  ResultadoUsuario Executar(const Email &_email) override;
  void inline SetCtrlServicoUsuario(InterfaceServicoUsuario *isu) override {
    this->ctrl_servico_usuario_ = isu;
  }
 private:
  InterfaceServicoUsuario *ctrl_servico_usuario_;
  enum {
    knull,
    keditar,
    kexcluir,
    kvoltar
  };
  Resultado ShowDados(const Email &, InterfaceServicoUsuario *);
};

class CtrlApresentacaoVocabulario : public InterfaceApresentacaoVocabulario {
 public:
  void Executar(const Email &email) override;
  void SetCtrlServicoVocabulario(InterfaceServicoVocabulario *isv) override {
    this->ctrl_servico_vocabulario_ = isv;
  }
 private:
  InterfaceServicoVocabulario *ctrl_servico_vocabulario_;
  enum {
    knull,
    klistarvocabularios,
    kapresentarvocabulario,
    kconsultartermo,
    kconsultardefinicao,
    kcadastrardesenvolvedor,
    kcriartermo,
    keditartermo,
    kexcluirtermo,
    kcriardefinicao,
    keditardefinicao,
    kexcluirdefinicao,
    kcriarvocabulario,
    keditarvocabulario,
    kexcluirvocabulario,
    kvoltar
  };
};

#endif // TRABALHO__CONTROLADORAS__H__

