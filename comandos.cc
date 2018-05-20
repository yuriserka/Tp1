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

  return result;
}

Resultado ComandoAUsuarioExcluir::Executar(InterfaceServicoUsuario *stub_isu, const Email &email) {
  Resultado res;
  if (email.GetEmail() == StubAutenticacao::ktrigger_leitor_ || email.GetEmail() == StubAutenticacao::ktrigger_administrador_ ||
      email.GetEmail() == StubAutenticacao::ktrigger_desenvolvedor_) {
    res = stub_isu->Excluir(email);
  }
    
  if (res.GetResultado() == Resultado::ksucesso_) {
    cout << "Conta excluida com sucesso.\n";
  } else {
    cout << "Erro ao excluir conta.\n";
  }
  return res;
}

void ComandoAVocabularioLeitor::Executar(InterfaceServicoVocabulario *stub_isv) {
  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Vocabulos\n";
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << klistarvocabularios << ". Listar Vocabularios\n";
    cout << kapresentarvocabulario << ". Apresentar Vocabulario\n";
    cout << kconsultartermo << ". Consultar Termo\n";
    cout << kconsultardefinicao << ". Consultar Definicao\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case klistarvocabularios:system(CLEAR);
        if (stub_isv->ListarVocabularios().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Listar Vocabularios\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Listar Vocabularios\n" << endl;
          system(PAUSE);
        }
        break;
      case kapresentarvocabulario:system(CLEAR);
        if (stub_isv->ApresentarVocabulario().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Apresentar Vocabulario\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Apresentar Vocabulario\n" << endl;
          system(PAUSE);
        }
        break;
      case kconsultartermo:system(CLEAR);
        if (stub_isv->ConsultarTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Consultar Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Consultar Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case kconsultardefinicao:system(CLEAR);
        if (stub_isv->ConsultarDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Consultar Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Consultar Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioDesenvolvedor::Executar(InterfaceServicoVocabulario *stub_isv) {
  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Vocabulos\n";
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << klistarvocabularios << ". Listar Vocabularios\n";
    cout << kapresentarvocabulario << ". Apresentar Vocabulario\n";
    cout << kconsultartermo << ". Consultar Termo\n";
    cout << kconsultardefinicao << ". Consultar Definicao\n";
    cout << kcriartermo << ". Criar Termo\n";
    cout << keditartermo << ". Editar Termo\n";
    cout << kexcluirtermo << ". Excluir Termo\n";
    cout << kcriardefinicao << ". Criar Definicao\n";
    cout << keditardefinicao << ". Editar Definicao\n";
    cout << kexcluirdefinicao << ". Excluir Definicao\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case klistarvocabularios:system(CLEAR);
        if (stub_isv->ListarVocabularios().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Listar Vocabularios\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Listar Vocabularios\n" << endl;
          system(PAUSE);
        }
        break;
      case kapresentarvocabulario:system(CLEAR);
        if (stub_isv->ApresentarVocabulario().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Apresentar Vocabulario\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Apresentar Vocabulario\n" << endl;
          system(PAUSE);
        }
        break;
      case kconsultartermo:system(CLEAR);
        if (stub_isv->ConsultarTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Consultar Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Consultar Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case kconsultardefinicao:system(CLEAR);
        if (stub_isv->ConsultarDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Consultar Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Consultar Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kcadastrardesenvolvedor:system(CLEAR);
        if (stub_isv->CadastrarDesenvolvedor().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Cadastrar Desenvolvedor\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Cadastrar Desenvolvedor\n" << endl;
          system(PAUSE);
        }
        break;
      case kcriartermo:system(CLEAR);
        if (stub_isv->CriarTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Criar Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Criar Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case keditartermo:system(CLEAR);
        if (stub_isv->EditarTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Editar Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Editar Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case kexcluirtermo:system(CLEAR);
        if (stub_isv->ExcluirTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Excluir Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Excluir Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case kcriardefinicao:system(CLEAR);
        if (stub_isv->CriarDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Criar Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Criar Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case keditardefinicao:system(CLEAR);
        if (stub_isv->EditarDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Editar Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Editar Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kexcluirdefinicao:system(CLEAR);
        if (stub_isv->ExcluirDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Excluir Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Excluir Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

void ComandoAVocabularioAdministrador::Executar(InterfaceServicoVocabulario *stub_isv) {
  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Vocabulos\n";
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << klistarvocabularios << ". Listar Vocabularios\n";
    cout << kapresentarvocabulario << ". Apresentar Vocabulario\n";
    cout << kconsultartermo << ". Consultar Termo\n";
    cout << kconsultardefinicao << ". Consultar Definicao\n";
    cout << kcadastrardesenvolvedor << ". Cadastrar Desenvolvedor\n";
    cout << kcriartermo << ". Criar Termo\n";
    cout << keditartermo << ". Editar Termo\n";
    cout << kexcluirtermo << ". Excluir Termo\n";
    cout << kcriardefinicao << ". Criar Definicao\n";
    cout << keditardefinicao << ". Editar Definicao\n";
    cout << kexcluirdefinicao << ". Excluir Definicao\n";
    cout << kcriarvocabulario << ". Criar Vocabulario\n";
    cout << keditarvocabulario << ". Editar Vocabulario\n";
    cout << kexcluirvocabulario << ". Excluir Vocabulario\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case klistarvocabularios:system(CLEAR);
        if (stub_isv->ListarVocabularios().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Listar Vocabularios\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Listar Vocabularios\n" << endl;
          system(PAUSE);
        }
        break;
      case kapresentarvocabulario:system(CLEAR);
        if (stub_isv->ApresentarVocabulario().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Apresentar Vocabulario\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Apresentar Vocabulario\n" << endl;
          system(PAUSE);
        }
        break;
      case kconsultartermo:system(CLEAR);
        if (stub_isv->ConsultarTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Consultar Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Consultar Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case kconsultardefinicao:system(CLEAR);
        if (stub_isv->ConsultarDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Consultar Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Consultar Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kcadastrardesenvolvedor:system(CLEAR);
        if (stub_isv->CadastrarDesenvolvedor().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Cadastrar Desenvolvedor\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Cadastrar Desenvolvedor\n" << endl;
          system(PAUSE);
        }
        break;
      case kcriartermo:system(CLEAR);
        if (stub_isv->CriarTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Criar Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Criar Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case keditartermo:system(CLEAR);
        if (stub_isv->EditarTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Editar Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Editar Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case kexcluirtermo:system(CLEAR);
        if (stub_isv->ExcluirTermo().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Excluir Termo\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Excluir Termo\n" << endl;
          system(PAUSE);
        }
        break;
      case kcriardefinicao:system(CLEAR);
        if (stub_isv->CriarDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Criar Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Criar Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case keditardefinicao:system(CLEAR);
        if (stub_isv->EditarDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Editar Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Editar Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kexcluirdefinicao:system(CLEAR);
        if (stub_isv->ExcluirDefinicao().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Excluir Definicao\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Excluir Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kcriarvocabulario:system(CLEAR);
        if (stub_isv->CriarVocabulario().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Criar Vocabulario\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Criar Vocabulario\n" << endl;
          system(PAUSE);
        }
        break;
      case keditarvocabulario:system(CLEAR);
        if (stub_isv->EditarVocabulario().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Editar Vocabulario\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Editar Vocabulario\n" << endl;
          system(PAUSE);
        }
        break;
      case kexcluirvocabulario:system(CLEAR);
        if (stub_isv->ExcluirVocabulario().GetResultado() == Resultado::ksucesso_) {
          cout << "Sucesso ao Excluir Vocabulario\n" << endl;
          system(PAUSE);
        } else {
          cout << "Falha ao Excluir Definicao\n" << endl;
          system(PAUSE);
        }
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}