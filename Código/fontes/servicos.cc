#include "../cabecalhos/includes.h"

void CtrlServicoControle::Construir() {
  ComandoSql *servico_sql;
  servico_sql = new ComandoSqlCriarTabelas();
  servico_sql->Executar();

  InterfaceApresentacaoAutenticacao *ctrl_aa;
  InterfaceApresentacaoUsuario *ctrl_au;
  InterfaceApresentacaoVocabulario *ctrl_av;
  InterfaceApresentacaoCadastro *ctrl_ak;

  ctrl_aa = new CtrlApresentacaoAutenticacao();
  ctrl_au = new CtrlApresentacaoUsuario();
  ctrl_av = new CtrlApresentacaoVocabulario();
  ctrl_ak = new CtrlApresentacaoCadastro();

  InterfaceServicoAutenticacao *ctrl_sa;
  InterfaceServicoUsuario *ctrl_su;
  InterfaceServicoVocabulario *ctrl_sv;
  InterfaceServicoCadastro *ctrl_sk;

  ctrl_sa = new CtrlServicoAutenticacao();
  ctrl_su = new CtrlServicoUsuario();
  ctrl_sv = new CtrlServicoVocabulario();
  ctrl_sk = new CtrlServicoCadastro();

  ctrl_aa->SetCtrlServicoAutenticacao(ctrl_sa);
  ctrl_au->SetCtrlServicoUsuario(ctrl_su);
  ctrl_av->SetCtrlServicoVocabulario(ctrl_sv);
  ctrl_ak->SetCtrlServicoCadastro(ctrl_sk);

  InterfaceApresentacaoControle *ctrl_ac;

  ctrl_ac = new CtrlApresentacaoControle();

  ctrl_ac->SetCtrlApresentacaoAutenticacao(ctrl_aa);
  ctrl_ac->SetCtrlApresentacaoCadastro(ctrl_ak);
  ctrl_ac->SetCtrlApresentacaoUsuario(ctrl_au);
  ctrl_ac->SetCtrlApresentacaoVocabulario(ctrl_av);

  ctrl_ac->Inicializar();

  delete servico_sql;
  delete ctrl_aa;
  delete ctrl_au;
  delete ctrl_av;
  delete ctrl_ak;
  delete ctrl_sa;
  delete ctrl_su;
  delete ctrl_sv;
  delete ctrl_sk;
  delete ctrl_ac;
}

Resultado CtrlServicoAutenticacao::Autenticar(const Email &email, const Senha &senha) {
  ResultadoAutenticar resultado;
  ComandoSqlLerEmail *comando_e;
  comando_e = new ComandoSqlLerEmail(email);
  try {
    comando_e->Executar();
    comando_e->RecuperaEmail();
  } catch (exception &e) {
    cout << "Email nao cadastrado\n";
    delete comando_e;
    resultado.SetResultado(ResultadoAutenticar::kfalha_);
    return resultado;
  }
  delete comando_e;

  ComandoSqlLerSenha *comando_s;
  comando_s = new ComandoSqlLerSenha(email);
  try {
    comando_s->Executar();
    string senha_recuperada = comando_s->RecuperaSenha();
    if (senha.GetSenha() == senha_recuperada) {
      resultado.SetResultado(ResultadoAutenticar::ksucesso_);
    } else {
      resultado.SetResultado(ResultadoAutenticar::kfalha_);
    }
  } catch (exception &e) {
    resultado.SetResultado(ResultadoAutenticar::kfalha_);
    delete comando_s;
    throw invalid_argument("Erro de Sistema!\n");
  }
  delete comando_s;

  return resultado;
}

