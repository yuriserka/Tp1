#include "apresentacao.h"

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

vector<Leitor> v_leitor_;
vector<Administrador> v_admin_;
vector<Desenvolvedor> v_desenvolvedor_;

void ServicoAutenticacao::CadastrarAdministrador() {
  system(CLEAR);
  Administrador novoadministrador;
  ApresentacaoControle ac_;

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
    system(PAUSE);
    CadastrarAdministrador();
  }

  try {
    novoadministrador = Administrador(nome_, sobrenome_, senha_, email_, data_, telefone_, endereco_);
  }
  catch (exception &e) {
    char sair;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e se cadastrar como outra coisa? [y / n] : ";
    cin >> sair;
    sair == 'y' ? ac_.Cadastrar() : CadastrarAdministrador();
  }

  v_admin_.push_back(novoadministrador);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system(PAUSE);
}

void ServicoAutenticacao::CadastrarDesenvolvedor() {
  system(CLEAR);
  Desenvolvedor novodesenvolvedor;
  ApresentacaoControle ac_;

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
    system(PAUSE);
    CadastrarDesenvolvedor();
  }

  try {
    novodesenvolvedor = Desenvolvedor(nome_, sobrenome_, senha_, email_, data_);
  }
  catch (exception &e) {
    char sair;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e se cadastrar como outra coisa? [y / n] : ";
    cin >> sair;
    sair == 'y' ? ac_.Cadastrar() : CadastrarDesenvolvedor();
  }

  v_desenvolvedor_.push_back(novodesenvolvedor);
  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system(PAUSE);
}

void ServicoAutenticacao::CadastrarLeitor() {
  system(CLEAR);
  Leitor novoleitor;
  ApresentacaoControle ac_;

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
    system(PAUSE);
    CadastrarLeitor();
  }

  try {
    novoleitor = Leitor(nome_, sobrenome_, senha_, email_);
  }
  catch (exception &e) {
    char sair;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e se cadastrar como outra coisa? [y / n] : ";
    cin >> sair;
    sair == 'y' ? ac_.Cadastrar() : CadastrarLeitor();
  }

  v_leitor_.push_back(novoleitor);

  cout << "Conta criada com sucesso, agora voce pode fazer login!\n";
  system(PAUSE);
}

bool ServicoAutenticacao::Autenticar(const Email &email_procurado, const Senha &senha_procurada) {
  bool ok = true;

  for (auto const leitor : v_leitor_) {
    if (leitor.GetEmail().GetEmail() == email_procurado.GetEmail() &&
        leitor.GetSenha().GetSenha() == senha_procurada.GetSenha()) {
      return ok;
    }
  }

  for (auto const desenvolvedor : v_desenvolvedor_) {
    if (desenvolvedor.GetEmail().GetEmail() == email_procurado.GetEmail() &&
        desenvolvedor.GetSenha().GetSenha() == senha_procurada.GetSenha()) {
      return ok;
    }
  }

  for (auto const admin : v_admin_) {
    if (admin.GetEmail().GetEmail() == email_procurado.GetEmail() &&
        admin.GetSenha().GetSenha() == senha_procurada.GetSenha()) {
      return ok;
    }
  }
  return !ok;
}

void ServicoUsuario::Procurador(const Email &email) {
  auto lit = find(v_leitor_.begin(), v_leitor_.end(), email);
  auto dit = find(v_desenvolvedor_.begin(), v_desenvolvedor_.end(), email);
  auto ait = find(v_admin_.begin(), v_admin_.end(), email);

  if (lit < v_leitor_.end()) {
    cout << "Nome: " << lit->GetNome().GetNome() << " " << lit->GetSobrenome().GetSobrenome() << "\n";
    cout << "Email: " << lit->GetEmail().GetEmail() << "\n";
    cout << "Senha: " << lit->GetSenha().GetSenha() << "\n";

  } else if (dit < v_desenvolvedor_.end()) {
    cout << "Nome: " << dit->GetNome().GetNome() << " " << dit->GetSobrenome().GetSobrenome() << "\n";
    cout << "Email: " << dit->GetEmail().GetEmail() << "\n";
    cout << "Senha: " << dit->GetSenha().GetSenha() << "\n";
    cout << "Data de Nascimento: " << dit->GetDataDeNascimento().GetData() << "\n";

  } else if (ait < v_admin_.end()) {
    cout << "Nome: " << ait->GetNome().GetNome() << " " << ait->GetSobrenome().GetSobrenome() << "\n";
    cout << "Email: " << ait->GetEmail().GetEmail() << "\n";
    cout << "Senha: " << ait->GetSenha().GetSenha() << "\n";
    cout << "Data de Nascimento: " << ait->GetDataDeNascimento().GetData() << "\n";
    cout << "Telefone: " << ait->GetTelefone().GetTelefone() << "\n";
    cout << "Endereco: " << ait->GetEndereco().GetAddress() << "\n";

  } else {
    throw invalid_argument("Usuario nao encontrado\n");
  }
}

