#include "controladores.h"
#include "comandos.h"
#include "stubs.h"

ResultadoAutenticar CtrlApresentacaoAutenticacao::Autenticar() {
  ResultadoAutenticar resultado;
  Resultado verificado;
  string iemail, isenha;
  Email email;
  Senha senha;

  while(true) {
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

  verificado = CtrlServicoAutenticacao_->Autenticar(email, senha);

  if (verificado.GetResultado() == ResultadoAutenticar::FALHA) {
    cout << "Falha na autenticacao\n";
  }

  resultado.SetResultado(verificado.GetResultado());
  resultado.SetEmailResultado(email);

  return resultado;
}

void CtrlApresentacaoControle::Inicializar() {
  InterfaceApresentacaoAutenticacao *ctrl_iaa = new CtrlApresentacaoAutenticacao();
  StubAutenticacao *stub_a = new StubAutenticacao();
  ctrl_iaa->SetCtrlServicoAutenticacao(stub_a);
  int opt;
  system(CLEAR);
  cout << "Sistema Vocabularios Controlados\n\n";
  cout << "Escolha uma das opcoes abaixo.\n\n";
  cout << kentrar << ". Entrar\n";
  cout << kcadastrar << ". Cadastrar\n";
  cout << ksair << ". Sair\n\tOpcao: ";

  cin >> opt;
  ResultadoAutenticar resultado;

  switch(opt) {
    case kentrar:
      SetCtrlAutenticacao(ctrl_iaa);
      resultado = ctrl_apresentacao_autenticacao_->Autenticar();
      if (resultado.GetResultado() == ResultadoAutenticar::SUCESSO) {
        Logado(resultado.GetEmailResultado());
      }
      break;
    case kcadastrar:
      break;
    case ksair:
      break;
  }
}

void CtrlApresentacaoControle::Logado(const Email &email) {
  InterfaceApresentacaoUsuario *ctrl_iau = new CtrlApresentacaoUsuario();
  system(CLEAR);
  cout << "\tBem-vindo!\n\n";
  cout << "Escolha uma das opcoes abaixo.\n\n";
  cout << "1. Acessar Dados da Conta\n2. Acessar Vocabulos\n3. Voltar ao Menu Principal\n\topcao: ";
  int opt;
  cin >> opt;

  switch (opt) {
    case 1: ctrl_iau->Executar(email);
      break;
    case 2:
      break;
    case 3:
      break;
  }
}


void CtrlApresentacaoUsuario::Executar(const Email &_email) {

    if(_email.GetEmail() == "leitor@gmail.com") {
        Leitor leitor(Nome("John"), Sobrenome("Leitor"), Senha("Leit1234"), _email);
        ExibirLeitor(leitor);
    } else {
        if(_email.GetEmail() == "desenvolvedor@gmail.com") {
            Desenvolvedor desenvolvedor(Nome("John"), Sobrenome("Desenvolvedor"), Senha("Dese1234"), _email, Data("01/11/2027"));
            ExibirDesenvolvedor(desenvolvedor);
        } else {
            if(_email.GetEmail() == "administrador@gmail.com") {
                Administrador administrador(Nome("John"), Sobrenome("Administrador"), Senha("Admi1234"), _email, Data("01/11/2027"), Telefone("61 99803-7458"), Address("Avenida Future"));
                ExibirAdministrador(administrador);
            } else {
                cout << "Email Invalido" << endl;
            }
        }
    }
}

void CtrlApresentacaoUsuario::ExibirLeitor(Leitor &leitor) {
    // ComandoApresentacaoUsuario *comando;

    int opcao;

    do {
        system(CLEAR);
        cout << "\tLEITOR\n" << endl;
        cout << "Nome: " << leitor.GetNome().GetNome() << "\tSobrenome: " << leitor.GetSobrenome().GetSobrenome() << endl;
        cout << "Email: " << leitor.GetEmail().GetEmail() << endl;
        cout << endl;
        cout << keditar_ << ". Editar Dados" << endl;
        cout << kexcluir_ << ". Excluir Conta" << endl;
        cout << ksair_ << ". Voltar" << endl;
        cin >> opcao;

        // switch(opcao) {
        //     case keditar_: comando = new ComandoApresentacaoUsuarioEditar();
        //                    comando->executar();
        //                    delete comando;
        //                    break;
        //     case kexcluir_: comando = new ComandoApresentacaoUsuarioExcluir();
        //                     comando->executar();
        //                     delete comando;
        //                     break;
        //     default: break;
        // }
    } while(opcao != ksair_);
}

void CtrlApresentacaoUsuario::ExibirDesenvolvedor(Desenvolvedor &desenvolvedor) {
    // ComandoApresentacaoUsuario *comando;

    int opcao;

    do {
        system(CLEAR);
        cout << "\tDESENVOLVEDOR\n" << endl;
        cout << "Nome: " << desenvolvedor.GetNome().GetNome() << "\tSobrenome: " << desenvolvedor.GetSobrenome().GetSobrenome() << endl;
        cout << "Email: " << desenvolvedor.GetEmail().GetEmail() << endl;
        cout << "Data de Nascimento: " << desenvolvedor.GetDataDeNascimento().GetData() << endl;
        cout << endl;
        cout << keditar_ << ". Editar Dados" << endl;
        cout << kexcluir_ << ". Excluir Conta" << endl;
        cout << ksair_ << ". Voltar" << endl;
        cin >> opcao;

        // switch(opcao) {
        //     case keditar_: comando = new ComandoApresentacaoUsuarioEditar();
        //                    comando->executar();
        //                    delete comando;
        //                    break;
        //     case kexcluir_: comando = new ComandoApresentacaoUsuarioExcluir();
        //                     comando->executar();
        //                     delete comando;
        //                     break;
        //     default: break;
        // }
    } while(opcao != ksair_);
}

void CtrlApresentacaoUsuario::ExibirAdministrador(Administrador &administrador) {
    // ComandoApresentacaoUsuario *comando;

    int opcao;

    do {
        system(CLEAR);
        cout << "\tADMINISTRADOR\n" << endl;
        cout << "Nome: " << administrador.GetNome().GetNome() << "\tSobrenome: " << administrador.GetSobrenome().GetSobrenome() << endl;
        cout << "Email: " << administrador.GetEmail().GetEmail() << endl;
        cout << "Data de Nascimento: " << administrador.GetDataDeNascimento().GetData() << endl;
        cout << "Telefone: " << administrador.GetTelefone().GetTelefone() << endl;
        cout << "Endereco: " << administrador.GetEndereco().GetAddress() << endl;
        cout << endl;
        cout << keditar_ << ". Editar Dados" << endl;
        cout << kexcluir_ << ". Excluir Conta" << endl;
        cout << ksair_ << ". Voltar" << endl;
        cin >> opcao;

        // switch(opcao) {
        //     case keditar_: comando = new ComandoApresentacaoUsuarioEditar();
        //                    comando->executar();
        //                    delete comando;
        //                    break;
        //     case kexcluir_: comando = new ComandoApresentacaoUsuarioExcluir();
        //                     comando->executar();
        //                     delete comando;
        //                     break;
        //     default: break;
        // }
    } while(opcao != ksair_);
}
