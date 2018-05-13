#ifndef TRABALHO__INTERFACES__H__
#define TRABALHO__INTERFACES__H__

#include "entidades.h"
#include "auxiliares.h"

#ifdef _WIN32
#define CLEAR "cls"
#define PAUSE "pause"
#else
#define CLEAR "clear"
#define PAUSE "read -p \"Digite Enter para continuar...\" saindo"
#endif

class InterfaceServicoAutenticacao;
class InterfaceApresentacaoAutenticacao;
class InterfaceServicoUsuario;
class InterfaceApresentacaoUsuario;
class InterfaceServicoVocabulario;
class InterfaceApresentacaoVocabulario;
class InterfaceApresentacaoControle;

class InterfaceApresentacaoControle {
 public:
  virtual void Inicializar() = 0;
  virtual void ControleLogado(const Email &) = 0;
  virtual void SetCtrlAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;
  virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;
  virtual void SetCtrlApresentacaoVocabulario(InterfaceApresentacaoVocabulario *) = 0;
  virtual ~InterfaceApresentacaoControle() = default;
};

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

class InterfaceServicoUsuario {
 public:
  virtual void ExibirLeitor(const Leitor &) = 0;
  virtual void ExibirDesenvolvedor(const Desenvolvedor &) = 0;
  virtual void ExibirAdministrador(const Administrador &) = 0;
  virtual Resultado Editar(const Email &) = 0;
  virtual Resultado Excluir(const Email &) = 0;
  virtual Leitor CriaLeitor(const Email &) = 0;
  virtual Desenvolvedor CriaDesenvolvedor(const Email &) = 0;
  virtual Administrador CriaAdministrador(const Email &) = 0;
  virtual ~InterfaceServicoUsuario() = default;
};

class InterfaceApresentacaoUsuario {
 public:
  virtual ResultadoUsuario Executar(const Email &) = 0;
  virtual void SetCtrlServicoUsuario(InterfaceServicoUsuario *) = 0;
  virtual ~InterfaceApresentacaoUsuario() = default;
};

class InterfaceServicoVocabulario {
 public:
  virtual void ListarVocabularios() = 0;
  virtual void ApresentarVocabulario(const VocabularioControlado &) = 0;
  virtual void ConsultarTermo(const Termo &) = 0;
  virtual void ConsultarDefinicao(const Definicao &) = 0;
  virtual void CadastrarDesenvolvedor(const Desenvolvedor &) = 0;
  virtual void CriarTermo(const Termo &) = 0;
  virtual void EditarTermo() = 0;
  virtual void ExcluirTermo() = 0;
  virtual void CriarDefinicao(const Definicao &) = 0;
  virtual void EditarDefinicao() = 0;
  virtual void ExcluirDefinicao() = 0;
  virtual void CriarVocabulario(const VocabularioControlado &) = 0;
  virtual void EditarVocabulario() = 0;
  virtual void ExcluirVocabulario() = 0;
  virtual ~InterfaceServicoVocabulario() = default;
};

class InterfaceApresentacaoVocabulario {
 public:
  virtual void Executar(const Email &) = 0;
  virtual void SetCtrlServicoVocabulario(InterfaceServicoVocabulario *) = 0;
  virtual ~InterfaceApresentacaoVocabulario() = default;
};

#endif //TRABALHO_INTERFACES_H
