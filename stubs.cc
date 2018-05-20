#include "includes.h"

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
  InterfaceApresentacaoCadastro *ctrl_ak;

  ctrl_aa = new CtrlApresentacaoAutenticacao();
  ctrl_au = new CtrlApresentacaoUsuario();
  ctrl_av = new CtrlApresentacaoVocabulario();
  ctrl_ak = new CtrlApresentacaoCadastro();

  InterfaceServicoAutenticacao *stub_a;
  InterfaceServicoUsuario *stub_u;
  InterfaceServicoVocabulario *stub_v;
  InterfaceServicoCadastro *stub_k;

  stub_a = new StubAutenticacao();
  stub_u = new StubUsuario();
  stub_v = new StubVocabulario();
  stub_k = new StubCadastro();

  ctrl_aa->SetCtrlServicoAutenticacao(stub_a);
  ctrl_au->SetCtrlServicoUsuario(stub_u);
  ctrl_av->SetCtrlServicoVocabulario(stub_v);
  ctrl_ak->SetCtrlServicoCadastro(stub_k);

  InterfaceApresentacaoControle *ctrl_ac;

  ctrl_ac = new CtrlApresentacaoControle();

  ctrl_ac->SetCtrlApresentacaoAutenticacao(ctrl_aa);
  ctrl_ac->SetCtrlApresentacaoCadastro(ctrl_ak);
  ctrl_ac->SetCtrlApresentacaoUsuario(ctrl_au);
  ctrl_ac->SetCtrlApresentacaoVocabulario(ctrl_av);

  ctrl_ac->Inicializar();

  delete ctrl_aa;
  delete ctrl_au;
  delete ctrl_av;
  delete ctrl_ak;
  delete stub_a;
  delete stub_u;
  delete stub_v;
  delete stub_k;
  delete ctrl_ac;
}

void StubCadastro::CadastrarLeitor() {
  system(CLEAR);
  Leitor novoleitor;

  string inome, isobrenome, isenha, iemail;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;

  try {
    cout << "Digite seu Nome: ";
    cin >> inome;
    nome = Nome(inome);

    cout << "Digite seu Sobrenome: ";
    cin >> isobrenome;
    sobrenome = Sobrenome(isobrenome);

    cout << "Digite sua Senha: ";
    cin >> isenha;
    senha = Senha(isenha);

    cout << "Digite seu Email: ";
    cin >> iemail;
    email = Email(iemail);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    CadastrarLeitor();
  }

  try {
    novoleitor = Leitor(nome, sobrenome, senha, email);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
  }
}

void StubCadastro::CadastrarAdm() {
  system(CLEAR);
  Administrador novoadm;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, iemail, idata, iaddres, itelefone;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;
  Data data;
  Address endereco;
  Telefone telefone;

  try {
    cout << "Digite seu Nome: ";
    cin >> inome;
    nome = Nome(inome);

    cout << "Digite seu Sobrenome: ";
    cin >> isobrenome;
    sobrenome = Sobrenome(isobrenome);

    cout << "Digite sua Data de Nascimento: ";
    cin >> idata;
    data = Data(idata);

    cin.clear();
    cin.ignore();

    cout << "Digite seu Telefone: ";
    getline(cin, itelefone);
    telefone = Telefone(itelefone);

    cout << "Digite seu Endereco: ";
    getline(cin, iaddres);
    endereco = Address(iaddres);

    cout << "Digite sua Senha: ";
    cin >> isenha;
    senha = Senha(isenha);

    cout << "Digite seu Email: ";
    cin >> iemail;
    email = Email(iemail);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    CadastrarAdm();
  }

  try {
    novoadm = Administrador(nome, sobrenome, senha, email, data, telefone, endereco);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
  }
}

void StubCadastro::CadastrarDev() {
  system(CLEAR);
  Desenvolvedor novodev;

  string inome, isobrenome, isenha, iemail, idata;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;
  Data data;

  try {
    cout << "Digite seu Nome: ";
    cin >> inome;
    nome = Nome(inome);

    cout << "Digite seu Sobrenome: ";
    cin >> isobrenome;
    sobrenome = Sobrenome(isobrenome);

    cout << "Digite sua Data de Nascimento: ";
    cin >> idata;
    data = Data(idata);

    cin.clear();
    cin.ignore();

    cout << "Digite sua Senha: ";
    cin >> isenha;
    senha = Senha(isenha);

    cout << "Digite seu Email: ";
    cin >> iemail;
    email = Email(iemail);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    CadastrarDev();
  }

  try {
    novodev = Desenvolvedor(nome, sobrenome, senha, email, data);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
  }
}

