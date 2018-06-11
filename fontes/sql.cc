#include "../cabecalhos/includes.h"

list<ElementoResultado> ComandoSql::lista_resultado_;

void ComandoSql::Conectar() {
  rc_ = sqlite3_open(nome_banco_de_dados_, &bd_);
  if (rc_ != SQLITE_OK) {
    throw ErroDePersistencia("Erro na conexao do banco de dados\n");
  }
}

void ComandoSql::Desconectar() {
  rc_ = sqlite3_close(bd_);
  if (rc_ != SQLITE_OK) {
    throw ErroDePersistencia("Erro na desconexao do banco de dados\n");
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
    throw ErroDePersistencia("Erro na execucao do comando para o banco de dados\n");
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
      cmdSql_  = "CREATE TABLE IF NOT EXISTS usuarios (nome TEXT NOT NULL, ";
      cmdSql_ += "sobrenome TEXT NOT NULL, ";
      cmdSql_ += "senha TEXT NOT NULL, ";
      cmdSql_ += "email TEXT NOT NULL, ";
      cmdSql_ += "nascimento TEXT, ";
      cmdSql_ += "telefone TEXT, ";
      cmdSql_ += "endereco TEXT, ";
      cmdSql_ += "conta TEXT, ";
      cmdSql_ += "PRIMARY KEY(email) );";

      cmdSql_ += "CREATE TABLE IF NOT EXISTS vocabularios (nome TEXT NOT NULL, ";
      cmdSql_ += "idioma TEXT NOT NULL, ";
      cmdSql_ += "data TEXT NOT NULL, ";
      cmdSql_ += "administrador TEXT, ";
      cmdSql_ += "desenvolvedor TEXT, ";
      cmdSql_ += "PRIMARY KEY(nome) );";

      cmdSql_ += "CREATE TABLE IF NOT EXISTS termos (nome TEXT NOT NULL, ";
      cmdSql_ += "classe TEXT NOT NULL, ";
      cmdSql_ += "data TEXT NOT NULL, ";
      cmdSql_ += "vocabulario TEXT, ";
      cmdSql_ += "PRIMARY KEY(nome) );";

      cmdSql_ += "CREATE TABLE IF NOT EXISTS definicao (texto TEXT NOT NULL, ";
      cmdSql_ += "data TEXT NOT NULL, ";
      cmdSql_ += "termo TEXT, ";
      cmdSql_ += "vocabulario TEXT, ";
      cmdSql_ += "PRIMARY KEY(texto) );";
    }

string ComandoSqlLerSenha::RecuperaSenha() const {
  ElementoResultado resultado;
  string senha;

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
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
    throw ErroDePersistencia("Lista Vazia\n");
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
    throw ErroDePersistencia("Lista Vazia\n");
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
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  l.SetNome(Nome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  l.SetSobrenome(Sobrenome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  l.SetSenha(Senha(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
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
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetNome(Nome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetSobrenome(Sobrenome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetSenha(Senha(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  d.SetEmail(Email(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
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
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetNome(Nome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetSobrenome(Sobrenome(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetSenha(Senha(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetEmail(Email(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetDataDeNascimento(Data(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
  }
  resultado = lista_resultado_.back();
  lista_resultado_.pop_back();
  a.SetTelefone(Telefone(resultado.GetValorColuna()));

  if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
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
      throw ErroDePersistencia("Lista Vazia\n");
    }

    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetNome(Nome(resultado.GetValorColuna()));
  
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetIdioma(Idioma(resultado.GetValorColuna()));

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
      throw ErroDePersistencia("Lista Vazia\n");
    }

    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetNome(Nome(resultado.GetValorColuna()));
  
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetPreferencia(ClasseDoTermo(resultado.GetValorColuna()));

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
  vector<Definicao> defs;
  ElementoResultado resultado;
  Definicao aux;

  for (auto i = lista_resultado_.begin(); i != lista_resultado_.end(); i++) {
    if (lista_resultado_.empty()) {
    throw ErroDePersistencia("Lista Vazia\n");
    }
    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetDefinicao(TextoDefinicao(resultado.GetValorColuna()));

    resultado = lista_resultado_.back();
    lista_resultado_.pop_back();
    aux.SetData(Data(resultado.GetValorColuna()));

    defs.push_back(aux);
  }

  while (!lista_resultado_.empty()) {
    lista_resultado_.pop_back();
  }

  return defs;
}

