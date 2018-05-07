#ifndef TRABALHO_INTERFACES_H
#define TRABALHO_INTERFACES_H

#include "dominios.h"

class Interfaces {
 protected:
  virtual bool Autenticar(const Email &, const Senha &) = 0;
};

#endif //TRABALHO_INTERFACES_H
