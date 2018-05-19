#ifndef TRABALHO__STUBS_H__
#define TRABALHO__STUBS_H__

#include "interfaces.h"

/**
 * @file stubs.h
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
class StubControle : public InterfaceServicoControle {
 public:
  void Construir() override;
};

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
class StubCadastro : public InterfaceServicoCadastro {
  public:
    /**
     * @brief 
     * 
     */
    void CadastrarLeitor() override;

    /**
     * @brief 
     * 
     */
    void CadastrarDev() override;

    /**
     * @brief 
     * 
     */
    void CadastrarAdm() override;
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
  ResultadoUsuario Editar(const Leitor &) override;

  /**
   * @brief 
   * 
   * @return Resultado 
   */
  ResultadoUsuario Editar(const Desenvolvedor &) override;

  /**
   * @brief 
   * 
   * @return Resultado 
   */
  ResultadoUsuario Editar(const Administrador &) override;

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

 private:
  ResultadoUsuario AtualizaLeitor();
  ResultadoUsuario AtualizaDesenvolvedor();
  ResultadoUsuario AtualizaAdministrador();
};

/**
 * @brief 
 * 
 */
class StubVocabulario : public InterfaceServicoVocabulario {
 public:
  /**
   * @brief 
   * 
   */
  Resultado ListarVocabularios() override;

  /**
   * @brief 
   * 
   */
  Resultado ApresentarVocabulario() override;

  /**
   * @brief 
   * 
   */
  Resultado ConsultarTermo() override;

  /**
   * @brief 
   * 
   */
  Resultado ConsultarDefinicao() override;

  /**
   * @brief 
   * 
   */
  Resultado CadastrarDesenvolvedor() override;

  /**
   * @brief 
   * 
   */
  Resultado CriarTermo() override;

  /**
   * @brief 
   * 
   */
  Resultado EditarTermo() override;

  /**
   * @brief 
   * 
   */
  Resultado ExcluirTermo() override;

  /**
   * @brief 
   * 
   */
  Resultado CriarDefinicao() override;

  /**
   * @brief 
   * 
   */
  Resultado EditarDefinicao() override;

  /**
   * @brief 
   * 
   */
  Resultado ExcluirDefinicao() override;

  /**
   * @brief 
   * 
   */
  Resultado CriarVocabulario() override;

  /**
   * @brief 
   * 
   */
  Resultado EditarVocabulario() override;

  /**
   * @brief 
   * 
   */
  Resultado ExcluirVocabulario() override;
};

#endif  // TRABALHO__STUBS_H__