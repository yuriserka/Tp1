#ifndef TRABALHO__INTERFACES__H__
#define TRABALHO__INTERFACES__H__

#include "../cabecalhos/../cabecalhos/includes.h"

class InterfaceServicoAutenticacao;
class InterfaceApresentacaoAutenticacao;
class InterfaceServicoCadastro;
class InterfaceApresentacaoCadastro;
class InterfaceServicoUsuario;
class InterfaceApresentacaoUsuario;
class InterfaceServicoVocabulario;
class InterfaceApresentacaoVocabulario;
class InterfaceServicoControle;
class InterfaceApresentacaoControle;

/**
 * @file interfaces.h
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 *
 * @brief Declaração de todas as interfaces usadas no programa.
 *
 * As interfaces são importantes, pois mesmo se o código for modificado, desde
 * que a interface se mantenha a mesma as coisas irão continuar funcionando como
 * previsto e isso é bom em vários aspectos.
 *
 */

/**
 * @brief Interface de serviços do controle, é responsavel por linkar os modulos do sistema.
 *
 */
class InterfaceServicoControle {
 public:
  /**
   * @brief função que ligará as controladoras com os serviços
   *
   * Também são chamados de builders, pois fazem todo o processo para que
   * o programa funcione corretamente.
   *
   */
  virtual void Construir() = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceServicoControle() = default;
};

/**
 * @brief Interface de apresentação do controle
 *
 */
class InterfaceApresentacaoControle {
 public:
  /**
   * @brief função que inicializa o menu principal.
   *
   */
  virtual void Inicializar() = 0;

  /**
   * @brief função que vai para um menu apos ser logado
   *
   */
  virtual void ControleLogado(const Email &) = 0;

  /**
   * @brief função que Seta o controle para a parte de apresentação autenticação.
   *
   */
  virtual void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;

  /**
   * @brief função que Seta o controle para a parte de apresentação cadastro.
   *
   */
  virtual void SetCtrlApresentacaoCadastro(InterfaceApresentacaoCadastro *) = 0;

  /**
   * @brief função que Seta o controle para a parte de apresentação usuario.
   *
   */
  virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;

  /**
   * @brief função que Seta o controle para a parte de apresentação vocabulário.
   *
   */
  virtual void SetCtrlApresentacaoVocabulario(InterfaceApresentacaoVocabulario *) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceApresentacaoControle() = default;
};

/**
 * @brief Interface de serviços de autenticação, os dados digitados pelo 
 * usuario serão válidados de acordo com as regras do sistema.
 *
 */
class InterfaceServicoAutenticacao {
 public:
  /**
   * @brief  função que autentica os dados que foram passados
   * quando solicitada a entrada no sistema.
   *
   * @return Resultado retorna um objeto com a informação de sucesso ou
   * falha.
   */
  virtual Resultado Autenticar(const Email &, const Senha &) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceServicoAutenticacao() = default;
};

/**
 * @brief Interface de apresentação autenticação
 *
 */
class InterfaceApresentacaoAutenticacao {
 public:
  /**
   * @brief função que autentica os dados do usuario.
   *
   * @return ResultadoAutenticar retorna um objeto que conterá email e
   * um resultado que representará sucesso ou falha.
   */
  virtual ResultadoAutenticar Autenticar() = 0;

  /**
   * @brief Seta o controle para a parte de serviço de autenticação.
   *
   */
  virtual void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceApresentacaoAutenticacao() = default;
};

/**
 * @brief Interface de Serviço de Cadastro, responsavel por cadastrar as entidades
 * do tipo Leitor, Desenvolvedor e Administrador.
 * *
 */
class InterfaceServicoCadastro {
 public:
  /**
   * @brief Função que irá receber os argumentos necessarios para a criação de 
   * um Leitor e irá cadastra-lo ao banco de dados.
   * 
   * @return Resultado retorna se foi sucesso ou falha.
   */
  virtual Resultado CadastrarLeitor(Leitor &, const Nome &,
                                    const Sobrenome &, const Senha &,
                                    const Email &) = 0;

  /**
   * @brief Função que irá receber os argumentos necessarios para a criação de 
   * um Administrador e irá cadastra-lo ao banco de dados.
   * 
   * @return Resultado retorna se foi sucesso ou falha.
   */
  virtual Resultado CadastrarAdm(Administrador &, const Nome &,
                                 const Sobrenome &, const Senha &,
                                 const Email &, const Data &,
                                 const Telefone &, const Address &) = 0;

