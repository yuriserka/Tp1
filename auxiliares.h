#ifndef TRABALHO__AUX__H__
#define TRABALHO__AUX__H__

#include "dominios.h"

/**
 * @file 
 * @author Yuri Serka e Thiago Matos
 * @date 13 de Abril de 2018
 * 
 * @brief
 * 
 */

/**
 * @brief 
 * 
 */
class Resultado {
 public:
  /**
  * @brief 
  * 
  */
  const static int SUCESSO = 1;
  /**
   * @brief 
   * 
   */
  const static int FALHA = 0;

  /**
   * @brief Set the Resultado object
   * 
   * @param valor 
   */
  inline void SetResultado(int valor) {
    this->valor = valor;
  }

  /**
   * @brief Get the Resultado object
   * 
   * @return int 
   */
  inline int GetResultado() const {
    return valor;
  }

 private:
  int valor;
};

/**
 * @brief 
 * 
 */
class ResultadoAutenticar : public Resultado {
 public:
  /**
   * @brief Set the Email Resultado object
   * 
   * @param email 
   */
  inline void SetEmailResultado(const Email &email) {
    this->email_ = email;
  }

  /**
   * @brief Get the Email Resultado object
   * 
   * @return Email 
   */
  Email GetEmailResultado() const {
    return email_;
  }

 private:
  Email email_;
};

/**
 * @brief 
 * 
 */
class ResultadoUsuario {
 public:
  /**
   * @brief 
   * 
   */
  const static int kok = 0;
  /**
   * @brief 
   * 
   */
  const static int kconta_excluida = 1;

  /**
   * @brief Set the Resultado object
   * 
   * @param valor 
   */
  inline void SetResultado(int valor) {
    this->valor = valor;
  }

  /**
   * @brief Get the Resultado object
   * 
   * @return int 
   */
  inline int GetResultado() const {
    return valor;
  }

 private:
  int valor;
};

#endif // TRABALHO__AUX__H__