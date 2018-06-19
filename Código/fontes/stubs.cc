/*
#include "../cabecalhos/includes.h"

const string StubAutenticacao::ktrigger_erro_sistema_ = "errodesistema@gmail.com";
const string StubAutenticacao::ktrigger_falha_ = "falha@gmail.com";
const string StubAutenticacao::ktrigger_senha_invalida_ = "100Nha99";
const string StubAutenticacao::ktrigger_leitor_ = "leitor@gmail.com";
const string StubAutenticacao::ktrigger_desenvolvedor_ = "desenvolvedor@gmail.com";
const string StubAutenticacao::ktrigger_administrador_ = "administrador@gmail.com";
const string StubVocabulario::ktrigger_cadastro_valido_ = "Exemplo";
const string StubVocabulario::ktrigger_cadastro_invalido_ = "Teste";
const string StubVocabulario::ktrigger_criar_termo_invalido_ = "Invalido";
const string StubVocabulario::ktrigger_criar_definicao_invalida_ = "Invalida";
const string StubVocabulario::ktrigger_criar_vocabulario_invalido_ = "Invalido";
const string StubVocabulario::ktrigger_excluir_termo_valido_ = "Vocabulario";
const string StubVocabulario::ktrigger_excluir_termo_invalido_ = "Controle";
const string StubVocabulario::ktrigger_excluir_definicao_valida_ = "Decodificador de palavras";
const string StubVocabulario::ktrigger_excluir_definicao_invalida_ = "Efeito de controlar";
const string StubVocabulario::ktrigger_excluir_vocabulario_valido_ = "Exemplo";
const string StubVocabulario::ktrigger_excluir_vocabulario_invalido_ = "Teste";

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

Resultado StubAutenticacao::Autenticar(const Email &email, const Senha &senha) {
  ResultadoAutenticar resultado;

  if (email.GetEmail() == ktrigger_falha_ ||
      senha.GetSenha() == ktrigger_senha_invalida_) {
    resultado.SetResultado(ResultadoAutenticar::kfalha_);
  } else if (email.GetEmail() == ktrigger_erro_sistema_) {
    throw invalid_argument("Erro de Sistema!\n");
  } else {
    resultado.SetResultado(ResultadoAutenticar::ksucesso_);
  }
  return resultado;
}

ResultadoUsuario StubCadastro::CadastrarLeitor(Leitor &novoleitor, const Nome &nome,
                                        const Sobrenome &sobrenome, const Senha &senha, const Email &email) {
  ResultadoUsuario resultado;
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
  return resultado;
}

ResultadoUsuario StubCadastro::CadastrarAdm(Administrador &novoadm, const Nome &nome,
                                     const Sobrenome &sobrenome, const Senha &senha, const Email &email,
                                     const Data &data, const Telefone &telefone, const Address &endereco) {
  ResultadoUsuario resultado;
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
  return resultado;
}

ResultadoUsuario StubCadastro::CadastrarDev(Desenvolvedor &novodev,
                                     const Nome &nome,
                                     const Sobrenome &sobrenome,
                                     const Senha &senha,
                                     const Email &email,
                                     const Data &data) {
  ResultadoUsuario resultado;
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
  Leitor novoleitor;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, iemail;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;

  do {
    try {
      system(CLEAR);
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

      break;
    }
    catch (exception &e) {
      cout << "\n\t" << e.what() << "\n";
      system(PAUSE);
    }
  } while (true);

  try {
    novoleitor = Leitor(nome, sobrenome, senha, email);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  resultado.SetLeitorResultado(novoleitor);

  return resultado;
}

ResultadoUsuario StubUsuario::AtualizaDesenvolvedor() {
  Desenvolvedor novodev;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, iemail, idata;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;
  Data data;

  do {
    try {
      system(CLEAR);
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

      break;
    }
    catch (exception &e) {
      cout << "\n\t" << e.what() << "\n";
      system(PAUSE);
    }
  } while (true);

  try {
    novodev = Desenvolvedor(nome, sobrenome, senha, email, data);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  resultado.SetDevResultado(novodev);

  return resultado;
}

ResultadoUsuario StubUsuario::AtualizaAdministrador() {
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

  do {
    try {
      system(CLEAR);
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

      break;
    }
    catch (exception &e) {
      cout << "\n\t" << e.what() << "\n";
      system(PAUSE);
    }
  } while (true);

  try {
    novoadm = Administrador(nome, sobrenome, senha, email, data, telefone, endereco);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
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

  system(CLEAR);
  cout << "\tTRIGGER\n";
  cout << "Trigger Senha Invalido:   " << StubAutenticacao::ktrigger_senha_invalida_;
  cout << "\n";
  system(PAUSE);

  system(CLEAR);
  cout << "Digite sua senha para confirmar: ";
  try {
    cin >> isenha;
    senha = Senha(isenha);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  if (senha.GetSenha() == StubAutenticacao::ktrigger_senha_invalida_) {
    resultado.SetResultado(Resultado::kfalha_);
  } else {
    resultado.SetResultado(Resultado::ksucesso_);
  }

  return resultado;
}

vector<VocabularioControlado> StubVocabulario::ConsultarVocabularios() {
  VocabularioControlado null;

  Nome nome_exemplo("Exemplo");
  Idioma idioma_exemplo("POR");
  Data data_exemplo("20/05/2018");

  VocabularioControlado exemplo(nome_exemplo, idioma_exemplo, data_exemplo);

  Nome nome_teste("Teste");
  Idioma idioma_teste("POR");
  Data data_teste("20/05/2018");

  VocabularioControlado teste(nome_teste, idioma_teste, data_teste);

  vector<VocabularioControlado> vocabularios;
  vocabularios.push_back(null);
  vocabularios.push_back(exemplo);
  vocabularios.push_back(teste);

  return vocabularios;
}

vector<Termo> StubVocabulario::ConsultarTermos() {
  Termo null;

  Nome nome_controle("Controle");
  ClasseDoTermo cdt_controle("NP");
  Data data_controle("20/05/2018");

  Termo controle(nome_controle, cdt_controle, data_controle);

  Nome nome_vocabulario("Vocabulario");
  ClasseDoTermo cdt_vocabulario("PT");
  Data data_vocabulario("20/05/2018");

  Termo vocabulario(nome_vocabulario, cdt_vocabulario, data_vocabulario);

  vector<Termo> termos;
  termos.push_back(null);
  termos.push_back(controle);
  termos.push_back(vocabulario);

  return termos;
}

Definicao StubVocabulario::ConsultarDefinicao(const Termo &termo) {
  TextoDefinicao texto;
  Data data;

  if (termo.GetNome().GetNome() == "Controle") {
    texto.SetDefinicao("Efeito de controlar");
    data.SetData("13/11/2019");
  } else if (termo.GetNome().GetNome() == "Vocabulario") {
    texto.SetDefinicao("Decodificador de palavras");
    data.SetData("20/05/2018");
  }

  Definicao definicao(texto, data);
  return definicao;
}

Resultado StubVocabulario::CadastrarDesenvolvedor(const VocabularioControlado &vocabulario) {
  Resultado resultado;

  if (vocabulario.GetNome().GetNome() == StubVocabulario::ktrigger_cadastro_valido_) {
    resultado.SetResultado(Resultado::ksucesso_);
  } else if (vocabulario.GetNome().GetNome() == StubVocabulario::ktrigger_cadastro_invalido_) {
    resultado.SetResultado(Resultado::kfalha_);
  }

  return resultado;
}

Resultado StubVocabulario::CriarTermo(Termo &termo, const Nome &nome,
                                      const ClasseDoTermo &preferencia, const Data &data) {
  Resultado resultado;

  if (nome.GetNome() == ktrigger_criar_termo_invalido_) {
    resultado.SetResultado(Resultado::kfalha_);
  } else {
    termo = Termo(nome, preferencia, data);
    resultado.SetResultado(Resultado::ksucesso_);
  }

  return resultado;
}

Resultado StubVocabulario::EditarTermo(Termo &termo, const Nome &nome,
                                       const ClasseDoTermo &preferencia, const Data &data) {
  Resultado resultado;

  if (nome.GetNome() == ktrigger_criar_termo_invalido_) {
    resultado.SetResultado(Resultado::kfalha_);
  } else {
    termo = Termo(nome, preferencia, data);
    resultado.SetResultado(Resultado::ksucesso_);
  }

  return resultado;
}

Resultado StubVocabulario::ExcluirTermo(const Termo &termo) {
  Resultado resultado;

  if (termo.GetNome().GetNome() == ktrigger_excluir_termo_valido_) {
    resultado.SetResultado(Resultado::ksucesso_);
  } else if (termo.GetNome().GetNome() == ktrigger_excluir_termo_invalido_) {
    resultado.SetResultado(Resultado::kfalha_);
  }

  return resultado;
}

Resultado StubVocabulario::CriarDefinicao(Definicao &definicao, const TextoDefinicao &texto, const Data &data) {
  Resultado resultado;

  if (texto.GetDefinicao() == ktrigger_criar_definicao_invalida_) {
    resultado.SetResultado(Resultado::kfalha_);
  } else {
    definicao = Definicao(texto, data);
    resultado.SetResultado(Resultado::ksucesso_);
  }

  return resultado;
}

Resultado StubVocabulario::EditarDefinicao(Definicao &definicao, const TextoDefinicao &texto, const Data &data) {
  Resultado resultado;

  if (texto.GetDefinicao() == ktrigger_criar_definicao_invalida_) {
    resultado.SetResultado(Resultado::kfalha_);
  } else {
    definicao = Definicao(texto, data);
    resultado.SetResultado(Resultado::ksucesso_);
  }

  return resultado;
}

Resultado StubVocabulario::ExcluirDefinicao(const Definicao &definicao) {
  Resultado resultado;

  if (definicao.GetDefinicao().GetDefinicao() == ktrigger_excluir_definicao_valida_) {
    resultado.SetResultado(Resultado::ksucesso_);
  } else if (definicao.GetDefinicao().GetDefinicao() == ktrigger_excluir_definicao_invalida_) {
    resultado.SetResultado(Resultado::kfalha_);
  }

  return resultado;
}

Resultado StubVocabulario::CriarVocabulario(VocabularioControlado &vocabulario,
                                            const Nome &nome, const Idioma &idioma, const Data &data) {
  Resultado resultado;

  if (nome.GetNome() == ktrigger_criar_vocabulario_invalido_) {
    resultado.SetResultado(Resultado::kfalha_);
  } else {
    vocabulario = VocabularioControlado(nome, idioma, data);
    resultado.SetResultado(Resultado::ksucesso_);
  }
  return resultado;
}

Resultado StubVocabulario::EditarVocabulario(VocabularioControlado &vocabulario,
                                             const Nome &nome, const Idioma &idioma, const Data &data) {
  Resultado resultado;

  if (nome.GetNome() == ktrigger_criar_vocabulario_invalido_) {
    resultado.SetResultado(Resultado::kfalha_);
  } else {
    vocabulario = VocabularioControlado(nome, idioma, data);
    resultado.SetResultado(Resultado::ksucesso_);
  }
  return resultado;
}

Resultado StubVocabulario::ExcluirVocabulario(const VocabularioControlado &vocabulario) {
  Resultado resultado;

  if (vocabulario.GetNome().GetNome() == ktrigger_excluir_vocabulario_valido_) {
    resultado.SetResultado(Resultado::ksucesso_);
  } else if (vocabulario.GetNome().GetNome() == ktrigger_excluir_vocabulario_invalido_) {
    resultado.SetResultado(Resultado::kfalha_);
  }

  return resultado;
}*/