  /**
   * @brief Função que irá receber os argumentos necessarios para a criação de 
   * um Dcesenvolvedor e irá cadastra-lo ao banco de dados.
   * 
   * @return Resultado retorna se foi sucesso ou falha.
   */
  virtual Resultado CadastrarDev(Desenvolvedor &, const Nome &,
                                 const Sobrenome &, const Senha &,
                                 const Email &, const Data &) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceServicoCadastro() = default;
};

/**
 * @brief Interface de Apresentação de Cadastro, mostrará as opções disponiveis para
 * cadastro
 *
 */
class InterfaceApresentacaoCadastro {
 public:
  /**
   * @brief função que irá mostrar os tipos de conta que é possível se cadastrar.
   *
   */
  virtual void Cadastrar() = 0;

  /**
   * @brief função que irá Seta o controle para a parte de
   * serviço de cadastro.
   *
   */
  virtual void SetCtrlServicoCadastro(InterfaceServicoCadastro *) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceApresentacaoCadastro() = default;
};

/**
 * @brief Interface de Serviço de Usuario
 *
 */
class InterfaceServicoUsuario {
 public:
  /**
   * @brief função que irá exibir as informações de um leitor.
   *
   */
  virtual void Exibir(const Leitor &) = 0;

  /**
   * @brief função que irá exibir as informações de um desenvolvedor.
   *
   */
  virtual void Exibir(const Desenvolvedor &) = 0;

  /**
   * @brief função que irá exibir as informações de um administrador.
   *
   */
  virtual void Exibir(const Administrador &) = 0;

  /**
   * @brief função que irá editar as informações de um leitor.
   *
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Leitor.
   *
   * */
  virtual ResultadoUsuario Editar(const Leitor &) = 0;

  /**
   * @brief função que irá editar as informações de um desenvolvedor.
   *
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Desenvolvedor.
   */
  virtual ResultadoUsuario Editar(const Desenvolvedor &) = 0;

  /**
   * @brief função que irá editar as informações de um administrador.
   *
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Administrador.
   */
  virtual ResultadoUsuario Editar(const Administrador &) = 0;

  /**
   * @brief função que irá excluir a conta do usuario atual, caso seja um
   * administrador excluirá todos os vocabularios associados a ele.
   *
   * @return Resultado retorna um objeto que conterá a informação
   * se foi sucesso ou falha
   */
  virtual Resultado Excluir(const Email &) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceServicoUsuario() = default;
};

/**
 * @brief Interface de apresentação de usuario, mostra as opções disponiveis 
 * na gestão de usuario.
 *
 */
class InterfaceApresentacaoUsuario {
 public:
  /**
   * @brief função que direciona para a tela de gestão de usuarios.
   *
   * @return Resultado retorna um objeto que poderá dizer se a conta foi excluida
   * com sucesso ou falha.
   */
  virtual Resultado Executar(const Email &) = 0;

  /**
   * @brief função que irá Seta o controle para a parte
   * de serviço de usuario.
   *
   */
  virtual void SetCtrlServicoUsuario(InterfaceServicoUsuario *) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceApresentacaoUsuario() = default;
};

/**
 * @brief Interface de Serviços de Vocabularios
 *
 */
class InterfaceServicoVocabulario {
 public:
  /**
   * @brief função  que retorna todos os vocabulários armazenados.
   *
   * @return vector<VocabularioControlado> vetor que contém todos os vocabularios armazenados.
   */
  virtual vector<VocabularioControlado> ConsultarVocabularios() = 0;

  /**
   * @brief função  que retorna todos os termos armazenados.
   *
   * @return vector<Termo> vetor que contém todos os termos armazenados.
   */
  virtual vector<Termo> ConsultarTermos() = 0;

  /**
   * @brief função  que retorna todos os termos de determinado vocabulário.
   *
   * @return vector<Termo> vetor que contém os termos do vocabulário.
   */
  virtual vector<Termo> ConsultarTermos(const VocabularioControlado &) = 0;

  /**
   * @brief função  que retorna a quantidade de termos associados a determinada definição.
   *
   * @return int quantidade de termos associados a definição.
   */
  virtual int ConsultarTermos(const Definicao &) = 0;

  /**
   * @brief função  que retorna todas as definições armazenadas.
   *
   * @return vector<Definicao> vetor que contém todas as definições armazenadas.
   */
  virtual vector<Definicao> ConsultarDefinicoes() = 0;

