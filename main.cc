#include "controladores.h"
#include "stubs.h"
#include "bits/stdc++.h"

int main() {

  cout << "\tTRIGGERS\n";
  cout << "Trigger Falha de autenticacao:   " << StubAutenticacao::ktrigger_falha_ << "\n";
  cout << "Trigger Erro de Sistema:         " << StubAutenticacao::ktrigger_erro_sistema_ << "\n";
  cout << "Trigger para ser leitor:         " << StubAutenticacao::ktrigger_leitor_ << "\n";
  cout << "Trigger para ser desenvolvedor:  " << StubAutenticacao::ktrigger_desenvolvedor_ << "\n";
  cout << "Trigger para ser administrador:  " << StubAutenticacao::ktrigger_administrador_ << "\n";

  system(PAUSE);

  CtrlApresentacaoControle *ctrl_ac = new CtrlApresentacaoControle();
  ctrl_ac->Inicializar();
  delete ctrl_ac;
  return 0;
}
