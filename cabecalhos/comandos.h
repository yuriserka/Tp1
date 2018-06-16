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
 * @brief Classe Abstrata dos Comandos de apresentação cadastro.
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
 * @brief Classe Abstrata dos Comandos de apresentação usuário.
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
 * @brief Classe Abstrata dos Comandos de apresentação vocabulario.
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
   * @brief Destrutor padrão da classe virtual.
   *
   */
  virtual ~ComandoAVocabulario() = default;
};

/**
 * @brief Classe Abstrata dos Comandos de apresentação vocabulario.
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
   * @brief Destrutor padrão da classe virtual.
   *
   */
  virtual ~ComandoAVocabularioEmail() = default;
};

/**
 * @brief Classe Abstrata dos Comandos de apresentação vocabulario.
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
   * @brief Destrutor padrão da classe virtual.
   *
   */
  virtual ~ComandoAVocabularioVoc() = default;
};

/**
 * @brief Classe que é responsavel pelas funcionalidades do leitor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioLeitor : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um leitor pode acessar no sistema.
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
 * @brief Classe que é responsavel pelas funcionalidades do Desenvolvedor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioDesenvolvedor : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief mostrara as funcionalidades que um desenvolvedor pode acessar no sistema.
   *
   */
  void Executar(InterfaceServicoVocabulario *, const Email &) override;

 private:
  enum {
    knull,
    klistarvocabularios,
    kcadastrardesenvolvedor,
    kinteragirtermo,
    kinteragirdefinicao,
    kvoltar
  };
};
//
/**
 * @brief Classe que é responsavel pelas funcionalidades do Administrador na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioAdministrador : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief mostrara as funcionalidades que um administrador pode acessar no sistema.
   *
   */
  void Executar(InterfaceServicoVocabulario *, const Email &) override;
 private:
  enum {
    knull,
    klistarvocabularios,
    kcadastrardesenvolvedor,
    kinteragirtermo,
    kinteragirdefinicao,
    kinteragirvocabulario,
    kvoltar
  };
};
//
///**
// * @brief Classe que é responsavel por listar os vocabularios cadastrados.
// * 
// */
class ComandoAVocabularioListarVocabularios : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as todos os vocabularios disponiveis para seleção.
   * 
   */
  void Executar(InterfaceServicoVocabulario *) override;
};

/**
 * @brief Classe que é responsavel por listar os termos cadastrados.
 * 
 */
class ComandoAVocabularioListarTermos : public ComandoAVocabularioVoc {
 public:
  /**
   * @brief  mostrara as todos os termos disponiveis para seleção.
   * 
   */
  void Executar(InterfaceServicoVocabulario *, const VocabularioControlado &) override;
};

/**
 * @brief Classe que é responsavel por Cadastrar um Desenvolvedor à algum vocabulario controlado.
 * 
 */

class ComandoAVocabularioCadastrarDesenvolvedor : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief Cadastra um Desenvolvedor à algum vocabulario controlado.
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

class ComandoAVocabularioCadastrarAdministrador : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief Cadastra um Desenvolvedor à algum vocabulario controlado.
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
* @brief Classe que é responsavel pelas ações com os Termos, tais como editar,
* exluir e criar.
* 
*/
//class ComandoAVocabularioInteragirTermo : public ComandoAVocabulario {
// public:
//  /**
//   * @brief mostrara as opções disponiveis para manipulação de Termos.
//   * 
//   */
//  void Executar(InterfaceServicoVocabulario *) override;
//
// private:
//  enum {
//    knull,
//    kcriar,
//    keditar,
//    kexcluir,
//    kvoltar
//  };
//
//  void Criar(InterfaceServicoVocabulario *);
//  void Editar(InterfaceServicoVocabulario *);
//  void Excluir(InterfaceServicoVocabulario *);
//};

/**
* @brief Classe que é responsavel pelas ações com as Definições, tais como editar,
* exluir e criar.
* 
*/
class ComandoAVocabularioInteragirDefinicao : public ComandoAVocabulario {
public:
 /**
  * @brief mostrara as opções disponiveis para manipulação de Definições.
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
//  void Editar(InterfaceServicoVocabulario *);
//  void Excluir(InterfaceServicoVocabulario *);
};

/**
* @brief Classe que é responsavel pelas ações com os Vocabularios, tais como editar,
* exluir e criar.
* 
*/
class ComandoAVocabularioInteragirVocabulario : public ComandoAVocabularioEmail {
 public:
  /**
   * @brief mostrara as opções disponiveis para manipulação de Vocabularios.
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

#endif  // TRABALHO__COMANDOS__H__