  /**
   * @brief função  que retorna todas as definições de determinado termo.
   *
   * @return vector<Definicao> vetor que contém todas as definições do termo.
   */
  virtual vector<Definicao> ConsultarDefinicao(const Termo &) = 0;

  /**
   * @brief função  que retorna a definição de determinado vocabulário.
   *
   * @return Definicao definição do vocabulário.
   */
  virtual Definicao ConsultarDefinicao(const VocabularioControlado &) = 0;

  /**
   * @brief função  que cadastra um usuário como administrador de determinado vocabulario.
   *
   * @return Resultado sucesso ou falha ao cadastrar o usuário.
   */
  virtual Resultado CadastrarAdministrador(const VocabularioControlado &, const Email &) = 0;

  /**
   * @brief função  que cadastra um usuário como desenvolvedor de determinado vocabulario.
   *
   * @return Resultado sucesso ou falha ao cadastrar o usuário.
   */
  virtual Resultado CadastrarDesenvolvedor(const VocabularioControlado &,
                                           const Email &) = 0;

  /**
   * @brief função  que retorna a quantidade de desenvolvedores de determinado vocabulário.
   *
   * @return int quantidade de desenvolvedores do vocabulário.
   */
  virtual int ConsultarDesenvolvedores(const VocabularioControlado &) = 0;

  /**
   * @brief função  que cria um termo.
   *
   * @return Resultado sucesso ou falha ao criar o termo.
   */
  virtual Resultado CriarTermo(Termo &,
                               const Nome &,
                               const ClasseDoTermo &,
                               const Data &,
                               const VocabularioControlado &) = 0;

  /**
   * @brief função  que edita um termo.
   *
   * @return Resultado sucesso ou falha ao editar o termo.
   */
  virtual Resultado EditarTermo(Termo &, const Data &) = 0;

  /**
   * @brief função  que exclui um termo.
   *
   * @return Resultado sucesso ou falha ao excluir o termo.
   */
  virtual Resultado ExcluirTermo(const Termo &) = 0;

  /**
   * @brief função  que cria uma definição.
   *
   * @return Resultado sucesso ou falha ao criar a definição.
   */
  virtual Resultado CriarDefinicao(Definicao &,
                                   const TextoDefinicao &, const Data &) = 0;

  /**
   * @brief função  que edita uma definição.
   *
   * @return Resultado sucesso ou falha ao editar a definição.
   */
  virtual Resultado EditarDefinicao(Definicao &, const Data &) = 0;

  /**
   * @brief função  que exclui uma definição.
   *
   * @return Resultado sucesso ou falha ao excluir a definição.
   */
  virtual Resultado ExcluirDefinicao(const Definicao &) = 0;

  /**
   * @brief função  que cria um vocabulário.
   *
   * @return Resultado sucesso ou falha ao criar o vocabulário.
   */
  virtual Resultado CriarVocabulario(VocabularioControlado &, const Nome &,
                                     const Idioma &, const Data &,
                                     const Definicao &, const Email &) = 0;

  /**
   * @brief função  que edita um vocabulário.
   *
   * @return Resultado sucesso ou falha ao editar o vocabulário.
   */
  virtual Resultado EditarVocabulario(VocabularioControlado &, const Idioma &,
                                      const Data &) = 0;

  /**
   * @brief função que irá Excluir um Vocabulario.
   * @brief função  que exclui um vocabulário.
   *
   * @return Resultado sucesso ou falha ao excluir o vocabulário.
   */
  virtual Resultado ExcluirVocabulario(const VocabularioControlado &) = 0;

  /**
   * @brief função  que associa uma definição a um termo.
   *
   * @return Resultado sucesso ou falha ao associar a definição ao termo.
   */
  virtual Resultado AssociarTermoDefinicao(const Termo &, const Definicao &) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceServicoVocabulario() = default;
};

/**
 * @brief Interface de Apresentação de Vocabularios
 *
 */
class InterfaceApresentacaoVocabulario {
 public:
  /**
   * @brief função que direciona para a tela de gestão de vocabularios.
   *
   */
  virtual void Executar(const Email &) = 0;

  /**
   * @brief função  que seta o controle para a interface de serviço de vocabulário.
   *
   */
  virtual void SetCtrlServicoVocabulario(InterfaceServicoVocabulario *) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceApresentacaoVocabulario() = default;
};

#endif //TRABALHO_INTERFACES_H
