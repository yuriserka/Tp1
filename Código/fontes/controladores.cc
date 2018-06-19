#include "../cabecalhos/includes.h"

void CtrlApresentacaoControle::Inicializar() {
  ResultadoAutenticar resultado;
  int opt;

  do {
    system(CLEAR);
    cout << "Sistema Vocabularios Controlados\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << kentrar << ". Entrar\n";
    cout << kcadastrar << ". Cadastrar\n";
    cout << ksair << ". Sair\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case Controle::kentrar:
        try {
          resultado = ctrl_aa->Autenticar();
          if (resultado.GetResultado() == ResultadoAutenticar::ksucesso_) {
            ControleLogado(resultado.GetEmailResultado());
          }
        } catch (exception &e) {
          cout << "\n\t" << e.what() << "\n";
          opt = ksair;
        }
        break;
      case Controle::kcadastrar:ctrl_ak->Cadastrar();
        break;
      case Controle::ksair:break;
      default:break;
    }
  } while (opt != ksair);
}

void CtrlApresentacaoControle::ControleLogado(const Email &email) {
  int opt;
  Resultado res;
  int conta_excluida = Resultado::ksucesso_;

  do {
    system(CLEAR);
    cout << "\tBem-vindo!\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << kgestao_usuario << ". Acessar Conta\n";
    cout << kgestao_vocabulo << ". Acessar Vocabulos\n";
    cout << kvoltar << ". Voltar ao Menu Principal\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case ControleLogado::kgestao_usuario:res = ctrl_au->Executar(email);
        if (res.GetResultado() == conta_excluida) {
          opt = kvoltar;
        }
        break;
      case ControleLogado::kgestao_vocabulo:ctrl_av->Executar(email);
        break;
      case ControleLogado::kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

ResultadoAutenticar CtrlApresentacaoAutenticacao::Autenticar() {
  ResultadoAutenticar resultado;
  Resultado verificado;
  string iemail, isenha;
  Email email;
  Senha senha;
  int tentativas = 0, opt;

  do {
    system(CLEAR);
    if (tentativas >= 2) {
      cout << "Deseja Retornar?\n\n1. Sim\n2. Nao\n";
      cout << "\topcao: ";
      cin >> opt;

      switch (opt) {
        case 1:resultado.SetResultado(Resultado::kfalha_);
          return resultado;
          break;
        case 2:
        default:break;
      }
      system(CLEAR);
    }
    try {
      cout << "Email: ";
      cin >> iemail;
      email = Email(iemail);

      cout << "Senha: ";
      cin >> isenha;
      senha = Senha(isenha);
      break;
    }
    catch (exception &e) {
      cout << "Formato incorreto!\n\t" << e.what() << "\n";
      tentativas++;
      system(PAUSE);
    }
  } while (true);

  try {
    verificado = ctrl_servico_autenticacao_->Autenticar(email, senha);
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  if (verificado.GetResultado() == ResultadoAutenticar::kfalha_) {
    cout << "Falha de autenticacao!\n";
    system(PAUSE);
  } else {
    resultado.SetEmailResultado(email);
  }
  resultado.SetResultado(verificado.GetResultado());

  return resultado;
}

void CtrlApresentacaoCadastro::Cadastrar() {
  ComandoACadastro *comando;
  int opt;

  do {
    system(CLEAR);
    cout << "Deseja se cadastrar como: \n\n";
    cout << kadm << ". Administrador\n" << kdev << ". Desenvolvedor\n" << kleitor << ". Leitor\n";
    cout << kvoltar << ". Voltar\n\tOpcao: ";
    cin >> opt;

    switch (opt) {
      case Cadastro::kadm:comando = new ComandoACadastroAdm();
        comando->Executar(ctrl_servico_cadastro_);
        opt = kvoltar;
        delete comando;
        break;
      case Cadastro::kdev:comando = new ComandoACadastroDev();
        comando->Executar(ctrl_servico_cadastro_);
        opt = kvoltar;
        delete comando;
        break;
      case Cadastro::kleitor:comando = new ComandoACadastroLeitor();
        comando->Executar(ctrl_servico_cadastro_);
        opt = kvoltar;
        delete comando;
        break;
      case Cadastro::kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
}

Resultado CtrlApresentacaoUsuario::Executar(const Email &email) {
  Resultado resultado;
  resultado.SetResultado(Resultado::kfalha_);
  ComandoAUsuario *cmd_show, *comando;
  cmd_show = new ComandoAUsuarioMostrar();

  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Usuario\n\n";
    cout << "Seus Dados: \n\n";

    cmd_show->Executar(ctrl_servico_usuario_, email);

    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << keditar << ". Editar Dados da Conta\n";
    cout << kexcluir << ". Excluir Conta\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case keditar:system(CLEAR);
        comando = new ComandoAUsuarioEditar();
        comando->Executar(ctrl_servico_usuario_, email);
        delete comando;
        break;
      case kexcluir:system(CLEAR);
        comando = new ComandoAUsuarioExcluir();
        resultado = comando->Executar(ctrl_servico_usuario_, email);
        delete comando;
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar && (resultado.GetResultado() != Resultado::ksucesso_));
  delete cmd_show;
  return resultado;
}

void CtrlApresentacaoVocabulario::Executar(const Email &email) {
  ComandoSqlTipoConta *comando_sql;
  comando_sql = new ComandoSqlTipoConta(email);
  string tipo_conta;
  try {
    comando_sql->Executar();
    tipo_conta = comando_sql->RecuperaConta();
  } catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    delete comando_sql;
    return;
  }
  delete comando_sql;

  if (tipo_conta == "leitor") {
    ComandoAVocabularioLeitor *comando;
    comando = new ComandoAVocabularioLeitor();
    comando->Executar(ctrl_servico_vocabulario_);
    delete comando;
  } else if (tipo_conta == "desenvolvedor") {
    ComandoAVocabularioDesenvolvedor *comando;
    comando = new ComandoAVocabularioDesenvolvedor();
    comando->Executar(ctrl_servico_vocabulario_, email);
    delete comando;
  } else if (tipo_conta == "administrador") {
    ComandoAVocabularioAdministrador *comando;
    comando = new ComandoAVocabularioAdministrador();
    comando->Executar(ctrl_servico_vocabulario_, email);
    delete comando;
  }
}