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
    }
  } while (opt != ksair);
  delete ctrl_iaa;
  delete stub_a;
}

void CtrlApresentacaoControle::ControleLogado(const Email &email) {
  InterfaceApresentacaoUsuario *ctrl_iau = new CtrlApresentacaoUsuario();

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
        ctrl_apresentacao_usuario_->Executar(email);
        break;
      case ControleLogado::kgestao_vocabulo:break;
      case ControleLogado::kvoltar:break;
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

void CtrlApresentacaoUsuario::Executar(const Email &email) {
  StubUsuario *stub_u = new StubUsuario();
  SetCtrlServicoUsuario(stub_u);

  int opt;
  do {
    system(CLEAR);
    cout << "\tGestao de Usuario\n\n";
    cout << "Seus Dados: \n\n";
    ShowDados(email, stub_u);
    cout << "\nEscolha uma das opcoes abaixo.\n\n";
    cout << keditar << ". Editar Dados da Conta\n";
    cout << kexcluir << ". Excluir conta\n";
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
          system(PAUSE);
          CtrlApresentacaoControle ret_inicio;
          ret_inicio = CtrlApresentacaoControle();
          ret_inicio.Inicializar();
        } else {
          cout << "Falha ao Excluir\n" << endl;
        }
        system(PAUSE);
        break;
      case kvoltar:break;
    }
  } while (opt != kvoltar);
  delete stub_u;
}

void CtrlApresentacaoUsuario::ShowDados(const Email &email, StubUsuario *stub_u) {
  if (email.GetEmail() == StubAutenticacao::ktrigger_leitor_) {
    Leitor novoleitor = stub_u->CriaLeitor(email);
    ctrl_servico_usuario_->ExibirLeitor(novoleitor);
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_desenvolvedor_) {
    Desenvolvedor novodesenvolvedor = stub_u->CriaDesenvolvedor(email);
    ctrl_servico_usuario_->ExibirDesenvolvedor(novodesenvolvedor);
  } else if (email.GetEmail() == StubAutenticacao::ktrigger_administrador_) {
    Administrador novoadministrador = stub_u->CriaAdministrador(email);
    ctrl_servico_usuario_->ExibirAdministrador(novoadministrador);
  } else {
    cout << "Email nao suportado pelos triggers\n";
    system(PAUSE);
    CtrlApresentacaoControle ret_inicio;
    ret_inicio = CtrlApresentacaoControle();
    ret_inicio.Inicializar();
  }
}