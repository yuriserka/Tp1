#include "controladores.h"
#include "stubs.h"

const string StubAutenticacao::ktrigger_falha_ = "falha@gmail.com";
const string StubAutenticacao::ktrigger_erro_sistema_ = "errodesistema@gmail.com";
const string StubAutenticacao::ktrigger_leitor_ = "leitor@gmail.com";
const string StubAutenticacao::ktrigger_desenvolvedor_ = "desenvolvedor@gmail.com";
const string StubAutenticacao::ktrigger_administrador_ = "administrador@gmail.com";
const string StubAutenticacao::ktrigger_senha_invalida_ = "100Nha99";

void StubControle::Construir() {
  InterfaceApresentacaoAutenticacao *ctrl_aa;
  InterfaceApresentacaoUsuario *ctrl_au;
  InterfaceApresentacaoVocabulario *ctrl_av;

  ctrl_aa = new CtrlApresentacaoAutenticacao();
  ctrl_au = new CtrlApresentacaoUsuario();
  ctrl_av = new CtrlApresentacaoVocabulario();

  InterfaceServicoAutenticacao *stub_a;
  InterfaceServicoUsuario *stub_u;
  InterfaceServicoVocabulario *stub_v;

  stub_a = new StubAutenticacao();
  stub_u = new StubUsuario();
  stub_v = new StubVocabulario();

  ctrl_aa->SetCtrlServicoAutenticacao(stub_a);
  ctrl_au->SetCtrlServicoUsuario(stub_u);
  ctrl_av->SetCtrlServicoVocabulario(stub_v);

  InterfaceApresentacaoControle *ctrl_ac;

  ctrl_ac = new CtrlApresentacaoControle();

  ctrl_ac->SetCtrlApresentacaoAutenticacao(ctrl_aa);
  ctrl_ac->SetCtrlApresentacaoUsuario(ctrl_au);
  ctrl_ac->SetCtrlApresentacaoVocabulario(ctrl_av);

  ctrl_ac->Inicializar();
}

Resultado StubAutenticacao::Autenticar(const Email &email, const Senha &senha) {
  ResultadoAutenticar resultado;

  if (email.GetEmail() == ktrigger_falha_ ||
      senha.GetSenha() == ktrigger_senha_invalida_) {
    resultado.SetResultado(ResultadoAutenticar::FALHA);
  } else if (email.GetEmail() == ktrigger_erro_sistema_) {
    throw ("Erro de Sistema!\n");
  } else {
    resultado.SetResultado(ResultadoAutenticar::SUCESSO);
  }
  return resultado;
}

void StubUsuario::Exibir(const Leitor &leitor) {
  cout << "Nome: " << leitor.GetNome().GetNome() << " ";
  cout << leitor.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << leitor.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << leitor.GetSenha().GetSenha() << "\n";
}

void StubUsuario::Exibir(const Desenvolvedor &desenvolvedor) {
  cout << "Nome: " << desenvolvedor.GetNome().GetNome() << " ";
  cout << desenvolvedor.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << desenvolvedor.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << desenvolvedor.GetSenha().GetSenha() << "\n";
  cout << "Data de Nascimento: " << desenvolvedor.GetDataDeNascimento().GetData() << "\n";
}

void StubUsuario::Exibir(const Administrador &administrador) {
  cout << "Nome: " << administrador.GetNome().GetNome() << " ";
  cout << administrador.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << administrador.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << administrador.GetSenha().GetSenha() << "\n";
  cout << "Data de Nascimento: " << administrador.GetDataDeNascimento().GetData() << "\n";
  cout << "Telefone: " << administrador.GetTelefone().GetTelefone() << "\n";
  cout << "Endereco: " << administrador.GetEndereco().GetAddress() << "\n";
}

Resultado StubUsuario::Editar(const Email &email) {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubUsuario::Excluir(const Email &email) {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
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

Resultado StubVocabulario::ListarVocabularios() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::ApresentarVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::ConsultarTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::ConsultarDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::CadastrarDesenvolvedor() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::CriarTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::EditarTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::ExcluirTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::CriarDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::EditarDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::ExcluirDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::CriarVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::EditarVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}

Resultado StubVocabulario::ExcluirVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);
  return resultado;
}