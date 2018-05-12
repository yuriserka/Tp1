#include "controladores.h"
#include "stubs.h"
#include "bits/stdc++.h"

int main() {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Email Invalido:      " << StubAutenticacao::ktrigger_falha_;
  cout << "\n";
  cout << "Trigger Senha Invalida:      " << StubAutenticacao::ktrigger_senha_invalida_;
  cout << "\n";
  cout << "Trigger Erro de Sistema:     " << StubAutenticacao::ktrigger_erro_sistema_;
  cout << "\n";
  cout << "Trigger para Leitor:         " << StubAutenticacao::ktrigger_leitor_;
  cout << "\n";
  cout << "Trigger para Desenvolvedor:  " << StubAutenticacao::ktrigger_desenvolvedor_;
  cout << "\n";
  cout << "Trigger para Administrador:  " << StubAutenticacao::ktrigger_administrador_;
  cout << "\n\n";
  system(PAUSE);

  InterfaceApresentacaoControle *ctrl_ac = new CtrlApresentacaoControle();
  ctrl_ac->Inicializar();
  delete ctrl_ac;

  return 0;
}
