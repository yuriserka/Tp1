//#ifndef TRABALHO__STUBS__H__
//#define TRABALHO__STUBS__H__
//
//#include "../cabecalhos/../cabecalhos/includes.h"
//
///**
// * @file stubs.h
// * @author Yuri Serka e Thiago Matos
// * @date 13 de Abril de 2018
// * 
// * @brief Neste arquivo estão as classes de Stub.
// * 
// * As classes de Stub servem para simular o que seria o comportamento do 
// * sistema em estágios mais avançados, são usados para fins de debug
// * e utiliza triggers para realizar os testes.
// * 
// */
//
///**
// * @brief classe responsável por simular a inicialização do programa. 
// * 
// */
//class StubControle : public InterfaceServicoControle {
// public:
//  /**
//   * @brief ligará as controladoras com os serviços, fazendo com que
//   * o programa funcione corretamente.
//   * 
//   * */
//  void Construir() override;
//};
//
///**
// * @brief classe responsável por simular a autenticação dos usuarios. 
// * 
// */
//class StubAutenticacao : public InterfaceServicoAutenticacao {
// public:
//  /**
//   * @brief trigger de email para testar falha de autenticação.
//   * 
//   */
//  const static string ktrigger_falha_;
//
//  /**
//   * @brief trigger de email para testar erro de sistema.
//   * 
//   */
//  const static string ktrigger_erro_sistema_;
//
//  /**
//   * @brief trigger de email para testar funcionalidades de leitores.
//   * 
//   */
//  const static string ktrigger_leitor_;
//
//  /**
//   * @brief trigger de email para testar funcionalidades de desenvolvedores.
//   * 
//   */
//  const static string ktrigger_desenvolvedor_;
//
//  /**
//   * @brief trigger de email para testar funcionalidades de administradores.
//   * 
//   */
//  const static string ktrigger_administrador_;
//
//  /**
//   * @brief trigger de email para testar senha invalida.
//   * 
//   */
//  const static string ktrigger_senha_invalida_;
//
//  /**
//   * @brief implementa a classe base e autentica os dados que foram passados
//   * quando solicitada a entrada no sistema.
//   * 
//   * @return Resultado retorna um objeto com a informação de sucesso ou 
//   * falha.
//   */
//  Resultado Autenticar(const Email &, const Senha &) override;
//};
//
///**
// * @brief classe responsável por simular o cadastramento de usuarios. 
// * 
// */
//class StubCadastro : public InterfaceServicoCadastro {
// public:
//  /**
//  * @brief implementa a classe base e tenta cadastrar um Leitor.
//  * 
//  * @return Resultado se foi sucesso ou falha no cadastro.
//  */
//  ResultadoUsuario CadastrarLeitor(Leitor &, const Nome &,
//                            const Sobrenome &, const Senha &, const Email &) override;
//
//  /**
//   * @brief implementa a classe base e tenta cadastrar um Desenvolvedor.
//   * 
//   * @return Resultado se foi sucesso ou falha no cadastro.
//   */
//  ResultadoUsuario CadastrarDev(Desenvolvedor &, const Nome &,
//                         const Sobrenome &, const Senha &, const Email &, const Data &) override;
//
//  /**
//   * @brief implementa a classe base e tenta cadastrar um Administrador.
//   * 
//   * @return Resultado se foi sucesso ou falha no cadastro.
//   */
//  ResultadoUsuario CadastrarAdm(Administrador &, const Nome &,
//                         const Sobrenome &, const Senha &, const Email &, const Data &,
//                         const Telefone &, const Address &) override;
//};
//
///**
// * @brief classe responsável por simular a gestão de usuarios. 
// * 
// */
//class StubUsuario : public InterfaceServicoUsuario {
// public:
//
//  /**
//   * @brief implementa a classe base e exibe um leitor.
//   * 
//   */
//  void Exibir(const Leitor &) override;
//
//  /**
//   * @brief implementa a classe base e exibe um desenvolvedor.
//   * 
//   */
//  void Exibir(const Desenvolvedor &) override;
//
//  /**
//   * @brief implementa a classe base e exibe um administrador.
//   * 
//   */
//  void Exibir(const Administrador &) override;
//
//  /**
//   * @brief irá editar as informações de um leitor.
//   * 
//   * @return ResultadoUsuario retorna um objeto que conterá a informação
//   * se foi sucesso ou falha e um objeto da classe Desenvolvedor. 
//   */
//  ResultadoUsuario Editar(const Leitor &) override;
//
//  /**
//   * @brief irá editar as informações de um desenvolvedor.
//   * 
//   * @return ResultadoUsuario retorna um objeto que conterá a informação
//   * se foi sucesso ou falha e um objeto da classe Desenvolvedor.
//   */
//  ResultadoUsuario Editar(const Desenvolvedor &) override;
//
//  /**
//   * @brief edita as informações de um administrador.
//   * 
//   * @return ResultadoUsuario retorna um objeto que conterá a informação
//   * se foi sucesso ou falha e um objeto da classe Administrador.
//   */
//  ResultadoUsuario Editar(const Administrador &) override;
//
//  /**
//   * @brief exclui a conta do usuario logado atualmente.
//   * 
//   * @return Resultado retorna um objeto que conterá a informação
//   * se foi sucesso ou falha
//   */
//  Resultado Excluir(const Email &) override;
//
// private:
//  Leitor CriaLeitor(const Email &);
//  Desenvolvedor CriaDesenvolvedor(const Email &);
//  Administrador CriaAdministrador(const Email &);
//  ResultadoUsuario AtualizaLeitor();
//  ResultadoUsuario AtualizaDesenvolvedor();
//  ResultadoUsuario AtualizaAdministrador();
//};
//
///**
// * @brief classe responsável por simular a gestão de vocabularios.
// * 
// */
//class StubVocabulario : public InterfaceServicoVocabulario {
// public:
//  /**
//   * @brief trigger de Vocabulario para testar cadastramento valido de Desenvolvedor.
//   * 
//   */
//  const static string ktrigger_cadastro_valido_;
//
//  /**
//   * @brief trigger de Vocabulario para testar cadastramento invalido de Desenvolvedor.
//   * 
//   */
//  const static string ktrigger_cadastro_invalido_;
//
//  /**
//   * @brief trigger de Termo para testar criação invalida.
//   * 
//   */
//  const static string ktrigger_criar_termo_invalido_;
//
//  /**
//   * @brief trigger de Definição para testar criação invalida
//   * 
//   */
//  const static string ktrigger_criar_definicao_invalida_;
//
//  /**
//   * @brief trigger de Vocabulário para testar criação invalida
//   * 
//   */
//  const static string ktrigger_criar_vocabulario_invalido_;
//
//  /**
//   * @brief trigger de Termo para testar exclusão valida.
//   * 
//   */
//  const static string ktrigger_excluir_termo_valido_;
//
//  /**
//   * @brief trigger de Termo para testar exclusão invalida.
//   * 
//   */
//  const static string ktrigger_excluir_termo_invalido_;
//
//  /**
//   * @brief trigger de Definição para testar exclusão valida.
//   * 
//   */
//  const static string ktrigger_excluir_definicao_valida_;
//
//  /**
//   * @brief trigger de definição para testar exclusão invalida.
//   * 
//   */
//  const static string ktrigger_excluir_definicao_invalida_;
//
//  /**
//   * @brief trigger de Vocabulario para testar exclusão valida.
//   * 
//   */
//  const static string ktrigger_excluir_vocabulario_valido_;
//
//  /**
//   * @brief trigger de Vocabulario para testar exclusão invalida.
//   * 
//   */
//  const static string ktrigger_excluir_vocabulario_invalido_;
//
//  /**
//   * @brief consulta os vocabularios disponiveis.
//   * 
//   * @return vector<VocabularioControlado> vetor com os vocabularios disponiveis
//   * para consulta.
//   */
//  vector<VocabularioControlado> ConsultarVocabularios() override;
//
//  /**
//   * @brief consulta os Termos disponiveis.
//   * 
//   * @return vector<Termo> vetor com os termos disponiveis
//   * para consulta.
//   */
//  vector<Termo> ConsultarTermos() override;
//
//  /**
//   * @brief consulta a Definição de um dos Vocabularios disponiveis.
//   * 
//   * @return Definicao vetor com os vocabularios disponiveis
//   * para consulta.
//   */
//  Definicao ConsultarDefinicao(const Termo &) override;
//
//  /**
//   * @brief Cadastra um desenvolvedor à algum vocabulario controlado.
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado CadastrarDesenvolvedor(const VocabularioControlado &) override;
//
//  /**
//   * @brief Tenta criar um Termo.
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado CriarTermo(Termo &, const Nome &, const ClasseDoTermo &, const Data &) override;
//
//  /**
//   * @brief Tenta Editar um Termo.
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado EditarTermo(Termo &, const Nome &, const ClasseDoTermo &, const Data &) override;
//
//  /**
//   * @brief Tenta excluir um Termo.
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado ExcluirTermo(const Termo &) override;
//
//  /**
//   * @brief Tenta Criar uma Definição.
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado CriarDefinicao(Definicao &, const TextoDefinicao &, const Data &) override;
//
//  /**
//   * @brief Tenta editar uma Definição
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado EditarDefinicao(Definicao &, const TextoDefinicao &, const Data &) override;
//
//  /**
//   * @brief tenta excluir unma definição
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado ExcluirDefinicao(const Definicao &) override;
//
//  /**
//   * @brief tenta criar um vocabulario
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado CriarVocabulario(VocabularioControlado &, const Nome &,
//                             const Idioma &, const Data &) override;
//
//  /**
//   * @brief tenta editar um vocabulario
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado EditarVocabulario(VocabularioControlado &, const Nome &,
//                              const Idioma &, const Data &) override;
//
//  /**
//   * @brief tenta excluir um vocabulario.
//   * 
//   * @return Resultado sucesso ou falha na ação.
//   */
//  Resultado ExcluirVocabulario(const VocabularioControlado &) override;
//};
//
//#endif  // TRABALHO__STUBS__H__
//