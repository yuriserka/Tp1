#ifndef TRABALHO__SERVICOS__H__
#define TRABALHO__SERVICOS__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file servicos.h
 * @author Yuri Serka e Thiago Matos
 * @date 18 de Junho de 2018
 * 
 * @brief Arquivos com as classes responsáveis pela lógica de negócio do sistema.
 */

/**
 * @brief Classe Builder, ou seja ela é responsavel pelo linking dos objetos e 
 * ponteiros para que tudo funcione corretamente.
 * 
 */
class CtrlServicoControle : public InterfaceServicoControle {
 public:
  /**
   * @brief função que cria os ponteiros e os linka apropriadamente e ao final
   * do programa os deleta. Também cria as tabelas do banco de dados.
   * 
   */
  void Construir() override;
};

/**
 * @brief Classe responsável pela autenticação de um usuario no sistema.
 * 
 */
class CtrlServicoAutenticacao : public InterfaceServicoAutenticacao {
 public:
  /**
   * @brief é passado um email e uma senha, esses que serão criticados quanto
   * a existencia no banco de dados, após isso será comparada a string passada
   * com a recuperada do banco de dados.
   * 
   * @return Resultado 
   */
  Resultado Autenticar(const Email &, const Senha &) override;
};

/**
 * @brief Classe responsavel pelo cadastro de novos usuarios ao sistema.
 * 
 */
class CtrlServicoCadastro : public InterfaceServicoCadastro {
 public:
  /**
   * @brief são passados os argumentos necessarios pora o cadastramento de um Leitor
   * no banco de dados, e é verificado se ja existem emails cadastrados com o passado.
   * 
   * @return Resultado retorna sucesso ou falha dependendo se foi possivel se castrar
   * ou nao.
   */
  Resultado CadastrarLeitor(Leitor &, const Nome &,
                            const Sobrenome &, const Senha &,
                            const Email &) override;

  /**
   * @brief são passados os argumentos necessarios pora o cadastramento de um Desenvolvedor
   * no banco de dados, e é verificado se ja existem emails cadastrados com o passado.
   * 
   * @return Resultado retorna sucesso ou falha dependendo se foi possivel se castrar
   * ou nao.
   */
  Resultado CadastrarDev(Desenvolvedor &, const Nome &,
                         const Sobrenome &, const Senha &, const Email &,
                         const Data &) override;

  /**
   * @brief são passados os argumentos necessarios pora o cadastramento de um Administrador
   * no banco de dados, e é verificado se ja existem emails cadastrados com o passado.
   * 
   * @return Resultado retorna sucesso ou falha dependendo se foi possivel se castrar
   * ou nao.
   */
  Resultado CadastrarAdm(Administrador &, const Nome &,
                         const Sobrenome &, const Senha &, const Email &,
                         const Data &, const Telefone &,
                         const Address &) override;
};

/**
 * @brief Classe reponsavel pelos serviços de usuarios, são eles: Exibir dados, 
 * excluir conta e modificar conta.
 * 
 */
class CtrlServicoUsuario : public InterfaceServicoUsuario {
 public:
  /**
   * @brief Exibe as informações do Leitor que está logado.
   * 
   */
  void Exibir(const Leitor &) override;

  /**
   * @brief Exibe as informações do Desenvolvedor que está logado.
   * 
   */
  void Exibir(const Desenvolvedor &) override;

  /**
   * @brief Exibe as informações do Administrador que está logado.
   * 
   */
  void Exibir(const Administrador &) override;

  /**
   * @brief Edita os dados do Leitor atualmente logado e atualiza no banco de dados.
   * 
   * @return ResultadoUsuario Retorna um Leitor preenchido com os novos dados.
   */
  ResultadoUsuario Editar(const Leitor &) override;

  /**
   * @brief Edita os dados do Desenvolvedor atualmente logado e atualiza no banco de dados.
   * 
   * @return ResultadoUsuario Retorna um Leitor preenchido com os novos dados.
   */
  ResultadoUsuario Editar(const Desenvolvedor &) override;

  /**
   * @brief Edita os dados do Administrador atualmente logado e atualiza no banco de dados.
   * 
   * @return ResultadoUsuario Retorna um Leitor preenchido com os novos dados.
   */
  ResultadoUsuario Editar(const Administrador &) override;

  /**
   * @brief Exclui a conta do usuario logado, caso ele seja um administrador, entao 
   * todos os vocabularios associados a este administrador serao excluidos e junto com isso
   * todos os termos associados a este vocabulario.
   * 
   * @return Resultado irá retornar sucesso ou falha na exclusão.
   */
  Resultado Excluir(const Email &) override;
 private:
  ResultadoUsuario AtualizaLeitor(const Email &email);
  ResultadoUsuario AtualizaDesenvolvedor(const Email &email);
  ResultadoUsuario AtualizaAdministrador(const Email &email);
};

/**
 * @brief Classe reponsavel pelos serviços de vocabulario, são eles: listar vocabularios, 
 * escluir, criar ou editar termos, vocabularios ou definicoes alem de poder se cadastrar como
 * desenvolvedor de vocabularios.
 * 
 */
