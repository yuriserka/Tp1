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
      system(PAUSE);
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
  cmdSql_  = "CREATE TABLE IF NOT EXISTS usuarios (";
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
  cmdSql_ += "definicao INT NOT NULL, ";
  cmdSql_ += "administrador VARCHAR(100) NOT NULL, ";
  cmdSql_ += "FOREIGN KEY(definicao) REFERENCES definicoes(id), ";
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
  cmdSql_ += "FOREIGN KEY(definicao) REFERENCES definicoes(id) );";
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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

  return a;
}

vector<VocabularioControlado> ComandoSqlConsultarVocabs::GetVocabs() {
  vector<VocabularioControlado> vocabularios;
  ElementoResultado resultado;
  VocabularioControlado aux;

  for (auto i = lista_resultado_.begin(); i != lista_resultado_.end(); i++) {
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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

  return vocabularios;
}

vector<Termo> ComandoSqlConsultarTermos::GetTermos() {
  vector<Termo> termos;
  ElementoResultado resultado;
  Termo aux;

  for (auto i = lista_resultado_.begin(); i != lista_resultado_.end(); i++) {
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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

  return termos;
}

vector<Definicao> ComandoSqlConsultarDefinicao::GetDefinicoes() {
  vector<Definicao> definicoes;
  ElementoResultado resultado;
  Definicao aux;

  for (auto i = lista_resultado_.begin(); i != lista_resultado_.end(); i++) {
    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = *i;
    aux.SetData(Data(resultado.GetValorColuna()));

    i++;

    if (lista_resultado_.empty()) {
      throw invalid_argument("Lista Vazia\n");
    }
    resultado = *i;
    aux.SetDefinicao(TextoDefinicao(resultado.GetValorColuna()));

    definicoes.push_back(aux);
  }

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

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

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

  return def;
}