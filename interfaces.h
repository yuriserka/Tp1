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

/**
 * @file 
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief
 * 
 */

/**
 * @brief 
 * 
 */
class InterfaceApresentacaoControle {
 public:
  /**
   * @brief 
   * 
   */
  virtual void Inicializar() = 0;

  /**
   * @brief 
   * 
   */
  virtual void ControleLogado(const Email &) = 0;

  /**
   * @brief Set the Ctrl Autenticacao object
   * 
   */
  virtual void SetCtrlAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;

  /**
   * @brief Set the Ctrl Apresentacao Usuario object
   * 
   */
  virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;

  /**
   * @brief Set the Ctrl Apresentacao Vocabulario object
   * 
   */
  virtual void SetCtrlApresentacaoVocabulario(InterfaceApresentacaoVocabulario *) = 0;

  /**
   * @brief Destroy the Interface Apresentacao Controle object
   * 
   */
  virtual ~InterfaceApresentacaoControle() = default;
};

/**
 * @brief 
 * 
 */
class InterfaceServicoAutenticacao {
 public:
  /**
   * @brief 
   * 
   * @return Resultado 
   */
  virtual Resultado Autenticar(const Email &, const Senha &) = 0;

  /**
   * @brief Destroy the Interface Servico Autenticacao object
   * 
   */
  virtual ~InterfaceServicoAutenticacao() = default;
};

/**
 * @brief 
 * 
 */
class InterfaceApresentacaoAutenticacao {
 public:
  /**
   * @brief 
   * 
   * @return ResultadoAutenticar 
   */
  virtual ResultadoAutenticar Autenticar() = 0;

  /**
   * @brief Set the Ctrl Servico Autenticacao object
   * 
   */
  virtual void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *) = 0;

  /**
   * @brief Destroy the Interface Apresentacao Autenticacao object
   * 
   */
  virtual ~InterfaceApresentacaoAutenticacao() = default;
};

/**
 * @brief 
 * 
 */
class InterfaceServicoUsuario {
 public:
  /**
   * @brief 
   * 
   */
  virtual void ExibirLeitor(const Leitor &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void ExibirDesenvolvedor(const Desenvolvedor &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void ExibirAdministrador(const Administrador &) = 0;

  /**
   * @brief 
   * 
   * @return Resultado 
   */
  virtual Resultado Editar(const Email &) = 0;

  /**
   * @brief 
   * 
   * @return Resultado 
   */
  virtual Resultado Excluir(const Email &) = 0;

  /**
   * @brief 
   * 
   * @return Leitor 
   */
  virtual Leitor CriaLeitor(const Email &) = 0;

  /**
   * @brief 
   * 
   * @return Desenvolvedor 
   */
  virtual Desenvolvedor CriaDesenvolvedor(const Email &) = 0;

  /**
   * @brief 
   * 
   * @return Administrador 
   */
  virtual Administrador CriaAdministrador(const Email &) = 0;

  /**
   * @brief Destroy the Interface Servico Usuario object
   * 
   */
  virtual ~InterfaceServicoUsuario() = default;
};

/**
 * @brief 
 * 
 */
class InterfaceApresentacaoUsuario {
 public:
  /**
   * @brief 
   * 
   * @return ResultadoUsuario 
   */
  virtual ResultadoUsuario Executar(const Email &) = 0;

  /**
   * @brief Set the Ctrl Servico Usuario object
   * 
   */
  virtual void SetCtrlServicoUsuario(InterfaceServicoUsuario *) = 0;

  /**
   * @brief Destroy the Interface Apresentacao Usuario object
   * 
   */
  virtual ~InterfaceApresentacaoUsuario() = default;
};

/**
 * @brief 
 * 
 */
class InterfaceServicoVocabulario {
 public:
  /**
   * @brief 
   * 
   */
  virtual void ListarVocabularios() = 0;

  /**
   * @brief 
   * 
   */
  virtual void ApresentarVocabulario(const VocabularioControlado &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void ConsultarTermo(const Termo &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void ConsultarDefinicao(const Definicao &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void CadastrarDesenvolvedor(const Desenvolvedor &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void CriarTermo(const Termo &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void EditarTermo() = 0;

  /**
   * @brief 
   * 
   */
  virtual void ExcluirTermo() = 0;

  /**
   * @brief 
   * 
   */
  virtual void CriarDefinicao(const Definicao &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void EditarDefinicao() = 0;

  /**
   * @brief 
   * 
   */
  virtual void ExcluirDefinicao() = 0;

  /**
   * @brief 
   * 
   */
  virtual void CriarVocabulario(const VocabularioControlado &) = 0;

  /**
   * @brief 
   * 
   */
  virtual void EditarVocabulario() = 0;

  /**
   * @brief 
   * 
   */
  virtual void ExcluirVocabulario() = 0;

  /**
   * @brief Destroy the Interface Servico Vocabulario object
   * 
   */
  virtual ~InterfaceServicoVocabulario() = default;
};

class InterfaceApresentacaoVocabulario {
 public:
  /**
   * @brief 
   * 
   */
  virtual void Executar(const Email &) = 0;

  /**
   * @brief Set the Ctrl Servico Vocabulario object
   * 
   */
  virtual void SetCtrlServicoVocabulario(InterfaceServicoVocabulario *) = 0;

  /**
   * @brief Destroy the Interface Apresentacao Vocabulario object
   * 
   */
  virtual ~InterfaceApresentacaoVocabulario() = default;
};

#endif //TRABALHO_INTERFACES_H
