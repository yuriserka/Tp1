#ifndef TRABALHO__STUBS__H__
#define TRABALHO__STUBS__H__

#include "includes.h"

/**
 * @file stubs.h
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief Neste arquivo estão as classes de Stub.
 * 
 * As classes de Stub servem para simular o que seria o comportamento do 
 * sistema em estágios mais avançados, são usados para fins de debug
 * e utiliza triggers para realizar os testes.
 * 
 */

/**
 * @brief classe responsável por simular a inicialização do programa. 
 * 
 */
class StubControle : public InterfaceServicoControle {
 public:
  /**
   * @brief ligará as controladoras com os serviços, fazendo com que
   * o programa funcione corretamente.
   * 
   * */
  void Construir() override;
};

/**
 * @brief classe responsável por simular a autenticação dos usuarios. 
 * 
 */
class StubAutenticacao : public InterfaceServicoAutenticacao {
 public:
  /**
   * @brief trigger de email para testar falha.
   * 
   */
  const static string ktrigger_falha_;

  /**
   * @brief trigger de email para testar erro de sistema.
   * 
   */
  const static string ktrigger_erro_sistema_;

  /**
   * @brief trigger de email para testar funcionalidades de leitores.
   * 
   */
  const static string ktrigger_leitor_;

  /**
   * @brief trigger de email para testar funcionalidades de desenvolvedores.
   * 
   */
  const static string ktrigger_desenvolvedor_;

  /**
   * @brief trigger de email para testar funcionalidades de administradores.
   * 
   */
  const static string ktrigger_administrador_;

  /**
   * @brief trigger de email para testar senha invalida.
   * 
   */
  const static string ktrigger_senha_invalida_;

  /**
   * @brief implementa a classe base e autentica os dados que foram passados
   * quando solicitada a entrada no sistema.
   * 
   * @return Resultado retorna um objeto com a informação de sucesso ou 
   * falha.
   */
  Resultado Autenticar(const Email &, const Senha &) override;
};

/**
 * @brief classe responsável por simular o cadastramento de usuarios. 
 * 
 */
class StubCadastro : public InterfaceServicoCadastro {
  public:
    /**
     * @brief implementa a classe base e cadastra um leitor.
     * 
     */
    void CadastrarLeitor() override;

    /**
     * @brief implementa a classe base e cadastra um desenvolvedor.
     * 
     */
    void CadastrarDev() override;

    /**
     * @brief implementa a classe base e cadastra um administrador.
     * 
     */
    void CadastrarAdm() override;
};

/**
 * @brief classe responsável por simular a gestão de usuarios. 
 * 
 */
class StubUsuario : public InterfaceServicoUsuario {
 public:
  /**
   * @brief cria um novo Leitor.
   * 
   * @return Leitor leitor que foi criado.
   */
  Leitor CriaLeitor(const Email &) override;

  /**
   * @brief cria um novo Desenvolvedor
   * 
   * @return Desenvolvedor desenvolvedor que foi criado.
   */
  Desenvolvedor CriaDesenvolvedor(const Email &) override;

  /**
   * @brief cria um novo Administrador.
   * 
   * @return Administrador administrador que foi criado.
   */
  Administrador CriaAdministrador(const Email &) override;
  
  /**
   * @brief implementa a classe base e exibe um leitor.
   * 
   */
  void Exibir(const Leitor &) override;

  /**
   * @brief implementa a classe base e exibe um desenvolvedor.
   * 
   */
  void Exibir(const Desenvolvedor &) override;

  /**
   * @brief implementa a classe base e exibe um administrador.
   * 
   */
  void Exibir(const Administrador &) override;

  /**
   * @brief irá editar as informações de um leitor.
   * 
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Desenvolvedor. 
   */
  ResultadoUsuario Editar(const Leitor &) override;

  /**
   * @brief irá editar as informações de um desenvolvedor.
   * 
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Desenvolvedor.
   */
  ResultadoUsuario Editar(const Desenvolvedor &) override;

  /**
   * @brief edita as informações de um administrador.
   * 
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Administrador.
   */
  ResultadoUsuario Editar(const Administrador &) override;

  /**
   * @brief exclui a conta do usuario logado atualmente.
   * 
   * @return Resultado retorna um objeto que conterá a informação
   * se foi sucesso ou falha
   */
  Resultado Excluir(const Email &) override;

 private:
  ResultadoUsuario AtualizaLeitor();
  ResultadoUsuario AtualizaDesenvolvedor();
  ResultadoUsuario AtualizaAdministrador();
};

/**
 * @brief classe responsável por simular a gestão de vocabularios.
 * 
 */
class StubVocabulario : public InterfaceServicoVocabulario {
 public:
  /**
   * @brief trigger de email para testar falha.
   * 
   */
  const static string ktrigger_cadastro_valido_;

  /**
   * @brief trigger de email para testar erro de sistema.
   * 
   */
  const static string ktrigger_cadastro_invalido_;

  /**
   * @brief 
   * 
   */
  vector<VocabularioControlado> ConsultarVocabularios() override;

  /**
   * @brief 
   * 
   * @return vector<Termo> 
   */
  vector<Termo> ConsultarTermos() override;

  /**
   * @brief 
   * 
   * @return Definicao 
   */
  Definicao ConsultarDefinicao(Termo &) override;

  /**
   * @brief 
   * 
   */
  Resultado CadastrarDesenvolvedor(VocabularioControlado &) override;

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

#endif  // TRABALHO__STUBS__H__