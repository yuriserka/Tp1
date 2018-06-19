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

class CtrlServicoVocabulario : public InterfaceServicoVocabulario {
  vector<VocabularioControlado> ConsultarVocabularios() override;

  vector<Termo> ConsultarTermos(const VocabularioControlado &voc) override;

  int ConsultarTermos(const Definicao &) override;

  vector<Termo> ConsultarTermos() override;

  vector<Definicao> ConsultarDefinicao(const Termo &) override;

  Definicao ConsultarDefinicao(const VocabularioControlado &) override;

  vector<Definicao> ConsultarDefinicoes() override;

  int ConsultarDesenvolvedores(const VocabularioControlado &) override;

  Resultado CadastrarDesenvolvedor(const VocabularioControlado &,
                                   const Email &) override;

  Resultado CadastrarAdministrador(const VocabularioControlado &,
                                   const Email &) override;

  Resultado CriarTermo(Termo &,
                       const Nome &,
                       const ClasseDoTermo &,
                       const Data &,
                       const VocabularioControlado &) override;

  Resultado EditarTermo(Termo &, const Data &) override;

  Resultado ExcluirTermo(const Termo &) override;

  Resultado CriarDefinicao(Definicao &,
                           const TextoDefinicao &,
                           const Data &) override;

  Resultado EditarDefinicao(Definicao &, const Data &) override;

  Resultado ExcluirDefinicao(const Definicao &) override;

  Resultado CriarVocabulario(VocabularioControlado &, const Nome &,
                             const Idioma &, const Data &, const Definicao &,
                             const Email &) override;

  Resultado EditarVocabulario(VocabularioControlado &, const Idioma &,
                              const Data &) override;

  Resultado ExcluirVocabulario(const VocabularioControlado &) override;

  Resultado AssociarTermoDefinicao(const Termo &, const Definicao &) override;
};

#endif //TRABALHO__SERVICOS__H__