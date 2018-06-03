#ifndef TRABALHO__CMDSQL__H__
#define TRABALHO__CMDSQL__H__

#include "includes.h"

class ErroDePersistencia {
  public:
    ErroDePersistencia(string mensagem) {
      this->msg_ = mensagem;
    }
    
    string GetMsg() const {
      return msg_;
    }

  private:
    string msg_;
};

class ElementoResultado {
  public:
    inline void SetNomeColuna(const string &colname) {
      this->nome_coluna_ = colname;
    }

    inline void SetValorColuna(const string &colval) {
      this->valor_coluna_ = colval;
    }

    inline string GetNomeColuna() const {
      return nome_coluna_;
    }

    inline string GetValorColuna() const {
      return valor_coluna_;
    }

  private:
    string nome_coluna_;
    string valor_coluna_;
};

class ComandoSql {
  public:
    ComandoSql() {
      nome_banco_de_dados_ = "databank.db";
    }
    void Executar();
    
  protected:
    string cmdSql_;
    static list<ElementoResultado> lista_resultado_;

  private:
    const char* nome_banco_de_dados_;
    sqlite3* bd_;
    char* mensagem_;
    int rc_;
    void Conectar();
    void Desconectar();
    static int Callback(void *, int, char **, char **);
};

class ComandoSqlLerSenha : public ComandoSql {
  public:
    ComandoSqlLerSenha() = default;
    explicit ComandoSqlLerSenha(const Email &email) {
      cmdSql_  = "SELECT senha FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }

    string RecuperaSenha() const;
};

class ComandoSqlLerEmail : public ComandoSql {
  public:
    ComandoSqlLerEmail() = default;
    explicit ComandoSqlLerEmail(const Email &email) {
      cmdSql_  = "SELECT email FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }
    string RecuperaEmail() const;
};

class ComandoSqlTipoConta : public ComandoSql {
  public:
    ComandoSqlTipoConta() = default;
    explicit ComandoSqlTipoConta(const Email &email) {
      cmdSql_ = "SELECT conta FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }
    string RecuperaConta() const;
};

class ComandoSqlCadastrar : public ComandoSql { 
  public:
    ComandoSqlCadastrar() = default;
    explicit ComandoSqlCadastrar(const Leitor &leitor, string conta) {
      cmdSql_ = "INSERT or IGNORE INTO usuarios (nome, sobrenome, senha, email, conta)"\
      " VALUES (";
      cmdSql_ += "'" + leitor.GetNome().GetNome() +           "', ";
      cmdSql_ += "'" + leitor.GetSobrenome().GetSobrenome() + "', ";
      cmdSql_ += "'" + leitor.GetSenha().GetSenha() +         "', ";
      cmdSql_ += "'" + leitor.GetEmail().GetEmail() +         "', ";
      cmdSql_ += "'" + conta + "');";
    }

    explicit ComandoSqlCadastrar(const Desenvolvedor &dev, string conta) {
      cmdSql_ = "INSERT or IGNORE INTO usuarios (nome, sobrenome, senha, email, "\
      "nascimento, conta) VALUES (";
      cmdSql_ += "'" + dev.GetNome().GetNome() +              "', ";
      cmdSql_ += "'" + dev.GetSobrenome().GetSobrenome() +    "', ";
      cmdSql_ += "'" + dev.GetSenha().GetSenha() +            "', ";
      cmdSql_ += "'" + dev.GetEmail().GetEmail() +            "', ";
      cmdSql_ += "'" + dev.GetDataDeNascimento().GetData() +  "', ";
      cmdSql_ += "'" + conta + "');";
    }

