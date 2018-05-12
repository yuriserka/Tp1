#ifndef TRABALHO_INTERFACES_H
#define TRABALHO_INTERFACES_H

#include "entidades.h"
#include "auxiliares.h"

#ifdef _WIN32
#define CLEAR "cls"
#define PAUSE "pause"
#else
#define CLEAR "clear"
#define PAUSE "read -p \"Digite Enter para continuar...\" saindo"
#endif

class InterfaceApresentacaoUsuario;

class InterfaceServicoAutenticacao {
 public:
  virtual Resultado Autenticar(const Email &, const Senha &) = 0;
  virtual ~InterfaceServicoAutenticacao() = default;
};

class InterfaceApresentacaoAutenticacao {
 public:
  virtual ResultadoAutenticar Autenticar() = 0;
  virtual void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *) = 0;
  virtual ~InterfaceApresentacaoAutenticacao() = default;
};

class InterfaceApresentacaoControle {
 public:
  virtual void Inicializar() = 0;
  virtual void ControleLogado(const Email &) = 0;
  virtual void SetCtrlAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;
  virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;
  virtual ~InterfaceApresentacaoControle() = default;
};

class InterfaceServicoUsuario {
 public:
  virtual Resultado Editar(const Email &) = 0;
  virtual Resultado Excluir(const Email &) = 0;
  virtual void ExibirLeitor(const Leitor &) = 0;
  virtual void ExibirDesenvolvedor(const Desenvolvedor &) = 0;
  virtual void ExibirAdministrador(const Administrador &) = 0;
  virtual ~InterfaceServicoUsuario() = default;
};

class InterfaceApresentacaoUsuario {
 public:
  virtual void Executar(const Email &) = 0;
  virtual void SetCtrlServicoUsuario(InterfaceServicoUsuario *) = 0;
  virtual ~InterfaceApresentacaoUsuario() = default;
};

#endif //TRABALHO_INTERFACES_H
