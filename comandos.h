#ifndef TRABALHO__COMANDOS__H__
#define TRABALHO__COMANDOS__H__

#include "interfaces.h"

/**
 * @file comandos.h
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief Neste arquivo estão as classes de comando que serão usadas
 * para executar certas ações e deixar o código mais legível.
 * 
 * As classes de comando são usadas para aproximar a implementação com interfaces gráficas.
 * 
 */

/**
 * @brief Classe Abstrata dos Comandos de apresentação vocabulario.
 * 
 */
class ComandoAVocabulario {
 public:
  /**
  * @brief
  *
   */
  virtual void Executar(InterfaceServicoVocabulario *) = 0;

  /**
   * @brief Destroy the Comando A Vocabulario object
   *
   */
  virtual ~ComandoAVocabulario() = default;
};

/**
 * @brief 
 * 
 */
class ComandoAVocabularioLeitor : public ComandoAVocabulario {
 public:
  /**
   * @brief
   *
   */
  void Executar(InterfaceServicoVocabulario *) override;
 private:
  enum {
    knull,
    klistarvocabularios,
    kapresentarvocabulario,
    kconsultartermo,
    kconsultardefinicao,
    kvoltar
  };
};

/**
 * @brief 
 * 
 */
class ComandoAVocabularioDesenvolvedor : public ComandoAVocabulario {
 public:
  /**
   * @brief
   *
   */
  void Executar(InterfaceServicoVocabulario *) override;
 private:
  enum {
    knull,
    klistarvocabularios,
    kapresentarvocabulario,
    kconsultartermo,
    kconsultardefinicao,
    kcadastrardesenvolvedor,
    kcriartermo,
    keditartermo,
    kexcluirtermo,
    kcriardefinicao,
    keditardefinicao,
    kexcluirdefinicao,
    kvoltar
  };
};

/**
 * @brief 
 * 
 */
class ComandoAVocabularioAdministrador : public ComandoAVocabulario {
 public:
  /**
   * @brief
   *
   */
  void Executar(InterfaceServicoVocabulario *) override;
 private:
  enum {
    knull,
    klistarvocabularios,
    kapresentarvocabulario,
    kconsultartermo,
    kconsultardefinicao,
    kcadastrardesenvolvedor,
    kcriartermo,
    keditartermo,
    kexcluirtermo,
    kcriardefinicao,
    keditardefinicao,
    kexcluirdefinicao,
    kcriarvocabulario,
    keditarvocabulario,
    kexcluirvocabulario,
    kvoltar
  };
};

/**
 * @brief Classe Abstrata dos Comandos de apresentação usuário.
 * 
 */
class ComandoAUsuario {
 public:
  /**
   * @brief
   *
   * @param email
   */
  virtual Resultado Executar(InterfaceServicoUsuario *, const Email &email) = 0;

  /**
   * @brief Destroy the Comando A Usuario object
   *
   */
  virtual ~ComandoAUsuario() = default;
};

/**
 * @brief 
 * 
 */
class ComandoAUsuarioEditar : public ComandoAUsuario {
 public:
  /**
   * @brief
   *
   * @param email
   */
  Resultado Executar(InterfaceServicoUsuario *, const Email &email) override;
};

/**
 * @brief 
 * 
 */
class ComandoAUsuarioMostrar : public ComandoAUsuario {
 public:
  /**
   * @brief
   *
   * @param email
   */
  Resultado Executar(InterfaceServicoUsuario *, const Email &email) override;
};

/**
 * @brief 
 * 
 */
class ComandoAUsuarioExcluir : public ComandoAUsuario {
 public:
  /**
   * @brief
   *
   * @param email
   */
  Resultado Executar(InterfaceServicoUsuario *, const Email &email) override;
};

#endif  // TRABALHO__COMANDOS__H__