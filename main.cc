#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladores.h"
#include "stubs.h"
#include "bits/stdc++.h"

int main() {
  InterfaceApresentacaoAutenticacao *ctrl_iaa;
  InterfaceServicoAutenticacao *stub_isa;
  ctrl_iaa = new CtrlApresentacaoAutenticacao();
  stub_isa = new StubAutenticacao();

  ctrl_iaa->SetCtrlServicoAutenticacao(stub_isa);

  cout << "VALOR DOS TRIGGERS:\n";
  cout << "Trigger de falha           = " << StubAutenticacao::ktrigger_falha_ << "\n";
  cout << "Trigger de erro de sistema = " << StubAutenticacao::ktrigger_erro_sistema_ << "\n";

  system(PAUSE);

  ResultadoAutenticar resultado;

  while(true) {
    try {
      resultado = ctrl_iaa->Autenticar();
      if (resultado.GetResultado() == ResultadoAutenticar::SUCESSO) {
        break;
      }

    } catch (exception &e) {
      cout << "\n\t" << e.what() << "\n";
    }
    system(PAUSE);
  }

  delete ctrl_iaa;
  delete stub_isa;

  return 0;
}


