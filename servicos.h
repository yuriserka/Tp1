#ifndef TRABALHO_SERVICOS_H
#define TRABALHO_SERVICOS_H

#include "entidades.h"
#include "interfaces.h"

using namespace std;

class ServicoAutenticacao {
 public:
  void CadastrarAdministrador();
  void CadastrarDesenvolvedor();
  void CadastrarLeitor();
  void RecuperarSenha(const Email &);

 private:
  bool verificado_;
};

class ServicoUsuario : public Leitor {
 public:
  void AtualizarLeitor(const Email &);
  void AtualizarDesenvolvedor(const Email &);
  void AtualizarAdministrador(const Email &);
  void Procurador(const Email &);
  void Deletar(const Email &);
  int TipoConta(const Email &);
};

#endif //TRABALHO_SERVICOS_H
