#ifndef TRABALHO__COMANDOS__H__
#define TRABALHO__COMANDOS__H__

#include "interfaces.h"

class ComandoApresentacaoControle {
 public:
  virtual void Executar(InterfaceApresentacaoAutenticacao *) = 0;
  virtual ~ComandoApresentacaoControle() = default;
 private:
};

#endif  // TRABALHO__COMANDOS__H__