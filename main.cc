#include "controladores.h"
#include "stubs.h"
#include "bits/stdc++.h"

int main() {

  cout << "\tTRIGGERS\n";
  cout << "Trigger Falha de autenticacao:           " << StubAutenticacao::ktrigger_falha_ << "\n";
  cout << "Trigger Erro de Sistema:                 " << StubAutenticacao::ktrigger_erro_sistema_ << "\n";
  cout << "Trigger para entrar como Leitor:         " << StubAutenticacao::ktrigger_leitor_ << "\n";
  cout << "Trigger para entrar como Desenvolvedor:  " << StubAutenticacao::ktrigger_desenvolvedor_ << "\n";
  cout << "Trigger para entrar como Administrador:  " << StubAutenticacao::ktrigger_administrador_ << "\n";

  system(PAUSE);

  CtrlApresentacaoControle *ctrl_ac = new CtrlApresentacaoControle();
  ctrl_ac->Inicializar();
  delete ctrl_ac;
  return 0;
}