    explicit ComandoSqlCadastrar(const Administrador &adm, string conta) {
      cmdSql_ = "INSERT or IGNORE INTO usuarios (nome, sobrenome, senha, email, "\
      "nascimento, telefone, endereco, conta) VALUES (";
      cmdSql_ += "'" + adm.GetNome().GetNome() +              "', ";
      cmdSql_ += "'" + adm.GetSobrenome().GetSobrenome() +    "', ";
      cmdSql_ += "'" + adm.GetSenha().GetSenha() +            "', ";
      cmdSql_ += "'" + adm.GetEmail().GetEmail() +            "', ";
      cmdSql_ += "'" + adm.GetDataDeNascimento().GetData() +  "', ";
      cmdSql_ += "'" + adm.GetTelefone().GetTelefone() +      "', ";
      cmdSql_ += "'" + adm.GetEndereco().GetAddress() +       "', ";
      cmdSql_ += "'" + conta + "');";
    }
};

class ComandoSqlAtualizar : public ComandoSql {
  public:
    ComandoSqlAtualizar() = default;
    explicit ComandoSqlAtualizar(const Leitor &leitor) {
      cmdSql_  = "UPDATE usuarios ";
      cmdSql_ += "SET nome = '"      + leitor.GetNome().GetNome();
      cmdSql_ += "', sobrenome = '"  + leitor.GetSobrenome().GetSobrenome(); 
      cmdSql_ += "', senha = '"      + leitor.GetSenha().GetSenha();
      cmdSql_ += "' WHERE email = '" + leitor.GetEmail().GetEmail() + "';";
    }

    explicit ComandoSqlAtualizar(const Desenvolvedor &dev) {
      cmdSql_  = "UPDATE usuarios ";
      cmdSql_ += "SET nome = '"      + dev.GetNome().GetNome();
      cmdSql_ += "', sobrenome = '"  + dev.GetSobrenome().GetSobrenome(); 
      cmdSql_ += "', senha = '"      + dev.GetSenha().GetSenha();
      cmdSql_ += "', nascimento = '"  + dev.GetDataDeNascimento().GetData();
      cmdSql_ += "' WHERE email = '" + dev.GetEmail().GetEmail() + "';";
    }

    explicit ComandoSqlAtualizar(const Administrador &adm) {
      cmdSql_  = "UPDATE usuarios ";
      cmdSql_ += "SET nome =      '"  + adm.GetNome().GetNome();
      cmdSql_ += "', sobrenome =  '"  + adm.GetSobrenome().GetSobrenome(); 
      cmdSql_ += "', senha =      '"  + adm.GetSenha().GetSenha();
      cmdSql_ += "', nascimento = '"  + adm.GetDataDeNascimento().GetData();
      cmdSql_ += "', telefone =   '"  + adm.GetTelefone().GetTelefone();
      cmdSql_ += "', endereco =   '"  + adm.GetEndereco().GetAddress();
      cmdSql_ += "' WHERE email = '"  + adm.GetEmail().GetEmail() + "';";
    }
};

class ComandoSqlCriarTabelas : public ComandoSql {
  public:
    explicit ComandoSqlCriarTabelas() {
      cmdSql_  = "CREATE TABLE IF NOT EXISTS usuarios (nome TEXT NOT NULL, ";
      cmdSql_ += "sobrenome TEXT NOT NULL, ";
      cmdSql_ += "senha TEXT NOT NULL, ";
      cmdSql_ += "email TEXT NOT NULL, ";
      cmdSql_ += "nascimento TEXT, ";
      cmdSql_ += "telefone TEXT, ";
      cmdSql_ += "endereco TEXT, ";
      cmdSql_ += "conta TEXT, ";
      cmdSql_ += "PRIMARY KEY(email) );";
    }
};

class ComandoSqlPesquisarUsuario : public ComandoSql {
  public:
    ComandoSqlPesquisarUsuario() = default;
    explicit ComandoSqlPesquisarUsuario(const Email &email) {
      cmdSql_  = "SELECT * FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }

    Leitor GetLeitor() const;
    Desenvolvedor GetDev() const;
    Administrador GetAdm() const;
};

class ComandoSqlRemover : public ComandoSql {
  public:
    ComandoSqlRemover() = default;
    explicit ComandoSqlRemover(const Email &email) {
      cmdSql_  = "DELETE FROM usuarios WHERE email = ";
      cmdSql_ += "'" + email.GetEmail() + "';";
    }
};

#endif  //TRABALHO__CMDSQL__H__
