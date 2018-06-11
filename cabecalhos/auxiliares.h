#ifndef TRABALHO__AUX__H__
#define TRABALHO__AUX__H__

#include "../cabecalhos/../cabecalhos/includes.h"

/**
 * @file auxiliares.h
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief Arquivos com classes que irão auxiliar no retorno de objetos nas funções.
 * 
 */

/**
 * @brief Classe responsável por armazenar um valor de sucesso ou falha, 0 ou 1.
 * 
 */
class Resultado {
 public:
  /**
  * @brief constante que representará sucesso.
  * 
  */
  const static int ksucesso_ = 1;
  /**
   * @brief constante que representará falha.
   * 
   */
  const static int kfalha_ = 0;

  /**
   * @brief Seta o objeto Resultado  com um valor.
   * 
   * @param valor um inteiro que será 1 ou 0, sucesso ou falha.
   */
  inline void SetResultado(int valor) {
    this->valor_ = valor;
  }

  /**
   * @brief Retorna o atributo valor do objeto Resultado
   * 
   * @return int 0 ou 1, sucesso ou falha.
   */
  inline int GetResultado() const {
    return valor_;
  }

 private:
  int valor_;
};

/**
 * @brief Classe responsável por armazenar um valor de sucesso ou falha, 0 ou 1.
 * E além disso, armazenar um Email.
 * 
 */
class ResultadoAutenticar : public Resultado {
 public:
  /**
   * @brief Seta o Email do objeto ResultadoAutenticar
   * 
   * @param email email que será passado para setar.
   */
  inline void SetEmailResultado(const Email &email) {
    this->email_ = email;
  }

  /**
   * @brief Retorna o atributo email do objeto ResultadoAutenticar
   * 
   * @return Email email do objeto.
   */
  Email GetEmailResultado() const {
    return email_;
  }

 private:
  Email email_;
};

/**
 * @brief Classe que ajudará com retornos que envolvem as Entidades
 * 
 */
class ResultadoUsuario {
 public:

  /**
   * @brief Seta o valor do objeto ResultadoUsuario com um inteiro.
   * 
   * @param valor um inteiro que será 1 ou 0, sucesso ou falha.
   */
  inline void SetResultado(int valor) {
    this->valor_ = valor;
  }

  /**
   * @brief Seta o leitor do objeto ResultadoUsuario com um Leitor.
   * 
   * @param entidade será o leitor passado.
   */
  inline void SetLeitorResultado(const Leitor &entidade) {
    this->leitor_ = entidade;
  }

  /**
   * @brief Seta o desenvolvedor do objeto ResultadoUsuario com um Desenvolvedor.
   * 
   * @param entidade será o Desenvolvedor passado.
   */
  inline void SetDevResultado(const Desenvolvedor &entidade) {
    this->dev_ = entidade;
  }

  /**
   * @brief Seta o administrador do objeto ResultadoUsuario com um Administrador.
   * 
   * @param entidade será o Administrador passado.
   */
  inline void SetAdmResultado(const Administrador &entidade) {
    this->adm_ = entidade;
  }

  /**
   * @brief Retorna o atributo valor do objeto ResultadoAutenticar
   * 
   * @return int 0 ou 1, sucesso ou falha.
   */
  inline int GetResultado() const {
    return valor_;
  }

  /**
   * @brief Retorna o atributo leitor do objeto ResultadoAutenticar
   * 
   * @return Leitor o leitor que foi setado.
   */
  inline Leitor GetLeitor() const {
    return leitor_;
  }

  /**
   * @brief Retorna o atributo desenvolvedor do objeto ResultadoAutenticar
   * 
   * @return Desenvolvedor o desenvolvedor que foi setado.
   */
  inline Desenvolvedor GetDev() const {
    return dev_;
  }

  /**
   * @brief Retorna o atributo administrador do objeto ResultadoAutenticar
   * 
   * @return Administrador o administrador que foi setado.
   */
  inline Administrador GetAdm() const {
    return adm_;
  }

 private:
  int valor_;
  Leitor leitor_;
  Desenvolvedor dev_;
  Administrador adm_;
};

#endif // TRABALHO__AUX__H__