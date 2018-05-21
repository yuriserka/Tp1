#ifndef TRABALHO__INTERFACES__H__
#define TRABALHO__INTERFACES__H__

#include "includes.h"

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
  virtual void CadastrarLeitor() = 0;

  /**
   * @brief função abstrata que cadastra um administrador.
   *
   */
  virtual void CadastrarAdm() = 0;

  /**
   * @brief função abstrata que cadastra um desenvolvedor.
   *
   */
  virtual void CadastrarDev() = 0;

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
   * @brief função abstrata que irá criar um Leitor.
   * 
   * @return Leitor novo leitor criado.
   */
  virtual Leitor CriaLeitor(const Email &) = 0;

  /**
   * função abstrata que irá criar um Desenvolvedor.
   * 
   * @return Leitor novo Desenvolvedor criado.
   */
  virtual Desenvolvedor CriaDesenvolvedor(const Email &) = 0;

  /**
   * função abstrata que irá criar um Administrador.
   * 
   * @return Leitor novo Administrador criado.
   */
  virtual Administrador CriaAdministrador(const Email &) = 0;

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
   * @return Resultado retorna um objeto que poderá dizer se foi sucesso 
   * ou falha. 
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
 * @brief 
 * 
 */
class InterfaceServicoVocabulario {
 public:
  /**
   * @brief 
   * 
   */
  virtual vector<VocabularioControlado> ConsultarVocabularios() = 0;

  /**
   * @brief 
   * 
   * @return vector<Termo> 
   */
  virtual vector<Termo> ConsultarTermos() = 0;

  /**
   * @brief 
   * 
   * @return Definicao 
   */
  virtual Definicao ConsultarDefinicao(Termo &) = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado CadastrarDesenvolvedor(VocabularioControlado &) = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado CriarTermo() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado EditarTermo() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado ExcluirTermo() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado CriarDefinicao() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado EditarDefinicao() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado ExcluirDefinicao() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado CriarVocabulario() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado EditarVocabulario() = 0;

  /**
   * @brief 
   * 
   */
  virtual Resultado ExcluirVocabulario() = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
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
   * @brief Destrutor virtual padrão da classe.
   * 
   */
  virtual ~InterfaceApresentacaoVocabulario() = default;
};

#endif //TRABALHO_INTERFACES_H
