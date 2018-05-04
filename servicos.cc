#include "servicos.h"
#include "apresentacao.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
ApresentacaoControle xis = ApresentacaoControle();

void ServicoAutenticacao::CadastroAdministrador() {
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
    exit == 'y' ? xis.Selecao() : CadastroAdministrador();
  }
  vector_administradores_.push_back(novoadministrador);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system("pause");
  xis.Controle();
}

void ServicoAutenticacao::CadastroDesenvolvedor() {
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
    exit == 'y' ? xis.Selecao() : CadastroDesenvolvedor();
  }
  vector_desenvolvedores_.push_back(novodesenvolvedor);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system("pause");
  xis.Controle();
}

void ServicoAutenticacao::CadastroLeitor() {
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
    exit == 'y' ? xis.Selecao() : CadastroLeitor();
  }

  vector_leitores_.push_back(novoleitor);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system("pause");
  xis.Controle();
}

bool ServicoAutenticacao::Autenticar() {
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
