#include "../cabecalhos/includes.h"

list<ElementoResultado> ComandoSql::lista_resultado_;

void ComandoSql::Conectar() {
  rc_ = sqlite3_open(nome_banco_de_dados_, &bd_);
  if (rc_ != SQLITE_OK) {
    throw invalid_argument("Erro na conexao do banco de dados\n");
  }
}

void ComandoSql::Desconectar() {
  rc_ = sqlite3_close(bd_);
  if (rc_ != SQLITE_OK) {
    throw invalid_argument("Erro na desconexao do banco de dados\n");
  }
}

void ComandoSql::Executar() {
  Conectar();
  rc_ = sqlite3_exec(bd_, cmdSql_.c_str(), Callback, nullptr, &mensagem_);
  if (rc_ != SQLITE_OK) {
    if (mensagem_) {
      sqlite3_free(mensagem_);
    }
    throw invalid_argument("Erro na execucao do comando para o banco de dados\n");
  }
  Desconectar();
}

int ComandoSql::Callback(void *nao_usado, int argc, char **valorcoluna,
                         char **nomecoluna) {
  ElementoResultado elemento;
  for (int i = 0; i < argc; i++) {
    elemento.SetNomeColuna(nomecoluna[i]);
    if (valorcoluna[i] != nullptr) {
      elemento.SetValorColuna(valorcoluna[i]);
    } else {
      continue;
    }
    lista_resultado_.push_front(elemento);
  }
  return 0;
}

ComandoSqlCriarTabelas::ComandoSqlCriarTabelas() {
  cmdSql_ = "CREATE TABLE IF NOT EXISTS usuarios (";
  cmdSql_ += "nome VARCHAR(21) NOT NULL, ";
  cmdSql_ += "sobrenome VARCHAR(21) NOT NULL, ";
  cmdSql_ += "senha VARCHAR(9) NOT NULL, ";
  cmdSql_ += "email VARCHAR(100) NOT NULL, ";
  cmdSql_ += "nascimento VARCHAR(11), ";
  cmdSql_ += "telefone VARCHAR(14), ";
  cmdSql_ += "endereco VARCHAR(21), ";
  cmdSql_ += "conta VARCHAR(14) NOT NULL, ";
  cmdSql_ += "PRIMARY KEY(email) );";

  cmdSql_ += "CREATE TABLE IF NOT EXISTS vocabularios (";
  cmdSql_ += "nome VARCHAR(21) NOT NULL, ";
  cmdSql_ += "idioma VARCHAR(4) NOT NULL, ";
  cmdSql_ += "data VARCHAR(11) NOT NULL, ";
  cmdSql_ += "definicao VARCHAR(31) NOT NULL, ";
  cmdSql_ += "administrador VARCHAR(100) NOT NULL, ";
  cmdSql_ += "FOREIGN KEY(definicao) REFERENCES definicoes(texto), ";
  cmdSql_ += "FOREIGN KEY(administrador) REFERENCES usuarios(email), ";
  cmdSql_ += "PRIMARY KEY(nome) );";

  cmdSql_ += "CREATE TABLE IF NOT EXISTS termos (";
  cmdSql_ += "nome VARCHAR(21) NOT NULL, ";
  cmdSql_ += "classe VARCHAR(3) NOT NULL, ";
  cmdSql_ += "data VARCHAR(11) NOT NULL, ";
  cmdSql_ += "vocabulario VARCHAR(21) NOT NULL, ";
  cmdSql_ += "FOREIGN KEY(vocabulario) REFERENCES vocabularios(nome), ";
  cmdSql_ += "PRIMARY KEY(nome) );";

  cmdSql_ += "CREATE TABLE IF NOT EXISTS definicoes (";
  cmdSql_ += "texto VARCHAR(31) NOT NULL, ";
  cmdSql_ += "data VARCHAR(11) NOT NULL, ";
  cmdSql_ += "PRIMARY KEY(texto) );";

  cmdSql_ += "CREATE TABLE IF NOT EXISTS desenvolvedor_vocabulario (";
  cmdSql_ += "desenvolvedor VARCHAR(100) NOT NULL, ";
  cmdSql_ += "vocabulario VARCHAR(21) NOT NULL, ";
  cmdSql_ += "FOREIGN KEY(desenvolvedor) REFERENCES usuarios(email), ";
  cmdSql_ += "FOREIGN KEY(vocabulario) REFERENCES vocabularios(nome) );";

  cmdSql_ += "CREATE TABLE IF NOT EXISTS termo_definicao (";
  cmdSql_ += "termo VARCHAR(21) NOT NULL, ";
  cmdSql_ += "definicao VARCHAR(31) NOT NULL, ";
  cmdSql_ += "FOREIGN KEY(termo) REFERENCES termos(nome), ";
  cmdSql_ += "FOREIGN KEY(definicao) REFERENCES definicoes(texto) );";
}

