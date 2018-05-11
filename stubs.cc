#include "stubs.h"

const string StubAutenticacao::ktrigger_falha_ = "falha@hotmail.com";
const string StubAutenticacao::ktrigger_erro_sistema_ = "ErroDeSistema@gmail.com";
const string StubAutenticacao::ktrigger_leitor_ = "leitor@gmail.com";
const string StubAutenticacao::ktrigger_desenvolvedor_ = "desenvolvedor@gmail.com";
const string StubAutenticacao::ktrigger_administrador_ = "administrador@gmail.com";

Resultado StubAutenticacao::Autenticar(const Email &email, const Senha &senha) {
  cout << "Email passado como arg: " << email.GetEmail() << "\n";
  cout << "Senha passado como arg: " << senha.GetSenha() << "\n";

  ResultadoAutenticar resultado;

  if (email.GetEmail() == ktrigger_falha_) {
    resultado.SetResultado(ResultadoAutenticar::FALHA);
  } else if (email.GetEmail() == ktrigger_erro_sistema_) {
    throw("Erro de Sistema!\n");
    } else {
        resultado.SetResultado(ResultadoAutenticar::SUCESSO);
      }
  return resultado;
}