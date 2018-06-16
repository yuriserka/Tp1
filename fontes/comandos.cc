#include "../cabecalhos/includes.h"

void ComandoACadastroLeitor::Executar(InterfaceServicoCadastro *isc) {
  Leitor novoleitor; 
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
  
  Resultado res = isc->CadastrarLeitor(novoleitor, nome, sobrenome, senha, email);
  if (res.GetResultado() == Resultado::ksucesso_) {
    cout << "Cadastrado com sucesso!\n";
  } else {
    cout << "Falha ao cadastrar!\n";
  }
}

void ComandoACadastroAdm::Executar(InterfaceServicoCadastro *isc) {
  Administrador novoadm;

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

  Resultado res = isc->CadastrarAdm(novoadm, nome, sobrenome, senha, email,
                                         data, telefone, endereco);
  
  if (res.GetResultado() == Resultado::ksucesso_) {
    cout << "Cadastrado com sucesso!\n";
  } else {
    cout << "Falha ao cadastrar!\n";
  }
}

void ComandoACadastroDev::Executar(InterfaceServicoCadastro *isc) {
  system(CLEAR);
  Desenvolvedor novodev;

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
  } while(true);
  
  Resultado res = isc->CadastrarDev(novodev, nome, sobrenome, senha, 
                                          email, data);
  if (res.GetResultado() == Resultado::ksucesso_) {
    cout << "Cadastrado com sucesso!\n";
  } else {
    cout << "Falha ao cadastrar!\n";
  }
}

Resultado ComandoAUsuarioMostrar::Executar(InterfaceServicoUsuario *isu, const Email &email) {
  Resultado res;
  ComandoSqlTipoConta *cmd_tc = new ComandoSqlTipoConta(email);
  
  try {
    cmd_tc->Executar();
    string tipo_conta = cmd_tc->RecuperaConta();
    delete cmd_tc;
    if ("leitor" == tipo_conta) {
      ComandoSqlPesquisarUsuario *comando = new ComandoSqlPesquisarUsuario(email);
      comando->Executar();
      Leitor l = comando->GetLeitor();
      isu->Exibir(l);
      delete comando;
    } else if ("desenvolvedor" == tipo_conta) {
      ComandoSqlPesquisarUsuario *comando = new ComandoSqlPesquisarUsuario(email);
      comando->Executar();
      Desenvolvedor d = comando->GetDev();
      isu->Exibir(d);
      delete comando;
    } else if ("administrador" == tipo_conta) {
      ComandoSqlPesquisarUsuario *comando = new ComandoSqlPesquisarUsuario(email);
      comando->Executar();
      Administrador a = comando->GetAdm();
      isu->Exibir(a);
      delete comando;
    } 
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    res.SetResultado(Resultado::kfalha_);
    delete cmd_tc;
    return res;
  }
  res.SetResultado(Resultado::ksucesso_);
  return res;
}

Resultado ComandoAUsuarioEditar::Executar(InterfaceServicoUsuario *isu, const Email &email) {
  ResultadoUsuario res;
  Resultado result;

  ComandoSqlTipoConta *cmd_tc = new ComandoSqlTipoConta(email);
  try {
    cmd_tc->Executar();
    string tipo_conta = cmd_tc->RecuperaConta();
    delete cmd_tc;
    if ("leitor" == tipo_conta) {
      ComandoSqlPesquisarUsuario *comando = new ComandoSqlPesquisarUsuario(email);
      comando->Executar();
      Leitor leitor = comando->GetLeitor();
      delete comando;
      res = isu->Editar(leitor);
      ComandoSqlAtualizar *comando_att = new ComandoSqlAtualizar(res.GetLeitor());
      comando_att->Executar();
      delete comando_att;
    } else if ("desenvolvedor" == tipo_conta) {
      ComandoSqlPesquisarUsuario *comando = new ComandoSqlPesquisarUsuario(email);
      comando->Executar();
      Desenvolvedor dev = comando->GetDev();
      delete comando;
      res = isu->Editar(dev);
      ComandoSqlAtualizar *comando_att = new ComandoSqlAtualizar(res.GetDev());
      comando_att->Executar();
      delete comando_att;
    } else if ("administrador" == tipo_conta) {
      ComandoSqlPesquisarUsuario *comando = new ComandoSqlPesquisarUsuario(email);
      comando->Executar();
      Administrador adm = comando->GetAdm();
      delete comando;
      res = isu->Editar(adm);
      ComandoSqlAtualizar *comando_att = new ComandoSqlAtualizar(res.GetAdm());
      comando_att->Executar();
      delete comando_att;
    } 
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    result.SetResultado(Resultado::kfalha_);
  }

  if (res.GetResultado() == Resultado::ksucesso_) {
    cout << "Conta modificada com sucesso.\n";
  } else {
    cout << "Erro ao modificar conta.\n";
  }

  result.SetResultado(res.GetResultado());
  system(PAUSE);
  return result;
}

