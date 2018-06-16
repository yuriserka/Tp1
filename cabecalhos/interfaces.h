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
 * @brief Interface de serviços do controle
 *
 */
class InterfaceServicoControle {
 public:
  /**
   * @brief função abstrata que ligará as controladoras com os serviços
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
   * @brief função abstrata que inicializa o menu principal.
   *
   */
  virtual void Inicializar() = 0;

  /**
   * @brief função abstrata que vai para um menu apos ser logado
   *
   */
  virtual void ControleLogado(const Email &) = 0;

  /**
   * @brief função abstrata que Seta o controle para a parte de apresentação autenticação.
   *
   */
  virtual void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;

  /**
   * @brief função abstrata que Seta o controle para a parte de apresentação cadastro.
   *
   */
  virtual void SetCtrlApresentacaoCadastro(InterfaceApresentacaoCadastro *) = 0;

  /**
   * @brief função abstrata que Seta o controle para a parte de apresentação usuario.
   *
   */
  virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;

  /**
   * @brief função abstrata que Seta o controle para a parte de apresentação vocabulário.
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
 * @brief Interface de serviços de autenticação
 *
 */
class InterfaceServicoAutenticacao {
 public:
  /**
   * @brief @brief classe virtual que autentica os dados que foram passados
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
   * @brief função abstrata que autentica os dados do usuario.
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
 * @brief Interface de Serviço de Cadastro
 *
 */
class InterfaceServicoCadastro {
 public:
  /**
   * @brief função abstrata que cadastra um leitor.
   *
   */
  virtual Resultado CadastrarLeitor(Leitor &, const Nome &,
                                    const Sobrenome &, const Senha &, const Email &) = 0;

  /**
   * @brief função abstrata que cadastra um administrador.
   *
   */
  virtual Resultado CadastrarAdm(Administrador &, const Nome &,
                                 const Sobrenome &, const Senha &, const Email &, const Data &,
                                 const Telefone &, const Address &) = 0;

  /**
   * @brief função abstrata que cadastra um desenvolvedor.
   *
   */
  virtual Resultado CadastrarDev(Desenvolvedor &, const Nome &,
                                 const Sobrenome &, const Senha &, const Email &, const Data &) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~InterfaceServicoCadastro() = default;
};

/**
 * @brief Interface de Apresentação de Cadastro
 *
 */
class InterfaceApresentacaoCadastro {
 public:
  /**
   * @brief função abstrata que irá cadastrar um usuario.
   *
   */
  virtual void Cadastrar() = 0;

  /**
   * @brief função abstrata que irá Seta o controle para a parte de
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
   * @brief função virtual que irá exibir as informações de um leitor.
   *
   */
  virtual void Exibir(const Leitor &) = 0;

  /**
   * @brief função virtual que irá exibir as informações de um desenvolvedor.
   *
   */
  virtual void Exibir(const Desenvolvedor &) = 0;

  /**
   * @brief função virtual que irá exibir as informações de um administrador.
   *
   */
  virtual void Exibir(const Administrador &) = 0;

  /**
   * @brief função virtual que irá editar as informações de um leitor.
   *
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Leitor.
   *
   * */
  virtual ResultadoUsuario Editar(const Leitor &) = 0;

  /**
   * @brief função virtual que irá editar as informações de um desenvolvedor.
   *
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Desenvolvedor.
   */
  virtual ResultadoUsuario Editar(const Desenvolvedor &) = 0;

  /**
   * @brief função virtual que irá editar as informações de um administrador.
   *
   * @return ResultadoUsuario retorna um objeto que conterá a informação
   * se foi sucesso ou falha e um objeto da classe Administrador.
   */
  virtual ResultadoUsuario Editar(const Administrador &) = 0;

  /**
   * @brief função abstrata que irá excluir a conta do usuario atual.
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
 * @brief Interface de apresentação de usuario
 *
 */
class InterfaceApresentacaoUsuario {
 public:
  /**
   * @brief função abstrata que direciona para a tela de gestão de usuarios.
   *
   * @return Resultado retorna um objeto que poderá dizer se a conta foi excluida
   * com sucesso ou falha.
   */
  virtual Resultado Executar(const Email &) = 0;

  /**
   * @brief função abstrata que irá Seta o controle para a parte
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
   * @brief função abstrata que irá apresentar os vocabularios disponiveis.
   *
   * @return vector<VocabularioControlado> o vetor que possui os vocabularios.
   */
  virtual vector<VocabularioControlado> ConsultarVocabularios() = 0;

  /**
   * @brief função abstrata que irá apresentar os termos disponiveis.
   *
   * @return vector<Termo> o vetor que possui os termos.
   */
  virtual vector<Termo> ConsultarTermos(const VocabularioControlado &voc) = 0;

  virtual vector<Termo> ConsultarTermos() = 0;

  /**
   * @brief função abstrata que irá retornar a definição do vocabulario.
   *
   * @return Definicao a definição procurada.
   */
  virtual vector<Definicao> ConsultarDefinicao(const Termo &) = 0;

  virtual Definicao ConsultarDefinicao(const VocabularioControlado &) = 0;

  virtual vector<Definicao> ConsultarDefinicoes() = 0;

  /**
   * @brief função abstrata que irá cadastrar um leitor a um vocabulario controlado.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado CadastrarDesenvolvedor(const VocabularioControlado &, const Email &) = 0;

  virtual Resultado CadastrarAdministrador(const VocabularioControlado &, const Email &) = 0;
  /**
   * @brief função abstrata que irá Criar um Termo.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado CriarTermo(Termo &, const Nome &, const ClasseDoTermo &, const Data &, const VocabularioControlado &) = 0;

  /**
   * @brief função abstrata que irá Editar um Termo.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado EditarTermo(Termo &, const Data &) = 0;

  /**
   * @brief função abstrata que irá Excluir um Termo.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  // virtual Resultado ExcluirTermo(const Termo &) = 0;

  /**
   * @brief função abstrata que irá Criar uma Definição.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado CriarDefinicao(Definicao &,
                                   const TextoDefinicao &, const Data &) = 0;

  /**
   * @brief função abstrata que irá Editar uma Definição.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado EditarDefinicao(Definicao &, const Data &) = 0;

  /**
   * @brief função abstrata que irá Excluir uma Definição.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  // virtual Resultado ExcluirDefinicao(const Definicao &) = 0;

  /**
   * @brief função abstrata que irá Criar um Vocabulario.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado CriarVocabulario(VocabularioControlado &, const Nome &,
                              const Idioma &, const Data &, const Definicao &, const Email &) = 0;
  
  /**
   * @brief função abstrata que irá Editar um Vocabulario.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado EditarVocabulario(VocabularioControlado &, const Idioma &, 
                                      const Data &) = 0;

  /**
   * @brief função abstrata que irá Excluir um Vocabulario.
   *
   * @return Resultado sucesso ou falha na ação.
   */
  virtual Resultado ExcluirVocabulario(const VocabularioControlado &) = 0;

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
   * @brief função abstrata que direciona para a tela de gestão de vocabularios.
   *
   */
  virtual void Executar(const Email &) = 0;

  /**
   * @brief função abstrata que Seta o controle para a parte de
   * serviços de vocabulário.
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
