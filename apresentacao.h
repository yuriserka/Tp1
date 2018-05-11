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
  void ControleLogado();
  void Cadastrar();
  void TrocarConta();
};

class ApresentacaoAutenticacao {
 public:
  void Entrar();
  void VerificaLogin();
  Email email_logado_;
  bool logado_ = false;
 private:
  int tentativas = 0;
};

class ApresentacaoVocabulo {
 public:
  void Controle();
};

class ApresentacaoUsuario {
 public:
  void Controle();
 private:
  void Editar();
  void Excluir();
  void Mostrar();
};

#endif //VOC_CTRL_UI_H