class CtrlServicoVocabulario : public InterfaceServicoVocabulario {
  /**
   * @brief função herdada que retorna todos os vocabulários armazenados.
   *
   * @return vector<VocabularioControlado> vetor que contém todos os vocabularios armazenados.
   */
  vector<VocabularioControlado> ConsultarVocabularios() override;

  /**
   * @brief função herdada que retorna todos os termos armazenados.
   *
   * @return vector<Termo> vetor que contém todos os termos armazenados.
   */
  vector<Termo> ConsultarTermos() override;

  /**
   * @brief função herdada que retorna todos os termos de determinado vocabulário.
   *
   * @return vector<Termo> vetor que contém os termos do vocabulário.
   */
  vector<Termo> ConsultarTermos(const VocabularioControlado &voc) override;

  /**
   * @brief função herdada que retorna a quantidade de termos associados a determinada definição.
   *
   * @return int quantidade de termos associados a definição.
   */
  int ConsultarTermos(const Definicao &) override;

  /**
   * @brief função herdada que retorna todas as definições armazenadas.
   *
   * @return vector<Definicao> vetor que contém todas as definições armazenadas.
   */
  vector<Definicao> ConsultarDefinicoes() override;

  /**
   * @brief função herdada que retorna todas as definições de determinado termo.
   *
   * @return vector<Definicao> vetor que contém todas as definições do termo.
   */
  vector<Definicao> ConsultarDefinicao(const Termo &) override;

  /**
   * @brief função herdada que retorna a definição de determinado vocabulário.
   *
   * @return Definicao definição do vocabulário.
   */
  Definicao ConsultarDefinicao(const VocabularioControlado &) override;

  /**
   * @brief função herdada que cadastra um usuário como administrador de determinado vocabulario.
   *
   * @return Resultado sucesso ou falha ao cadastrar o usuário.
   */
  Resultado CadastrarAdministrador(const VocabularioControlado &,
                                   const Email &) override;

  /**
   * @brief função herdada que cadastra um usuário como desenvolvedor de determinado vocabulario.
   *
   * @return Resultado sucesso ou falha ao cadastrar o usuário.
   */
  Resultado CadastrarDesenvolvedor(const VocabularioControlado &,
                                   const Email &) override;

  /**
   * @brief função herdada que retorna a quantidade de desenvolvedores de determinado vocabulário.
   *
   * @return int quantidade de desenvolvedores do vocabulário.
   */
  int ConsultarDesenvolvedores(const VocabularioControlado &) override;

  /**
   * @brief função herdada que cria um termo.
   *
   * @return Resultado sucesso ou falha ao criar o termo.
   */
  Resultado CriarTermo(Termo &,
                       const Nome &,
                       const ClasseDoTermo &,
                       const Data &,
                       const VocabularioControlado &) override;

  /**
   * @brief função herdada que edita um termo.
   *
   * @return Resultado sucesso ou falha ao editar o termo.
   */
  Resultado EditarTermo(Termo &, const Data &) override;

  /**
   * @brief função herdada que exclui um termo.
   *
   * @return Resultado sucesso ou falha ao excluir o termo.
   */
  Resultado ExcluirTermo(const Termo &) override;

  /**
   * @brief função herdada que cria uma definição.
   *
   * @return Resultado sucesso ou falha ao criar a definição.
   */
  Resultado CriarDefinicao(Definicao &,
                           const TextoDefinicao &,
                           const Data &) override;

  /**
   * @brief função herdada que edita uma definição.
   *
   * @return Resultado sucesso ou falha ao editar a definição.
   */
  Resultado EditarDefinicao(Definicao &, const Data &) override;

  /**
   * @brief função herdada que exclui uma definição.
   *
   * @return Resultado sucesso ou falha ao excluir a definição.
   */
  Resultado ExcluirDefinicao(const Definicao &) override;

  /**
   * @brief função herdada que cria um vocabulário.
   *
   * @return Resultado sucesso ou falha ao criar o vocabulário.
   */
  Resultado CriarVocabulario(VocabularioControlado &, const Nome &,
                             const Idioma &, const Data &, const Definicao &,
                             const Email &) override;

  /**
   * @brief função herdada que edita um vocabulário.
   *
   * @return Resultado sucesso ou falha ao editar o vocabulário.
   */
  Resultado EditarVocabulario(VocabularioControlado &, const Idioma &,
                              const Data &) override;

  /**
   * @brief função herdada que exclui um vocabulário.
   *
   * @return Resultado sucesso ou falha ao excluir o vocabulário.
   */
  Resultado ExcluirVocabulario(const VocabularioControlado &) override;

  /**
   * @brief função herdada que associa uma definição a um termo.
   *
   * @return Resultado sucesso ou falha ao associar a definição ao termo.
   */
  Resultado AssociarTermoDefinicao(const Termo &, const Definicao &) override;
};

#endif //TRABALHO__SERVICOS__H__