string ComandoSqlLerSenha::RecuperaSenha() const {
  ElementoResultado resultado;
  string senha;

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  senha = resultado.GetValorColuna();

  lista_resultado_.clear();

  return senha;
}

string ComandoSqlLerEmail::RecuperaEmail() const {
  ElementoResultado resultado;
  string email;

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  email = resultado.GetValorColuna();

  lista_resultado_.clear();

  return email;
}

string ComandoSqlTipoConta::RecuperaConta() const {
  ElementoResultado resultado;
  string conta;

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  conta = resultado.GetValorColuna();

  lista_resultado_.clear();

  return conta;
}

Leitor ComandoSqlPesquisarUsuario::GetLeitor() const {
  ElementoResultado resultado;
  Leitor l;

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  l.SetNome(Nome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  l.SetSobrenome(Sobrenome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  l.SetSenha(Senha(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  l.SetEmail(Email(resultado.GetValorColuna()));

  lista_resultado_.clear();

  return l;
}

Desenvolvedor ComandoSqlPesquisarUsuario::GetDev() const {
  ElementoResultado resultado;
  Desenvolvedor d;

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetNome(Nome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetSobrenome(Sobrenome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetSenha(Senha(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetEmail(Email(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetDataDeNascimento(Data(resultado.GetValorColuna()));

  lista_resultado_.clear();

  return d;
}

Administrador ComandoSqlPesquisarUsuario::GetAdm() const {
  ElementoResultado resultado;
  Administrador a;

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetNome(Nome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetSobrenome(Sobrenome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetSenha(Senha(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetEmail(Email(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetDataDeNascimento(Data(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetTelefone(Telefone(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetEndereco(Address(resultado.GetValorColuna()));

  lista_resultado_.clear();

  return a;
}

vector<VocabularioControlado> ComandoSqlConsultarVocabs::GetVocabs() {
  vector<VocabularioControlado> vocabularios;
  ElementoResultado resultado;
  VocabularioControlado aux;

  while (!lista_resultado_.empty()) {
    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetNome(Nome(resultado.GetValorColuna()));

    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetIdioma(Idioma(resultado.GetValorColuna()));

    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetData(Data(resultado.GetValorColuna()));

    vocabularios.push_back(aux);
  }

  lista_resultado_.clear();

  return vocabularios;
}

vector<Termo> ComandoSqlConsultarTermos::GetTermos() {
  vector<Termo> termos;
  ElementoResultado resultado;
  Termo aux;

  while (!lista_resultado_.empty()) {
    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }

    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetNome(Nome(resultado.GetValorColuna()));

    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetPreferencia(ClasseDoTermo(resultado.GetValorColuna()));

    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetData(Data(resultado.GetValorColuna()));

    termos.push_back(aux);
  }

  lista_resultado_.clear();

  return termos;
}

vector<Nome> ComandoSqlConsultarTermos::GetNomes() {
  vector<Nome> termos;
  ElementoResultado resultado;
  Nome aux;

  while (!lista_resultado_.empty()) {
    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetNome(resultado.GetValorColuna());

    termos.push_back(aux);
  }

  lista_resultado_.clear();

  return termos;
}

vector<Definicao> ComandoSqlConsultarDefinicao::GetDefinicoes() {
  vector<Definicao> definicoes;
  ElementoResultado resultado;
  Definicao aux;

  while (!lista_resultado_.empty()) {
    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetDefinicao(TextoDefinicao(resultado.GetValorColuna()));

    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetData(Data(resultado.GetValorColuna()));

    definicoes.push_back(aux);
  }

  lista_resultado_.clear();

  return definicoes;
}

Definicao ComandoSqlConsultarDefinicao::GetDefinicao() {
  ElementoResultado resultado;
  Definicao def;

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  def.SetDefinicao(TextoDefinicao(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw invalid_argument("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  def.SetData(Data(resultado.GetValorColuna()));

  lista_resultado_.clear();

  return def;
}

vector<Email> ComandoSqlConsultarDevs::GetDevs() {
  vector<Email> desenvolvedores;
  ElementoResultado resultado;
  Email aux;

  while (!lista_resultado_.empty()) {
    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetEmail(resultado.GetValorColuna());

    desenvolvedores.push_back(aux);
  }

  lista_resultado_.clear();

  return desenvolvedores;
}