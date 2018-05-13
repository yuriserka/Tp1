#ifndef TRABALHO__STUBS_H__
#define TRABALHO__STUBS_H__

#include "interfaces.h"

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
class StubAutenticacao : public InterfaceServicoAutenticacao {
 public:
  /**
   * @brief 
   * 
   */
  const static string ktrigger_falha_;

  /**
   * @brief 
   * 
   */
  const static string ktrigger_erro_sistema_;

  /**
   * @brief 
   * 
   */
  const static string ktrigger_leitor_;

  /**
   * @brief 
   * 
   */
  const static string ktrigger_desenvolvedor_;

  /**
   * @brief 
   * 
   */
  const static string ktrigger_administrador_;

  /**
   * @brief 
   * 
   */
  const static string ktrigger_senha_invalida_;

  /**
   * @brief 
   * 
   * @return Resultado 
   */
  Resultado Autenticar(const Email &, const Senha &) override;
};

/**
 * @brief 
 * 
 */
class StubUsuario : public InterfaceServicoUsuario {
 public:
  /**
   * @brief 
   * 
   */
  void Exibir(const Leitor &) override;

  /**
   * @brief 
   * 
   */
  void Exibir(const Desenvolvedor &) override;

  /**
   * @brief 
   * 
   */
  void Exibir(const Administrador &) override;

  /**
   * @brief 
   * 
   * @return Resultado 
   */
  Resultado Editar(const Email &) override;

  /**
   * @brief 
   * 
   * @return Resultado 
   */
  Resultado Excluir(const Email &) override;

  /**
   * @brief 
   * 
   * @return Leitor 
   */
  Leitor CriaLeitor(const Email &) override;

  /**
   * @brief 
   * 
   * @return Desenvolvedor 
   */
  Desenvolvedor CriaDesenvolvedor(const Email &) override;

  /**
   * @brief 
   * 
   * @return Administrador 
   */
  Administrador CriaAdministrador(const Email &) override;
};

#endif  // TRABALHO__STUBS_H__