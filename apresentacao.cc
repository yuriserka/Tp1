#include "apresentacao.h"
#include "dominios.h"
#include "servicos.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void ApresentacaoControle::Controle() {
  int opt;
  ApresentacaoAutenticacao y = ApresentacaoAutenticacao();
  do {
    system(CLEAR);
    cout << "\tVocabularios Controlados\n\n";
    cout << "Selecione alguma das alternativas abaixo para usar o sistema: \n";
    cout << "1- Entrar.\n2- Cadastrar.\n3- Sair do programa\n";
    cout << "\topcao: ";
    cin >> opt;
  } while (opt < 1 or opt > 3);

  if (opt == 3) {
    exit(0);
  } else {
    opt == 1 ? y.Entrar() : Selecao();
  }
}

void ApresentacaoControle::Selecao() {
  int opt;
  do {
    system(CLEAR);
    cout << "Deseja se cadastrar como: \n";
    cout << "1- Administrador.\n2- Desenvolvedor.\n3- Leitor.\n";
    cout << "\toption: ";
    cin >> opt;
  } while (opt < 1 or opt > 3);

  if (opt == 1) {
    sa.CadastroAdministrador();
  } else {
    opt == 2 ? sa.CadastroDesenvolvedor() : sa.CadastroLeitor();
  }
}

void ApresentacaoAutenticacao::Entrar() {
  system(CLEAR);
  string senha, email;
  ApresentacaoControle y = ApresentacaoControle();

  try {
    cout << "Digite seu e-mail: ";
    cin >> email;
    sa.email_digitado_ = Email(email);

    cout << "Digite sua senha: ";
    cin >> senha;
    sa.senha_digitada_ = Senha(senha);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  sa.Autenticar() ? cout << "Logado com sucesso!.\n" :
  cout << "\te-mail ou senha incorretos, tente novamente.\n", system("pause"), y.Controle();
}
