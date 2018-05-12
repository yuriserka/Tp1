#include "apresentacao.h"

ServicoAutenticacao sa_;
ApresentacaoAutenticacao aa_;
ApresentacaoControle ac_;
ApresentacaoUsuario au_;
ApresentacaoVocabulo av_;
ServicoUsuario su_;

void ApresentacaoControle::Controle() {
  system(CLEAR);
  cout << "Sistema Vocabularios Controlados\n\n";
  cout << "Escolha uma das opcoes abaixo.\n\n";
  if (aa_.logado_) {
    cout << "Logado como: " << aa_.email_logado_.GetEmail() << "\n\n";
  }
  cout << "1. Entrar\n2. Cadastrar\n3. Trocar de Conta\n4. Sair\n\topcao: ";
  int opt;
  cin >> opt;

  switch (opt) {
    case 1:aa_.Entrar();
      break;
    case 2:ac_.Cadastrar();
      break;
    case 3:ac_.TrocarConta();
      break;
    case 4:exit(0);
      break;
  }
}

void ApresentacaoControle::TrocarConta() {
  if (aa_.logado_) {
    aa_.logado_ = false;
    cout << "Voce foi desconectado de sua conta.\n";
    system(PAUSE);
    ac_.Controle();
  } else {
    cout << "Voce nao esta logado em nenhuma conta ainda.\n";
    system(PAUSE);
    ac_.Controle();
  }
}

void ApresentacaoControle::Cadastrar() {
  if (aa_.logado_) {
    cout << "Voce ja esta logado.\n";
    system(PAUSE);
    ac_.ControleLogado();
  }
  system(CLEAR);
  cout << "Deseja se cadastrar como: \n\n";
  cout << "1. Administrador\n2. Desenvolvedor\n3. Leitor\n4. Voltar\n\tOpcao: ";
  int opt;
  cin >> opt;

  switch (opt) {
    case 1:sa_.CadastrarAdministrador();
      break;
    case 2:sa_.CadastrarDesenvolvedor();
      break;
    case 3:sa_.CadastrarLeitor();
      break;
    case 4:ac_.Controle();
      break;
  }
  ac_.Controle();
}

void ApresentacaoAutenticacao::Entrar() {
  if (logado_) {
    ac_.ControleLogado();
  }

  system(CLEAR);
  string iemail, isenha;
  Email email;
  Senha senha;

  try {
    cout << "Email: ";
    cin >> iemail;
    email = Email(iemail);

    if (tentativas > 2) {
      char recover;
      cout << "Esqueceu a senha ? (y/n)\n\tOpcao: ";
      cin >> recover;

      if (recover == 'y') {
        try {
          sa_.RecuperarSenha(email);
        }
        catch (exception &e) {
          cout << "\n\t" << e.what() << "\n";
          cout << "Eh necessario se cadastrar primeiro.\n";
          system(PAUSE);
          ac_.Controle();
        }
      }
    }

    cout << "Senha: ";
    cin >> isenha;
    senha = Senha(isenha);
  }
  catch (exception &e) {
    cout << "Formato incorreto!\n\t" << e.what() << "\n";
    system(PAUSE);
    tentativas++;
    aa_.Entrar();
  }

  this->logado_ = sa_.Autenticar(email, senha);
  this->email_logado_ = email;
  aa_.VerificaLogin();
}

void ApresentacaoAutenticacao::VerificaLogin() {
  if (logado_ == true) {
    ac_.ControleLogado();
  } else {
    email_logado_ = Email("i.n.v.a.l.i.d.o@sakudgiu.com.br.us");  // email aleatorio invalido
    cout << "Email ou Senha incorretos!\n";
    system(PAUSE);
    ac_.Controle();
  }
}

void ApresentacaoControle::ControleLogado() {
  system(CLEAR);
  cout << "\tBem-vindo!\n\n";
  cout << "Escolha uma das opcoes abaixo.\n\n";
  cout << "1. Acessar Dados da Conta\n2. Acessar Vocabulos\n3. Voltar ao Menu Principal\n\topcao: ";
  int opt;
  cin >> opt;

  switch (opt) {
    case 1:au_.Controle();
      break;
    case 2:av_.Controle();
      break;
    case 3:ac_.Controle();
      break;
  }
}

void ApresentacaoUsuario::Controle() {
  system(CLEAR);
  cout << "\tGestao de Usuario\n\n";
  cout << "Escolha uma das opcoes abaixo.\n\n";
  cout << "1. Editar Dados da Conta\n2. Excluir conta\n3. Mostrar Dados\n4. Voltar\n\topcao: ";
  int opt;
  cin >> opt;

  switch (opt) {
    case 1:au_.Editar();
      break;
    case 2:au_.Excluir();
      break;
    case 3:au_.Mostrar();
      break;
    case 4:ac_.ControleLogado();
      break;
  }
}

void ApresentacaoUsuario::Editar() {
  system(CLEAR);
  char opt;
  cout << "Voce tem certeza que deseja continuar? (y/n)\n\tOpcao: ";
  cin >> opt;

  if (opt == 'y') {
    try {
      cout << "\tDigite todos os seus Dados novamente.\n\n";
      switch (su_.TipoConta(aa_.email_logado_)) {
        case 0:su_.AtualizarLeitor(aa_.email_logado_);
          break;
        case 1:su_.AtualizarDesenvolvedor(aa_.email_logado_);
          break;
        case 2:su_.AtualizarAdministrador(aa_.email_logado_);
          break;
      }
    }
    catch (exception &e) {
      cout << "\n\t" << e.what() << "\n";
    }
  } else {
    au_.Controle();
  }
  ac_.Controle();
}

void ApresentacaoUsuario::Excluir() {
  system(CLEAR);
  char opt;
  cout << "Voce tem certeza que deseja continuar? (y/n)\n\tOpcao: ";
  cin >> opt;

  if (opt == 'y') {
    try {
      su_.Deletar(aa_.email_logado_);
    }
    catch (exception &e) {
      cout << "\n\t" << e.what() << "\n";
    }
  } else {
    au_.Controle();
  }
  cout << "Conta deletada com sucesso\n";
  aa_.email_logado_ = Email("i.n.v.a.l.i.d.o@sakudgiu.com.br.us");  // email aleatorio invalido
  aa_.logado_ = false;
  system(PAUSE);
  ac_.Controle();
}

void ApresentacaoUsuario::Mostrar() {
  system(CLEAR);
  cout << "\tSeus dados\n\n";
  try {
    su_.Procurador(aa_.email_logado_);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }
  system(PAUSE);
  au_.Controle();
}

void ApresentacaoVocabulo::Controle() {
  cout << "Tem que ver como implementar isso ainda\n";
  system(PAUSE);
  ac_.ControleLogado();
}