Resultado ComandoAUsuarioExcluir::Executar(InterfaceServicoUsuario *isu, const Email &email) {
  Resultado res;
  res = isu->Excluir(email);

  if (res.GetResultado() == Resultado::ksucesso_) {
    cout << "Conta excluida com sucesso\n";
  } else {
    cout << "Erro ao excluir conta\n";
  }

  system(PAUSE);
  return res;
}

void ComandoAVocabularioLeitor::Executar(InterfaceServicoVocabulario *isv) {
  ComandoAVocabulario *comando;

  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Vocabulos\n";
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << klistarvocabularios << ". Listar Vocabularios\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case klistarvocabularios:comando = new ComandoAVocabularioListarVocabularios();
        comando->Executar(isv);
        delete comando;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioDesenvolvedor::Executar(InterfaceServicoVocabulario *isv, const Email &email) {
  ComandoAVocabulario * comando_v;
  ComandoAVocabularioEmail *comando_e;

  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Vocabulos\n";
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << klistarvocabularios << ". Listar Vocabularios\n";
    cout << kcadastrardesenvolvedor << ". Cadastrar Vocabulario\n";
    cout << kinteragirtermo << ". Interagir com Termos\n";
    cout << kinteragirdefinicao << ". Interagir com Definicoes\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case klistarvocabularios:
        comando_v = new ComandoAVocabularioListarVocabularios();
        comando_v->Executar(isv);
        delete comando_v;
        break;
      case kcadastrardesenvolvedor:
        comando_e = new ComandoAVocabularioCadastrarDesenvolvedor();
        comando_e->Executar(isv, email);
        delete comando_e;
        break;
      case kinteragirtermo:
        comando_v = new ComandoAVocabularioInteragirTermo();
        comando_v->Executar(isv);
        delete comando_v;
        break;
      case kinteragirdefinicao:
        comando_v = new ComandoAVocabularioInteragirDefinicao();
        comando_v->Executar(isv);
        delete comando_v;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioAdministrador::Executar(InterfaceServicoVocabulario *isv, const Email &email) {
  ComandoAVocabulario * comando_v;
  ComandoAVocabularioEmail *comando_e;

  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Vocabulos\n";
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << klistarvocabularios << ". Listar Vocabularios\n";
    cout << kcadastrardesenvolvedor << ". Cadastrar Vocabulario\n";
    cout << kinteragirtermo << ". Interagir com Termos\n";
    cout << kinteragirdefinicao << ". Interagir com Definicoes\n";
    cout << kinteragirvocabulario << ". Interagir com Vocabularios\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case klistarvocabularios:
        comando_v = new ComandoAVocabularioListarVocabularios();
        comando_v->Executar(isv);
        delete comando_v;
        break;
      case kcadastrardesenvolvedor:
        comando_e = new ComandoAVocabularioCadastrarAdministrador();
        comando_e->Executar(isv, email);
        delete comando_e;
        break;
      case kinteragirtermo:
        comando_v = new ComandoAVocabularioInteragirTermo();
        comando_v->Executar(isv);
        delete comando_v;
        break;
      case kinteragirdefinicao:
        comando_v = new ComandoAVocabularioInteragirDefinicao();
        comando_v->Executar(isv);
        delete comando_v;
        break;
      case kinteragirvocabulario:
        comando_e = new ComandoAVocabularioInteragirVocabulario();
        comando_e->Executar(isv, email);
        delete comando_e;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioListarVocabularios::Executar(InterfaceServicoVocabulario *isv) {
  ComandoAVocabularioVoc *comando;
  vector<VocabularioControlado> vocabularios;

  try {
    vocabularios = isv->ConsultarVocabularios();
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  int voltar = vocabularios.size() + 1;
  int opt;
  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 0; i < voltar - 1; i++) {
      cout << i + 1 << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para apresentar os termos deste vocabulario.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      comando = new ComandoAVocabularioListarTermos();
      comando->Executar(isv, vocabularios[opt - 1]);
      delete comando;
    }
  } while (opt != voltar);
}

void ComandoAVocabularioListarTermos::Executar(InterfaceServicoVocabulario *isv, const VocabularioControlado &voc) {
  Definicao definicao;
  try {
    definicao = isv->ConsultarDefinicao(voc);
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  vector<Termo> termos;
  try {
    termos = isv->ConsultarTermos(voc);
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  int voltar = termos.size() + 1;
  int opt;
  do {
    system(CLEAR);
    cout << "\tDefinicao do Vocabulario: " << definicao.GetDefinicao().GetDefinicao() << "\n";
    cout << "\tData da Definicao: " << definicao.GetData().GetData() << "\n\n";
    cout << "Termos do Vocabulario" << "\n\n";
    for (int i = 0; i < voltar - 1; i++) {
      cout << i + 1 << ". " << termos[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos termos acima para apresentar informacoes sobre este termo.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    vector<Definicao> defs;
    try {
      defs = isv->ConsultarDefinicao(termos[opt - 1]);
    } catch(exception &e) {
      cout << "\n\t" << e.what() << "\n";
      system(PAUSE);
      return;
    }
    if (opt < voltar && opt > 0) {
      system(CLEAR);
      cout << "Nome do Termo: " << termos[opt - 1].GetNome().GetNome() << "\n";
      cout << "Classe do Termo: " << termos[opt - 1].GetPreferencia().GetPreferencia() << "\n";
      cout << "Data do Termo: " << termos[opt - 1].GetData().GetData() << "\n\n";
      for (auto e : defs) {
        cout << "\tDefinicao do Termo: " << e.GetDefinicao().GetDefinicao() << "\n";
        cout << "\tData da Definicao: " << e.GetData().GetData() << "\n";
      }
      system(PAUSE);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioCadastrarDesenvolvedor::Executar(InterfaceServicoVocabulario *isv, 
                                                        const Email &email) {
  Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  try {
    vocabularios = isv->ConsultarVocabularios(); 
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }
  
  int voltar = vocabularios.size() + 1;
  int opt;

  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 0; i < voltar - 1; i++) {
      cout << i + 1 << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para se cadastrar como Desenvolvedor.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      resultado = isv->CadastrarDesenvolvedor(vocabularios[opt - 1], email);
      system(CLEAR);
      if (resultado.GetResultado() == Resultado::ksucesso_) {
        cout << "Cadastrado com Sucesso!\n";
        opt = voltar;
      } else {
        cout << "Falha ao Cadastrar!\n";
      }
      system(PAUSE);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioCadastrarAdministrador::Executar(InterfaceServicoVocabulario *isv, 
                                                        const Email &email) {
  Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  try {
    vocabularios = isv->ConsultarVocabularios(); 
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }
  
  int voltar = vocabularios.size() + 1;
  int opt;

  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 0; i < voltar - 1; i++) {
      cout << i + 1 << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para se cadastrar como Administrador.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      resultado = isv->CadastrarAdministrador(vocabularios[opt - 1], email);
      system(CLEAR);
      if (resultado.GetResultado() == Resultado::ksucesso_) {
        cout << "Cadastrado com Sucesso!\n";
        opt = voltar;
      } else {
        cout << "Falha ao Cadastrar!\n";
      }
      system(PAUSE);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioInteragirTermo::Executar(InterfaceServicoVocabulario *isv) {
  int opt;
  do {
    system(CLEAR);
    cout << "Gestao de Termos\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << kcriar << ". Criar Termo\n";
    cout << keditar << ". Editar Termo\n";
    cout << kexcluir << ". Excluir Termo\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case kcriar:Criar(isv);
        break;
      case keditar://Editar(isv);
        break;
      case kexcluir://Excluir(isv);
        break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioInteragirTermo::Criar(InterfaceServicoVocabulario *isv) {
  vector<VocabularioControlado> vocabularios;
  VocabularioControlado voc;

  try {
    vocabularios = isv->ConsultarVocabularios();
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  if(vocabularios.empty()) {
    system(CLEAR);
    cout << "Nao existem Vocabularios para associar o Termo\n";
    system(PAUSE);
    return;
  }

  int voltar = vocabularios.size() + 1;
  int opt;
  
  system(CLEAR);
  cout << "Vocabularios Disponiveis" << "\n\n";
  for (int i = 0; i < voltar - 1; i++) {
    cout << i + 1 << ". " << vocabularios[i].GetNome().GetNome() << "\n";
  }
  cout << "\n";
  cout << "Escolha um dos vocabularios acima para associar o termo que sera criado.\n\n";
  cout << voltar << ". Voltar\n\topcao: ";
  cin >> opt;
  if (opt == voltar) {
    return;
  }
  if (opt < voltar && opt > 0) {
    voc = vocabularios[opt - 1];
  }

  vector<Definicao> definicoes;
  Definicao def;

  try {
    definicoes = isv->ConsultarDefinicoes();
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  if(definicoes.empty()) {
    system(CLEAR);
    cout << "Nao existem Definicoes para associar ao Termo\n";
    system(PAUSE);
    return;
  }

  voltar = definicoes.size() + 1;
  
  system(CLEAR);
  cout << "Definicoes Disponiveis" << "\n\n";
  for (int i = 0; i < voltar - 1; i++) {
    cout << i + 1 << ". " << definicoes[i].GetDefinicao().GetDefinicao() << "\n";
  }
  cout << "\n";
  cout << "Escolha uma das definicoes acima para associar ao termo que sera criado.\n\n";
  cout << voltar << ". Voltar\n\topcao: ";
  cin >> opt;
  if (opt == voltar) {
    return;
  }
  if (opt < voltar && opt > 0) {
    def = definicoes[opt - 1];
  }

  Resultado resultado;
  Termo termo;

  string inome, ipreferencia, idata;
  Nome nome;
  ClasseDoTermo preferencia;
  Data data;

  system(CLEAR);
  try {
    cout << "Digite o Nome do Termo: ";
    cin >> inome;
    nome.SetNome(inome);

    cout << "Digite a Classe do Termo: ";
    cin >> ipreferencia;
    preferencia.SetPreferencia(ipreferencia);

    cout << "Digite a Data do Termo: ";
    cin >> idata;
    data.SetData(idata);

    resultado = isv->CriarTermo(termo, nome, preferencia, data, voc);

    system(CLEAR);
    if (resultado.GetResultado() == Resultado::ksucesso_) {
      cout << "Termo Criado com Sucesso!\n\n";
      cout << "Nome do Termo: " << termo.GetNome().GetNome() << "\n";
      cout << "Classe do Termo: " << termo.GetPreferencia().GetPreferencia() << "\n";
      cout << "Data do Termo: " << termo.GetData().GetData() << "\n";
    } else {
      cout << "Falha ao Criar Termo!\n";
    }
    system(PAUSE);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
  }

  resultado = isv->AssociarTermoDefinicao(termo, def);
}

// void ComandoAVocabularioInteragirTermo::Editar(InterfaceServicoVocabulario *isv) {
//   system(CLEAR);
//   cout << "\tTRIGGERS\n";
//   cout << "Trigger nome para Termo Invalido: " << StubVocabulario::ktrigger_criar_termo_invalido_;
//   cout << "\n\n";
//   system(PAUSE);

//   Resultado resultado;
//   vector<Termo> termos;
//   termos = isv->ConsultarTermos();
//   int voltar = termos.size();

//   int opt;
//   do {
//     system(CLEAR);
//     cout << "Termos Disponiveis" << "\n\n";
//     for (int i = 1; i < voltar; i++) {
//       cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
//     }
//     cout << "\n";
//     cout << "Escolha um dos termos acima para editar.\n\n";
//     cout << voltar << ". Voltar\n\topcao: ";
//     cin >> opt;

//     if (opt < voltar && opt > 0) {
//       Termo termo;
//       Nome nome;
//       ClasseDoTermo preferencia;
//       Data data;

//       string inome, ipreferencia, idata;

//       system(CLEAR);

//       try {
//         cout << "Digite o Nome do Termo: ";
//         cin >> inome;
//         nome.SetNome(inome);

//         cout << "Digite a Classe do Termo: ";
//         cin >> ipreferencia;
//         preferencia.SetPreferencia(ipreferencia);

//         cout << "Digite a Data do Termo: ";
//         cin >> idata;
//         data.SetData(idata);

//         resultado = isv->EditarTermo(termo, nome, preferencia, data);

//         system(CLEAR);
//         if (resultado.GetResultado() == Resultado::ksucesso_) {
//           cout << "Termo Editado com Sucesso!\n\n";
//           cout << "Nome do Termo: " << termo.GetNome().GetNome() << "\n";
//           cout << "Classe do Termo: " << termo.GetPreferencia().GetPreferencia() << "\n";
//           cout << "Data do Termo: " << termo.GetData().GetData() << "\n";
//           opt = voltar;
//         } else {
//           cout << "Falha ao Editar Termo!\n";
//         }
//         system(PAUSE);
//       }
//       catch (exception &e) {
//         cout << "\n\t" << e.what() << "\n";
//         system(PAUSE);
//       }
//     }
//   } while (opt != voltar);
// }

// void ComandoAVocabularioInteragirTermo::Excluir(InterfaceServicoVocabulario *isv) {
//   system(CLEAR);
//   cout << "\tTRIGGERS\n";
//   cout << "Trigger Termo Excluivel:     " << StubVocabulario::ktrigger_excluir_termo_valido_;
//   cout << "\nTrigger Termo nao Excluivel: " << StubVocabulario::ktrigger_excluir_termo_invalido_;
//   cout << "\n\n";
//   system(PAUSE);

//   Resultado resultado;
//   vector<Termo> termos;
//   termos = isv->ConsultarTermos();
//   int voltar = termos.size();

//   int opt;
//   do {
//     system(CLEAR);
//     cout << "Termos Disponiveis" << "\n\n";
//     for (int i = 1; i < voltar; i++) {
//       cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
//     }
//     cout << "\n";
//     cout << "Escolha um dos termos acima para excluir.\n\n";
//     cout << voltar << ". Voltar\n\topcao: ";
//     cin >> opt;

//     if (opt < voltar && opt > 0) {
//       resultado = isv->ExcluirTermo(termos[opt]);
//       system(CLEAR);
//       if (resultado.GetResultado() == Resultado::ksucesso_) {
//         cout << "Termo Excluido com Sucesso!\n\n";
//         opt = voltar;
//       } else {
//         cout << "Falha ao Excluir Termo!\n";
//       }
//       system(PAUSE);
//     }
//   } while (opt != voltar);
// }

void ComandoAVocabularioInteragirDefinicao::Executar(InterfaceServicoVocabulario *isv) {
  int opt;
  do {
    system(CLEAR);
    cout << "Gestao de Definicoes\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << kcriar << ". Criar Definicao\n";
    cout << keditar << ". Editar Definicao\n";
    cout << kexcluir << ". Excluir Definicao\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case kcriar:Criar(isv);
        break;
      case keditar://Editar(isv);
        break;
      case kexcluir://Excluir(isv);
        break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioInteragirDefinicao::Criar(InterfaceServicoVocabulario *isv) {
  Definicao definicao;
  Resultado resultado;

  string itexto, idata;
  TextoDefinicao texto;
  Data data;

  system(CLEAR);
  try {
    cout << "Digite o Texto da Definicao: ";
    cin.clear();
    cin.ignore();
    getline(cin, itexto);
    texto.SetDefinicao(itexto);

    cout << "Digite a Data da Definicao: ";
    cin >> idata;
    data.SetData(idata);

    definicao = Definicao(texto, data);
    
    resultado = isv->CriarDefinicao(definicao, texto, data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  system(CLEAR);
  if (resultado.GetResultado() == Resultado::ksucesso_) {
    cout << "Definicao Criada com Sucesso!\n\n";
    cout << "Texto da Definicao: " << definicao.GetDefinicao().GetDefinicao() << "\n";
    cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n";
  } else {
    cout << "Falha ao Criar Definicao!\n";
  }
  system(PAUSE);
}

// void ComandoAVocabularioInteragirDefinicao::Editar(InterfaceServicoVocabulario *isv) {
//   system(CLEAR);
//   cout << "\tTRIGGERS\n";
//   cout << "Trigger texto para Definicao Invalida: " << StubVocabulario::ktrigger_criar_definicao_invalida_;
//   cout << "\n\n";
//   system(PAUSE);

//   Resultado resultado;
//   Definicao definicao;
//   vector<Termo> termos;
//   termos = isv->ConsultarTermos();
//   int voltar = termos.size();

//   int opt;
//   do {
//     system(CLEAR);
//     cout << "Termos Disponiveis" << "\n\n";
//     for (int i = 1; i < voltar; i++) {
//       cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
//     }
//     cout << "\n";
//     cout << "Escolha um dos termos acima para editar a definicao associada ao termo.\n\n";
//     cout << voltar << ". Voltar\n\topcao: ";
//     cin >> opt;

//     if (opt < voltar && opt > 0) {
//       int opcao;
//       do {
//         system(CLEAR);
//         definicao = isv->ConsultarDefinicao(termos[opt]);
//         cout << "Definicao do Termo: " << definicao.GetDefinicao().GetDefinicao() << "\n";
//         cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n\n";
//         cout << "Deseja editar esta Definicao?\n\n1. Sim\n2. Nao\n";
//         cout << "\topcao: ";
//         cin >> opcao;

//         TextoDefinicao texto;
//         Data data;
//         string itexto, idata;

//         switch (opcao) {
//           case 1:system(CLEAR);
//             try {
//               cout << "Digite o Texto da Definicao: ";
//               cin.ignore();
//               getline(cin, itexto);
//               texto.SetDefinicao(itexto);

//               cout << "Digite a Data da Definicao: ";
//               cin >> idata;
//               data.SetData(idata);

//               resultado = isv->EditarDefinicao(definicao, texto, data);

//               system(CLEAR);
//               if (resultado.GetResultado() == Resultado::ksucesso_) {
//                 cout << "Definicao Editada com Sucesso!\n\n";
//                 cout << "Texto da Definicao: " << definicao.GetDefinicao().GetDefinicao() << "\n";
//                 cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n";
//                 opt = voltar;
//               } else {
//                 cout << "Falha ao Editar Definicao!\n";
//               }
//               system(PAUSE);
//             }
//             catch (exception &e) {
//               cout << "\n\t" << e.what() << "\n";
//               system(PAUSE);
//             }
//           case 2:break;
//           default:break;
//         }
//       } while (opcao != 1 && opcao != 2);
//     }
//   } while (opt != voltar);
// }

// void ComandoAVocabularioInteragirDefinicao::Excluir(InterfaceServicoVocabulario *isv) {
//   system(CLEAR);
//   cout << "\tTRIGGERS\n";
//   cout << "Trigger Definicao Excluivel:     " << StubVocabulario::ktrigger_excluir_definicao_valida_;
//   cout << "\nTrigger Definicao nao Excluivel: " << StubVocabulario::ktrigger_excluir_definicao_invalida_;
//   cout << "\n\n";
//   system(PAUSE);

//   Resultado resultado;
//   Definicao definicao;
//   vector<Termo> termos;
//   termos = isv->ConsultarTermos();
//   int voltar = termos.size();

//   int opt;
//   do {
//     system(CLEAR);
//     cout << "Termos Disponiveis" << "\n\n";
//     for (int i = 1; i < voltar; i++) {
//       cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
//     }
//     cout << "\n";
//     cout << "Escolha um dos termos acima para excluir a definicao associada ao termo.\n\n";
//     cout << voltar << ". Voltar\n\topcao: ";
//     cin >> opt;

//     if (opt < voltar && opt > 0) {
//       int opcao;
//       do {
//         system(CLEAR);
//         definicao = isv->ConsultarDefinicao(termos[opt]);
//         cout << "Definicao do Termo: " << definicao.GetDefinicao().GetDefinicao() << "\n";
//         cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n\n";
//         cout << "Deseja excluir esta Definicao?\n\n1. Sim\n2. Nao\n";
//         cout << "\topcao: ";
//         cin >> opcao;

//         switch (opcao) {
//           case 1: resultado = isv->ExcluirDefinicao(definicao);
//             system(CLEAR);
//             if (resultado.GetResultado() == Resultado::ksucesso_) {
//               cout << "Definicao Excluida com Sucesso!\n\n";
//               opt = voltar;
//             } else {
//               cout << "Falha ao Excluir Definicao!\n";
//             }
//             system(PAUSE);
//             break;
//           case 2:break;
//           default:break;
//         }
//       } while (opcao != 1 && opcao != 2);
//     }
//   } while (opt != voltar);
// }

void ComandoAVocabularioInteragirVocabulario::Executar(InterfaceServicoVocabulario *isv, const Email &email) {
  int opt;
  do {
    system(CLEAR);
    cout << "Gestao de Vocabularios\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << kcriar << ". Criar Vocabulario\n";
    cout << keditar << ". Editar Vocabulario\n";
    cout << kexcluir << ". Excluir Vocabulario\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case kcriar:Criar(isv, email);
        break;
      case keditar:Editar(isv);
        break;
      case kexcluir:Excluir(isv);
        break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioInteragirVocabulario::Criar(InterfaceServicoVocabulario *isv, const Email &email) {
  VocabularioControlado vocabulario;
  Definicao definicao;
  Resultado resultado;

  string inome, iidioma, idata, itexto;
  Nome nome;
  Idioma idioma;
  Data data;
  TextoDefinicao texto;

  system(CLEAR);
  try {
    cout << "Digite o Texto da Definicao do Vocabulario: ";
    cin.clear();
    cin.ignore();
    getline(cin, itexto);
    texto.SetDefinicao(itexto);

    cout << "Digite a Data da Definicao do Vocabulario: ";
    cin >> idata;
    data.SetData(idata);

    definicao = Definicao(texto, data);
    
    resultado = isv->CriarDefinicao(definicao, texto, data);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  system(CLEAR);
  if (resultado.GetResultado() == Resultado::ksucesso_) {
    cout << "Definicao Criada com Sucesso!\n\n";
    cout << "Texto da Definicao: " << definicao.GetDefinicao().GetDefinicao() << "\n";
    cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n";
  } else {
    cout << "Falha ao Criar Definicao!\n";
  }
  system(PAUSE);

  try {
    system(CLEAR);

    cout << "Digite o Nome do Vocabulario: ";
    cin >> inome;
    nome.SetNome(inome);

    cout << "Digite o Idioma do Vocabulario: ";
    cin >> iidioma;
    idioma.SetIdioma(iidioma);

    cout << "Digite a Data do Vocabulario: ";
    cin >> idata;
    data.SetData(idata);

    resultado = isv->CriarVocabulario(vocabulario, nome, idioma, data, definicao, email);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }

  system(CLEAR);
  if (resultado.GetResultado() == Resultado::ksucesso_) {
    cout << "Vocabulario Criado com Sucesso!\n\n";
    cout << "Nome do Vocabulario: " << vocabulario.GetNome().GetNome() << "\n";
    cout << "Idioma do Vocabulario: " << vocabulario.GetIdioma().GetIdioma() << "\n";
    cout << "Data do Vocabulario: " << vocabulario.GetData().GetData() << "\n";
  } else {
    cout << "Falha ao Criar Vocabulario!\n";
  }
  system(PAUSE);
}

void ComandoAVocabularioInteragirVocabulario::Editar(InterfaceServicoVocabulario *isv) {
  Resultado resultado;
  vector<VocabularioControlado> vocabularios;

  try {
    vocabularios = isv->ConsultarVocabularios(); 
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }
  
  int voltar = vocabularios.size() + 1;
  int opt;

  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 0; i < voltar - 1; i++) {
      cout << i + 1 << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para Editar.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      system(CLEAR);
      VocabularioControlado vocabulario;
      Idioma idioma;
      Data data;

      string inome, iidioma, idata;

      try {
        cout << "Digite o Idioma do Vocabulario: ";
        cin >> iidioma;
        idioma = Idioma(iidioma);

        cout << "Digite a Data do Vocabulario: ";
        cin >> idata;
        data = Data(idata);

        resultado = isv->EditarVocabulario(vocabularios[opt - 1], vocabularios[opt - 1].GetNome(), idioma, data);
        system(CLEAR);
        if (resultado.GetResultado() == Resultado::ksucesso_) {
          cout << "Vocabulario Editado com Sucesso!\n\n";
          cout << "Nome do Vocabulario: " << vocabularios[opt - 1].GetNome().GetNome() << "\n";
          cout << "Idioma do Vocabulario: " << vocabularios[opt - 1].GetIdioma().GetIdioma() << "\n";
          cout << "Data do Vocabulario: " << vocabularios[opt - 1].GetData().GetData() << "\n";
          opt = voltar;
        } else {
          cout << "Falha ao Editar Vocabulario!\n";
        }
        system(PAUSE);
      }
      catch (exception &e) {
        cout << "\n\t" << e.what() << "\n";
        system(PAUSE);
      }
    }
  } while (opt != voltar);
}

void ComandoAVocabularioInteragirVocabulario::Excluir(InterfaceServicoVocabulario *isv) {
  Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  try {
    vocabularios = isv->ConsultarVocabularios(); 
  } catch(exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    return;
  }
  
  int voltar = vocabularios.size() + 1;
  int opt;

  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 0; i < voltar - 1; i++) {
      cout << i + 1 << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para Excluir.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      resultado = isv->ExcluirVocabulario(vocabularios[opt - 1]);
      system(CLEAR);
      if (resultado.GetResultado() == Resultado::ksucesso_) {
        cout << "Vocabulario Excluido com Sucesso!\n\n";
        opt = voltar;
      } else {
        cout << "Falha ao Excluir Vocabulario!\n";
      }
      system(PAUSE);
    }
  } while (opt != voltar);
}