#include "UI.h"
#include "dominios.h"
#include "entidades.h"

#include <iostream>
#include <string>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

void ApresentacaoAutenticacao::Controle() {
  int opt;
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
    opt == 1 ? Entrar() : Selecao();
  }
}

void ApresentacaoAutenticacao::Selecao() {
  int opt;
  do {
    system(CLEAR);
    cout << "Deseja se cadastrar como: \n";
    cout << "1- Administrador.\n2- Desenvolvedor.\n3- Leitor.\n";
    cout << "\toption: ";
    cin >> opt;
  } while (opt < 1 or opt > 3);

  if (opt == 1) {
    CadastroAdministrador();
  } else {
    opt == 2 ? CadastroDesenvolvedor() : CadastroLeitor();
  }
}

void ApresentacaoAutenticacao::CadastroAdministrador() {
  system(CLEAR);
  Administrador novoadministrador;

  string nome, sobrenome, senha, email, data, telefone, endereco;
  Nome nome_;
  Sobrenome sobrenome_;
  Senha senha_;
  Email email_;
  Data data_;
  Telefone telefone_;
  Address endereco_;

  try {
    cout << "Digite seu Nome: ";
    cin >> nome;
    nome_ = Nome(nome);

    cout << "Digite seu Sobrenome: ";
    cin >> sobrenome;
    sobrenome_ = Sobrenome(sobrenome);

    cout << "Digite seu e-mail: ";
    cin >> email;
    email_ = Email(email);

    cout << "Digite sua Senha: ";
    cin >> senha;
    senha_ = Senha(senha);

    cout << "Digite sua Data de nascimento: ";
    cin >> data;
    data_ = Data(data);

    cin.clear();
    cin.ignore();

    cout << "Digite seu Telefone: ";
    getline(cin, telefone);
    telefone_ = Telefone(telefone);

    cout << "Digite seu Endereco: ";
    getline(cin, endereco);
    endereco_ = Address(endereco);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system("pause");
    CadastroAdministrador();
  }

  try {
    novoadministrador = Administrador(nome_, sobrenome_, senha_, email_, data_, telefone_, endereco_);
  }
  catch (exception &e) {
    char exit;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e se cadastrar como outra coisa? [y / n] : ";
    cin >> exit;
    exit == 'y' ? Selecao() : CadastroAdministrador();
  }
  vector_administradores_.push_back(novoadministrador);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system("pause");
  Controle();
}

void ApresentacaoAutenticacao::CadastroDesenvolvedor() {
  system(CLEAR);
  Desenvolvedor novodesenvolvedor;

  string nome, sobrenome, senha, email, data;
  Nome nome_;
  Sobrenome sobrenome_;
  Senha senha_;
  Email email_;
  Data data_;

  try {
    cout << "Digite seu Nome: ";
    cin >> nome;
    nome_ = Nome(nome);

    cout << "Digite seu Sobrenome: ";
    cin >> sobrenome;
    sobrenome_ = Sobrenome(sobrenome);

    cout << "Digite seu e-mail: ";
    cin >> email;
    email_ = Email(email);

    cout << "Digite sua Senha: ";
    cin >> senha;
    senha_ = Senha(senha);

    cout << "Digite sua Data de nascimento: ";
    cin >> data;
    data_ = Data(data);

  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system("pause");
    CadastroDesenvolvedor();
  }

  try {
    novodesenvolvedor = Desenvolvedor(nome_, sobrenome_, senha_, email_, data_);
  }
  catch (exception &e) {
    char exit;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e se cadastrar como outra coisa? [y / n] : ";
    cin >> exit;
    exit == 'y' ? Selecao() : CadastroDesenvolvedor();
  }
  vector_desenvolvedores_.push_back(novodesenvolvedor);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system("pause");
  Controle();
}

void ApresentacaoAutenticacao::CadastroLeitor() {
  system(CLEAR);
  Leitor novoleitor;

  string nome, sobrenome, senha, email;
  Nome nome_;
  Sobrenome sobrenome_;
  Senha senha_;
  Email email_;
  try {
    cout << "Digite seu Nome: ";
    cin >> nome;
    nome_ = Nome(nome);

    cout << "Digite seu Sobrenome: ";
    cin >> sobrenome;
    sobrenome_ = Sobrenome(sobrenome);

    cout << "Digite seu e-mail: ";
    cin >> email;
    email_ = Email(email);

    cout << "Digite sua Senha: ";
    cin >> senha;
    senha_ = Senha(senha);

  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system("pause");
    CadastroLeitor();
  }

  try {
    novoleitor = Leitor(nome_, sobrenome_, senha_, email_);
  }
  catch (exception &e) {
    char exit;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e se cadastrar como outra coisa? [y / n] : ";
    cin >> exit;
    exit == 'y' ? Selecao() : CadastroLeitor();
  }

  vector_leitores_.push_back(novoleitor);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system("pause");
  Controle();
}

void ApresentacaoAutenticacao::Entrar() {
  system(CLEAR);
  string senha, email;

  try {
    cout << "Digite seu e-mail: ";
    cin >> email;
    email_digitado_ = Email(email);

    cout << "Digite sua senha: ";
    cin >> senha;
    senha_digitada_ = Senha(senha);
  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
  }

  Autenticar() ? cout << "Logado com sucesso!.\n" :
  cout << "\te-mail ou senha incorretos, tente novamente.\n", system("pause"), Controle();
}

bool ApresentacaoAutenticacao::Autenticar() {
  bool ok = true;

  for (auto const &leitor : vector_leitores_) {
    if (leitor.GetEmail().GetEmail() == email_digitado_.GetEmail() &&
        leitor.GetSenha().GetSenha() == senha_digitada_.GetSenha()) {
      return ok;
    }
  }

  for (auto const &desenvolvedor : vector_desenvolvedores_) {
    if (desenvolvedor.GetEmail().GetEmail() == email_digitado_.GetEmail() &&
        desenvolvedor.GetSenha().GetSenha() == senha_digitada_.GetSenha()) {
      return ok;
    }
  }

  for (auto const &admin : vector_administradores_) {
    if (admin.GetEmail().GetEmail() == email_digitado_.GetEmail() &&
        admin.GetSenha().GetSenha() == senha_digitada_.GetSenha()) {
      return ok;
    }
  }

  return !ok;
}
