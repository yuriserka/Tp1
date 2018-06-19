#ifndef TRABALHO__COMANDOS__H__
#define TRABALHO__COMANDOS__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file comandos.h
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief Classes de Comandos para executarem certas ações.
 * 
 * Neste arquivo estão as classes de comando que terão inteligencia suficiente
 * para executar certas ações e deixar o código das controladoras mais legível.
 * 
 * As classes de comando são usadas para aproximar a implementação ao 
 * contexto de interfaces gráficas.
 * 
 */

/**
 * @brief Classe  dos Comandos de apresentação cadastro.
 * 
 */
class ComandoACadastro {
 public:
  /**
   * @brief função virtual pura que servirá de base para as diversas outras classes de comando que
   * farão parte da parte de apresentação cadastro.
   *
   */
  virtual void Executar(InterfaceServicoCadastro *) = 0;

  /**
   * @brief Destrutor padrão da classe virtual.
   *
   */
  virtual ~ComandoACadastro() = default;
};

/**
 * @brief Classe de Comando que cadastra Leitor.
 * 
 */
class ComandoACadastroLeitor : public ComandoACadastro {
 public:
  /**
   * @brief implementa a função base e cadastra um Leitor.
   *
   */
  void Executar(InterfaceServicoCadastro *) override;
};

/**
 * @brief Classe de Comando que cadastra Administrador.
 * 
 */
class ComandoACadastroAdm : public ComandoACadastro {
 public:
  /**
   * @brief implementa a função base e cadastra um Administrador.
   *
   */
  void Executar(InterfaceServicoCadastro *) override;
};

/**
 * @brief Classe de Comando que cadastra Desenvolvedor.
 * 
 */
class ComandoACadastroDev : public ComandoACadastro {
 public:
  /**
   * @brief implementa a função base e cadastra um Desenvolvedor.
   *
   */
  void Executar(InterfaceServicoCadastro *) override;
};

/**
 * @brief Classe  dos Comandos de apresentação usuário.
 * 
 */
class ComandoAUsuario {
 public:
  /**
   * @brief  função virtual pura que servirá de base para as diversas outras classes de comando que
   * farão parte da parte de apresentação usuario.
   *
   * @return Resultado retornará sucesso ou falha.
   */
  virtual Resultado Executar(InterfaceServicoUsuario *, const Email &) = 0;

  /**
   * @brief Destrutor padrão da classe virtual.
   *
   */
  virtual ~ComandoAUsuario() = default;
};

/**
 * @brief Classe de comando que mostra as informações do usuario.
 * 
 */
class ComandoAUsuarioMostrar : public ComandoAUsuario {
 public:
  /**
   * @brief implementa a função base e mostra as informações do usuario
   * de acordo com o trigger de email passado.
   *
   * @return Resultado retornará sucesso ou falha.
   */
  Resultado Executar(InterfaceServicoUsuario *, const Email &) override;
};

/**
 * @brief Classe de comando que edita as informações do usuario.
 * 
 */
class ComandoAUsuarioEditar : public ComandoAUsuario {
 public:
  /**
   * @brief implementa a função base e edita as informações do usuario
   * de acordo com o trigger de email passado.
   * 
   * @return Resultado retornará sucesso ou falha.
   */
  Resultado Executar(InterfaceServicoUsuario *, const Email &) override;
};

/**
 * @brief Classe de comando que exclui as informações do usuario.
 * 
 */
class ComandoAUsuarioExcluir : public ComandoAUsuario {
 public:
  /**
   * @brief implementa a função base e exclui as informações do usuario.
   *
   * @return Resultado retornará sucesso ou falha.
   */
  Resultado Executar(InterfaceServicoUsuario *, const Email &) override;
};

/**
 * @brief Classe  dos comandos de apresentação de vocabulario.
 * 
 */
class ComandoAVocabulario {
 public:
  /**
  * @brief função virtual pura que servirá de base para as diversas outras classes de comando que
  * farão parte da parte de apresentação vocabulario.
  *
  */
  virtual void Executar(InterfaceServicoVocabulario *) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~ComandoAVocabulario() = default;
};

/**
 * @brief Classe  dos comandos de apresentação de vocabulario que precisam de um email para executar.
 * 
 */
class ComandoAVocabularioEmail {
 public:
  /**
  * @brief função virtual pura que servirá de base para as diversas outras classes de comando que
  * farão parte da parte de apresentação vocabulario.
  *
  */
  virtual void Executar(InterfaceServicoVocabulario *, const Email &) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~ComandoAVocabularioEmail() = default;
};

/**
 * @brief Classe  dos comandos de apresentação de vocabulario que precisam de um vocabulário para executar.
 * 
 */
class ComandoAVocabularioVoc {
 public:
  /**
  * @brief função virtual pura que servirá de base para as diversas outras classes de comando que
  * farão parte da parte de apresentação vocabulario.
  *
  */
  virtual void Executar(InterfaceServicoVocabulario *, const VocabularioControlado &) = 0;

  /**
   * @brief Destrutor virtual padrão da classe.
   *
   */
  virtual ~ComandoAVocabularioVoc() = default;
};

/**
 * @brief Classe responsável por exibir as opções de gestão de vocabulários ao leitor.
 * 
 */
