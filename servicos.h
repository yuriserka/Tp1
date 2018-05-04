#ifndef TRABALHO_SERVICOS_H
#define TRABALHO_SERVICOS_H

#include "bits/stdc++.h"
#include "interfaces.h"
#include "entidades.h"

using namespace std;

class ServicoAutenticacao : public Interfaces {
 public:
  bool Autenticar() override;
  void CadastroAdministrador();
  void CadastroDesenvolvedor();
  void CadastroLeitor();
  Email email_digitado_;
  Senha senha_digitada_;

 private:
  vector<Leitor> vector_leitores_;
  vector<Desenvolvedor> vector_desenvolvedores_;
  vector<Administrador> vector_administradores_;
};

#endif //TRABALHO_SERVICOS_H