Resultado CtrlServicoCadastro::CadastrarLeitor(Leitor &novoleitor,
                                               const Nome &nome,
                                               const Sobrenome &sobrenome,
                                               const Senha &senha,
                                               const Email &email) {
  Resultado resultado;
  try {
    novoleitor = Leitor(nome, sobrenome, senha, email);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlLerEmail *comando;
  try {
    comando = new ComandoSqlLerEmail(novoleitor.GetEmail());
    comando->Executar();
    if (email.GetEmail() == comando->RecuperaEmail()) {
      cout << "Email ja cadastrado\n";
      delete comando;
      resultado.SetResultado(Resultado::kfalha_);
      return resultado;
    }
  } catch (exception &e) {
    // aqui não precisa colocar nada, pois se o usuario nao estiver cadastrado
    // é obvio que a lista vai estar vazia, então vai ser lançada uma exceção de
    // lista vazia, mas é exatamente isso que precisa para q possa cadastrar.
  }
  delete comando;

  ComandoSqlCadastrar *comando_cadastro;
  ComandoSqlLerEmail *comando_pesquisa;
  try {
    comando_cadastro = new ComandoSqlCadastrar(novoleitor, "leitor");
    comando_cadastro->Executar();

    comando_pesquisa = new ComandoSqlLerEmail(novoleitor.GetEmail());
    comando_pesquisa->Executar();
    string email_cadastrado = comando_pesquisa->RecuperaEmail();
    if (email_cadastrado == novoleitor.GetEmail().GetEmail()) {
      resultado.SetResultado(Resultado::ksucesso_);
    }
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    delete comando_cadastro;
    delete comando_pesquisa;
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }
  delete comando_cadastro;
  delete comando_pesquisa;
  return resultado;
}

Resultado CtrlServicoCadastro::CadastrarDev(Desenvolvedor &novodev,
                                            const Nome &nome,
                                            const Sobrenome &sobrenome,
                                            const Senha &senha,
                                            const Email &email,
                                            const Data &data) {
  Resultado resultado;
  try {
    novodev = Desenvolvedor(nome, sobrenome, senha, email, data);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlLerEmail *comando;
  try {
    comando = new ComandoSqlLerEmail(novodev.GetEmail());
    comando->Executar();
    if (email.GetEmail() == comando->RecuperaEmail()) {
      cout << "Email ja cadastrado\n";
      delete comando;
      resultado.SetResultado(Resultado::kfalha_);
      return resultado;
    }
  } catch (exception &e) {
    // aqui não precisa colocar nada, pois se o usuario nao estiver cadastrado
    // é obvio que a lista vai estar vazia, então vai ser lançada uma exceção de
    // lista vazia, mas é exatamente isso que precisa para q possa cadastrar.
  }
  delete comando;

  ComandoSqlCadastrar *comando_cadastro;
  ComandoSqlLerEmail *comando_pesquisa;
  try {
    comando_cadastro = new ComandoSqlCadastrar(novodev, "desenvolvedor");
    comando_cadastro->Executar();

    comando_pesquisa = new ComandoSqlLerEmail(novodev.GetEmail());
    comando_pesquisa->Executar();
    string email_cadastrado = comando_pesquisa->RecuperaEmail();
    if (email_cadastrado == novodev.GetEmail().GetEmail()) {
      resultado.SetResultado(Resultado::ksucesso_);
    }
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    delete comando_cadastro;
    delete comando_pesquisa;
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }
  delete comando_cadastro;
  delete comando_pesquisa;
  return resultado;
}

Resultado CtrlServicoCadastro::CadastrarAdm(Administrador &novoadm,
                                            const Nome &nome,
                                            const Sobrenome &sobrenome,
                                            const Senha &senha,
                                            const Email &email,
                                            const Data &data,
                                            const Telefone &telefone,
                                            const Address &endereco) {
  Resultado resultado;
  try {
    novoadm = Administrador(nome, sobrenome, senha, email, data, telefone, endereco);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlLerEmail *comando;
  try {
    comando = new ComandoSqlLerEmail(novoadm.GetEmail());
    comando->Executar();
    if (email.GetEmail() == comando->RecuperaEmail()) {
      cout << "Email ja cadastrado\n";
      delete comando;
      resultado.SetResultado(Resultado::kfalha_);
      return resultado;
    }
  } catch (exception &e) {
    // aqui não precisa colocar nada, pois se o usuario nao estiver cadastrado
    // é obvio que a lista vai estar vazia, então vai ser lançada uma exceção de
    // lista vazia, mas é exatamente isso que precisa para q possa cadastrar.
  }
  delete comando;

  ComandoSqlCadastrar *comando_cadastro;
  ComandoSqlLerEmail *comando_pesquisa;
  try {
    comando_cadastro = new ComandoSqlCadastrar(novoadm, "administrador");
    comando_cadastro->Executar();

    comando_pesquisa = new ComandoSqlLerEmail(novoadm.GetEmail());
    comando_pesquisa->Executar();
    string email_cadastrado = comando_pesquisa->RecuperaEmail();
    if (email_cadastrado == novoadm.GetEmail().GetEmail()) {
      resultado.SetResultado(Resultado::ksucesso_);
    }
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    delete comando_cadastro;
    delete comando_pesquisa;
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }
  delete comando_cadastro;
  delete comando_pesquisa;
  return resultado;
}

void CtrlServicoUsuario::Exibir(const Leitor &leitor) {
  cout << "Nome: " << leitor.GetNome().GetNome() << " ";
  cout << leitor.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << leitor.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << leitor.GetSenha().GetSenha() << "\n";
}

void CtrlServicoUsuario::Exibir(const Desenvolvedor &desenvolvedor) {
  cout << "Nome: " << desenvolvedor.GetNome().GetNome() << " ";
  cout << desenvolvedor.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << desenvolvedor.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << desenvolvedor.GetSenha().GetSenha() << "\n";
  cout << "Data de Nascimento: " << desenvolvedor.GetDataDeNascimento().GetData() << "\n";
}

void CtrlServicoUsuario::Exibir(const Administrador &administrador) {
  cout << "Nome: " << administrador.GetNome().GetNome() << " ";
  cout << administrador.GetSobrenome().GetSobrenome() << "\n";
  cout << "Email: " << administrador.GetEmail().GetEmail() << "\n";
  cout << "Senha: " << administrador.GetSenha().GetSenha() << "\n";
  cout << "Data de Nascimento: " << administrador.GetDataDeNascimento().GetData() << "\n";
  cout << "Telefone: " << administrador.GetTelefone().GetTelefone() << "\n";
  cout << "Endereco: " << administrador.GetEndereco().GetAddress() << "\n";
}

ResultadoUsuario CtrlServicoUsuario::Editar(const Leitor &leitor) {
  ResultadoUsuario resultado;
  resultado = AtualizaLeitor(leitor.GetEmail());
  return resultado;
}

ResultadoUsuario CtrlServicoUsuario::Editar(const Desenvolvedor &dev) {
  ResultadoUsuario resultado;
  resultado = AtualizaDesenvolvedor(dev.GetEmail());
  return resultado;
}

ResultadoUsuario CtrlServicoUsuario::Editar(const Administrador &adm) {
  ResultadoUsuario resultado;
  resultado = AtualizaAdministrador(adm.GetEmail());
  return resultado;
}

ResultadoUsuario CtrlServicoUsuario::AtualizaLeitor(const Email &email) {
  Leitor novoleitor;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;

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

ResultadoUsuario CtrlServicoUsuario::AtualizaDesenvolvedor(const Email &email) {
  Desenvolvedor novodev;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, idata;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
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

ResultadoUsuario CtrlServicoUsuario::AtualizaAdministrador(const Email &email) {
  Administrador novoadm;
  ResultadoUsuario resultado;

  string inome, isobrenome, isenha, idata, iaddres, itelefone;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
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

Resultado CtrlServicoUsuario::Excluir(const Email &email) {
  string isenha;
  Senha senha;
  Resultado resultado;
  system(CLEAR);
  cout << "Digite sua senha para confirmar: ";
  ComandoSqlLerSenha *comando_s;
  try {
    cin >> isenha;
    senha = Senha(isenha);
    comando_s = new ComandoSqlLerSenha(email);
    comando_s->Executar();
    string senha_recuperada = comando_s->RecuperaSenha();
    if (senha.GetSenha() == senha_recuperada) {
      resultado.SetResultado(ResultadoAutenticar::ksucesso_);
    } else {
      resultado.SetResultado(ResultadoAutenticar::kfalha_);
    }
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
  }
  delete comando_s;

  if (resultado.GetResultado() == ResultadoAutenticar::kfalha_) {
    cout << "Falha de autenticacao!\n";
    return resultado;
  }

  InterfaceServicoVocabulario *isv;
  ComandoSqlConsultarVocabs *comando_c;
  vector<VocabularioControlado> vocabularios;

  isv = new CtrlServicoVocabulario();
  comando_c = new ComandoSqlConsultarVocabs(email);
  comando_c->Executar();
  vocabularios = comando_c->GetVocabs();

  for (auto i : vocabularios) {
    isv->ExcluirVocabulario(i);
  }
  delete isv;
  delete comando_c;

  ComandoSqlRemover *comando_r;
  try {
    comando_r = new ComandoSqlRemover(email);
    comando_r->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando_r;
    return resultado;
  }
  delete comando_r;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

vector<VocabularioControlado> CtrlServicoVocabulario::ConsultarVocabularios() {
  ComandoSqlConsultarVocabs *comando;
  comando = new ComandoSqlConsultarVocabs();
  vector<VocabularioControlado> vocabularios;
  try {
    comando->Executar();
    vocabularios = comando->GetVocabs();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  delete comando;
  return vocabularios;
}

vector<Termo> CtrlServicoVocabulario::ConsultarTermos(const VocabularioControlado &voc) {
  ComandoSqlConsultarTermos *comando;
  comando = new ComandoSqlConsultarTermos(voc);
  vector<Termo> termos;

  try {
    comando->Executar();
    termos = comando->GetTermos();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  delete comando;
  return termos;
}

int CtrlServicoVocabulario::ConsultarTermos(const Definicao &def) {
  ComandoSqlConsultarTermos *comando;
  comando = new ComandoSqlConsultarTermos(def);
  vector<Nome> termos;

  try {
    comando->Executar();
    termos = comando->GetNomes();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  delete comando;
  return termos.size();
}

vector<Termo> CtrlServicoVocabulario::ConsultarTermos() {
  ComandoSqlConsultarTermos *comando;
  comando = new ComandoSqlConsultarTermos();
  vector<Termo> termos;

  try {
    comando->Executar();
    termos = comando->GetTermos();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  delete comando;
  return termos;
}

vector<Definicao> CtrlServicoVocabulario::ConsultarDefinicao(const Termo &termo) {
  ComandoSqlConsultarDefinicao *comando;
  comando = new ComandoSqlConsultarDefinicao(termo);
  vector<Definicao> defs;
  try {
    comando->Executar();
    defs = comando->GetDefinicoes();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
  }
  delete comando;
  return defs;
}

Definicao CtrlServicoVocabulario::ConsultarDefinicao(const VocabularioControlado &voc) {
  ComandoSqlConsultarDefinicao *comando;
  comando = new ComandoSqlConsultarDefinicao(voc);
  Definicao def;
  try {
    comando->Executar();
    def = comando->GetDefinicao();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }
  delete comando;
  return def;
}

vector<Definicao> CtrlServicoVocabulario::ConsultarDefinicoes() {
  ComandoSqlConsultarDefinicao *comando;
  comando = new ComandoSqlConsultarDefinicao();
  vector<Definicao> definicoes;
  try {
    comando->Executar();
    definicoes = comando->GetDefinicoes();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    delete comando;
  }

  delete comando;
  return definicoes;
}

int CtrlServicoVocabulario::ConsultarDesenvolvedores(const VocabularioControlado &voc) {
  ComandoSqlConsultarDevs *comando;
  comando = new ComandoSqlConsultarDevs(voc);
  vector<Email> desenvolvedores;
  try {
    comando->Executar();
    desenvolvedores = comando->GetDevs();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  delete comando;
  return desenvolvedores.size();
}

Resultado CtrlServicoVocabulario::CadastrarDesenvolvedor(const VocabularioControlado &voc,
                                                         const Email &email) {
  Resultado resultado;
  ComandoSqlAssociar *comando;
  comando = new ComandoSqlAssociar(email, voc);
  try {
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }
  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}

Resultado CtrlServicoVocabulario::CadastrarAdministrador(const VocabularioControlado &voc,
                                                         const Email &email) {
  Resultado resultado;
  ComandoSqlPesquisarUsuario *comando_pesquisar;
  ComandoSql *comando_att;
  try {
    comando_pesquisar = new ComandoSqlPesquisarUsuario(email);
    comando_pesquisar->Executar();
    Administrador adm = comando_pesquisar->GetAdm();
    comando_att = new ComandoSqlAtualizar(adm, voc);
    comando_att->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando_att;
    delete comando_pesquisar;
    return resultado;
  }
  resultado.SetResultado(Resultado::ksucesso_);
  delete comando_att;
  delete comando_pesquisar;
  return resultado;
}

Resultado CtrlServicoVocabulario::CriarTermo(Termo &termo,
                                             const Nome &nome,
                                             const ClasseDoTermo &classe,
                                             const Data &data,
                                             const VocabularioControlado &voc) {
  Resultado resultado;

  try {
    termo = Termo(nome, classe, data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlCadastrar *comando;

  try {
    comando = new ComandoSqlCadastrar(termo, voc);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}

Resultado CtrlServicoVocabulario::CriarDefinicao(Definicao &def,
                                                 const TextoDefinicao &texto,
                                                 const Data &data) {
  Resultado resultado;

  try {
    def = Definicao(texto, data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlCadastrar *comando;

  try {
    comando = new ComandoSqlCadastrar(def);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}

Resultado CtrlServicoVocabulario::CriarVocabulario(VocabularioControlado &voc,
                                                   const Nome &nome,
                                                   const Idioma &idioma,
                                                   const Data &data,
                                                   const Definicao &def,
                                                   const Email &email) {
  Resultado resultado;

  try {
    voc = VocabularioControlado(nome, idioma, data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlCadastrar *comando;

  try {
    comando = new ComandoSqlCadastrar(voc, def, email);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}

Resultado CtrlServicoVocabulario::EditarTermo(Termo &termo,
                                              const Data &data) {
  Resultado resultado;
  try {
    termo.SetData(data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlAtualizar *comando;
  try {
    comando = new ComandoSqlAtualizar(termo);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}

Resultado CtrlServicoVocabulario::EditarDefinicao(Definicao &def,
                                                  const Data &data) {
  Resultado resultado;
  try {
    def.SetData(data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlAtualizar *comando;
  try {
    comando = new ComandoSqlAtualizar(def);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}

Resultado CtrlServicoVocabulario::EditarVocabulario(VocabularioControlado &voc,
                                                    const Idioma &idioma,
                                                    const Data &data) {
  Resultado resultado;
  try {
    voc.SetIdioma(idioma);
    voc.SetData(data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    return resultado;
  }

  ComandoSqlAtualizar *comando;
  try {
    comando = new ComandoSqlAtualizar(voc);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }

  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}

Resultado CtrlServicoVocabulario::ExcluirTermo(const Termo &termo) {
  Resultado resultado;
  ComandoSqlRemover *comando;
  try {
    comando = new ComandoSqlRemover(termo);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
  }
  delete comando;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado CtrlServicoVocabulario::ExcluirDefinicao(const Definicao &def) {
  Resultado resultado;
  ComandoSqlRemover *comando;
  try {
    comando = new ComandoSqlRemover(def);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }
  delete comando;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado CtrlServicoVocabulario::ExcluirVocabulario(const VocabularioControlado &voc) {
  Resultado resultado;
  ComandoSqlRemover *comando;

  vector<Termo> termos;
  termos = ConsultarTermos(voc);

  for (auto i : termos) {
    ExcluirTermo(i);
  }

  try {
    comando = new ComandoSqlRemover(voc);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }
  delete comando;
  resultado.SetResultado(Resultado::ksucesso_);
  return resultado;
}

Resultado CtrlServicoVocabulario::AssociarTermoDefinicao(const Termo &termo,
                                                         const Definicao &definicao) {
  Resultado resultado;
  ComandoSqlAssociar *comando;
  try {
    comando = new ComandoSqlAssociar(termo, definicao);
    comando->Executar();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    resultado.SetResultado(Resultado::kfalha_);
    delete comando;
    return resultado;
  }
  resultado.SetResultado(Resultado::ksucesso_);
  delete comando;
  return resultado;
}