class ComandoAVocabularioLeitor : public ComandoAVocabulario {
 public:
  /**
   * @brief função herdada que exibe as opções de gestão de vocabulários ao leitor.
   * 
   */
  void Executar(InterfaceServicoVocabulario *) override;

 private:
  enum {
    knull,
    klistarvocabularios,
    kvoltar
  };
};

/**
 * @brief Classe responsável por exibir as opções de gestão de vocabulários ao desenvolvedor.
 * 
 */
class ComandoAVocabularioDesenvolvedor : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief função herdada que exibe as opções de gestão de vocabulários ao desenvolvedor.
   *
   */
  void Executar(InterfaceServicoVocabulario *, const Email &) override;

 private:
  enum {
    knull,
    klistarvocabularios,
    kcadastrardesenvolvedor,
    kassociar,
    kinteragirtermo,
    kinteragirdefinicao,
    kvoltar
  };
};

/**
 * @brief Classe responsável por exibir as opções de gestão de vocabulários ao administrador.
 * 
 */
class ComandoAVocabularioAdministrador : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief função herdada que exibe as opções de gestão de vocabulários ao administrador.
   *
   */
  void Executar(InterfaceServicoVocabulario *, const Email &) override;
 private:
  enum {
    knull,
    klistarvocabularios,
    kcadastrardesenvolvedor,
    kassociar,
    kinteragirtermo,
    kinteragirdefinicao,
    kinteragirvocabulario,
    kvoltar
  };
};

/**
* @brief Classe responsável por listar vocabularios armazenados.
* 
*/
class ComandoAVocabularioListarVocabularios : public ComandoAVocabulario {
 public:
  /**
   * @brief função herdada que exibe todos os vocabulários disponíveis e permite a interação com eles.
   * 
   */
  void Executar(InterfaceServicoVocabulario *) override;
};

/**
 * @brief Classe responsável por listar termos armazenados.
 * 
 */
class ComandoAVocabularioListarTermos : public ComandoAVocabularioVoc {
 public:
  /**
   * @brief função herdada que exibe todos os termos disponíveis e permite a interação com eles.
   * 
   */
  void Executar(InterfaceServicoVocabulario *, const VocabularioControlado &) override;
};

/**
 * @brief Classe responsável por cadastrar um usuário como administrador de determinado vocabulário.
 * 
 */
class ComandoAVocabularioCadastrarAdministrador : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief função herdada que exibe os vocabulários disponíves para cadastrar-se como administrador.
   * 
   */
  void Executar(InterfaceServicoVocabulario *, const Email &) override;
 private:
  enum {
    knull,
    kcadastrar,
    kvoltar
  };
};

/**
 * @brief Classe responsável por cadastrar um usuário como desenvolvedor de determinado vocabulário.
 * 
 */
class ComandoAVocabularioCadastrarDesenvolvedor : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief função herdada que exibe os vocabulários disponíves para cadastrar-se como desenvolvedor.
   * 
   */
  void Executar(InterfaceServicoVocabulario *, const Email &) override;
 private:
  const static int kmaxdev_voc = 10;
  enum {
    knull,
    kcadastrar,
    kvoltar
  };
};

/**
* @brief Classe responsável pelas interações com termos: criar, editar e excluir.
* 
*/
class ComandoAVocabularioInteragirTermo : public ComandoAVocabulario {
 public:
  /**
    * @brief função herdada que exibe as opções de interação com termos.
    *
    */
  void Executar(InterfaceServicoVocabulario *) override;

 private:
  enum {
    knull,
    kcriar,
    keditar,
    kexcluir,
    kvoltar
  };

  void Criar(InterfaceServicoVocabulario *);
  void Editar(InterfaceServicoVocabulario *);
  void Excluir(InterfaceServicoVocabulario *);
};

/**
* @brief Classe responsável pelas interações com definições: criar, editar e excluir.
* 
*/
class ComandoAVocabularioInteragirDefinicao : public ComandoAVocabulario {
 public:
  /**
    * @brief função herdada que exibe as opções de interação com definições.
    * 
    */
  void Executar(InterfaceServicoVocabulario *) override;

 private:
  enum {
    knull,
    kcriar,
    keditar,
    kexcluir,
    kvoltar
  };

  void Criar(InterfaceServicoVocabulario *);
  void Editar(InterfaceServicoVocabulario *);
  void Excluir(InterfaceServicoVocabulario *);
};

/**
* @brief Classe responsável pelas interações com vocabulários: criar, editar e excluir.
* 
*/
class ComandoAVocabularioInteragirVocabulario : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief função herdada que exibe as opções de interação com vocabulários.
   * 
   */
  void Executar(InterfaceServicoVocabulario *, const Email &) override;

 private:
  enum {
    knull,
    kcriar,
    keditar,
    kexcluir,
    kvoltar
  };

  void Criar(InterfaceServicoVocabulario *, const Email &);
  void Editar(InterfaceServicoVocabulario *);
  void Excluir(InterfaceServicoVocabulario *);
};

/**
 * @brief Classe responsável por associar uma definição a um termo.
 * 
 */

class ComandoAVocabularioAssociar : public ComandoAVocabulario {
 public:
  /**
   * @brief função herdada que exibe as definições disponíveis para associar a termos.
   * 
   */
  void Executar(InterfaceServicoVocabulario *) override;
 private:
  const static int kmaxdef_termo = 5;
};

#endif  // TRABALHO__COMANDOS__H__