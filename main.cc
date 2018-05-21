#include "includes.h"

int main() {

  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Erro de Sistema:    " << StubAutenticacao::ktrigger_erro_sistema_;
  cout << "\n";
  cout << "Trigger Email Invalido:     " << StubAutenticacao::ktrigger_falha_;
  cout << "\n";
  cout << "Trigger Senha Invalida:     " << StubAutenticacao::ktrigger_senha_invalida_;
  cout << "\n";
  cout << "Trigger para Leitor:        " << StubAutenticacao::ktrigger_leitor_;
  cout << "\n";
  cout << "Trigger para Desenvolvedor: " << StubAutenticacao::ktrigger_desenvolvedor_;
  cout << "\n";
  cout << "Trigger para Administrador: " << StubAutenticacao::ktrigger_administrador_;
  cout << "\n\n";
  system(PAUSE);

  InterfaceServicoControle *stub_c;
  stub_c = new StubControle();
  stub_c->Construir();

  delete stub_c;

  return 0;
}
