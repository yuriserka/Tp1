#ifndef VOC_CTRL_UI_H
#define VOC_CTRL_UI_H

#include "bits/stdc++.h"
#include "servicos.h"

using namespace std;

class ApresentacaoControle {
 public:
  inline void RunMenu() {
    Controle();
  }
  void Controle();
  void Selecao();
  ServicoAutenticacao sa = ServicoAutenticacao();
};

class ApresentacaoAutenticacao : public ServicoAutenticacao {
 public:
  void Entrar();
  ServicoAutenticacao sa = ServicoAutenticacao();
};

#endif //VOC_CTRL_UI_H
