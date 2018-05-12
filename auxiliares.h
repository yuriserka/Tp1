#ifndef TRABALHO__AUX__H__
#define TRABALHO__AUX__H__

#include "dominios.h"

class Resultado {
 public:
  const static int SUCESSO = 1;
  const static int FALHA = 0;

  inline void SetResultado(int valor) {
    this->valor = valor;
  }

  inline int GetResultado() const {
    return valor;
  }
 private:
  int valor;
};

class ResultadoAutenticar : public Resultado {
 public:
  inline void SetEmailResultado(const Email &email) {
    this->email_ = email;
  }

  Email GetEmailResultado() const {
    return email_;
  }
 private:
  Email email_;
};

class ResultadoUsuario {
 public:
  const static int kok = 0;
  const static int kconta_excluida = 1;

  inline void SetResultado(int valor) {
    this->valor = valor;
  }

  inline int GetResultado() const {
    return valor;
  }
 private:
  int valor;
};

#endif // TRABALHO__AUX__H__