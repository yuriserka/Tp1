#include "controladores.h"
#include "comandos.h"
#include "stubs.h"

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
      case Controle::kentrar:resultado = ctrl_aa->Autenticar();
        if (resultado.GetResultado() == ResultadoAutenticar::ksucesso_) {
          ControleLogado(resultado.GetEmailResultado());
        }
        break;
      case Controle::kcadastrar:break;
      case Controle::ksair:break;
      default:break;
    }
  } while (opt != ksair);
}

void CtrlApresentacaoControle::ControleLogado(const Email &email) {
  int opt;
  Resultado res;

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
        if (res.GetResultado() == Resultado::ksucesso_) {
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
      cout << "Deseja Retornar?\n1. Sim\n2. Nao\n";
      cout << "\tOpcao: ";
      cin >> opt;

      switch (opt) {
        case 1:resultado.SetResultado(Resultado::kfalha_);
          return resultado;
          break;
        case 2:
        default:break;
      }
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

  verificado = ctrl_servico_autenticacao_->Autenticar(email, senha);

  if (verificado.GetResultado() == ResultadoAutenticar::kfalha_) {
    cout << "Falha de autenticacao!\n";
    system(PAUSE);
  }

  resultado.SetResultado(verificado.GetResultado());
  resultado.SetEmailResultado(email);

  return resultado;
}

Resultado CtrlApresentacaoUsuario::Executar(const Email &email) {
  ctrl_servico_usuario_ = new StubUsuario();
  Resultado resultado;
  ComandoAUsuario *cmd_show, *comando;

  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Usuario\n\n";
    cout << "Seus Dados: \n\n";

    cmd_show = new ComandoAUsuarioMostrar();
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
        system(PAUSE);
        break;
      case kexcluir:system(CLEAR);
        comando = new ComandoAUsuarioExcluir();
        resultado = comando->Executar(ctrl_servico_usuario_, email);
        delete comando;
        system(PAUSE);
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar && (resultado.GetResultado() != Resultado::ksucesso_));
  delete ctrl_servico_usuario_;
  delete cmd_show;
  return resultado;
}

void CtrlApresentacaoVocabulario::Executar(const Email &email) {
  ctrl_servico_vocabulario_ = new StubVocabulario();
  ComandoAVocabulario *comando;

  if (email.GetEmail() == StubAutenticacao::ktrigger_leitor_) {
    comando = new ComandoAVocabularioLeitor();
    comando->Executar(ctrl_servico_vocabulario_);
    delete comando;
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_desenvolvedor_) {
    comando = new ComandoAVocabularioDesenvolvedor();
    comando->Executar(ctrl_servico_vocabulario_);
    delete comando;
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_administrador_) {
    comando = new ComandoAVocabularioAdministrador();
    comando->Executar(ctrl_servico_vocabulario_);
    delete comando;
  } else {
    system(CLEAR);
    cout << "\tGestao de Vocabulos\n";
    cout << "\nEmail nao suportado pelos triggers\n\n";
    system(PAUSE);
  }
  delete ctrl_servico_vocabulario_;
}