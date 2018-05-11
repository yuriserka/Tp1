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
    void Logado(const Email &) override;
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

class CtrlApresentacaoUsuario : public InterfaceApresentacaoUsuario {
  public:
    void Executar(const Email &_email) override;
    // void inline SetCtrlServicoUsuario(InterfaceServicoUsuario *_stub_usuario) override {
    //     this->stub_usuario_ = _stub_usuario;
    // }
  private:
    // InterfaceServicoUsuario *stub_usuario_;

    enum {
      null,
      keditar_,
      kexcluir_,
      ksair_
    };

    void ExibirLeitor(Leitor &);
    void ExibirDesenvolvedor(Desenvolvedor &);
    void ExibirAdministrador(Administrador &);
};

#endif // TRABALHO__CONTROLADORAS__H__

