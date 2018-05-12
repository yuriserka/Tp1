#include "stubs.h"

const string StubAutenticacao::ktrigger_falha_ = "falha@gmail.com";
const string StubAutenticacao::ktrigger_erro_sistema_ = "errodesistema@gmail.com";
const string StubAutenticacao::ktrigger_leitor_ = "leitor@gmail.com";
const string StubAutenticacao::ktrigger_desenvolvedor_ = "desenvolvedor@gmail.com";
const string StubAutenticacao::ktrigger_administrador_ = "administrador@gmail.com";

Resultado StubAutenticacao::Autenticar(const Email &email, const Senha &senha) {
  ResultadoAutenticar resultado;

  if (email.GetEmail() == ktrigger_falha_) {
    resultado.SetResultado(ResultadoAutenticar::FALHA);
  } else if (email.GetEmail() == ktrigger_erro_sistema_) {
    throw ("Erro de Sistema!\n");
  } else {
    resultado.SetResultado(ResultadoAutenticar::SUCESSO);
  }
  return resultado;
}

void StubUsuario::ExibirLeitor(const Leitor &leitor) {
  system(CLEAR);
  cout << "Nome: " << leitor.GetNome().GetNome() << " ";
  cout << leitor.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << leitor.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << leitor.GetSenha().GetSenha() << "\n";
  system(PAUSE);
}

void StubUsuario::ExibirDesenvolvedor(const Desenvolvedor &desenvolvedor) {
  system(CLEAR);
  cout << "Nome: " << desenvolvedor.GetNome().GetNome() << " ";
  cout << desenvolvedor.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << desenvolvedor.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << desenvolvedor.GetSenha().GetSenha() << "\n";
  cout << "Data de Nascimento: " << desenvolvedor.GetDataDeNascimento().GetData() << "\n";
  system(PAUSE);
}

void StubUsuario::ExibirAdministrador(const Administrador &administrador) {
  system(CLEAR);
  cout << "Nome: " << administrador.GetNome().GetNome() << " ";
  cout << administrador.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << administrador.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << administrador.GetSenha().GetSenha() << "\n";
  cout << "Data de Nascimento: " << administrador.GetDataDeNascimento().GetData() << "\n";
  cout << "Telefone: " << administrador.GetTelefone().GetTelefone() << "\n";
  cout << "Endereco: " << administrador.GetEndereco().GetAddress() << "\n";
  system(PAUSE);
}

Resultado StubUsuario::Editar(const Email &email) {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
  system(PAUSE);
}

Resultado StubUsuario::Excluir(const Email &email) {
  Resultado resultado;
  if (email.GetEmail() == StubAutenticacao::ktrigger_erro_sistema_)
    resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
  system(PAUSE);
}

Leitor StubUsuario::CriaLeitor(const Email &email) {
  Leitor leitor = Leitor(
      Nome("John"), Sobrenome("Leitor"),
      Senha("Leit1234"), email
  );
  return leitor;
}

Desenvolvedor StubUsuario::CriaDesenvolvedor(const Email &email) {
  Desenvolvedor desenvolvedor = Desenvolvedor(
      Nome("John"),
      Sobrenome("Desenvolvedor"), Senha("Dese1234"),
      email, Data("01/11/2027")
  );
  return desenvolvedor;
}

Administrador StubUsuario::CriaAdministrador(const Email &email) {
  Administrador administrador = Administrador(
      Nome("John"),
      Sobrenome("Administrador"), Senha("Admi1234"),
      email, Data("01/11/2027"), Telefone("61 99803-7458"),
      Address("Avenida Future")
  );
  return administrador;
}