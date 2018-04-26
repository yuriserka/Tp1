#ifndef VOC_CTRL_UI_H
#define VOC_CTRL_UI_H

#include <vector>
#include "entidades.h"

class SerivcoAutenticacao {
 public:
  virtual bool Autenticar() = 0;
};

class ApresentacaoAutenticacao : public SerivcoAutenticacao {
 public:
  void RunMenu() {
    Controle();
  }

 private:
  vector<Leitor> vector_leitores_;
  vector<Desenvolvedor> vector_desenvolvedores_;
  vector<Administrador> vector_administradores_;
  Email email_digitado_;
  Senha senha_digitada_;
  void Controle();
  void Entrar();
  void Selecao();
  void CadastroAdministrador();
  void CadastroDesenvolvedor();
  void CadastroLeitor();
  bool Autenticar() override;
};

#endif //VOC_CTRL_UI_H
