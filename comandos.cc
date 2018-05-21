#include "includes.h"

void ComandoACadastroLeitor::Executar(InterfaceServicoCadastro *stub_isc) {
  stub_isc->CadastrarLeitor();
}

void ComandoACadastroAdm::Executar(InterfaceServicoCadastro *stub_isc) {
  stub_isc->CadastrarAdm();
}

void ComandoACadastroDev::Executar(InterfaceServicoCadastro *stub_isc) {
  stub_isc->CadastrarDev();
}

Resultado ComandoAUsuarioMostrar::Executar(InterfaceServicoUsuario *stub_isu, const Email &email) {
  Resultado res;
  if (email.GetEmail() == StubAutenticacao::ktrigger_leitor_) {
    stub_isu->Exibir(stub_isu->CriaLeitor(email));
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_desenvolvedor_) {
    stub_isu->Exibir(stub_isu->CriaDesenvolvedor(email));
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_administrador_) {
    stub_isu->Exibir(stub_isu->CriaAdministrador(email));
  } else {
    res.SetResultado(Resultado::kfalha_);
    cout << "Email nao suportado pelos triggers\n";
    return res;
  }
  res.SetResultado(Resultado::ksucesso_);
  return res;
}

Resultado ComandoAUsuarioEditar::Executar(InterfaceServicoUsuario *stub_isu, const Email &email) {
  ResultadoUsuario res;
  Resultado result;
  if (email.GetEmail() == StubAutenticacao::ktrigger_leitor_) {
    res = stub_isu->Editar(stub_isu->CriaLeitor(email));
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_desenvolvedor_) {
    res = stub_isu->Editar(stub_isu->CriaDesenvolvedor(email));
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_administrador_) {
    res = stub_isu->Editar(stub_isu->CriaAdministrador(email));
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

Resultado ComandoAUsuarioExcluir::Executar(InterfaceServicoUsuario *stub_isu, const Email &email) {
  Resultado res;
  if (email.GetEmail() == StubAutenticacao::ktrigger_leitor_
      || email.GetEmail() == StubAutenticacao::ktrigger_administrador_ ||
      email.GetEmail() == StubAutenticacao::ktrigger_desenvolvedor_) {
    res = stub_isu->Excluir(email);
  }

  if (res.GetResultado() == Resultado::ksucesso_) {
    cout << "Conta excluida com sucesso.\n";
  } else {
    cout << "Erro ao excluir conta.\n";
  }
  system(PAUSE);
  return res;
}

void ComandoAVocabularioLeitor::Executar(InterfaceServicoVocabulario *stub_isv) {
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
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioDesenvolvedor::Executar(InterfaceServicoVocabulario *stub_isv) {
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
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kcadastrardesenvolvedor:comando = new ComandoAVocabularioCadastrarDesenvolvedor();
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kinteragirtermo:comando = new ComandoAVocabularioInteragirTermo();
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kinteragirdefinicao:comando = new ComandoAVocabularioInteragirDefinicao();
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioAdministrador::Executar(InterfaceServicoVocabulario *stub_isv) {
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
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kcadastrardesenvolvedor:comando = new ComandoAVocabularioCadastrarDesenvolvedor();
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kinteragirtermo:comando = new ComandoAVocabularioInteragirTermo();
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kinteragirdefinicao:comando = new ComandoAVocabularioInteragirDefinicao();
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kinteragirvocabulario:comando = new ComandoAVocabularioInteragirVocabulario();
        comando->Executar(stub_isv);
        delete comando;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioListarVocabularios::Executar(InterfaceServicoVocabulario *stub_isv) {
  ComandoAVocabulario *comando;
  vector<VocabularioControlado> vocabularios;
  vocabularios = stub_isv->ConsultarVocabularios();
  int voltar = vocabularios.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    cout << "Escolha um dos vocabularios abaixo para apresentar os termos deste vocabulario.\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      comando = new ComandoAVocabularioListarTermos();
      comando->Executar(stub_isv);
    }
  } while (opt != voltar);
  delete comando;
}

void ComandoAVocabularioListarTermos::Executar(InterfaceServicoVocabulario *stub_isv) {
  Definicao definicao;
  vector<Termo> termos;
  termos = stub_isv->ConsultarTermos();
  int voltar = termos.size();

  int opt;
  do {
    system(CLEAR);
    cout << "Termos do Vocabulario" << "\n\n";
    cout << "Escolha um dos termos abaixo para apresentar informacoes sobre este termo.\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << termos[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      system(CLEAR);
      definicao = stub_isv->ConsultarDefinicao(termos[opt]);
      cout << "Nome do Termo: " << termos[opt].GetNome().GetNome() << "\n";
      cout << "Classe do Termo: " << termos[opt].GetPreferencia().GetPreferencia() << "\n";
      cout << "Data do Termo: " << termos[opt].GetData().GetData() << "\n";
      cout << "Definicao do Termo: " << definicao.GetDefinicao().GetDefinicao() << "\n";
      cout << "Data da Definicao: " << definicao.GetData().GetData() << "\n";
      system(PAUSE);
    }
  } while (opt != voltar);
}

void ComandoAVocabularioCadastrarDesenvolvedor::Executar(InterfaceServicoVocabulario *stub_isv) {
  Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  vocabularios = stub_isv->ConsultarVocabularios();
  int voltar = vocabularios.size();

  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Cadastro Valido:   " << StubVocabulario::ktrigger_cadastro_valido_;
  cout << "\n";
  cout << "Trigger Cadastro Invalido: " << StubVocabulario::ktrigger_cadastro_invalido_;
  cout << "\n\n";
  system(PAUSE);

  int opt;
  do {
    system(CLEAR);
    cout << "Vocabularios Disponiveis" << "\n\n";
    cout << "Escolha um dos vocabularios abaixo para se cadastrar como Desenvolvedor.\n\n";
    for (int i = 1; i < voltar; i++) {
      cout << i << ". " << vocabularios[i].GetNome().GetNome() << "\n";
    }
    cout << "\n";
    cout << voltar << ". Voltar\n\topcao: ";
    cin >> opt;

    if (opt < voltar && opt > 0) {
      resultado = stub_isv->CadastrarDesenvolvedor(vocabularios[opt]);
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

void ComandoAVocabularioInteragirTermo::Executar(InterfaceServicoVocabulario *stub_isv) {
  //Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  vocabularios = stub_isv->ConsultarVocabularios();

  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Termo Invalido: " << StubVocabulario::ktrigger_termo_invalido_;
  cout << "\n\n";
  system(PAUSE);

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
      case kcriar:break;
      case keditar:break;
      case kexcluir:break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioInteragirDefinicao::Executar(InterfaceServicoVocabulario *stub_isv) {
  //Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  vocabularios = stub_isv->ConsultarVocabularios();

  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Definicao Invalida: " << StubVocabulario::ktrigger_definicao_invalida_;
  cout << "\n\n";
  system(PAUSE);

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
      case kcriar:break;
      case keditar:break;
      case kexcluir:break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioInteragirVocabulario::Executar(InterfaceServicoVocabulario *stub_isv) {
  //Resultado resultado;
  vector<VocabularioControlado> vocabularios;
  vocabularios = stub_isv->ConsultarVocabularios();

  system(CLEAR);
  cout << "\tTRIGGERS\n";
  cout << "Trigger Vocabulario Invalido: " << StubVocabulario::ktrigger_vocabulario_invalido_;
  cout << "\n\n";
  system(PAUSE);

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
      case kcriar:break;
      case keditar:break;
      case kexcluir:break;
      case kvoltar:break;
      default: break;
    }
  } while (opt != kvoltar);
}