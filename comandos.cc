#include "includes.h"

void ComandoACadastroLeitor::Executar(InterfaceServicoCadastro *isc) {
  Leitor novoleitor; 
  string inome, isobrenome, isenha, iemail;
  Nome nome;
  Sobrenome sobrenome;
  Senha senha;
  Email email;
  ComandoSql *comando;

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
  
  ResultadoUsuario res = isc->CadastrarLeitor(novoleitor, nome, sobrenome, senha, email);
  try {
    ComandoSqlLerEmail *comando = new ComandoSqlLerEmail(res.GetLeitor().GetEmail());
    comando->Executar();
    if (email.GetEmail() == comando->RecuperaEmail()) {
      cout << "Email ja cadastrado\n";
      delete comando;
      return;
    }
    delete comando; 
  } catch (ErroDePersistencia &e) {
    // aqui não precisa colocar nada, pois se o usuario nao estiver cadastrado
    // é obvio que a lista vai estar vazia, então vai ser lançada uma exceção de
    // lista vazia, mas é exatamente isso que precisa para q possa cadastrar.
  }

  try {
    comando = new ComandoSqlCadastrar(res.GetLeitor(), "leitor");
    comando->Executar();
    cout << "Cadastrado com sucesso\n";
  } catch (ErroDePersistencia &e) {
    cout << "\n\t" << e.GetMsg() << "\n";
    cout << "Falha ao Cadastrar\n";
  }
  delete comando;
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
  ComandoSql *comando;

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

  ResultadoUsuario res = isc->CadastrarAdm(novoadm, nome, sobrenome, senha, email,
                                         data, telefone, endereco);
  
  try {
    ComandoSqlLerEmail *comando = new ComandoSqlLerEmail(res.GetAdm().GetEmail());
    comando->Executar();
    if (email.GetEmail() == comando->RecuperaEmail()) {
      cout << "Email ja cadastrado\n";
      delete comando;
      return;
    }
    delete comando; 
  } catch (ErroDePersistencia &e) {
    // aqui não precisa colocar nada, pois se o usuario nao estiver cadastrado
    // é obvio que a lista vai estar vazia, então vai ser lançada uma exceção de
    // lista vazia, mas é exatamente isso que precisa para q possa cadastrar.
  }

  try {
    comando = new ComandoSqlCadastrar(res.GetAdm(), "administrador");
    comando->Executar();
    cout << "Cadastrado com sucesso\n";
  } catch (ErroDePersistencia &e) {
    cout << "\n\t" << e.GetMsg() << "\n";
    cout << "Falha ao Cadastrar\n";
  }
  delete comando;
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
  ComandoSql *comando;

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
  
  ResultadoUsuario res = isc->CadastrarDev(novodev, nome, sobrenome, senha, 
                                          email, data);
  try {
    ComandoSqlLerEmail *comando = new ComandoSqlLerEmail(res.GetDev().GetEmail());
    comando->Executar();
    if (email.GetEmail() == comando->RecuperaEmail()) {
      cout << "Email ja cadastrado\n";
      delete comando;
      return;
    }
    delete comando; 
  } catch (ErroDePersistencia &e) {
    // aqui não precisa colocar nada, pois se o usuario nao estiver cadastrado
    // é obvio que a lista vai estar vazia, então vai ser lançada uma exceção de
    // lista vazia, mas é exatamente isso que precisa para q possa cadastrar.
  }

  try {
    comando = new ComandoSqlCadastrar(res.GetDev(), "desenvolvedor");
    comando->Executar();
    cout << "Cadastrado com sucesso\n";
  } catch (ErroDePersistencia &e) {
    cout << "\n\t" << e.GetMsg() << "\n";
    cout << "Falha ao Cadastrar\n";
  }
  delete comando;
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
  } catch (ErroDePersistencia &e) {
    cout << "\n\t" << e.GetMsg() << "\n";
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
  } catch(ErroDePersistencia &e) {
    cout << "\n\t" << e.GetMsg() << "\n";
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

void ComandoAVocabularioDesenvolvedor::Executar(InterfaceServicoVocabulario *isv) {
  ComandoAVocabulario *comando;

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
      case klistarvocabularios:comando = new ComandoAVocabularioListarVocabularios();
        comando->Executar(isv);
        delete comando;
        break;
      case kcadastrardesenvolvedor:comando = new ComandoAVocabularioCadastrarDesenvolvedor();
        comando->Executar(isv);
        delete comando;
        break;
      case kinteragirtermo:comando = new ComandoAVocabularioInteragirTermo();
        comando->Executar(isv);
        delete comando;
        break;
      case kinteragirdefinicao:comando = new ComandoAVocabularioInteragirDefinicao();
        comando->Executar(isv);
        delete comando;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioAdministrador::Executar(InterfaceServicoVocabulario *isv) {
  ComandoAVocabulario *comando;

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
      case klistarvocabularios:comando = new ComandoAVocabularioListarVocabularios();
        comando->Executar(isv);
        delete comando;
        break;
      case kcadastrardesenvolvedor:comando = new ComandoAVocabularioCadastrarDesenvolvedor();
        comando->Executar(isv);
        delete comando;
        break;
      case kinteragirtermo:comando = new ComandoAVocabularioInteragirTermo();
        comando->Executar(isv);
        delete comando;
        break;
      case kinteragirdefinicao:comando = new ComandoAVocabularioInteragirDefinicao();
        comando->Executar(isv);
        delete comando;
        break;
      case kinteragirvocabulario:comando = new ComandoAVocabularioInteragirVocabulario();
        comando->Executar(isv);
        delete comando;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioListarVocabularios::Executar(InterfaceServicoVocabulario *isv) {
  ComandoAVocabulario *comando;
  vector<VocabularioControlado> vocabularios;
  vocabularios = isv->ConsultarVocabularios();
  int voltar = vocabularios.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para apresentar os termos deste vocabulario.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      comando = new ComandoAVocabularioListarTermos();
      comando->Executar(isv);
      delete comando;
    }
  } while (opt != voltar);
}

void ComandoAVocabularioListarTermos::Executar(InterfaceServicoVocabulario *isv) {
  Definicao definicao;
  vector<Termo> termos;
  termos = isv->ConsultarTermos();
  int voltar = termos.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Termos do Vocabulario" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos termos acima para apresentar informacoes sobre este termo.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      system(CLEAR);
      definicao = isv->ConsultarDefinicao(termos[opt]);
      cout << "Nome do Termo: " << termos[opt].GetNome().GetNome() << "\n";
      cout << "Classe do Termo: " << termos[opt].GetPreferencia().GetPreferencia() << "\n";
      cout << "Data do Termo: " << termos[opt].GetData().GetData() << "\n";
      cout << "Definicao do Termo: " << definicao.GetDefinicao().GetDefinicao() << "\n";
      cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n";
      system(PAUSE);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioCadastrarDesenvolvedor::Executar(InterfaceServicoVocabulario *isv) {
  Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  vocabularios = isv->ConsultarVocabularios();
  int voltar = vocabularios.size();

  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Vocabulario Cadastravel:     " << StubVocabulario::ktrigger_cadastro_valido_;
  cout << "\n";
  cout << "Trigger Vocabulario nao Cadastravel: " << StubVocabulario::ktrigger_cadastro_invalido_;
  cout << "\n\n";
  system(PAUSE);

  int opt;
  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para se cadastrar como Desenvolvedor.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      resultado = isv->CadastrarDesenvolvedor(vocabularios[opt]);
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
  vector<VocabularioControlado> vocabularios;
  vocabularios = isv->ConsultarVocabularios();

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
      case keditar:Editar(isv);
        break;
      case kexcluir:Excluir(isv);
        break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioInteragirTermo::Criar(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger nome para criar Termo Invalido: " << StubVocabulario::ktrigger_criar_termo_invalido_;
  cout << "\n\n";
  system(PAUSE);

  system(CLEAR);
  Termo termo;
  Resultado resultado;

  string inome, ipreferencia, idata;
  Nome nome;
  ClasseDoTermo preferencia;
  Data data;

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

    resultado = isv->CriarTermo(termo, nome, preferencia, data);

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
}

void ComandoAVocabularioInteragirTermo::Editar(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger nome para Termo Invalido: " << StubVocabulario::ktrigger_criar_termo_invalido_;
  cout << "\n\n";
  system(PAUSE);

  Resultado resultado;
  vector<Termo> termos;
  termos = isv->ConsultarTermos();
  int voltar = termos.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Termos Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos termos acima para editar.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      Termo termo;
      Nome nome;
      ClasseDoTermo preferencia;
      Data data;

      string inome, ipreferencia, idata;

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

        resultado = isv->EditarTermo(termo, nome, preferencia, data);

        system(CLEAR);
        if (resultado.GetResultado() == Resultado::ksucesso_) {
          cout << "Termo Editado com Sucesso!\n\n";
          cout << "Nome do Termo: " << termo.GetNome().GetNome() << "\n";
          cout << "Classe do Termo: " << termo.GetPreferencia().GetPreferencia() << "\n";
          cout << "Data do Termo: " << termo.GetData().GetData() << "\n";
          opt = voltar;
        } else {
          cout << "Falha ao Editar Termo!\n";
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

void ComandoAVocabularioInteragirTermo::Excluir(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Termo Excluivel:     " << StubVocabulario::ktrigger_excluir_termo_valido_;
  cout << "\nTrigger Termo nao Excluivel: " << StubVocabulario::ktrigger_excluir_termo_invalido_;
  cout << "\n\n";
  system(PAUSE);

  Resultado resultado;
  vector<Termo> termos;
  termos = isv->ConsultarTermos();
  int voltar = termos.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Termos Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos termos acima para excluir.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      resultado = isv->ExcluirTermo(termos[opt]);
      system(CLEAR);
      if (resultado.GetResultado() == Resultado::ksucesso_) {
        cout << "Termo Excluido com Sucesso!\n\n";
        opt = voltar;
      } else {
        cout << "Falha ao Excluir Termo!\n";
      }
      system(PAUSE);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioInteragirDefinicao::Executar(InterfaceServicoVocabulario *isv) {
  vector<VocabularioControlado> vocabularios;
  vocabularios = isv->ConsultarVocabularios();

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
      case keditar:Editar(isv);
        break;
      case kexcluir:Excluir(isv);
        break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioInteragirDefinicao::Criar(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger texto para criar Definicao Invalida: " << StubVocabulario::ktrigger_criar_definicao_invalida_;
  cout << "\n\n";
  system(PAUSE);

  system(CLEAR);
  Definicao definicao;
  Resultado resultado;

  string itexto, idata;
  TextoDefinicao texto;
  Data data;

  try {
    cout << "Digite o Texto da Definicao: ";
    cin.ignore();
    getline(cin, itexto);
    texto.SetDefinicao(itexto);

    cout << "Digite a Data da Definicao: ";
    cin >> idata;
    data.SetData(idata);

    resultado = isv->CriarDefinicao(definicao, texto, data);

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
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
  }
}

void ComandoAVocabularioInteragirDefinicao::Editar(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger texto para Definicao Invalida: " << StubVocabulario::ktrigger_criar_definicao_invalida_;
  cout << "\n\n";
  system(PAUSE);

  Resultado resultado;
  Definicao definicao;
  vector<Termo> termos;
  termos = isv->ConsultarTermos();
  int voltar = termos.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Termos Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos termos acima para editar a definicao associada ao termo.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      int opcao;
      do {
        system(CLEAR);
        definicao = isv->ConsultarDefinicao(termos[opt]);
        cout << "Definicao do Termo: " << definicao.GetDefinicao().GetDefinicao() << "\n";
        cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n\n";
        cout << "Deseja editar esta Definicao?\n\n1. Sim\n2. Nao\n";
        cout << "\topcao: ";
        cin >> opcao;

        TextoDefinicao texto;
        Data data;
        string itexto, idata;

        switch (opcao) {
          case 1:system(CLEAR);
            try {
              cout << "Digite o Texto da Definicao: ";
              cin.ignore();
              getline(cin, itexto);
              texto.SetDefinicao(itexto);

              cout << "Digite a Data da Definicao: ";
              cin >> idata;
              data.SetData(idata);

              resultado = isv->EditarDefinicao(definicao, texto, data);

              system(CLEAR);
              if (resultado.GetResultado() == Resultado::ksucesso_) {
                cout << "Definicao Editada com Sucesso!\n\n";
                cout << "Texto da Definicao: " << definicao.GetDefinicao().GetDefinicao() << "\n";
                cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n";
                opt = voltar;
              } else {
                cout << "Falha ao Editar Definicao!\n";
              }
              system(PAUSE);
            }
            catch (exception &e) {
              cout << "\n\t" << e.what() << "\n";
              system(PAUSE);
            }
          case 2:break;
          default:break;
        }
      } while (opcao != 1 && opcao != 2);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioInteragirDefinicao::Excluir(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Definicao Excluivel:     " << StubVocabulario::ktrigger_excluir_definicao_valida_;
  cout << "\nTrigger Definicao nao Excluivel: " << StubVocabulario::ktrigger_excluir_definicao_invalida_;
  cout << "\n\n";
  system(PAUSE);

  Resultado resultado;
  Definicao definicao;
  vector<Termo> termos;
  termos = isv->ConsultarTermos();
  int voltar = termos.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Termos Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos termos acima para excluir a definicao associada ao termo.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      int opcao;
      do {
        system(CLEAR);
        definicao = isv->ConsultarDefinicao(termos[opt]);
        cout << "Definicao do Termo: " << definicao.GetDefinicao().GetDefinicao() << "\n";
        cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n\n";
        cout << "Deseja excluir esta Definicao?\n\n1. Sim\n2. Nao\n";
        cout << "\topcao: ";
        cin >> opcao;

        switch (opcao) {
          case 1: resultado = isv->ExcluirDefinicao(definicao);
            system(CLEAR);
            if (resultado.GetResultado() == Resultado::ksucesso_) {
              cout << "Definicao Excluida com Sucesso!\n\n";
              opt = voltar;
            } else {
              cout << "Falha ao Excluir Definicao!\n";
            }
            system(PAUSE);
            break;
          case 2:break;
          default:break;
        }
      } while (opcao != 1 && opcao != 2);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioInteragirVocabulario::Executar(InterfaceServicoVocabulario *isv) {
  vector<VocabularioControlado> vocabularios;
  vocabularios = isv->ConsultarVocabularios();

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
      case kcriar:Criar(isv);
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

void ComandoAVocabularioInteragirVocabulario::Criar(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger nome para criar Vocabulario Invalido: " << StubVocabulario::ktrigger_criar_vocabulario_invalido_;
  cout << "\n\n";
  system(PAUSE);

  system(CLEAR);
  VocabularioControlado vocabulario;
  Resultado resultado;

  string inome, iidioma, idata;
  Nome nome;
  Idioma idioma;
  Data data;

  try {
    cout << "Digite o Nome do Vocabulario: ";
    cin >> inome;
    nome.SetNome(inome);

    cout << "Digite o Idioma do Vocabulario: ";
    cin >> iidioma;
    idioma.SetIdioma(iidioma);

    cout << "Digite a Data do Vocabulario: ";
    cin >> idata;
    data.SetData(idata);

    resultado = isv->CriarVocabulario(vocabulario, nome, idioma, data);

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
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
  }
}

void ComandoAVocabularioInteragirVocabulario::Editar(InterfaceServicoVocabulario *isv) {
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger nome para Vocabulario Invalido: " << StubVocabulario::ktrigger_criar_vocabulario_invalido_;
  cout << "\n\n";
  system(PAUSE);

  Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  vocabularios = isv->ConsultarVocabularios();
  int voltar = vocabularios.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para editar.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      system(CLEAR);
      VocabularioControlado vocabulario;
      Nome nome;
      Idioma idioma;
      Data data;

      string inome, iidioma, idata;

      try {
        cout << "Digite o Nome do Vocabulario: ";
        cin >> inome;
        nome.SetNome(inome);

        cout << "Digite o Idioma do Vocabulario: ";
        cin >> iidioma;
        idioma.SetIdioma(iidioma);

        cout << "Digite a Data do Vocabulario: ";
        cin >> idata;
        data.SetData(idata);

        resultado = isv->EditarVocabulario(vocabulario, nome, idioma, data);

        system(CLEAR);
        if (resultado.GetResultado() == Resultado::ksucesso_) {
          cout << "Vocabulario Editado com Sucesso!\n\n";
          cout << "Nome do Vocabulario: " << vocabulario.GetNome().GetNome() << "\n";
          cout << "Idioma do Vocabulario: " << vocabulario.GetIdioma().GetIdioma() << "\n";
          cout << "Data do Vocabulario: " << vocabulario.GetData().GetData() << "\n";
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
  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Vocabulario Excluivel:     " << StubVocabulario::ktrigger_excluir_vocabulario_valido_;
  cout << "\nTrigger Vocabulario nao Excluivel: " << StubVocabulario::ktrigger_excluir_vocabulario_invalido_;
  cout << "\n\n";
  system(PAUSE);

  Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  vocabularios = isv->ConsultarVocabularios();
  int voltar = vocabularios.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << "Escolha um dos vocabularios acima para excluir.\n\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      resultado = isv->ExcluirVocabulario(vocabularios[opt]);
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