#ifndef TRABALHO_SERVICOS_H
#define TRABALHO_SERVICOS_H

#include "entidades.h"
#include "interfaces.h"

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#define PAUSE "pause"
#else
#define CLEAR "clear"
#define PAUSE "read -p \"Digite Enter para sair"\" saindo"
#endif

class ServicoAutenticacao : public Interfaces {
 public:
  bool Autenticar(const Email &, const Senha &) override;

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
