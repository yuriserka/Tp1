#include "controladores.h"
#include "comandos.h"
#include "stubs.h"

void CtrlApresentacaoControle::Inicializar() {
  InterfaceApresentacaoAutenticacao *ctrl_iaa = new CtrlApresentacaoAutenticacao();
  StubAutenticacao *stub_a = new StubAutenticacao();
  ctrl_iaa->SetCtrlServicoAutenticacao(stub_a);
  int opt;

  do {
    system(CLEAR);
    cout << "Sistema Vocabularios Controlados\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << kentrar << ". Entrar\n";
    cout << kcadastrar << ". Cadastrar\n";
    cout << ksair << ". Sair\n\topcao: ";

    cin >> opt;
    ResultadoAutenticar resultado;

    switch (opt) {
      case Controle::kentrar:SetCtrlAutenticacao(ctrl_iaa);
        resultado = ctrl_apresentacao_autenticacao_->Autenticar();
        if (resultado.GetResultado() == ResultadoAutenticar::SUCESSO) {
          ControleLogado(resultado.GetEmailResultado());
        }
        break;
      case Controle::kcadastrar:break;
      case Controle::ksair:break;
      default:break;
    }
  } while (opt != ksair);
  delete ctrl_iaa;
  delete stub_a;
}

void CtrlApresentacaoControle::ControleLogado(const Email &email) {
  InterfaceApresentacaoUsuario *ctrl_iau = new CtrlApresentacaoUsuario();
  InterfaceApresentacaoVocabulario *ctrl_iav = new CtrlApresentacaoVocabulario();

  int opt;
  do {
    system(CLEAR);
    cout << "\tBem-vindo!\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << kgestao_usuario << ". Acessar Conta\n";
    cout << kgestao_vocabulo << ". Acessar Vocabulos\n";
    cout << kvoltar << ". Voltar ao Menu Principal\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case ControleLogado::kgestao_usuario:SetCtrlApresentacaoUsuario(ctrl_iau);
        if (ctrl_apresentacao_usuario_->Executar(email).GetResultado() == ResultadoUsuario::kconta_excluida) {
          opt = kvoltar;
        }
        break;
      case ControleLogado::kgestao_vocabulo:SetCtrlApresentacaoVocabulario(ctrl_iav);
        ctrl_apresentacao_vocabulario_->Executar(email);
        break;
      case ControleLogado::kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar);
  delete ctrl_iau;
}

ResultadoAutenticar CtrlApresentacaoAutenticacao::Autenticar() {
  ResultadoAutenticar resultado;
  Resultado verificado;
  string iemail, isenha;
  Email email;
  Senha senha;
  
  while (true) {
    system(CLEAR);
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
      system(PAUSE);
    }
  }

  verificado = ctrl_servico_autenticacao_->Autenticar(email, senha);

  if (verificado.GetResultado() == ResultadoAutenticar::FALHA) {
    cout << "Falha de autenticacao!\n";
    system(PAUSE);
  }

  resultado.SetResultado(verificado.GetResultado());
  resultado.SetEmailResultado(email);

  return resultado;
}

ResultadoUsuario CtrlApresentacaoUsuario::Executar(const Email &email) {
  ctrl_servico_usuario_ = new StubUsuario();
  ResultadoUsuario resultado;
  resultado.SetResultado(ResultadoUsuario::kok);

  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Usuario\n\n";
    cout << "Seus Dados: \n\n";
    if (ShowDados(email, ctrl_servico_usuario_).GetResultado() == Resultado::FALHA) {
      resultado.SetResultado(ResultadoUsuario::kconta_excluida);
      return resultado;
    }
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << keditar << ". Editar Dados da Conta\n";
    cout << kexcluir << ". Excluir Conta\n";
    cout << kvoltar << ". Voltar\n\topcao: ";
    cin >> opt;

    switch (opt) {
      case keditar:system(CLEAR);
        if (ctrl_servico_usuario_->Editar(email).GetResultado() == Resultado::SUCESSO) {
          cout << "Sucesso ao Editar\n" << endl;
        } else {
          cout << "Falha ao Editar\n" << endl;
        }
        system(PAUSE);
        break;
      case kexcluir:system(CLEAR);
        if (ctrl_servico_usuario_->Excluir(email).GetResultado() == Resultado::SUCESSO) {
          cout << "Sucesso ao Excluir\n" << endl;
          resultado.SetResultado(ResultadoUsuario::kconta_excluida);
          opt = kvoltar;
          system(PAUSE);
        } else {
          cout << "Falha ao Excluir\n" << endl;
          system(PAUSE);
        }
        break;
      case kvoltar:break;
      default:break;
    }
  } while (opt != kvoltar && resultado.GetResultado() == ResultadoUsuario::kok);
  delete ctrl_servico_usuario_;
  return resultado;
}

Resultado CtrlApresentacaoUsuario::ShowDados(const Email &email, InterfaceServicoUsuario *stub_u) {
  Resultado resultado;
  resultado.SetResultado(Resultado::SUCESSO);

  if (email.GetEmail() == StubAutenticacao::ktrigger_leitor_) {
    Leitor novoleitor = stub_u->CriaLeitor(email);
    ctrl_servico_usuario_->Exibir(novoleitor);
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_desenvolvedor_) {
    Desenvolvedor novodesenvolvedor = stub_u->CriaDesenvolvedor(email);
    ctrl_servico_usuario_->Exibir(novodesenvolvedor);
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_administrador_) {
    Administrador novoadministrador = stub_u->CriaAdministrador(email);
    ctrl_servico_usuario_->Exibir(novoadministrador);
  } else {
    cout << "Email nao suportado pelos triggers\n\n";
    resultado.SetResultado(Resultado::FALHA);
    system(PAUSE);
  }
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
}