void ServicoUsuario::Deletar(const Email &email) {
  auto lit = find(v_leitor_.begin(), v_leitor_.end(), email);
  auto dit = find(v_desenvolvedor_.begin(), v_desenvolvedor_.end(), email);
  auto ait = find(v_admin_.begin(), v_admin_.end(), email);

  if (lit < v_leitor_.end()) {
    v_leitor_.erase(lit);

  } else if (dit < v_desenvolvedor_.end()) {
    v_desenvolvedor_.erase(dit);

  } else if (ait < v_admin_.end()) {
    v_admin_.erase(ait);

  } else {
    throw invalid_argument("Usuario nao encontrado\n");
  }
}

void ServicoAutenticacao::RecuperarSenha(const Email &email) {
  auto lit = find(v_leitor_.begin(), v_leitor_.end(), email);
  auto dit = find(v_desenvolvedor_.begin(), v_desenvolvedor_.end(), email);
  auto ait = find(v_admin_.begin(), v_admin_.end(), email);

  if (lit < v_leitor_.end()) {
    cout << "Sua Senha: " << lit->GetSenha().GetSenha() << "\n";

  } else if (dit < v_desenvolvedor_.end()) {
    cout << "Sua Senha: " << dit->GetSenha().GetSenha() << "\n";

  } else if (ait < v_admin_.end()) {
    cout << "Sua Senha: " << ait->GetSenha().GetSenha() << "\n";

  } else {
    throw invalid_argument("Usuario nao encontrado\n");
  }
}

int ServicoUsuario::TipoConta(const Email &email) {
  auto lit = find(v_leitor_.begin(), v_leitor_.end(), email);
  auto dit = find(v_desenvolvedor_.begin(), v_desenvolvedor_.end(), email);
  auto ait = find(v_admin_.begin(), v_admin_.end(), email);

  enum AccType {
    kleitor,
    kdesenvolvedor,
    kadministrador,
  };

  if (lit < v_leitor_.end()) {
    return kleitor;

  } else if (dit < v_desenvolvedor_.end()) {
    return kdesenvolvedor;

  } else if (ait < v_admin_.end()) {
    return kadministrador;

  } else {
    throw invalid_argument("Usuario nao encontrado\n");
  }
}

void ServicoUsuario::AtualizarLeitor(const Email &_email) {
  system(CLEAR);
  Leitor novoleitor;
  ApresentacaoUsuario au_;

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

    cout << "Digite sua Senha: ";
    cin >> senha;
    senha_ = Senha(senha);

  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    AtualizarLeitor(_email);
  }

  try {
    novoleitor = Leitor(nome_, sobrenome_, senha_, _email); // email é constante
  }
  catch (exception &e) {
    char sair;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e manter os dados como estao? [y / n]\n\tOpcao: ";
    cin >> sair;
    sair == 'y' ? au_.Controle() : AtualizarLeitor(_email);
  }

  Deletar(_email);
  v_leitor_.push_back(novoleitor);

  cout << "Conta alterada com sucesso\n";
  system(PAUSE);
}

void ServicoUsuario::AtualizarDesenvolvedor(const Email &_email) {
  system(CLEAR);
  Desenvolvedor novodesenvolvedor;
  ApresentacaoUsuario au_;

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

    cout << "Digite sua Senha: ";
    cin >> senha;
    senha_ = Senha(senha);

    cout << "Digite sua Data de nascimento: ";
    cin >> data;
    data_ = Data(data);

  }
  catch (exception &e) {
    cout << "\n\t" << e.what() << "\n";
    system(PAUSE);
    AtualizarDesenvolvedor(_email);
  }

  try {
    novodesenvolvedor = Desenvolvedor(nome_, sobrenome_, senha_, _email, data_);
  }
  catch (exception &e) {
    char sair;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e manter os dados como estao? [y / n]\n\tOpcao: ";
    cin >> sair;
    sair == 'y' ? au_.Controle() : AtualizarDesenvolvedor(_email);
  }

  Deletar(_email);
  v_desenvolvedor_.push_back(novodesenvolvedor);

  cout << "Conta alterada com sucesso\n";
  system(PAUSE);
}

void ServicoUsuario::AtualizarAdministrador(const Email &_email) {
  system(CLEAR);
  Administrador novoadministrador;
  ApresentacaoUsuario au_;

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
    system(PAUSE);
    AtualizarAdministrador(_email);
  }

  try {
    novoadministrador = Administrador(nome_, sobrenome_, senha_, _email, data_, telefone_, endereco_);
  }
  catch (exception &e) {
    char sair;
    cout << "\n\t" << e.what() << "\n";
    cout << "Deseja sair e manter os dados como estao? [y / n]\n\tOpcao: ";
    cin >> sair;
    sair == 'y' ? au_.Controle() : AtualizarAdministrador(_email);
  }

  Deletar(_email);
  v_admin_.push_back(novoadministrador);

  cout << "Conta alterada com sucesso\n";
  system(PAUSE);
}