Resultado StubAutenticacao::Autenticar(const Email &email, const Senha &senha) {
  ResultadoAutenticar resultado;

  if (email.GetEmail() == ktrigger_falha_ ||
      senha.GetSenha() == ktrigger_senha_invalida_) {
    resultado.SetResultado(ResultadoAutenticar::kfalha_);
  } else if (email.GetEmail() == ktrigger_erro_sistema_) {
    throw ("Erro de Sistema!\n");
  } else {
    resultado.SetResultado(ResultadoAutenticar::ksucesso_);
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

ResultadoUsuario StubUsuario::Editar(const Leitor &leitor) {
  ResultadoUsuario resultado;
  resultado = AtualizaLeitor();
  return resultado;
}

ResultadoUsuario StubUsuario::Editar(const Desenvolvedor &dev) {
  ResultadoUsuario resultado;
  resultado = AtualizaDesenvolvedor();
  return resultado;
}

ResultadoUsuario StubUsuario::Editar(const Administrador &adm) {
  ResultadoUsuario resultado;
  resultado = AtualizaAdministrador();
  return resultado;
}

ResultadoUsuario StubUsuario::AtualizaLeitor() {
  system(CLEAR);
  Leitor novoleitor;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, iemail;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;

  try {
    cout << "Digite seu Nome: ";
    cin >> inome;
    nome = Nome(inome);

    cout << "Digite seu Sobrenome: ";
    cin >> isobrenome;
    sobrenome = Sobrenome(isobrenome);

    cout << "Digite sua Senha: ";
    cin >> isenha;
    senha = Senha(isenha);

    cout << "Digite seu Email: ";
    cin >> iemail;
    email = Email(iemail);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    AtualizaLeitor();
  }

  try {
    novoleitor = Leitor(nome, sobrenome, senha, email);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  resultado.SetLeitorResultado(novoleitor);

  return resultado;
}

ResultadoUsuario StubUsuario::AtualizaDesenvolvedor() {
  system(CLEAR);
  Desenvolvedor novodev;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, iemail, idata;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;
  Data data;

  try {
    cout << "Digite seu Nome: ";
    cin >> inome;
    nome = Nome(inome);

    cout << "Digite seu Sobrenome: ";
    cin >> isobrenome;
    sobrenome = Sobrenome(isobrenome);

    cout << "Digite sua Data de Nascimento: ";
    cin >> idata;
    data = Data(idata);

    cin.clear();
    cin.ignore();

    cout << "Digite sua Senha: ";
    cin >> isenha;
    senha = Senha(isenha);

    cout << "Digite seu Email: ";
    cin >> iemail;
    email = Email(iemail);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    AtualizaDesenvolvedor();
  }

  try {
    novodev = Desenvolvedor(nome, sobrenome, senha, email, data);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  resultado.SetDevResultado(novodev);

  return resultado;
}

ResultadoUsuario StubUsuario::AtualizaAdministrador() {
  system(CLEAR);
  Administrador novoadm;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, iemail, idata, iaddres, itelefone;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;
  Data data;
  Address endereco;
  Telefone telefone;

  try {
    cout << "Digite seu Nome: ";
    cin >> inome;
    nome = Nome(inome);

    cout << "Digite seu Sobrenome: ";
    cin >> isobrenome;
    sobrenome = Sobrenome(isobrenome);

    cout << "Digite sua Data de Nascimento: ";
    cin >> idata;
    data = Data(idata);

    cin.clear();
    cin.ignore();

    cout << "Digite seu Telefone: ";
    getline(cin, itelefone);
    telefone = Telefone(itelefone);

    cout << "Digite seu Endereco: ";
    getline(cin, iaddres);
    endereco = Address(iaddres);

    cout << "Digite sua Senha: ";
    cin >> isenha;
    senha = Senha(isenha);

    cout << "Digite seu Email: ";
    cin >> iemail;
    email = Email(iemail);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    AtualizaAdministrador();
  }

  try {
    novoadm = Administrador(nome, sobrenome, senha, email, data, telefone, endereco);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  resultado.SetAdmResultado(novoadm);

  return resultado;
}

Resultado StubUsuario::Excluir(const Email &email) {
  Resultado resultado;
  string isenha;
  Senha senha;
  cout << "Digite sua senha para confirmar: ";
  try {
    cin >> isenha;
    senha = Senha(isenha);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_); 
    return resultado;
  }
  resultado.SetResultado(Resultado::ksucesso_);
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
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::ApresentarVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::ConsultarTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::ConsultarDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::CadastrarDesenvolvedor() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::CriarTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::EditarTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::ExcluirTermo() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::CriarDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::EditarDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::ExcluirDefinicao() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::CriarVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::EditarVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado StubVocabulario::ExcluirVocabulario() {
  Resultado resultado;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}