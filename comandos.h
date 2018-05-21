#ifndef TRABALHO__COMANDOS__H__
#define TRABALHO__COMANDOS__H__

#include "includes.h"

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
   * @param Email trigger de email do usuario.
   * @param InterfaceServicoUsuario interface que será necessaria para poder usar
   * as stubs.
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
   * @param Email email do usuario.
   * @param InterfaceServicoUsuario interface que será necessaria para poder usar
   * as stubs.
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
   * @param Email email do usuario.
   * @param InterfaceServicoUsuario interface que será necessaria para poder usar
   * as stubs.
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
   * @param Email email do usuario.
   * @param InterfaceServicoUsuario interface que será necessaria para poder usar
   * as stubs.
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
 * @brief Classe que responsavel pelas funcionalidades do leitor na apresentacao
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
 * @brief Classe que responsavel pelas funcionalidades do Desenvolvedor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioDesenvolvedor : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um desenvolvedor pode acessar no sistema.
   *
   */
  void Executar(InterfaceServicoVocabulario *) override;

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

/**
 * @brief Classe que responsavel pelas funcionalidades do Administrador na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioAdministrador : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um administrador pode acessar no sistema.
   *
   */
  void Executar(InterfaceServicoVocabulario *) override;

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

/**
 * @brief Classe que responsavel pelas funcionalidades do leitor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioListarVocabularios : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um leitor pode acessar no sistema.
   * 
   */
  void Executar(InterfaceServicoVocabulario *) override;
};

/**
 * @brief Classe que responsavel pelas funcionalidades do leitor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioListarTermos : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um leitor pode acessar no sistema.
   * 
   */
  void Executar(InterfaceServicoVocabulario *) override;
};

/**
 * @brief Classe que responsavel pelas funcionalidades do leitor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioCadastrarDesenvolvedor : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um leitor pode acessar no sistema.
   * 
   */
  void Executar(InterfaceServicoVocabulario *) override;
};

/**
 * @brief Classe que responsavel pelas funcionalidades do leitor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioInteragirTermo : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um leitor pode acessar no sistema.
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
};

/**
 * @brief Classe que responsavel pelas funcionalidades do leitor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioInteragirDefinicao : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um leitor pode acessar no sistema.
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
};

/**
 * @brief Classe que responsavel pelas funcionalidades do leitor na apresentacao
 * de vocabulario.
 * 
 */
class ComandoAVocabularioInteragirVocabulario : public ComandoAVocabulario {
 public:
  /**
   * @brief mostrara as funcionalidades que um leitor pode acessar no sistema.
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
};

#endif  // TRABALHO__COMANDOS__H__